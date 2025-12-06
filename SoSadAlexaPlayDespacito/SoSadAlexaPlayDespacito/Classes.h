#pragma once

#include <conio.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <memory>
#include <fstream>

#include "Constants.h"
#include "Decor.h"

using namespace std;

template<typename T>
T readObjectFromFile(int id, string filename, T type)
{
	T obj;
	string str;
	ifstream file;
	file.open(filename);
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file.\n";
		std::system("pause");
		return obj;
	}
	for (int i = 0; i <= id; i++) file >> obj;
	file.close();
	return obj;
}

template<typename T>
vector<T> readObjectsFromFile(string filename, T type);

template<typename T>
void rewriteObjectToFile(string filename, T obj, int id);

template<typename T>
vector<T> getVectorOfObjects(vector<int> ints, string filename, T type)
{
	ifstream file;
	string str;
	T obj;
	vector<T> vec = {};
	file.open(filename);
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file.\n";
		std::system("pause");
		return vec;
	}
	while (!file.eof())
	{
		try
		{
			file >> obj;
		}
		catch (...)
		{
			break;
		}
		vec.push_back(obj);
	}
	vector<T> toReturn = {};
	for (int i = 0; i < ints.size(); i++)
		toReturn.push_back(vec[ints[i]]);
	file.close();
	return toReturn;
}



template<typename T>
void writeVectorOfObjectsToFile(string filename, vector<T> vec)
{
	ofstream file;
	file.open(filename, ios::trunc);
	if (file.bad())
	{
		std::cout << "Error! Impossible to open the file.\n";
		system("pause");
		return;
	}
	for (int i = 0; i < vec.size(); i++) file << vec[i];
	file.close();
	return;
}

template<typename T>
void rewriteObjectToFile(string filename, T obj, int id)
{
	vector<T> vec = readObjectsFromFile(filename, obj);
	vec[id] = obj;
	writeVectorOfObjectsToFile(filename, vec);
}

string enterDurabilityForMovie();


template <typename T>
class DatabaseElement
{
protected:
	T id;
	int usingCount;
	int needsToBeShown;
public:
	void setId(T id)
	{
		this->id = id;
	}
	T getId()
	{
		return this->id;
	}
	virtual void addToUsingCount(int use)
	{
		this->usingCount += use;
	}
	virtual void setUsingCount(int use)
	{
		this->usingCount = use;
	}
	virtual int getUsingCount()
	{
		return this->usingCount;
	}
	void setNeedsToBeShown(int needs)
	{
		this->needsToBeShown = needs;
	}
	int getNeedsToBeShown()
	{
		return this->needsToBeShown;
	}
	virtual void showData() = 0;
};

class Movie : public DatabaseElement<int>
{
protected:
	string name;
	string durability;
	string audience;
	string description;
public:
	static int addedCount;
	friend istream& operator >> (istream& is, Movie*& m);
	friend istream& operator >> (istream& is, Movie& m);
	friend ostream& operator << (ostream& os, Movie*& m);
	friend ostream& operator << (ostream& os, Movie& m);
	Movie()
	{
		id = -1;
		usingCount = 0;
		needsToBeShown = 1;
		name = "NULL";
		durability = "00.00";
		audience = "NULL";
		description = "NULL";
	}
	Movie(int id, int needs, int s, string name, string durability, string audience, string description)
	{
		this->id = id;
		this->needsToBeShown = needs;
		this->usingCount = s;
		this->name = name;
		this->durability = durability;
		this->audience = audience;
		this->description = description;
	}
	Movie(const Movie& movie)
	{
		this->id = movie.id;
		this->needsToBeShown = movie.needsToBeShown;
		this->usingCount = movie.usingCount;
		this->name = movie.name;
		this->durability = movie.durability;
		this->audience = movie.audience;
		this->description = movie.description;
	}
	void setName(string name)
	{
		this->name = name;
	}
	string getName()
	{
		return this->name;
	}
	void setDurability(string durability)
	{
		this->durability = durability;
	}
	string getDurability()
	{
		return this->durability;
	}
	void setAudience(string audience)
	{
		this->audience = audience;
	}
	string getAudience()
	{
		return this->audience;
	}
	void setDescription(string desc)
	{
		this->description = desc;
	}
	string getDescription()
	{
		return this->description;
	}
	void showData()
	{
		cout << "Movie name: " << this->name;
		cout << "\nMovie length, hh:mm: " << this->durability;
		cout << "\nMovie description: " << this->description;
		cout << "\nMovie audience: " << this->audience;
	}
	int idOfLastObject(Movie movie)
	{
		ifstream file;
		file.open(MOVIES_DATA_FILE);
		if (file.bad())
		{
			std::cout << "Error! Unable to open the file.\n";
			std::system("pause");
			return -1;
		}
		while (file.peek() != EOF) file >> movie;
		file.close();
		return movie.getId() + 1;
	}
	void createNewObject();
};

vector<Movie> readObjectsFromFile(string filename, Movie m);
void showMoviesVector(vector<Movie> movies);


class Hall : public DatabaseElement<int>
{
protected:
	class Place
	{
	protected:
		int classOfPlace;
		string coordinates;
		int idnumber;
	public:
		Place()
		{
			classOfPlace = 1;
			coordinates = "0.0";
			idnumber = 0;
		}
		Place(int classOfPlace, string coordinates, int idnumber)
		{
			this->classOfPlace = classOfPlace;
			this->coordinates = coordinates;
			this->idnumber = idnumber;
		}
		Place(Place const& place)
		{
			this->classOfPlace = place.classOfPlace;
			this->coordinates = place.coordinates;
			this->idnumber = place.idnumber;
		}
		void setClassOfPlace(int classOfPlace)
		{
			this->classOfPlace = classOfPlace;
		}
		int getClassOfPlace()
		{
			return this->classOfPlace;
		}
		string getClassOfPlaceString()
		{
			switch (this->classOfPlace)
			{
			case 0:
				return "Standart";
			case 1:
				return "Comfort";
			case 2:
				return "VIP";
			default:
				return "NULL";
			}
		}
		void setCoordinates(string coordinates)
		{
			this->coordinates = coordinates;
		}
		string getCoordinates()
		{
			return this->coordinates;
		}
		void setIdnumber(int id)
		{
			this->idnumber = id;
		}
		int getIdnumber()
		{
			return this->idnumber;
		}
		char getPlaceStatusChar()
		{
			switch (this->classOfPlace)
			{
			case 1:
				return 'S';
			case 2:
				return 'C';
			case 3:
				return 'V';
			default:
				return 'N';
			}
		}
	};
	int N;
	int M;
	int number;
	Place place;
	vector<Place> row;
	vector<vector<Place>> places;
public:
	friend istream& operator >> (istream& is, Hall& h);
	friend ostream& operator << (ostream& os, Hall*& h);
	friend ostream& operator << (ostream& os, Hall& h);
	Hall()
	{
		id = -1;
		usingCount = 0;
		needsToBeShown = 1;
		N = 0;
		M = 0;
		number = -1;
		places = {};
	}
	Hall(int id, int use, int s, int N, int M, int number, vector<vector<Place>> places)
	{
		this->id = id;
		this->usingCount = use;
		this->needsToBeShown = s;
		this->N = N;
		this->M = M;
		this->number = number;
		this->places = places;
	}
	Hall(Hall const& hall)
	{
		this->id = hall.id;
		this->usingCount = hall.usingCount;
		this->needsToBeShown = hall.needsToBeShown;
		this->N = hall.N;
		this->M = hall.M;
		this->number = hall.number;
		this->places = hall.places;
	}
	void setN(int N)
	{
		this->N = N;
	}
	int getN()
	{
		return this->N;
	}
	void setM(int M)
	{
		this->M = M;
	}
	int getM()
	{
		return this->M;
	}
	void setNumber(int number)
	{
		this->number = number;
	}
	int getNumber()
	{
		return this->number;
	}
	void setPlaces(vector<vector<Place>> places)
	{
		this->places = places;
	}
	string getCoordinatesOfPlace(int number)
	{
		number++;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (this->places[i][j].getIdnumber() == number)
					return places[i][j].getCoordinates();
	}
	vector<vector<Place>> getPlaces()
	{
		return this->places;
	}
	void showData()
	{
		cout << endl;
		int cap = capacity(N);
		cout << " ";
		changeColor(LIME);
		for (int i = 0; i < cap; i++) cout << " ";
		for (int i = 1; i <= M; i++) cout << i << " ";
		changeColor(WHITE);
		for (int i = 0; i < N; i++)
		{
			cout << "\n";
			changeColor(LIME);
			cout << i + 1 << " ";
			changeColor(WHITE);
			for (int j = 0; j < M; j++)	cout << places[i][j].getPlaceStatusChar() << " ";
			cout << "\n";
		}
		cout << "\nS - standart, C - comfort, V - VIP, N - unknown\n";
	}
	int idOfLastObject(Hall hall)
	{
		ifstream file;
		file.open(HALLS_DATA_FILE);
		if (file.bad())
		{
			std::cout << "Error! Unable to open the file.\n";
			std::system("pause");
			return -1;
		}
		while (file.peek() != EOF)
		{
			try
			{
				file >> hall;
			}
			catch (...)
			{
				break;
			}
		}
		file.close();
		return hall.getId() + 1;
	}
	void createNewObject(int number);
	void changeSeatClasses(int id)
	{
		system("cls");
		Place place;
		int choiceN, choiceM, choice;
		while (true)
		{
			system("cls");
			cout << "Rows in total: " << this->N;
			cout << ". Places in total: " << this->M;
			cout << endl;
			this->showData();
			separator;
			if (this->usingCount > 0)
			{
				system("pause");
				return;
			}
			while (true)
			{
				cout << "Enter the row you would like to edit. Enter 0 to exit: ";
				choiceN = enterDigit();
				if (choiceN == 0)
				{
					for (int i = 0; i < N; i++)
					{
						rewriteObjectToFile(HALLS_DATA_FILE, *this, this->id);
						return;
					}
				}
				if (choiceN <= N) break;
				cout << "Wrong input! ";
			}
			while (true)
			{
				cout << "Enter the seat in a row " << choiceN << ", which you would like to edit. Enter 0 to exit: ";
				choiceM = enterDigit();
				if (choiceM == 0)
				{
					for (int i = 0; i < N; i++)
					{
						rewriteObjectToFile(HALLS_DATA_FILE, *this, this->id);
						return;
					}
				}
				if (choiceM <= M) break;
				cout << "Wrong input! ";
			}
			cout << "Current seat status: " << places[choiceN - 1][choiceM - 1].getPlaceStatusChar();
			cout << "\nNew seat status: \n 1. S (standart)\n 2. C (comfort)\n 3. V (VIP)\n -- ";
			while (true)
			{
				choice = enterDigit();
				if (choice == 1 || choice == 2 || choice == 3) break;
				cout << "Wrong input! ";
			}
			places[choiceN - 1][choiceM - 1].setClassOfPlace(choice);
		}
		rewriteObjectToFile(HALLS_DATA_FILE, *this, this->id);
		return;
	}
};

void showHallsVector(vector<Hall> halls);


class Cinema : public DatabaseElement<int>
{
protected:
	string adress;
	string name;
	vector<int> halls;
public:
	static int addedCount;
	friend istream& operator >> (istream& is, Cinema& c);
	friend istream& operator >> (istream& is, Cinema*& c);
	friend ostream& operator << (ostream& os, Cinema*& c);
	friend ostream& operator << (ostream& os, Cinema& c);
	Cinema()
	{
		id = -1;
		usingCount = 0;
		needsToBeShown = 1;
		adress = "NULL";
		name = "NULL";
		halls = {};
	}
	Cinema(int id, int use, int s, string adress, string name, vector<int> halls)
	{
		this->id = id;
		this->usingCount = use;
		this->needsToBeShown = s;
		this->adress = adress;
		this->name = name;
		this->halls = halls;
	}
	Cinema(Cinema const& cinema)
	{
		this->id = cinema.id;
		this->usingCount = cinema.usingCount;
		this->needsToBeShown = cinema.needsToBeShown;
		this->adress = cinema.adress;
		this->name = cinema.name;
		this->halls = cinema.halls;
	}
	void setAdress(string adress)
	{
		this->adress = adress;
	}
	string getAdress()
	{
		return this->adress;
	}
	void changeAdress()
	{
		string str;
		cout << "Current adress: " << this->adress;
		cout << "\nNew adress (up to 30 symbols): ";
		str = enterLineWithCertainSize(30);
		if(str == "") str = enterLineWithCertainSize(30);
		this->adress = str;
		rewriteObjectToFile(CINEMA_DATA_FILE, *this, this->id);
	}
	void setName(string name)
	{
		this->name = name;
	}
	string getName()
	{
		return this->name;
	}
	void changeName()
	{
		string str;
		cout << "Current name: " << this->getName();
		cout << "\nNew name (up to 15 symbols): ";
		str = enterLineWithCertainSize(15);
		if (str == "") str = enterLineWithCertainSize(15);
		this->name = str;
		rewriteObjectToFile(CINEMA_DATA_FILE, *this, this->id);
	}
	void setHalls(vector<int> halls)
	{
		this->halls = halls;
	}
	void setHallsStr(string line)
	{
		vector<string> vec;
		vector<int> places;
		vec = divideString(line, "▲");
		this->halls = stringVectorToInt(vec);
	}
	vector<int> getHalls()
	{
		return this->halls;
	}
	vector<Hall> getHallsVector()
	{
		Hall h;
		return getVectorOfObjects(this->halls, HALLS_DATA_FILE, h);
	}
	void deleteOneHall()
	{
		vector<int> halls = {};
		if (this->halls.size() == 0)
		{
			cout << "There is nothing to delete, it is empty :(\n";
			return;
		}
		if (this->halls.size() == 1)
		{
			this->setHalls(halls);
			return;
		}
		int id;
		while (true)
		{
			cout << "Enter the number of a hall you would like to delete: ";
			id = enterAnyDigit();
			if (id > this->halls.size())
			{
				cout << "Wrong input!\n";
				system("pause");
				continue;
			}
			else break;
		}
		id--;
		if (this->getHallsVector()[id].getUsingCount() > 0)
		{
			cout << "Cannot delete the hall! It is used.\n";
			system("pause");
			return;
		}
		halls = this->getHalls();
		halls.erase(halls.begin() + id);
		this->setHalls(halls);
		rewriteObjectToFile(CINEMA_DATA_FILE, *this, this->id);
	}

	void showData()
	{
		cout << "Cinema name: " << this->name;
		cout << "\nCinema adress: " << this->adress;
		cout << "\nCinema halls: " << this->halls.size();
	}
	int idOfLastObject(Cinema cinema)
	{
		ifstream file;
		file.open(CINEMA_DATA_FILE);
		if (file.bad())
		{
			std::cout << "Error! Unable to open the file.\n";
			std::system("pause");
			return -1;
		}
		while (file.peek() != EOF)
		{
			try
			{
				file >> cinema;
			}
			catch (...)
			{
				break;
			}
		}
		file.close();
		return cinema.getId() + 1;
	}
	void createNewObject();
};

vector<Cinema> readObjectsFromFile(string filename, Cinema c);
void printCinemasFromVector(vector<Cinema> cinemas);


class Seance : public DatabaseElement<int>
{
protected:
	string date;
	string time;
	string movieTitle;
	string cinemaName;
	int cinema;
	int hall;
	int movie;
	int doHaveTickets;
public:
	static int addedCount;
	friend istream& operator >> (istream& is, Seance& s);
	friend istream& operator >> (istream& is, Seance*& s);
	friend ostream& operator << (ostream& os, Seance*& s);
	friend ostream& operator << (ostream& os, Seance& s);
	Seance()
	{
		id = 0;
		usingCount = 0;
		needsToBeShown = 1;
		date = "0.0";
		time = "00:00";
		doHaveTickets = 0;
		cinema;
		hall;
		movie;
	}
	Seance(int id, int use, int s, string date, string time, int cinema, int hall, int movie, int doH)
	{
		this->id = id;
		this->usingCount = use;
		this->needsToBeShown = s;
		this->date = date;
		this->time = time;
		this->cinema = cinema;
		this->hall = hall;
		this->movie = movie;
		this->doHaveTickets = doH;
	}
	Seance(Seance const& seance)
	{
		this->id = seance.id;
		this->usingCount = seance.usingCount;
		this->needsToBeShown = seance.needsToBeShown;
		this->date = seance.date;
		this->time = seance.time;
		this->cinema = seance.cinema;
		this->hall = seance.hall;
		this->movie = seance.movie;
		this->cinemaName = seance.cinemaName;
		this->movieTitle = seance.movieTitle;
		this->doHaveTickets = seance.doHaveTickets;
	}
	unique_ptr<Hall> getHallPointer()
	{
		Hall hall = readObjectFromFile(this->hall, HALLS_DATA_FILE, hall);
		unique_ptr<Hall> h(new Hall(hall));
		return h;
	}
	void setMovieTitle(string title)
	{
		this->movieTitle = title;
	}
	string getMovieTitle()
	{
		return this->movieTitle;
	}
	void setCinemaName(string name)
	{
		this->cinemaName = name;
	}
	string getCinemaName()
	{
		return this->cinemaName;
	}
	void setDate(string date)
	{
		this->date = date;
	}
	string getDate()
	{
		return this->date;
	}
	void setTime(string time)
	{
		this->time = time;
	}
	string getTime()
	{
		return this->time;
	}
	void setCinema(int cinema)
	{
		this->cinema = cinema;
	}
	Cinema getCinema()
	{
		Cinema cinema;
		return readObjectFromFile(this->cinema, CINEMA_DATA_FILE, cinema);
	}
	int getCinemaInt()
	{
		return this->cinema;
	}
	void setHall(int hall)
	{
		this->hall = hall;
	}
	Hall getHall();
	int getHallInt()
	{
		return this->hall;
	}
	void setMovie(int movie)
	{
		this->movie = movie;
	}
	Movie getMovie()
	{
		Movie movie;
		return readObjectFromFile(this->movie, MOVIES_DATA_FILE, movie);
	}
	int getMovieInt()
	{
		return this->movie;
	}
	void setHaveTickets(int doH)
	{
		this->doHaveTickets = doH;
	}
	int getHaveTickets()
	{
		return this->doHaveTickets;
	}
	int idOfLastObject(Seance seance)
	{
		ifstream file;
		file.open(SEANCES_DATA_FILE);
		if (file.bad())
		{
			std::cout << "Error! Unable to open the file.\n";
			std::system("pause");
			return -1;
		}
		int kol = 0;
		while (file.peek() != EOF)
		{
			try
			{
				file >> seance;
				kol++;
			}
			catch (...)
			{
				break;
			}
		}
		file.close();
		return kol;
	}
	void createNewObject(vector<Movie> movies, vector<Cinema> cinemas);
	void showData()
	{
		cout << "Movie name: " << this->getMovie().getName();
		cout << "\nFilm show date: " << this->date;
		cout << "\nFilm show time: " << this->time;
		cout << "\nCinema: " << this->getCinema().getName();
		cout << "\nHall: " << this->getHall().getNumber() << endl;
		cout << (this->needsToBeShown == -1 ? "Not presented on the billboard" : "Presented on the billboard") << endl;
	}
};

vector<Seance> readObjectsFromFile(string filename, Seance seance);
void showSeanceVector(vector<Seance> seances);

void writeVectorOfObjectsToFile(string filename, vector<Seance> seances);
vector<Seance> onlyShowable(vector<Seance> seances);



class Ticket : public DatabaseElement<int>
{
protected:
	int place;
	int hall;
	int seance;
	double price;
	int status;
public:
	static int bought;
	friend istream& operator >> (istream& is, Ticket& t);
	friend istream& operator >> (istream& is, Ticket*& t);
	friend ostream& operator << (ostream& os, Ticket*& t);
	friend ostream& operator << (ostream& os, Ticket& t);
	Ticket()
	{
		id = -1;
		usingCount = 0;
		needsToBeShown = 1;
		place = -1;
		seance = -1;
		hall = -1;
		price = 0;
		status = 0;
	}
	Ticket(int id, int use, int needs, int place, int hall, int seance, double price, int status)
	{
		this->id = id;
		this->usingCount = use;
		this->needsToBeShown = needs;
		this->place = place;
		this->hall = hall;
		this->seance = seance;
		this->price = price;
		this->status = status;
	}
	Ticket(Ticket const& ticket)
	{
		this->id = ticket.id;
		this->usingCount = ticket.usingCount;
		this->needsToBeShown = ticket.needsToBeShown;
		this->place = ticket.place;
		this->hall = ticket.hall;
		this->seance = ticket.seance;
		this->price = ticket.price;
		this->status = ticket.status;
	}
	pair<vector<double>, vector<Ticket>> createTicketsForSeance(vector<Seance> seances, vector<Cinema> cinemas);
	static int getBought()
	{
		return bought;
	}
	static void increaseBought(int count)
	{
		bought+=count;
	}
	static void setBought(int a)
	{
		bought = a;
	}
	void setPlace(int place)
	{
		this->place = place;
	}
	int getPlace()
	{
		return this->place;
	}
	void setHall(int hall)
	{
		this->hall = hall;
	}
	int getHallInt()
	{
		return this->hall;
	}
	void setSeance(int seance)
	{
		this->seance = seance;
	}
	int getSeanceInt()
	{
		return this->seance;
	}
	void setPrice(double price)
	{
		this->price = price;
	}
	double getPrice()
	{
		return this->price;
	}
	void setStatus(int status)
	{
		this->status = status;
	}
	int getStatus()
	{
		return this->status;
	}
	string getStatusString()
	{
		switch (this->status)
		{
		case 0:
			return "Available";
		case 1:
			return "Unavailable";
		}
	}
	Seance getSeance()
	{
		Seance seance;
		return readObjectFromFile(this->seance, SEANCES_DATA_FILE, seance);
	}
	Hall getHall()
	{
		Hall hall;
		return readObjectFromFile(this->hall, HALLS_DATA_FILE, hall);
	}
	void showData()
	{
		Seance seance = this->getSeance();
		Hall hall = this->getHall();
		cout << "\nCinema: " << seance.getCinema().getName();
		cout << "\nMovie: " << seance.getMovie().getName();
		cout << "\nDate: " << seance.getDate();
		cout << "\nTime: " << seance.getTime();
		string coordinates = hall.getCoordinatesOfPlace(place);
		cout << "\nHall: " << hall.getNumber() << "; row: ";
		if(coordinates.size() == 5)
			cout << coordinates[0] + coordinates[1] << ", place: " << coordinates[3] + coordinates[4] << endl;
		else if (coordinates.size() == 3)
			cout << coordinates[0] << ", place: " << coordinates[2] << endl;
	}
};

vector<Ticket> readObjectsFromFile(string filename, Ticket ticket);
vector<vector<Ticket>> readTicketsFromFile(Ticket ticket);

vector<pair<vector<double>, vector<Ticket>>> readObjectsFromFile(string filename, vector<pair<vector<double>, vector<Ticket>>> tickets);

ostream& operator << (ostream& os, pair<vector<double>, vector<Ticket>>& tickets);

void writeNewObjectToFile(pair<vector<double>, vector<Ticket>> p);


class Order : public DatabaseElement<int>
{
protected:
	int status;
	vector<Ticket> tickets;
public:

	friend istream& operator >> (istream& is, Order& o);
	friend istream& operator >> (istream& is, Order*& o);
	friend ostream& operator << (ostream& os, Order*& o);
	friend ostream& operator << (ostream& os, Order& o);
	Order()
	{
		id = -1;
		status = -1;
		tickets = {};
	}
	Order(int id, int status, vector<Ticket> tickets)
	{
		this->id = id;
		this->status = status;
		this->tickets = tickets;
	}
	Order(Order const& order)
	{
		this->id = order.id;
		this->status = order.status;
		this->tickets = order.tickets;
	}
	void setStatus(int status)
	{
		this->status = status;
	}
	int getStatus()
	{
		return this->status;
	}
	int setIdOfLastObjectPlusOne(Order order)
	{
		ifstream file;
		vector<Order> orders;
		file.open(ORDERS_DATA_FILE);
		if (file.bad())
		{
			std::cout << "Error! Unable to open the file.\n";
			std::system("pause");
			return -1;
		}
		while (file.peek() != EOF)
		{
			try
			{
				file >> order;
				orders.push_back(order);
			}
			catch (...)
			{
				break;
			}
		}
		file.close();
		this->id = orders.size();
	}
	string getStatusString()
	{
		switch (this->status)
		{
		case 0:
			return "Not paid";
		case 1:
			return "Paid";
		case -1:
			return "Cancelled";
		default:
			return "NULL";
		}
	}
	void addTicket(Ticket ticket)
	{
		this->tickets.push_back(ticket);
	}
	void setTickets(vector<Ticket> tickets);
	vector<Ticket> getTickets()
	{
		return this->tickets;
	}
	int getTicketsCount();
	double getTotalPrice()
	{
		double sum = 0;
		int size = this->tickets.size();
		for (int i = 0; i < size; i++) sum += tickets[i].getPrice();
		return sum;
	}
	void showData()
	{
		cout << "Order ID: " << this->id << "\nOrder status: " << this->getStatusString() << endl;
		separator();
		int size = this->tickets.size();
		double sum = 0;
		for (int i = 0; i < size; i++)
		{
			tickets[i].showData();
			sum += tickets[i].getPrice();
			separator();
		}
		cout << "Total sum: " << sum << " eur.";
	}
};
vector<Order> readObjectsFromFile(string filename, Order o);
int writeNewObjectToFile(string filename, Order o);
void printOrdersFromVector(vector<Order> vec);
void createACheck(Order order, string nickname);

void UpdateReport(Movie movie, double price, int count);

class User : public DatabaseElement<int>
{
protected:
	string login;
	string password;
	int role;
	int access;
	string FIO;
	vector<int> orders;
	string bankCardData;
	double balance;
public:
	static int loggedIn;
	static int registered;
	void setBalance(double balance)
	{
		this->balance = balance;
	}
	double getBalance()
	{
		return this->balance;
	}
	void addToBalance(double sum)
	{
		this->balance += sum;
	}
	inline void setLogin(string login)
	{
		this->login = login;
	}
	string getLogin();
	void setPasswordWithHash(string password);
	void setPassword(string password)
	{
		this->password = password;
	}
	string getPassword()
	{
		return this->password;
	}
	void setRole(int role)
	{
		this->role = role;
	}
	int getRole()
	{
		return this->role;
	}
	string getRoleString()
	{
		switch (this->role)
		{
		case 0:
			return "User";
		case 1:
			return "Cashier";
		case 2:
			return "Administrator";
		case 3:
			return "Show manager";
			break;
		case 4:
			return "Content manager";
			break;
		default:
			return "NULL";
		}
	}
	void setAccess(int access)
	{
		this->access = access;
	}
	int getAccess()
	{
		return this->access;
	}
	static void setLoggedIn(int a)
	{
		loggedIn = a;
	}
	static void increaseLoggedIn()
	{
		loggedIn++;
	}
	static int getLoggedIn()
	{
		return loggedIn;
	}
	static void setSignedIn(int a)
	{
		registered = a;
	}
	static void increaseSignedIn()
	{
		registered++;
	}
	static int getSignedIn()
	{
		return registered;
	}
	friend ostream& operator << (std::ostream& os, const User*& c);
	friend istream& operator >> (istream& is, User& c);
	friend istream& operator >> (istream& is, User*& c);
	friend ostream& operator << (ostream& os, User& c);
	friend ostream& operator << (ostream& os, User*& c);
	friend bool operator == (User& first, User& second);
	User()
	{
		this->id = -1;
		this->usingCount = 0;
		this->needsToBeShown = 1;
		this->login = "NULL";
		this->password = "NULL";
		this->role = -1;
		this->access = -1;
		this->FIO = "NULL";
		this->orders = {};
		this->bankCardData = "NULL";
		this->balance = 0;
	}
	User(int id, int use, int s, string login, string password, int role, int access, string FIO, vector<int> orders, string bankCardData, double balance)
	{
		this->id = id;
		this->usingCount = use;
		this->needsToBeShown = s;
		this->login = login;
		this->password = password;
		this->role = role;
		this->access = access;
		this->FIO = FIO;
		this->orders = orders;
		this->bankCardData = bankCardData;
		this->balance = balance;
	}
	User(User const& user)
	{
		this->id = user.id;
		this->usingCount = user.usingCount;
		this->needsToBeShown = user.needsToBeShown;
		this->login = user.login;
		this->password = user.password;
		this->role = user.role;
		this->access = user.access;
		this->FIO = user.FIO;
		this->orders = user.orders;
		this->bankCardData = user.bankCardData;
		this->balance = user.balance;
	}
	void showDataProtected();
	void setFIO(string FIO)
	{
		this->FIO = FIO;
	}
	string getFIO()
	{
		return this->FIO;
	}
	void setOrders(vector<int> orders);
	void setOrders(string line)
	{
		vector<string> vec;
		vector<int> orders;
		vec = divideString(line, "▼");
		this->orders = stringVectorToInt(vec);
	}
	vector<int> getOrders();
	vector<Order> getOrdersVector()
	{
		Order o;
		return getVectorOfObjects(this->orders, ORDERS_DATA_FILE, o);
	}
	void addOrder(int id)
	{
		this->orders.push_back(id);
	}
	void setBankCardData(string card)
	{
		this->bankCardData = card;
	}
	string getBankCardData()
	{
		return this->bankCardData;
	}
	int registerUser();
	void showData();
	void viewOrders()
	{
		system("cls");
		vector<Order> orders = this->getOrdersVector();
		if (orders.size() == 0)
		{
			cout << "\nEmpty here :(\n";
			system("pause");
			return;
		}
		printOrdersTableHeader();
		printOrdersFromVector(orders);
		separator();
		int choice;
		cout << "Enter the number of an order you would like to see information about. Enter 0 to exit: ";
		while (true)
		{
			choice = enterDigit();
			if (choice == 0) return;
			if (choice <= orders.size()) break;
			cout << "Wrong input! ";
		}
		system("cls");
		choice--;
		orders[choice].showData();
		cout << endl;
		system("pause");
		int pos = 1;
		int key = 0;
		double price;
		vector<Ticket> tickets = orders[choice].getTickets();
		if (orders[choice].getStatus() == 0)
		{
			while (true)
			{
				key = 0;
				system("cls");
				price = orders[choice].getTotalPrice();
				cout << "Order price: " << price << endl;
				cout << "What do you want to do with an order?\n";
				switch (pos)
				{
				case 1:
					changeColor(YELLOW);
					cout << ">   Pay for an order\n";
					changeColor(WHITE);
					cout << "    Nothing for now\n";
					break;
				case 2:
					cout << "    Pay for an order\n";
					changeColor(YELLOW);
					cout << ">   Nothing for now\n";
					changeColor(WHITE);
					break;
				}
				key = _getch();
				switch (key)
				{
				case UP_ENG:
				case UP_RUS:
					if (pos != 1) pos--;
					else pos = 3;
					continue;
				case DOWN_ENG:
				case DOWN_RUS:
					if (pos != 3) pos++;
					else pos = 1;
					continue;
				case ENTER:
					system("cls");
					switch (pos)
					{
					case 1:
						if (this->balance - price < 0)	cout << "Insufficient funds! :(\n";
						else
						{
							this->balance -= price;
							orders[choice].setStatus(1);
							rewriteObjectToFile(ORDERS_DATA_FILE, orders[choice], orders[choice].getId());
							createACheck(orders[choice], this->getLogin());
							Ticket::increaseBought(orders[choice].getTickets().size());
							rewriteObjectToFile(USER_DATA_FILE, *this, this->id);
							UpdateReport(orders[choice].getTickets()[0].getSeance().getMovie(), price, orders[choice].getTickets().size());
							cout << "Bought successfully! :)\n";
						}
						system("pause");
						return;
						break;
					case 2:
						return;
						break;
					}
					break;
				default:
					continue;
				}
			}
		}
		return;
	}
};




int idOfLastObject(Movie movie);
int idOfLastObject(Hall hall);

template<typename T>
vector<T> readObjectsFromFile(string filename, T type)
{
	ifstream file;
	T ty;
	User s;
	Cinema c;
	Seance se;
	Movie m;
	Ticket t;
	Order o;
	Hall h;
	file.open(filename);
	vector<T> vec = {};
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file.\n";
		std::system("pause");
		return vec;
	}
	while (!file.eof())
	{
		try
		{
			//file >> type;
			if (std::is_same<T, User*>::value) file >> s;
			else
			{
				if (std::is_same<T, Cinema*>::value) file >> c;
				else
				{
					if (std::is_same<T, Seance*>::value) file >> se;
					else
					{
						if (std::is_same<T, Movie*>::value) file >> m;
						else
						{
							if (std::is_same<T, Ticket*>::value) file >> t;
							else
							{
								if (std::is_same<T, Order*>::value) file >> o;
								else if (std::is_same<T, Hall*>::value) file >> h;
							}
						}
					}
				}
			}
		}
		catch (...)
		{
			break;
		}
		vec.push_back(type);
	}
	file.close();
	return vec;
}
vector<User> readObjectsFromFile(string filename, User user);
vector<Hall> readObjectsFromFile(string filename, Hall hall);


class ReportOld
{
protected:
	int loggedCount;
	int regCount;
	int boughtCount;
	int moviesCount;
	int cinemasCount;
	int seancesCount;
public:
	friend istream& operator >> (istream& is, ReportOld& r);
	friend ostream& operator << (ostream& is, ReportOld& r);
	ReportOld()
	{
		loggedCount = 0;
		regCount = 0;
		boughtCount = 0;
		moviesCount = 0;
		cinemasCount = 0;
		seancesCount = 0;
	}
	void setLoggedCount(int count)
	{
		this->loggedCount = count;
	}
	int getLoggedCount()
	{
		return this->loggedCount;
	}
	void setRegCount(int count)
	{
		this->regCount = count;
	}
	int getRegCount()
	{
		return this->regCount;
	}
	void setBoughtCount(int count)
	{
		this->boughtCount = count;
	}
	int getBoughtCount()
	{
		return this->boughtCount;
	}
	void setMoviesCount(int count)
	{
		this->moviesCount = count;
	}
	int getMoviesCount()
	{
		return this->moviesCount;
	}
	void setCinemasCount(int count)
	{
		this->cinemasCount = count;
	}
	int getCinemasCount()
	{
		return this->cinemasCount;
	}
	void setSeancesCount(int count)
	{
		this->seancesCount = count;
	}
	int getSeancesCount()
	{
		return this->seancesCount;
	}
};

class Report
{
protected:
	int movie;
	int biletsKol;
	double gainedMoney;
public:
	friend istream& operator >> (istream& is, Report& r);
	friend ostream& operator << (ostream& is, Report& r);
	void setMovie(int movie)
	{
		this->movie = movie;
	}
	string getMovieName()
	{
		Movie movie;
		movie = readObjectFromFile(this->movie, MOVIES_DATA_FILE, movie);
		return movie.getName();
	}
	void setBilets(int bilets)
	{
		this->biletsKol = bilets;
	}
	int getBilets()
	{
		return this->biletsKol;
	}
	void setMoney(double money)
	{
		this->gainedMoney = money;
	}
	double getMoney()
	{
		return this->gainedMoney;
	}
};

void writeReportInFile();

vector<ReportOld> readObjectsFromFile(string filename, ReportOld r);



