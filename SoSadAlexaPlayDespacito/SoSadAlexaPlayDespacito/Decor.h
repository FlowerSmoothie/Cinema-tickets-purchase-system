#pragma once

#include <string>
#include <vector>
#include <fstream>

using namespace std;


void separator();
void littleSeparator();
void printHeader(string str, int color);
void deleteSymbol();
void switchWrongInput();
void changeColor(int color);
int symbolCheck(char c);
bool isDigit(char c);
bool isEngLetter(char c);
int enterNumber();
string enterNumberInString();
double roundingToSecond(double a);
double enterDouble();
int numberInputCheck(int index, int size);
void deleteAllFromFile();
int checkExit();
int enterAnyDigit();
int enterDigit();
string enterLineWithCertainSize(int size);

int countLinesInFile(string name);
void sortFileById(string name);

vector<string> divideString(string line, string separator);
vector<int> stringVectorToInt(vector<string> vec);
string intVectorToString(vector<int> vec);
istream& operator >> (istream& is, vector<int> ints);
ostream& operator << (ostream& os, vector<int> ints);

int countStringCountInString(string strBig, string strSmall);

void printUsersTableHeader();
void printCinemaTableHeader();
void printMovieTableHeader();
void printHallTableHeader();
void printSeanceTableHeader();
void printTicketTableHeader();
void printOrdersTableHeader();

void printAfishaHeader();

string myToLower(string str);

size_t capacity(int a);

template<typename T>
int countObjectsInFile(string name, T type)
{
	ifstream file;
	file.open(name);
	if (!file.good())
	{
		cout << "Error! Unable to open the file!";
		return -1;
	}
	int count = 0;
	while (file.peek() != EOF)
	{
		try
		{
			file >> type;
		}
		catch (...)
		{
			return count;
		}
		count++;
	}
	file.close();
	return count;
}

string enterDate();

string enterTime();

string toLower(string str);


