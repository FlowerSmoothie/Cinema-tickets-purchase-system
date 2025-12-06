#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "Classes.h"
#include "ObjectOperations.h"

using namespace std;

void writeVectorOfObjectsToFile(string filename, vector<Movie> movies)
{
	ofstream file;
	file.open(filename, ios::trunc);
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file!\n";
		system("pause");
		return;
	}
	for (int i = 0; i < movies.size(); i++) file << movies[i];
	file.close();
	return;
}

/*void writeVectorOfObjectsToFile(string filename, vector<Place> places)
{
	ofstream file;
	file.open(filename, ios::trunc);
	if (file.bad())
	{
		cout << "Ошибка! Невозможно открыть файл!\n";
		system("pause");
		return;
	}
	for (int i = 0; i < places.size(); i++) file << places[i];
	file.close();
	return;
}*/

/*void writeVectorOfObjectsToFile(string filename, vector<vector<Place>> places)
{
	ofstream file;
	file.open(filename);
	if (file.bad())
	{
		cout << "Ошибка! Невозможно открыть файл!\n";
		system("pause");
		return;
	}
	for (int i = 0; i < places.size(); i++)
		for (int j = 0; j < places[i].size(); j++)
			file << places[i][j];
	file.close();
	return;
}*/



void writeVectorOfObjectsToFile(string filename, vector<Hall> halls)
{
	ofstream file;
	file.open(filename, ios::trunc);
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file!\n";
		system("pause");
		return;
	}
	for (int i = 0; i < halls.size(); i++) file << halls[i];
	file.close();
	return;
}

void writeVectorOfObjectsToFile(string filename, vector<Cinema> cinemas)
{
	ofstream file;
	file.open(filename, ios::trunc);
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file!\n";
		system("pause");
		return;
	}
	for (int i = 0; i < cinemas.size(); i++) file << cinemas[i];
	file.close();
	return;
}

void writeVectorOfObjectsToFile(string filename, vector<Seance> seances)
{
	ofstream file;
	file.open(filename, ios::trunc);
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file!\n";
		system("pause");
		return;
	}
	for (int i = 0; i < seances.size(); i++) file << seances[i];
	file.close();
	return;
}

void writeVectorOfObjectsToFile(string filename, vector<Ticket> tickets)
{
	ofstream file;
	file.open(filename, ios::trunc);
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file!\n";
		system("pause");
		return;
	}
	for (int i = 0; i < tickets.size(); i++) file << tickets[i];
	file.close();
	return;
}

void writeVectorOfObjectsToFile(string filename, vector<Order> orders)
{
	ofstream file;
	file.open(filename, ios::trunc);
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file!\n";
		system("pause");
		return;
	}
	for (int i = 0; i < orders.size(); i++) file << orders[i];
	file.close();
	return;
}

void writeVectorOfObjectsToFile(string filename, vector<User> users)
{
	ofstream file;
	file.open(filename, ios::trunc);
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file!\n";
		system("pause");
		return;
	}
	for (int i = 0; i < users.size(); i++) file << users[i];
	file.close();
	return;
}


void writeVectorOfObjectsToFile(string filename, vector<vector<Ticket>> tickets)
{
	ofstream file;
	file.open(filename, ios::trunc);
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file!\n";
		system("pause");
		return;
	}
	for (int i = 0; i < tickets.size(); i++)
	{
		file << tickets[i].size() << endl;
		for (int j = 0; j < tickets[i].size(); j++) file << tickets[i][j];
	}
	file.close();
	return;
}

void writeVectorOfObjectsToFile(string filename, vector<pair<vector<double>, vector<Ticket>>> vec)
{
	ofstream file;
	file.open(filename, ios::trunc);
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file!\n";
		system("pause");
		return;
	}
	for (int i = 0; i < vec.size(); i++)
		file << vec[i];
	file.close();
	return;
}



Seance stringToSeance(string line)
{
	Seance seance;
	vector<string> lines = divideString(line, "★");
	seance.setId(stoi(lines[0]));
	seance.setDate(lines[1]);
	seance.setTime(lines[2]);
	seance.setCinema(stoi(lines[3]));
	seance.setHall(stoi(lines[4]));
	seance.setHall(stoi(lines[5]));
	return seance;
}



string SeanceToString(Seance seance)
{
	string str = "";
	str += seance.getId();
	str += "★";
	str += seance.getDate();
	str += "★";
	str += seance.getTime();
	str += "★";
	str += seance.getCinemaInt();
	str += "★";
	str += seance.getHallInt();
	str += "★";
	str += seance.getMovieInt();
	str += "★0";
	return str;
}




void showHallsVector(vector<Hall> halls)
{
	for (int i = 0; i < halls.size(); i++)
	{
		std::cout << "\n|| " << setiosflags(ios::left) << setw(4) << i + 1;
		std::cout << " | " << setw(5) << halls[i].getNumber();
		std::cout << " | " << setw(4) << halls[i].getN();
		std::cout << " | " << setw(7) << halls[i].getM();
		std::cout << " | " << setw(8) << halls[i].getN() * halls[i].getM();
	}
}



int idOfLastObject(Cinema cinema)
{
	ifstream file;
	file.open(CINEMA_DATA_FILE);
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file!\n";
		std::system("pause");
		return -1;
	}
	while (file.peek() != EOF) file >> cinema;
	file.close();
	return cinema.getId() + 1;
}

int idOfLastObject(Movie movie)
{
	ifstream file;
	file.open(MOVIES_DATA_FILE);
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file!\n";
		std::system("pause");
		return -1;
	}
	while (file.peek() != EOF) file >> movie;
	file.close();
	return movie.getId() + 1;
}

int idOfLastObject(Hall hall)
{
	ifstream file;
	file.open(HALLS_DATA_FILE);
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file!\n";
		std::system("pause");
		return -1;
	}
	while (file.peek() != EOF) file >> hall;
	file.close();
	return hall.getId() + 1;
}
