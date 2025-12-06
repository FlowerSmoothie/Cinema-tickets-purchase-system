#pragma once

#include "Classes.h"

void showTickets();
void showUsers();
void showCinemaInfo();
void showMovieInfo();
void showSeancesInfo();


User ShowProfileInfo(User user);

void showStatistics();

User changeFIO(User user);
User viewOrders(User user);
User changeCard(User user);
void deleteUser(User user);
void deleteAccount(User user);



User changeRole(User user);
User changeAccess(User user);
User addToBalance(User user);


void showHallData(Hall hall);

Cinema viewHalls(Cinema cinema);

Movie changeName(Movie movie);
Movie changeMovieDurability(Movie movie);
Movie changeMovieAudience(Movie movie);
Movie changeMovieDescription(Movie movie);

vector<Seance> showSeanceInDetail(vector<Seance> seances, vector<Movie> movies, vector<Cinema> cinemas);
void changeMovie(Seance& seance, vector<Movie> movies);
void filterSeances(vector<Seance> seances);
vector<Seance> onlyShowable(vector<Seance> seances);

template<typename T>
vector<T> reverseSortingOrNot(vector<T> vec)
{
    int pos = 1;
    int key = 0;
    vector<T> rev(vec.rbegin(), vec.rend());
    while (true)
    {
        system("cls");
        drawSortTypeChoosing(pos);
        key = _getch();
        switch (key)
        {
        case UP_ENG:
        case UP_RUS:
            if (pos != 1) pos--;
            else pos = 2;
            continue;
        case DOWN_ENG:
        case DOWN_RUS:
            if (pos != 2) pos++;
            else pos = 1;
            continue;
        case ENTER:
            switch (pos)
            {
            case 1:
                return vec;
                break;
            case 2:
                return rev;
                break;
            default:
                break;
            }
        default:
            continue;
        }
    }
}



vector<Movie> showMovieInDetail(vector<Movie> movies);
vector<Movie> deleteMovie(vector<Movie> movies);
vector<Movie> sortMovies(vector<Movie> movies);
void filterMovies(vector<Movie> movies);
void searchMovies(vector<Movie> movies);
vector<Movie> onlyShowable(vector<Movie> movies);
vector<Movie> mergeVectors(vector<Movie> biggerOne, vector<Movie> smallerOne);

User showAfisha(User user);

void searchCinemas(vector<Cinema> cinemas);
vector<Cinema> onlyShowable(vector<Cinema> cinemas);

void printUsersVector(vector<User> users)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getNeedsToBeShown() == 0) continue;
        std::cout << "\n|| " << setiosflags(ios::left) << setw(4) << (users[i].getId() + 1);
        std::cout << " | " << setw(15) << users[i].getLogin();
        std::cout << " | " << setw(7);
        switch (users[i].getRole())
        {
        case 0:
            cout << "User";
            break;
        case 1:
            cout << "Cashier";
            break;
        case 2:
            cout << "Admin";
            break;
        case 3:
            cout << "Showing";
            break;
        case 4:
            cout << "Content";
            break;
        default:
            cout << "NULL";
            break;
        }
        std::cout << " | " << setw(7);
        if (users[i].getAccess() == 1) cout << "Active";
        else cout << "Blocked";
        std::cout << " | " << setw(20) << users[i].getFIO();
    }
}
