#include <iostream>
#include <string>
#include <vector>

#include "Classes.h"
#include "Decor.h"
#include "Exceptions.h"
#include "ObjectOperations.h"



using namespace std;

void writeNewObjectToFile(string filename, User u)
{
	ofstream file;
	file.open(filename, ios::app);
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file.\n";
		std::system("pause");
		return;
	}
	file << u;
	file.close();
	return;
}
void writeNewObjectToFile(string filename, Movie m)
{
	ofstream file;
	file.open(filename, ios::app);
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file.\n";
		std::system("pause");
		return;
	}
	file << m;
	file.close();
	return;
}
void writeNewObjectToFile(string filename, Hall h)
{
	ofstream file;
	file.open(filename, ios::app);
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file.\n";
		std::system("pause");
		return;
	}
	file << h;
	file.close();
	return;
}
void writeNewObjectToFile(string filename, Cinema c)
{
	ofstream file;
	file.open(filename, ios::app);
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file.\n";
		std::system("pause");
		return;
	}
	file << c;
	file.close();
	return;
}
void writeNewObjectToFile(string filename, Seance s)
{
	ofstream file;
	file.open(filename, ios::app);
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file.\n";
		std::system("pause");
		return;
	}
	file << s;
	file.close();
	return;
}
int writeNewObjectToFile(string filename, Order o)
{
	ofstream file;
	o.setIdOfLastObjectPlusOne(o);
	file.open(filename, ios::app);
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file.\n";
		std::system("pause");
		return o.getId();
	}
	file << o;
	file.close();
	return o.getId();
}


istream& operator >> (istream& is, Movie*& m)
{
	string str;
	getline(is, str);
	if (str == "") throw EndOfFile();
	m->id = stoi(str);
	getline(is, str);
	m->usingCount = stoi(str);
	getline(is, str);
	m->needsToBeShown = stoi(str);
	getline(is, m->name);
	getline(is, m->durability);
	getline(is, m->audience);
	getline(is, m->description);
	return is;
}

istream& operator >> (istream& is, Movie& m)
{
	string str;
	getline(is, str);
	if (str == "") throw EndOfFile();
	m.id = stoi(str);
	getline(is, str);
	m.usingCount = stoi(str);
	getline(is, str);
	m.needsToBeShown = stoi(str);
	getline(is, m.name);
	getline(is, m.durability);
	getline(is, m.audience);
	getline(is, m.description);
	return is;
}

ostream& operator << (ostream& os, Movie*& m)
{
	os << m->id << endl;
	os << m->usingCount << endl;
	os << m->needsToBeShown << endl;
	os << m->name << endl;
	os << m->durability << endl;
	os << m->audience << endl;
	os << m->description << endl;
	return os;
}

ostream& operator << (ostream& os, Movie& m)
{
	os << m.id << endl;
	os << m.usingCount << endl;
	os << m.needsToBeShown << endl;
	os << m.name << endl;
	os << m.durability << endl;
	os << m.audience << endl;
	os << m.description << endl;
	return os;
}


vector<Movie> readObjectsFromFile(string filename, Movie m)
{
	ifstream file;
	file.open(MOVIES_DATA_FILE);
	vector<Movie> vec = {};
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
			file >> m;
		}
		catch (...)
		{
			break;
		}
		vec.push_back(m);
	}
	file.close();
	return vec;
}



string enterDurabilityForMovie()
{
	int choice;
	string str;
	cout << "Enter movie duration (hours): ";
	while (true)
	{
		choice = enterDigit();
		if (choice < 100) break;
		cout << "Wrong input! Too much ";
	}
	str = "";
	if (choice >= 0 && choice <= 9) str += "0";
	str += to_string(choice);
	str += ":";
	cout << "Enter movie duration (minutes): ";
	while (true)
	{
		choice = enterDigit();
		if (choice < 60) break;
		cout << "Wrong input! Too much ";
	}
	if (choice >= 0 && choice <= 9) str += "0";
	str += to_string(choice);
	return str;
}


//----------------------------------------------





istream& operator >> (istream& is, Hall& h)
{
	string str;
	getline(is, str);
	if (str == "") throw EndOfFile();
	h.id = stoi(str);
	getline(is, str);
	h.usingCount = stoi(str);
	getline(is, str);
	h.needsToBeShown = stoi(str);
	getline(is, str);
	h.N = stoi(str);
	getline(is, str);
	h.M = stoi(str);
	getline(is, str);
	h.number = stoi(str);
	h.row = {};
	h.places = {};
	for (int i = 0; i < h.N; i++)
	{
		h.row.clear();
		for (int j = 0; j < h.M; j++)
		{
			getline(is, str);
			if (str == "") throw EndOfFile();
			h.place.setClassOfPlace(stoi(str));
			getline(is, str);
			h.place.setCoordinates(str);
			getline(is, str);
			h.place.setIdnumber(stoi(str));
			h.row.push_back(h.place);
		}
		h.places.push_back(h.row);
	}
	return is;
}


ostream& operator << (ostream& os, Hall*& h)
{
	os << h->id << endl;
	os << h->usingCount << endl;
	os << h->needsToBeShown << endl;
	os << h->N << endl;
	os << h->M << endl;
	os << h->number << endl;
	for (int i = 0; i < h->N; i++)
		for (int j = 0; j < h->M; j++)
		{
			os << h->places[i][j].getClassOfPlace() << endl;
			os << h->places[i][j].getCoordinates() << endl;
			os << h->places[i][j].getIdnumber() << endl;
		}
	return os;
}

ostream& operator << (ostream& os, Hall& h)
{
	os << h.id << endl;
	os << h.usingCount << endl;
	os << h.needsToBeShown << endl;
	os << h.N << endl;
	os << h.M << endl;
	os << h.number << endl;
	for (int i = 0; i < h.N; i++)
		for (int j = 0; j < h.M; j++)
		{
			os << h.places[i][j].getClassOfPlace() << endl;
			os << h.places[i][j].getCoordinates() << endl;
			os << h.places[i][j].getIdnumber() << endl;
		}
	return os;
}




istream& operator >> (istream& is, Cinema& c)
{
	string str;
	getline(is, str);
	if (str == "") throw EndOfFile();
	c.id = stoi(str);
	getline(is, str);
	c.usingCount = stoi(str);
	getline(is, str);
	c.needsToBeShown = stoi(str);
	getline(is, c.adress);
	getline(is, c.name);
	int kol;
	getline(is, str);
	kol = stoi(str);
	c.halls = {};
	for (int i = 0; i < kol; i++)
	{
		getline(is, str);
		c.halls.push_back(stoi(str));
	}
	return is;
}

istream& operator >> (istream& is, Cinema*& c)
{
	string str;
	getline(is, str);
	c->id = stoi(str);
	getline(is, str);
	c->usingCount = stoi(str);
	getline(is, str);
	c->needsToBeShown = stoi(str);
	getline(is, c->adress);
	getline(is, c->name);
	int kol;
	getline(is, str);
	kol = stoi(str);
	c->halls = {};
	for (int i = 0; i < kol; i++)
	{
		getline(is, str);
		c->halls.push_back(stoi(str));
	}
	return is;
}

ostream& operator << (ostream& os, Cinema*& c)
{
	os << c->id << endl;
	os << c->usingCount << endl;
	os << c->needsToBeShown << endl;
	os << c->adress << endl;
	os << c->name << endl;
	int kol = c->halls.size();
	os << kol << endl;
	for (int i = 0; i < kol; i++)
		os << c->halls[i];
	return os;
}

ostream& operator << (ostream& os, Cinema& c)
{
	os << c.id << endl;
	os << c.usingCount << endl;
	os << c.needsToBeShown << endl;
	os << c.adress << endl;
	os << c.name << endl;
	int kol = c.halls.size();
	os << kol << endl;
	for (int i = 0; i < kol; i++)
		os << c.halls[i] << endl;
	return os;
}


vector<Cinema> readObjectsFromFile(string filename, Cinema c)
{
	ifstream file;
	file.open(CINEMA_DATA_FILE);
	vector<Cinema> vec = {};
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
			file >> c;
		}
		catch (...)
		{
			break;
		}
		vec.push_back(c);
	}
	file.close();
	return vec;
}




inline Hall Seance::getHall()
{
	Hall hall;
	return readObjectFromFile(this->hall, HALLS_DATA_FILE, hall);
}


vector<Hall> readObjectsFromFile(string filename, Hall hall)
{
	ifstream file;
	file.open(HALLS_DATA_FILE);
	vector<Hall> vec = {};
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
			file >> hall;
		}
		catch (...)
		{
			break;
		}
		vec.push_back(hall);
	}
	file.close();
	return vec;
}


istream& operator >> (istream& is, Seance& s)
{
	string str;
	getline(is, str);
	if (str == "") throw EndOfFile();
	s.id = stoi(str);
	is >> str; is.get();
	s.usingCount = stoi(str);
	getline(is, str);
	s.needsToBeShown = stoi(str);
	getline(is, s.date);
	getline(is, s.time);
	getline(is, s.movieTitle);
	getline(is, s.cinemaName);
	is >> str; is.get();
	s.doHaveTickets = stoi(str);
	is >> str; is.get();
	s.cinema = stoi(str);
	is >> str; is.get();
	s.hall = stoi(str);
	is >> str; is.get();
	s.movie = stoi(str);
	return is;
}

istream& operator >> (istream& is, Seance*& s)
{
	string str;
	getline(is, str); is.get();
	s->id = stoi(str);
	getline(is, str);
	s->usingCount = stoi(str);
	getline(is, str);
	s->needsToBeShown = stoi(str);
	getline(is, s->date); is.get();
	getline(is, s->time); is.get();
	getline(is, str); is.get();
	s->doHaveTickets = stoi(str);
	getline(is, str); is.get();
	s->cinema = stoi(str);
	getline(is, str); is.get();
	s->hall = stoi(str);
	getline(is, str); is.get();
	s->movie = stoi(str); is.get();
	return is;
}

ostream& operator << (ostream& os, Seance*& s)
{
	os << s->id << endl;
	os << s->usingCount << endl;
	os << s->needsToBeShown << endl;
	os << s->date << endl;
	os << s->time << endl;
	os << s->doHaveTickets << endl;
	os << s->cinema << endl;
	os << s->hall << endl;
	os << s->movie << endl;
	return os;
}

ostream& operator << (ostream& os, Seance& s)
{
	os << s.id << endl;
	os << s.usingCount << endl;
	os << s.needsToBeShown << endl;
	os << s.date << endl;
	os << s.time << endl;
	os << s.movieTitle << endl;
	os << s.cinemaName << endl;
	os << s.doHaveTickets << endl;
	os << s.cinema << endl;
	os << s.hall << endl;
	os << s.movie << endl;
	return os;
}

vector<Seance> readObjectsFromFile(string filename, Seance seance)
{
	ifstream file;
	file.open(SEANCES_DATA_FILE);
	vector<Seance> vec = {};
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
			file >> seance;
		}
		catch (...)
		{
			break;
		}
		vec.push_back(seance);
	}
	file.close();
	return vec;
}

//----------------------------------------------



istream& operator >> (istream& is, Ticket& t)
{
	string str;
	getline(is, str);
	if (str == "") throw EndOfFile();
	t.id = stoi(str);
	getline(is, str);
	t.usingCount = stoi(str);
	getline(is, str);
	t.needsToBeShown = stoi(str);
	getline(is, str);
	t.place = stoi(str);
	getline(is, str);
	t.hall = stoi(str);
	getline(is, str);
	t.seance = stoi(str);
	getline(is, str);
	t.price = stod(str);
	return is;
}

istream& operator >> (istream& is, Ticket*& t)
{
	string str;
	getline(is, str); is.get();
	t->id = stoi(str);
	getline(is, str);
	t->usingCount = stoi(str);
	getline(is, str);
	t->needsToBeShown = stoi(str);
	getline(is, str); is.get();
	t->place = stoi(str);
	getline(is, str); is.get();
	t->hall = stoi(str);
	getline(is, str); is.get();
	t->seance = stoi(str);
	getline(is, str); is.get();
	t->price = stod(str);
	return is;
}

ostream& operator << (ostream& os, Ticket*& t)
{
	os << t->id << endl;
	os << t->usingCount << endl;
	os << t->needsToBeShown << endl;
	os << to_string(t->place) << endl;
	os << to_string(t->hall) << endl;
	os << to_string(t->seance) << endl;
	os << t->price << endl;
	return os;
}

ostream& operator << (ostream& os, Ticket& t)
{
	os << t.id << endl;
	os << t.usingCount << endl;
	os << t.needsToBeShown << endl;
	os << t.place << endl;
	os << t.hall << endl;
	os << t.seance << endl;
	os << t.price << endl;
	return os;
}

istream& operator >> (istream& is, pair<vector<double>, vector<Ticket>>& tickets)
{
	vector<double> a;
	vector<Ticket> b;
	string str;
	for (int i = 0; i < 6; i++)
	{
		getline(is, str);
		if (str == "") throw EndOfFile();
		a.push_back(stod(str));
	}
	getline(is, str);
	int kol = stod(str);
	Ticket t;
	for (int i = 0; i < kol; i++)
	{
		getline(is, str);
		t.setId(stoi(str));
		getline(is, str);
		t.setUsingCount(stoi(str));
		getline(is, str);
		t.setNeedsToBeShown(stoi(str));
		getline(is, str);
		t.setStatus(stoi(str));
		getline(is, str);
		t.setPlace(stoi(str));
		getline(is, str);
		t.setHall(stoi(str));
		getline(is, str);
		t.setSeance(stoi(str));
		getline(is, str);
		t.setPrice(stod(str));
		b.push_back(t);
	}
	tickets.first = a;
	tickets.second = b;
}

ostream& operator << (ostream& os, pair<vector<double>, vector<Ticket>>& tickets)
{
	vector<double> a = tickets.first;
	vector<Ticket> b = tickets.second;
	for (int i = 0; i < 6; i++)
		os << a[i] << endl;
	int kol = b.size();
	os << kol << endl;
	for (int i = 0; i < kol; i++)
	{
		os << b[i].getId() << endl;
		os << b[i].getUsingCount() << endl;
		os << b[i].getNeedsToBeShown() << endl;
		os << b[i].getStatus() << endl;
		os << b[i].getPlace() << endl;
		os << b[i].getHallInt() << endl;
		os << b[i].getSeanceInt() << endl;
		os << b[i].getPrice() << endl;
	}
	return os;
}

void writeNewObjectToFile(string filename, pair<vector<double>, vector<Ticket>> p)
{
	ofstream file;
	file.open(filename, ios::app);
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file.\n";
		std::system("pause");
		return;
	}
	file << p;
	file.close();
	return;
}

vector<Ticket> readObjectsFromFile(string filename, Ticket ticket)
{
	ifstream file;
	file.open(TICKETS_DATA_FILE);
	vector<Ticket> vec = {};
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
			file >> ticket;
		}
		catch (...)
		{
			break;
		}
		vec.push_back(ticket);
	}
	file.close();
	return vec;
}

vector<pair<vector<double>, vector<Ticket>>> readObjectsFromFile(string filename, vector<pair<vector<double>, vector<Ticket>>> tickets)
{
	ifstream file;
	file.open(TICKETS_DATA_FILE);
	vector<pair<vector<double>, vector<Ticket>>> vec = {};
	pair<vector<double>, vector<Ticket>> p;
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
			file >> p;
		}
		catch (...)
		{
			break;
		}
		vec.push_back(p);
	}
	file.close();
	return vec;
}


//----------------------------------------------




inline void Order::setTickets(vector<Ticket> tickets)
{
	this->tickets = tickets;
}


inline int Order::getTicketsCount()
{
	return this->tickets.size();
}


istream& operator >> (istream& is, Order& o)
{
	string str;
	getline(is, str);
	if (str == "") throw EndOfFile();
	o.id = stoi(str);
	getline(is, str);
	o.usingCount = stoi(str);
	getline(is, str);
	o.needsToBeShown = stoi(str);
	getline(is, str);
	o.status = stoi(str);
	getline(is, str);
	int kol = stoi(str);
	o.tickets = {};
	vector<Ticket> vec;
	Ticket t;
	for (int i = 0; i < kol; i++)
	{
		is >> t;
		vec.push_back(t);
	}
	o.setTickets(vec);
	return is;
}

istream& operator >> (istream& is, Order*& o)
{
	string str;
	getline(is, str); is.get();
	o->id = stoi(str);
	getline(is, str);
	o->usingCount = stoi(str);
	getline(is, str);
	o->needsToBeShown = stoi(str);
	getline(is, str); is.get();
	o->status = stoi(str);
	getline(is, str); is.get();
	getline(is, str); is.get();
	int kol = stoi(str);
	o->tickets = {};
	vector<Ticket> vec;
	Ticket t;
	for (int i = 0; i < kol; i++)
	{
		is >> t;
		vec.push_back(t);
	}
	o->setTickets(vec);
	return is;
}

ostream& operator << (ostream& os, Order*& o)
{
	os << o->id << endl;
	os << o->usingCount << endl;
	os << o->needsToBeShown << endl;
	os << o->status << endl;
	int kol = o->tickets.size();
	os << kol << endl;
	for (int i = 0; i < kol; i++) os << o->tickets[i];
	return os;
}

ostream& operator << (ostream& os, Order& o)
{
	os << o.id << endl;
	os << o.usingCount << endl;
	os << o.needsToBeShown << endl;
	os << o.status << endl;
	int kol = o.tickets.size();
	os << kol << endl;
	for (int i = 0; i < kol; i++) os << o.tickets[i];
	return os;
}


vector<Order> readObjectsFromFile(string filename, Order order)
{
	ifstream file;
	file.open(ORDERS_DATA_FILE);
	vector<Order> vec = {};
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
			file >> order;
		}
		catch (...)
		{
			break;
		}
		vec.push_back(order);
	}
	file.close();
	return vec;
}

inline string User::getLogin()
{
	return this->login;
}



//----------------------------------------------




inline void User::setOrders(vector<int> orders)
{
	this->orders = orders;
}

inline vector<int> User::getOrders()
{
	return this->orders;
}








istream& operator >> (istream& is, User& c)
{
	string str;
	vector<int> vec;
	getline(is, str);
	if (str == "") throw EndOfFile();
	c.id = stoi(str);
	getline(is, str);
	c.needsToBeShown = stoi(str);
	getline(is, c.login);
	getline(is, c.password);
	getline(is, str);
	c.role = stoi(str);
	getline(is, str);
	c.access = stoi(str);
	getline(is, c.FIO);
	getline(is, str);
	int kol = stoi(str);
	c.orders = {};
	for (int i = 0; i < kol; i++)
	{
		getline(is, str);
		c.orders.push_back(stoi(str));
	}
	getline(is, c.bankCardData);
	getline(is, str);
	c.balance = stod(str);
	return is;
}



istream& operator >> (istream& is, User*& c)
{
	string str;
	vector<int> vec;
	getline(is, str);
	if (str == "") throw EndOfFile();
	c->id = stoi(str);
	getline(is, str);
	c->needsToBeShown = stoi(str);
	getline(is, c->login);
	getline(is, c->password);
	getline(is, str);
	c->role = stoi(str);
	getline(is, str);
	c->access = stoi(str);
	getline(is, c->FIO);
	getline(is, str);
	int kol = stoi(str);
	c->orders = {};
	for (int i = 0; i < kol; i++)
	{
		getline(is, str);
		c->orders.push_back(stoi(str));
	}
	getline(is, c->bankCardData);
	getline(is, str);
	c->balance = stod(str);
	return is;
}


ostream& operator << (ostream& os, User& c)
{
	os << c.id << endl;
	os << c.needsToBeShown << endl;
	os << c.login << endl;
	os << c.password << endl;
	os << c.role << endl;
	os << c.access << endl;
	os << c.FIO << endl;
	os << c.orders;
	os << c.bankCardData << endl;
	os << c.balance << endl;
	return os;
}

ostream& operator << (ostream& os, User*& c)
{
	os << c->id << endl;
	os << c->needsToBeShown << endl;
	os << c->login << endl;
	os << c->password << endl;
	os << c->role << endl;
	os << c->access << endl;
	os << c->FIO << endl;
	os << c->orders;
	os << c->bankCardData << endl;
	os << c->balance << endl;
	return os;
}

ostream& operator << (std::ostream& os, const User*& c)
{
	os << "ID of the user in system: " << c->id << endl;
	os << "User login: " << c->login << endl;
	os << "User role: ";
	switch (c->role)
	{
	case 0:
		cout << "User";
		break;
	case 1:
		cout << "Cashier";
		break;
	case 2:
		cout << "Administrator";
		break;
	case 3:
		cout << "Showing manager";
		break;
	case 4:
		cout << "Content maanger";
		break;
	default:
		cout << "NULL";
		break;
	}
	os << "\nAccount status: ";
	switch (c->access)
	{
	case 0:
		cout << "Not confirmed";
		break;
	case 1:
		cout << "Confirmed";
		break;
	case 2:
		cout << "Blocked";
		break;
	}
	os << "\nName: ";
	if (c->FIO == "NULL") os << "info not filled!";
	else os << c->FIO;
	cout << "\nCredit card number: ";
	if (c->bankCardData == "NULL") os << "card is not linked!";
	else os << c->bankCardData;
	os << "\n";
	return os;
}


bool operator == (User& first, User& second)
{
	if (first.getLogin() == second.getLogin() && first.getPassword() == second.getPassword()) return true;
	else return false;
}

void User::showData()
{
	cout << "ID of the user in system: " << this->id << endl;
	cout << "User login: " << this->login << endl;
	cout << "User role: ";
	switch (this->role)
	{
	case 0:
		cout << "User";
		break;
	case 1:
		cout << "Cashier";
		break;
	case 2:
		cout << "Administrator";
		break;
	case 3:
		cout << "Showing manager";
		break;
	case 4:
		cout << "Content maanger";
		break;
	default:
		cout << "NULL";
		break;
	}
	cout << "\nAccount status: ";
	switch (this->access)
	{
	case 0:
		cout << "Not confirmed";
		break;
	case 1:
		cout << "Confirmed";
		break;
	case 2:
		cout << "Blocked";
		break;
	}
	cout << "\nName: ";
	if (this->FIO == "NULL") cout << "info not filled!";
	else cout << this->FIO;
	cout << "\nCredit card number: ";
	if (this->bankCardData == "NULL") cout << "card is not linked!";
	else cout << this->bankCardData;
	cout << "\nBalance: " << this->balance;
	cout << "\n";
}

void User::showDataProtected()
{
	cout << "ID of the user in system: " << this->id << endl;
	cout << "User login: " << this->login << endl;
	cout << "User role: ";
	switch (this->role)
	{
	case 0:
		cout << "User";
		break;
	case 1:
		cout << "Cashier";
		break;
	case 2:
		cout << "Administrator";
		break;
	case 3:
		cout << "Showing manager";
		break;
	case 4:
		cout << "Content maanger";
		break;
	default:
		cout << "NULL";
		break;
	}
	cout << "\nAccount status: ";
	switch (this->access)
	{
	case 0:
		cout << "Not confirmed";
		break;
	case 1:
		cout << "Confirmed";
		break;
	case 2:
		cout << "Blocked";
		break;
	}
	cout << "\nName: ";
	if (this->FIO == "NULL") cout << "info not filled!";
	else cout << this->FIO;
	cout << "\nCredit card number: ";
	if (this->bankCardData == "NULL") cout << "card is not linked!";
	else
	{
		string str(this->bankCardData.size(), 'X');
		cout << str;
	}
	cout << "\n";
}



int User::registerUser()
{
	int exist = 0;
	string loginFromFile;
	string passwordFromFile;
	string str;
	int access;
	int roleFromFile;
	ifstream file;
	User* s = new User;
	file.open(USER_DATA_FILE);
	if (file.bad())
	{
		std::cout << "Error! Unable to open the file.\n";
		std::system("pause");
		return false;
	}
	while (file.peek() != EOF)
	{
		file >> s;
		if (login == s->getLogin())
		{
			exist = 1;
			break;
		}
	}
	file.close();
	if (exist == 1)
	{
		cout << "Error! Login is already in use.\n";
		return -1;
	}
	int lastId = s->getId() + 1;
	s->setId(lastId);
	str = this->login;
	s->setLogin(str);
	str = this->password;
	s->setPassword(str);
	s->role = 0;
	s->access = 1;
	s->bankCardData = "NULL";
	s->FIO = "NULL";
	s->balance = 0;
	s->orders = {};
	s->needsToBeShown = 1;
	this->id = lastId;
	writeNewObjectToFile(USER_DATA_FILE, *s);
	delete s;
	return 1;
}

//--------------------------------------------------------------------------------------------------

vector<User> readObjectsFromFile(string filename, User s)
{
	ifstream file;
	file.open(USER_DATA_FILE);
	vector<User> vec = {};
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
			file >> s;
		}
		catch (...)
		{
			break;
		}
		vec.push_back(s);
	}
	file.close();
	return vec;
}

vector<User*> readUsersFromFile(string filename)
{
	ifstream file;
	User obj;
	vector<User*> vec = {};
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
		vec.push_back(&obj);
	}
	file.close();
	return vec;
}

/*void rewriteObjectToFile(string filename, User* obj, int id)
{
	vector<User*> vec = readObjectsFromFile(filename, obj);
	vec[id] = obj;
	writeVectorOfObjectsToFile(filename, vec);
}*/




void Movie::createNewObject()
{
	string str;
	int choice;
	int id = idOfLastObject(*this);
	this->id = id;
	cout << "Enter movie name (up to 30 symbols): ";
	cin.clear();
	str = enterLineWithCertainSize(30);
	if(str == "") str = enterLineWithCertainSize(30);
	this->name = str;
	str = enterDurabilityForMovie();
	this->durability = str;
	cout << "At what age can you watch the movie? ";
	choice = enterDigit();
	str = to_string(choice) + "+";
	this->audience = str;
	cout << "Describe the movie (up to 255 symbols): ";
	str = enterLineWithCertainSize(255);
	this->description = str;
	Movie m;
	vector<Movie> movies = readObjectsFromFile(MOVIES_DATA_FILE, m);
	for (int i = 0; i < movies.size(); i++)
		if (movies[i].getName() == this->getName() && movies[i].getDescription() == this->getDescription()) throw AlreadyHere();
	writeNewObjectToFile(MOVIES_DATA_FILE, *this);
	Movie::addedCount += 1;
}

void Hall::createNewObject(int number)
{
	int id = idOfLastObject(*this);
	this->id = id;
	int count;
	cout << "Enter row count (up to 100): ";
	while (true)
	{
		count = enterDigit();
		if (count <= 100) break;
		cout << "Wrong input! ";
	}
	this->N = count;
	cout << "Enter seat count in a row (up to 100): ";
	while (true)
	{
		count = enterDigit();
		if (count <= 100) break;
		cout << "Wrong input! ";
	}
	this->M = count;
	this->number = number;
	Place place;
	for (int i = 1; i <= this->N; i++)
	{
		this->places.push_back({});
		for (int j = 1; j <= this->M; j++)
		{
			place.setCoordinates(to_string(i) + "." + to_string(j));
			place.setIdnumber(this->M * (i - 1) + j);
			this->places[i - 1].push_back(place);
		}
	}
	writeNewObjectToFile(HALLS_DATA_FILE, *this);
}

void Cinema::createNewObject()
{
	string str;
	int id = idOfLastObject(*this);
	this->id = id;
	cout << "Enter the name of a cinema (up to 30 symbols): ";
	str = enterLineWithCertainSize(30);
	if(str == "") str = enterLineWithCertainSize(30);
	this->name = str;
	cout << "Enter the adress of a cinema (up to 20 symbols): ";
	str = enterLineWithCertainSize(20);
	this->adress = str;
	this->halls = {};
	this->usingCount = 0;
	this->needsToBeShown = 1;
	Cinema c;
	vector<Cinema> cinemas = readObjectsFromFile(CINEMA_DATA_FILE, c);
	for (int i = 0; i < cinemas.size(); i++)
		if(cinemas[i].getAdress() == this->getAdress() && cinemas[i].getName() == this->getName())
	writeNewObjectToFile(CINEMA_DATA_FILE, *this);
	Movie::addedCount += 1;
}

void Seance::createNewObject(vector<Movie> movies, vector<Cinema> cinemas)
{
	vector<Hall> halls;
	int choice;
	int buf;
	int id = idOfLastObject(*this);
	this->id = id;
	this->usingCount = 0;
	this->needsToBeShown = 1;
	this->date = enterDate();
	this->time = enterTime();
	this->doHaveTickets = 0;
	while (true)
	{
		system("cls");
		printCinemaTableHeader();
		printCinemasFromVector(cinemas);
		separator();
		cout << "Enter cinema where the showing will be: ";
		while (true)
		{
			choice = enterDigit();
			if (choice > cinemas.size())
			{
				cout << "Wrong input! ";
				continue;
			}
			if (cinemas[choice - 1].getNeedsToBeShown() == 0)
			{
				cout << "Wrong input! ";
				continue;
			}
			if (choice <= cinemas.size()) break;
			cout << "Wrong input! ";
		}
		choice--;
		if (cinemas[choice].getHalls().size() == 0)
		{
			cout << "Oops! There are no halls in this cinema... Go back (1) or exit (any other positive number)? ";
			choice = enterDigit();
			if (choice == 1) continue;
			else return;
		}
		else break;
	}
	this->cinema = cinemas[choice].getId();
	this->cinemaName = cinemas[choice].getName();
	cinemas[choice].addToUsingCount(1);
	rewriteObjectToFile(CINEMA_DATA_FILE, cinemas[choice], cinemas[choice].getId());
	system("cls");
	printHallTableHeader();
	halls = cinemas[choice].getHallsVector();
	showHallsVector(halls);
	separator();
	buf = choice;
	cout << "Enter the hall where the showing will be: ";
	while (true)
	{
		choice = enterDigit();
		if (choice > cinemas[buf].getHalls().size())
		{
			cout << "Wrong input! ";
			continue;
		}
		if (cinemas[buf].getHallsVector()[choice - 1].getNeedsToBeShown() == 0)
		{
			cout << "Wrong input! ";
			continue;
		}
		if (choice <= cinemas[buf].getHalls().size()) break;
		cout << "Wrong input! ";
	}
	choice--;
	this->hall = cinemas[buf].getHalls()[choice];
	halls[choice].addToUsingCount(1);
	rewriteObjectToFile(HALLS_DATA_FILE, halls[choice], halls[choice].getId());
	int buf2 = choice;
	system("cls");
	printMovieTableHeader();
	showMoviesVector(movies);
	separator();
	cout << "Enter movie that would be on the showing: ";
	while (true)
	{
		choice = enterDigit();
		if (choice > movies.size())
		{
			cout << "Wrong input! ";
			continue;
		}
		if (movies[choice - 1].getNeedsToBeShown() == 0)
		{
			cout << "Wrong input! ";
			continue;
		}
		if (choice <= movies.size()) break;
		cout << "Wrong input! ";
	}
	choice--;
	this->movie = movies[choice].getId();
	this->movieTitle = movies[choice].getName();
	Seance s;
	vector<Seance> seances = readObjectsFromFile(SEANCES_DATA_FILE, s);
	for (int i = 0; i < seances.size(); i++)
		if (seances[i].getDate() == this->getDate() && seances[i].getTime() == this->getTime() && seances[i].getMovie().getName() == this->getMovie().getName() && seances[i].getCinema().getName() == this->getCinema().getName() && seances[i].getHall().getNumber() == this->getHall().getNumber())
		{
			halls[buf2].addToUsingCount(-1);
			rewriteObjectToFile(HALLS_DATA_FILE, halls[buf2], halls[buf2].getId());
			cinemas[buf].addToUsingCount(-1);
			rewriteObjectToFile(CINEMA_DATA_FILE, cinemas[buf], halls[buf].getId());
			throw AlreadyHere();
		}
	writeNewObjectToFile(SEANCES_DATA_FILE, *this);
	movies[choice].addToUsingCount(1);
	rewriteObjectToFile(MOVIES_DATA_FILE, movies[choice], movies[choice].getId());
	Seance::addedCount += 1;
}

pair<vector<double>, vector<Ticket>> Ticket::createTicketsForSeance(vector<Seance> seances, vector<Cinema> cinemas)
{
	vector<double> numbers;
	vector<Ticket> tickets;
	pair<vector<double>, vector<Ticket>> p;
	printSeanceTableHeader();
	showSeanceVector(seances);
	separator();
	cout << "Enter the number of a showing you would like to create tickets for. Enter 0 to exit: ";
	int id;
	while (true)
	{
		id = enterDigit();
		if (id == 0) return p;
		if (id > seances.size())
		{
			cout << "Wrong input! ";
			continue;
		}
		if (seances[id - 1].getNeedsToBeShown() == 0)
		{
			cout << "Wrong input! ";
			continue;
		}
		if (seances[id - 1].getUsingCount() > 0)
		{
			cout << "There are already tickets on this showing! ";
			continue;
		}
		if (id <= seances.size() && id != 0) break;
	}
	id--;
	seances[id].setUsingCount(1);
	rewriteObjectToFile(SEANCES_DATA_FILE, seances[id], seances[id].getId());
	double standard = -1, comfort = -1, VIP = -1;
	Hall h = seances[id].getHall();
	int M = h.getM();
	int N = h.getN();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (h.getPlaces()[i][j].getClassOfPlace() == 1) standard = 0;
			else if (h.getPlaces()[i][j].getClassOfPlace() == 2) comfort = 0;
			else if (h.getPlaces()[i][j].getClassOfPlace() == 3) VIP = 0;
		}
	if (standard == 0)
	{
		cout << "Enter cost of tickets of type Standart: ";
		while (true)
		{
			standard = enterDouble();
			if (standard <= 0)
			{
				cout << "Маловато... ";
				continue;
			}
			if (standard < 99999) break;
			cout << "Wrong input! Too much! ";
		}
		cout << endl;
	}
	if (comfort == 0)
	{
		cout << "Enter cost of tickets of type Comfort: ";
		while (true)
		{
			comfort = enterDouble();
			if (comfort <= 0)
			{
				cout << "Маловато... ";
				continue;
			}
			if (comfort < 99999) break;
			cout << "Wrong input! Too much! ";
		}
		cout << endl;
	}
	if (VIP == 0)
	{
		cout << "Enter cost of tickets of type VIP: ";
		while (true)
		{
			VIP = enterDouble();
			if (VIP <= 0)
			{
				cout << "Маловато... ";
				continue;
			}
			if (VIP < 99999) break;
			cout << "Wrong input! Too much! ";
		}
		cout << endl;
	}

	numbers.push_back(standard);
	numbers.push_back(comfort);
	numbers.push_back(VIP);
	numbers.push_back(h.getId());
	numbers.push_back(seances[id].getId());
	numbers.push_back(1);
	Ticket ticket;
	int num = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++, num++)
		{
			ticket.setId(1);
			ticket.setUsingCount(1);
			ticket.setNeedsToBeShown(1);
			ticket.setPlace(num);
			ticket.setHall(h.getId());
			ticket.setSeance(seances[id].getId());
			switch (h.getPlaces()[i][j].getClassOfPlace())
			{
			case 1:
				ticket.setPrice(standard);
				break;
			case 2:
				ticket.setPrice(comfort);
				break;
			case 3:
				ticket.setPrice(VIP);
				break;
			}
			ticket.setStatus(0);
			tickets.push_back(ticket);
		}
	p.first = numbers;
	p.second = tickets;
	writeNewObjectToFile(TICKETS_DATA_FILE, p);
	return p;
}



vector<ReportOld> readObjectsFromFile(string filename, ReportOld r)
{
	ifstream file;
	file.open(REPORT_DATA_FILE);
	vector<ReportOld> vec = {};
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
			file >> r;
		}
		catch (...)
		{
			break;
		}
		vec.push_back(r);
	}
	file.close();
	return vec;
}


istream& operator >> (istream& is, ReportOld& r)
{
	string str;
	getline(is, str);
	if (str == "") throw EndOfFile();
	r.loggedCount = stoi(str);
	getline(is, str);
	r.regCount = stoi(str);
	getline(is, str);
	r.boughtCount = stoi(str);
	getline(is, str);
	r.moviesCount = stoi(str);
	getline(is, str);
	r.cinemasCount = stoi(str);
	getline(is, str);
	r.seancesCount = stoi(str);
	return is;
}

ostream& operator << (ostream& os, ReportOld& r)
{
	os << r.loggedCount << endl;
	os << r.regCount << endl;
	os << r.boughtCount << endl;
	os << r.moviesCount << endl;
	os << r.cinemasCount << endl;
	os << r.seancesCount << endl;
	return os;
}

istream& operator >> (istream& is, Report& r)
{
	string str;
	getline(is, str);
	if (str == "") throw EndOfFile();
	r.movie = stoi(str);
	getline(is, str);
	r.biletsKol = stoi(str);
	getline(is, str);
	r.gainedMoney = stod(str);
	return is;
}

ostream& operator << (ostream& os, Report& r)
{
	os << r.movie << endl;
	os << r.biletsKol << endl;
	os << r.gainedMoney << endl;
	return os;
}


int User::loggedIn = 0;
int User::registered = 0;
int Ticket::bought = 0;
int Movie::addedCount = 0;
int Cinema::addedCount = 0;
int Seance::addedCount = 0;

