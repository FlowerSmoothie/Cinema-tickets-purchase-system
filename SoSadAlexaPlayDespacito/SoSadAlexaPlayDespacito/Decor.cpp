#include <algorithm>
#include <cmath>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <iomanip>

#include "Constants.h"
#include "Decor.h"

using namespace std;

void separator()
{
	cout << "\n-----------------------------------\n";
}

void littleSeparator()
{
	cout << "\n-----\n";
}


void changeColor(int color)
{
	HANDLE consoleColor;
	consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleColor, color);
}

void printHeader(string str, int color)
{
	changeColor(color);
	cout << "---------";
	cout << " " << str << " ";
	cout << "---------";
	cout << "\n";
	changeColor(15);
}

void deleteSymbol()
{
	_putch('\b');
	_putch(' ');
	_putch('\b');
}

void switchWrongInput()
{
	cout << WRONG_INPUT << ' ' << ENTER_ANY_CHARACTER;
	cout << '\n';
	system("pause");
	system("cls");
}

bool isDigit(char c)
{
	if (c >= 48 && c <= 57)
		return true;
	return false;
}

bool isEngLetter(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return true;
	return false;
}

string enterNumberInString()
{
	string str;
	char c;
	while (1)
	{
		c = _getch();
		if (c == ENTER)
		{
			if (str.size() == 0)
				continue;
			else
				break;
		}
		if (c == 8)
		{
			if (str.size() == 0)
				continue;
			str.pop_back();
			deleteSymbol();
		}
		if (isDigit(c) == 0)
		{
			continue;
		}
		str.append(1, c);
		_putch(c);
	}
	return str;
}

int enterAnyDigit()
{
	int choice;
	while (true)
	{
		cin >> choice;
		if (!cin)
		{
			cin.clear();
			cout << "Enter a number please!";
			cin.ignore(10000, '\n');
			continue;
		}
		return choice;
	}
}

int enterDigit()
{
	int choice;
	while (true)
	{
		cin >> choice;
		if (!cin || choice < 0)
		{
			cin.clear();
			std::cout << "Enter a positive number please! ";
			cin.ignore(10000, '\n');
			continue;
		}
		return choice;
	}
	cout << endl;
}

size_t capacity(int n) {
	size_t i = 0;
	for (; n; n /= 10)
		++i;
	return i;
}

string enterLineWithCertainSize(int size)
{
	string str;
	while (true)
	{
		cin.clear();
		getline(cin, str);
		if (str == "") continue;
		if (str.size() <= size) return str;
		cout << "Too much!\n";
	}
}

int checkExit()
{
	int key;
	while (true)
	{
		system("cls");
		cout << "Are you sure you want to exit? 0 for no, 1 for yes.\n";
		while (true)
		{
			key = enterDigit();
			if (key == 1 || key == 0) break;
			cout << "Enter 0 or 1!\n";
		}
		return key;
	}
}

int numberInputCheck(int index, int size)
{
	if (index > size && index < 1)
	{
		std::cout << WRONG_INPUT << endl;
		std::system("pause");
		return 0;
	}
	return 1;
}

double roundingToSecond(double a)
{
	return (round(a * 100) / 100);
}

int countStringCountInString(string strBig, string strSmall)
{
	size_t count = 0;
	for (std::string::size_type i = 0; i < strBig.length(); ++i)
		if (strBig[i] == strSmall[0])
			if (strBig.substr(i, strSmall.length()) == strSmall)
			{
				++count;
				i += strSmall.length() - 1;
			}
	return count;
}

double enterDouble()
{
	string str;
	char c;
	while (1)
	{
		c = _getch();
		if (c == ENTER)
		{
			if (str.size() == 0) continue;
			else
			{
				if (countStringCountInString(str, ".") > 1)
				{
					cout << "\nToo many dots!\n";
					continue;
				}
				if(stod(str) > 0) break;
				str.clear();
				cout << "\nEnter a positive number!\n";
			}
		}
		if (c == 8)
		{
			if (str.size() == 0) continue;
			str.pop_back();
			deleteSymbol();
		}
		if (isDigit(c) == 0 && c != 46)	continue;
		str.append(1, c);
		_putch(c);
	}
	double res = roundingToSecond(stod(str));
	return res;
}

int enterNumber()
{
	string str = enterNumberInString();
	return stoi(str);
}

bool isRusLetter(char c)
{
	if ((c >= -64 && c <= -33) || (c >= -32 && c <= -1))
		return true;
	return false;
}

int symbolCheck(char c)
{
	//if ((c >= 48 && c <= 57) || c == 61 || c == 173 || (c >= 65 && c <= 90) || c == 192)
	if (isEngLetter(c) || isDigit(c) || c == 96 || c == 92)
		return 1;
	else
		return 0;
}


int countLinesInFile(string name)
{
	ifstream file;
	file.open(name);
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file.\n";
		std::system("pause");
		return 0;
	}
	string line;
	int count = 0;
	while (file.peek() != EOF)
	{
		getline(file, line);
		count++;
	}
	file.close();
	return count;
}



vector<string> divideString(string line, string separator)
{
	vector<string> vec;
	size_t pos = 0;
	while (pos = line.find(separator) != string::npos)
	{
		vec.push_back(line.substr(0, pos));
		line.erase(0, pos + 1);
	}
	return vec;
}

vector<int> stringVectorToInt(vector<string> vec)
{
	vector<int> vect = {};
	if (vec.size() == 1 || vect.size() == 0) return vect;
	for (int i = 0; i < vec.size(); i++) vect.push_back(stoi(vec[i]));
	return vect;
}

string intVectorToString(vector<int> vec)
{
	string str = "";
	for (int i = 0; i < vec.size() - 1; i++) str += to_string(vec[i]) + "▲";
	str += "0";
	return str;
}


istream& operator >> (istream& is, vector<int> ints)
{
	return is;
}

ostream& operator << (ostream& os, vector<int> ints)
{
	os << ints.size() << endl;
	for (int i = 0; i < ints.size(); i++) os << ints[i] << endl;
	return os;
}

void printUsersTableHeader()
{
	std::cout << "|| " << setiosflags(ios::left) << setw(4) << "ID";
	std::cout << " | " << setw(15) << "Login";
	std::cout << " | " << setw(7) << "Role";
	std::cout << " | " << setw(6) << "Access";
	std::cout << " | " << setw(20) << "Name";
}

void printMovieTableHeader()
{
	std::cout << "|| " << setiosflags(ios::left) << setw(4) << "ID";
	std::cout << " | " << setw(30) << "Name";
	std::cout << " | " << setw(15) << "Goes for HH:MM";
	std::cout << " | " << setw(8) << "Audience";
}

void printCinemaTableHeader()
{
	std::cout << "|| " << setiosflags(ios::left) << setw(4) << "ID";
	std::cout << " | " << setw(30) << "Adress";
	std::cout << " | " << setw(15) << "Name";
	std::cout << " | " << setw(5) << "Halls";
}

void printHallTableHeader()
{
	std::cout << "|| " << setiosflags(ios::left) << setw(4) << "ID";
	std::cout << " | " << setw(6) << "Number";
	std::cout << " | " << setw(4) << "Rows";
	std::cout << " | " << setw(7) << "In rows";
	std::cout << " | " << setw(10) << "Seat count";
}

void printSeanceTableHeader()
{
	std::cout << "|| " << setiosflags(ios::left) << setw(4) << "ID";
	std::cout << " | " << setw(30) << "Movie";
	std::cout << " | " << setw(15) << "Cinema";
	std::cout << " | " << setw(10) << "Date";
	std::cout << " | " << setw(5) << "Time";
	std::cout << " | " << setw(3) << "Hall";
}

void printTicketTableHeader()
{
	std::cout << "|| " << setiosflags(ios::left) << setw(4) << "ID";
	std::cout << " | " << setw(30) << "Movie";
	std::cout << " | " << setw(15) << "Cinema";
	std::cout << " | " << setw(10) << "Date";
	std::cout << " | " << setw(5) << "Time";
	std::cout << " | " << setw(3) << "Hall";
	std::cout << " | " << setw(6) << "S,руб";
	std::cout << " | " << setw(6) << "C,руб";
	std::cout << " | " << setw(6) << "V,руб";
}

void printOrdersTableHeader()
{
	std::cout << "|| " << setiosflags(ios::left) << setw(4) << "ID";
	std::cout << " | " << setw(12) << "Status";
	std::cout << " | " << setw(12) << "Tickets, pcs";
}

void printAfishaHeader()
{
	std::cout << "|| " << setiosflags(ios::left) << setw(4) << "ID";
	std::cout << " | " << setw(30) << "Movie";
	std::cout << " | " << setw(15) << "Cinema";
	std::cout << " | " << setw(10) << "Date";
	std::cout << " | " << setw(5) << "Time";
	std::cout << " | " << setw(3) << "Hall";
}

string enterDate()
{
	string str;
	string year;
	string month;
	string day;
	int choice;
	cout << "Enter date (year): ";
	while (true)
	{
		choice = enterDigit();
		if (choice <= 2022) break;
		cout << "Wrong input! ";
	}
	year = to_string(choice);
	cout << "Enter date (month): ";
	while (true)
	{
		choice = enterDigit();
		if (choice < 1 || choice > 12)
		{
			cout << "Wrong input! ";
			continue;
		}
		break;
	}
	if (choice < 10) month = "0" + to_string(choice);
	else month = to_string(choice);
	cout << "Enter date (day): ";
	int buf = choice;
	while (true)
	{
		choice = enterDigit();
		if (choice > 31 || choice < 1 || ((buf == 4 || buf == 6 || buf == 9 || buf == 11) && choice == 31) || (buf == 2 && choice > 29))
		{
			cout << "Wrong input! ";
			continue;
		}
		break;
	}
	if (choice < 10) day = "0" + to_string(choice);
	else day = to_string(choice);
	str = day + "." + month + "." + year;
	return str;
}

string enterTime()
{
	string str;
	string hours;
	string minutes;
	int choice;
	cout << "Enter time (hours): ";
	while (true)
	{
		choice = enterDigit();
		if (choice > 23)
		{
			cout << "Wrong input! ";
			continue;
		}
		break;
	}
	if (choice < 10) hours = "0" + to_string(choice);
	else hours = to_string(choice);
	str = to_string(choice);
	cout << "Enter time (minutes): ";
	while (true)
	{
		choice = enterDigit();
		if (choice > 59)
		{
			cout << "Wrong input! ";
			continue;
		}
		break;
	}
	if (choice < 10) minutes = "0" + to_string(choice);
	else minutes = to_string(choice);
	str = hours + ":" + minutes;
	return str;
}

string toLower(string str)
{
	transform(str.begin(), str.end(), str.begin(), tolower);
	return str;
}

string myToLower(string str)
{
	str = toLower(str);
	/*for (int i = 0; i < str.size(); i++)
		switch (str[i])
		{
		case 'А': str[i] = 'а'; break;
		case 'Б': str[i] = 'б'; break;
		case 'В': str[i] = 'в'; break;
		case 'Г': str[i] = 'г'; break;
		case 'Д': str[i] = 'д'; break;
		case 'Е': str[i] = 'е'; break;
		case 'Ж': str[i] = 'ж'; break;
		case 'З': str[i] = 'з'; break;
		case 'И': str[i] = 'и'; break;
		case 'Й': str[i] = 'й'; break;
		case 'К': str[i] = 'к'; break;
		case 'Л': str[i] = 'л'; break;
		case 'М': str[i] = 'м'; break;
		case 'Н': str[i] = 'н'; break;
		case 'О': str[i] = 'о'; break;
		case 'П': str[i] = 'п'; break;
		case 'Р': str[i] = 'р'; break;
		case 'С': str[i] = 'с'; break;
		case 'Т': str[i] = 'т'; break;
		case 'У': str[i] = 'у'; break;
		case 'Ф': str[i] = 'ф'; break;
		case 'Х': str[i] = 'х'; break;
		case 'Ц': str[i] = 'ц'; break;
		case 'Ч': str[i] = 'ч'; break;
		case 'Ш': str[i] = 'ш'; break;
		case 'Щ': str[i] = 'щ'; break;
		case 'Ъ': str[i] = 'ъ'; break;
		case 'Ы': str[i] = 'ы'; break;
		case 'Ь': str[i] = 'ь'; break;
		case 'Э': str[i] = 'э'; break;
		case 'Ю': str[i] = 'ю'; break;
		case 'Я': str[i] = 'я'; break;
		default: continue;
	}*/
	return str;
}

