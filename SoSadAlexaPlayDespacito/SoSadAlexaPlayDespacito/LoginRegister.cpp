#include <iostream>
#include <string>
#include <conio.h>
#include <memory>
#include <windows.h>

#include "Classes.h"
#include "Constants.h"
#include "Decor.h"
#include "Hash.h"
#include "Exceptions.h"
#include "LoginRegister.h"


using namespace std;
using namespace Hash;


string EnterLogin()
{
	string str;
	char c;
	while (1)
	{
		c = _getch();
		if (c == ENTER)
		{
			if (str.size() == 0) continue;
			else break;
		}
		if (c == 8)
		{
			if (str.size() == 0) continue;
			str.pop_back();
			deleteSymbol();
		}
		if (symbolCheck(c) == 0) continue;
		if (c == '`') continue;
		if (str.size() > 14) continue;
		str.append(1, c);
		_putch(c);
	}
	return str;
}

string EnterPassword() 
{
	string str;
	char c;
	while (1)
	{
		c = _getch();
		if (c == ENTER)
		{
			if (str.size() == 0) continue;
			else break;
		}
		if (c == 8)
		{
			if (str.size() == 0) continue;
			str.pop_back();
			deleteSymbol();
		}
		if (symbolCheck(c) == 0) continue;
		if (c == '`') continue;
		str.append(1, c);
		_putch(HIDE_SYMBOL);
	}
	return str;
}

void User::setPasswordWithHash(string password)
{
	this->password = getHash(password);
}

User changeLogin(User user)
{
	cout << "Enter new login (no more than 14 characters, latin letters and numbers only): ";
	string str;
	str = EnterLogin();
	user.setLogin(str);
	rewriteObjectToFile(USER_DATA_FILE, user, user.getId());
	return user;
}

User changePassword(User user)
{
	string str1, str2;
	cout << "Enter current password: ";
	str1 = EnterPassword();
	if (getHash(str1) != user.getPassword())
	{
		cout << "\nWrong password :(\n";
		system("pause");
		return user;
	}
	cout << "\nEnter new password (latin letters and numbers only): ";
	str1 = EnterPassword();
	cout << "\nRepeat password: ";
	str2 = EnterPassword();
	if (str1 != str2)
	{
		cout << "\nPasswords do not match :(\n";
		system("pause");
		return user;
	}
	user.setPasswordWithHash(str1);
	rewriteObjectToFile(USER_DATA_FILE, user, user.getId());
	return user;
}

bool doPasswrodsMatch(string a, string b)
{
	int size = a.size();
	if (size != b.size())
		return false;
	for (int i = 0; i < size; i++)
	{
		if (a[i] == b[i])
			continue;
		else
			return false;
	}
	return true;
}



int loginmenu(User& user)
{
	string password, login;
	User c;
	User* u = new User;
	int found = 0;
	char choice;
	int access;
	int role;
	while (1)
	{
		system("cls");
		printHeader("Log in into an existing account", 13);
		cout << "Enter login: ";
		login = EnterLogin();
		u->setLogin(login);
		cout << "\nEnter password: ";
		password = EnterPassword();
		u->setPassword(password);
		separator();
		cout << "\nTrying to log in...\n";
		separator();
		ifstream file;
		file.open(USER_DATA_FILE);
		if (!file.is_open())
		{
			cout << "Error! Unable to open the file!\n";
			system("pause");
			delete u;
			return -1;
		}
		if (u->getLogin() == "admin" && u->getPassword() == "admin")
		{
			cout << "Logged in successfully! " << ENTER_ANY_CHARACTER << '\n';
			system("pause");
			delete u;
			return 2;
		}
		u->setPassword(getHash(u->getPassword()));
		password = u->getPassword();
		while (file.peek() != EOF)
		{
			file >> c;
			if (((*u == c) || (login == c.getLogin() && password == c.getPassword())) && c.getNeedsToBeShown() == 1)
			{
				user = c;
				found = 1;
				break;
			}
		}
		if (found == 0)
		{
			cout << "Check that entered login and password are correct.\n Pres 1 to continue or any other key to leave.\n";
			choice = _getch();
			if (choice == '1')
				continue;
			else
			{
				delete u;
				return -1;
			}
		}
		access = c.getAccess();
		try
		{
			if (access == 0) throw LoginErrorNotConfirmed();
			else if (access == 2) throw LoginErrorBan();
		}
		catch (LoginErrorBan e)
		{
			cout << e.what();
			delete u;
			return -1;
		}
		catch (LoginErrorNotConfirmed e)
		{
			cout << e.what();
			delete u;
			return -1;
		}
		cout << "Logged in successfully! " << ENTER_ANY_CHARACTER << '\n';
		system("pause");
		role = c.getRole();
		delete u;
		return role;
	}
}

User registermenu()
{
	string password;
	string checkPassword;
	int check;
	User user;
	while (1)
	{
		system("cls");
		printHeader("Registration of a new account", 13);
		cout << "Enter new login (no more than 14 characters, latin letters and numbers only): ";
		user.setLogin(EnterLogin());
		cout << "\nEnter password (latin letters and numbers only): ";
		password = EnterPassword();
		cout << "\nRepeat password: ";
		checkPassword = EnterPassword();
		separator();
		if (doPasswrodsMatch(password, checkPassword))
		{
			user.setPasswordWithHash(password);
			user.setRole(0);
			user.setAccess(1);
			cout << "Trzing to register an account...";
			separator();
			if (user.registerUser() == 1)
			{
				cout << "Account was created! " << ENTER_ANY_CHARACTER << '\n';
				User::increaseSignedIn();
				system("pause");
				return user;
			}
			else
			{
				cout << "Unable to create an account. " << ENTER_ANY_CHARACTER << '\n';
				system("pause");
				return user;
			}
		}
		else
		{
			cout << "Passwords do not match! " << ENTER_ANY_CHARACTER << '\n';
			system("pause");
			return user;
		}
	}
	return user;
}


void writeReportInFile()
{
	ofstream file;
	file.open(REPORT_DATA_FILE, ios::app);
	ReportOld r;
	r.setLoggedCount(User::loggedIn);
	r.setRegCount(User::registered);
	r.setBoughtCount(Ticket::bought);
	r.setMoviesCount(Movie::addedCount);
	r.setCinemasCount(Cinema::addedCount);
	r.setSeancesCount(Seance::addedCount);
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file.\n";
		std::system("pause");
		return;
	}
	file << r;
	file.close();
	return;
}

