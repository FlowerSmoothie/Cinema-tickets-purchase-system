#pragma once

#include <string>

#include "Classes.h"

using namespace std;




/*emplate<typename T>
void writeVectorOfObjectsToFile(string filename, vector<T> vec)
{
	ofstream file;
	file.open(filename, ios::trunc);
	if (file.bad())
	{
		cout << "Ошибка! Невозможно открыть файл!\n";
		system("pause");
		return;
	}
	for (int i = 0; i < vec.size(); i++) file << vec[i];
	file.close();
	return;
}*/

void writeVectorOfObjectsToFile(string filename, vector<Movie> movies);
void writeVectorOfObjectsToFile(string filename, vector<Hall> halls);
void writeVectorOfObjectsToFile(string filename, vector<Cinema> cinemas);
void writeVectorOfObjectsToFile(string filename, vector<Seance> seances);
void writeVectorOfObjectsToFile(string filename, vector<Order> orders);
void writeVectorOfObjectsToFile(string filename, vector<User> users);
void writeVectorOfObjectsToFile(string filename, vector<Ticket> tickets);
void writeVectorOfObjectsToFile(string filename, vector<pair<vector<double>, vector<Ticket>>>);






vector<User> readObjectsFromFile(User s);

//vector<int> createVectorOfPlaces(int size, int N, int M);

string vectorOfPlacesIntsToString(vector<int> ints);



Seance stringToSeance(string line);


string SeanceToString(Seance seance);



