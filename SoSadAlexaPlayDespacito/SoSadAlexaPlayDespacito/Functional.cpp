#include <iostream>
#include <algorithm>
#include <filesystem>
#include <iomanip>
#include <conio.h>
#include <windows.h>


#include "ObjectOperations.h"
#include "Classes.h"
#include "Exceptions.h"
#include "Drawings.h"
#include "Functional.h"
#include "Functors.h"
#include "LoginRegister.h"


using namespace std;




void UserMenu(User user) 
{
    int pos = 1;
    int key = 0;
    int result = 0;
    while (true)
    {
        user = readObjectFromFile(user.getId(), USER_DATA_FILE, user);
        key = 0;
        system("cls");
        drawUserMenu(pos);
        key = _getch();
        switch (key)
        {
        case UP_ENG:
        case UP_RUS:
            if (pos != 1) pos--;
            else pos = 4;
            continue;
        case DOWN_ENG:
        case DOWN_RUS:
            if (pos != 4) pos++;
            else pos = 1;
            continue;
        case ENTER:
            switch (pos)
            {
            case 1:
                showAfisha(user);
                break;
            case 2:
                user.viewOrders();
                break;
            case 3:
                user = ShowProfileInfo(user);
                break;
            case 4:
                if (checkExit() == 1) return;
                break;
            }
            break;
        default:
            continue;
        }
    }
}

void CashierMenu(User user)
{
    int pos = 1;
    int key = 0;
    int result = 0;
    while (true)
    {
        user = readObjectFromFile(user.getId(), USER_DATA_FILE, user);
        key = 0;
        system("cls");
        drawCashierMenu(pos);
        key = _getch();
        switch (key)
        {
        case UP_ENG:
        case UP_RUS:
            if (pos != 1) pos--;
            else pos = 5;
            continue;
        case DOWN_ENG:
        case DOWN_RUS:
            if (pos != 5) pos++;
            else pos = 1;
            continue;
        case ENTER:
            switch (pos)
            {
            case 1:
                showAfisha(user);
                break;
            case 2:
                user.viewOrders();
                break;
            case 3:
                user = ShowProfileInfo(user);
                break;
            case 4:
                showTickets();
            case 5:
                if (checkExit() == 1) return;
                break;
            }
            break;
        default:
            continue;
        }
    }
}

void SeanceManagerMenu(User user)
{
    user = readObjectFromFile(user.getId(), USER_DATA_FILE, user);
    int pos = 1;
    int key = 0;
    int result = 0;
    while (true)
    {
        key = 0;
        system("cls");
        drawSeanceManagerMenu(pos);
        key = _getch();
        switch (key)
        {
        case UP_ENG:
        case UP_RUS:
            if (pos != 1) pos--;
            else pos = 6;
            continue;
        case DOWN_ENG:
        case DOWN_RUS:
            if (pos != 6) pos++;
            else pos = 1;
            continue;
        case ENTER:
            switch (pos)
            {
            case 1:
                showAfisha(user);
                break;
            case 2:
                user.viewOrders();
                break;
            case 3:
                user = ShowProfileInfo(user);
                break;
            case 4:
                showSeancesInfo();
                break;
            case 5:
                showTickets();
                break;
            case 6:
                if (checkExit() == 1) return;
                break;
            }
            break;
        default:
            continue;
        }
    }
}

void ContentManagerMenu(User user)
{
    user = readObjectFromFile(user.getId(), USER_DATA_FILE, user);
    int pos = 1;
    int key = 0;
    int result = 0;
    while (true)
    {
        key = 0;
        system("cls");
        drawContentManagerMenu(pos);
        key = _getch();
        switch (key)
        {
        case UP_ENG:
        case UP_RUS:
            if (pos != 1) pos--;
            else pos = 5;
            continue;
        case DOWN_ENG:
        case DOWN_RUS:
            if (pos != 5) pos++;
            else pos = 1;
            continue;
        case ENTER:
            switch (pos)
            {
            case 1:
                showAfisha(user);
                break;
            case 2:
                user.viewOrders();
                break;
            case 3:
                user = ShowProfileInfo(user);
                break;
            case 4:
                showMovieInfo();
                break;
            case 5:
                if (checkExit() == 1) return;
                break;
            }
            break;
        default:
            continue;
        }
    }
}

void AdminMenu(User user)
{
    user = readObjectFromFile(user.getId(), USER_DATA_FILE, user);
    int pos = 1;
    int key = 0;
    int result = 0;
    while (true)
    {
        key = 0;
        system("cls");
        drawAdminMenu(pos);
        key = _getch();
        switch (key)
        {
        case UP_ENG:
        case UP_RUS:
            if (pos != 1) pos--;
            else pos = 10;
            continue;
        case DOWN_ENG:
        case DOWN_RUS:
            if (pos != 10) pos++;
            else pos = 1;
            continue;
        case ENTER:
            switch (pos)
            {
            case 1:
                showAfisha(user); 
                break;
            case 2:
                user = readObjectFromFile(user.getId(), USER_DATA_FILE, user);
                user.viewOrders();
                break;
            case 3:
                user = ShowProfileInfo(user); 
                break;
            case 4:
                showTickets(); 
                break;
            case 5:
                showUsers();
                break;
            case 6:
                showCinemaInfo();
                break;
            case 7:
                showMovieInfo();
                break;
            case 8:
                showSeancesInfo();
                break;
            case 9:
                showStatistics();
                break;
            case 10:
                if (checkExit() == 1) return; 
                break;
            }
            break;
        default:
            continue;
        }
    }
}




void showUsers()
{
    int id = 0;
    User s;
    vector<User> users = {};
    while (true)
    {
        users = readObjectsFromFile(USER_DATA_FILE, s);
        system("cls");
        if (users.size() == 0)
        {
            cout << "Empty here\n";
            system("pause");
            return;
        }
        printUsersTableHeader();
        printUsersVector(users);
        separator();
        while (true)
        {
            cout << "Enter the number of the user you want to see detailed information about, and 0 to exit: ";
            id = enterDigit();
            if (id == 0) return;
            if (id > users.size() || users[id - 1].getNeedsToBeShown() == 0)
            {
                cout << "Wrong input!\n";
                system("pause");
                continue;
            }
            if (users[id - 1].getLogin() == "Midori")
            {
                cout << "Cannot change information about that user!\n";
                system("pause");
                return;
            }
            break;
        }
        int pos = 1;
        int key = 0;
        id--;
        while (true)
        {
            system("cls");
            users[id].showDataProtected();
            separator();
            drawAdminUserChangeMenu(pos);
            key = 0;
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
                    users[id] = changeRole(users[id]);
                    break;
                case 2:
                    users[id] = changeAccess(users[id]);
                    break;
                case 3:
                    return;
                    break;
                }
                system("pause");
                break;
            default:
                continue;
            }
            break;
        }
    }
}

User ShowProfileInfo(User user)
{
    int key = 0;
    int pos = 1;
    while (true)
    {
        key = 0;
        system("cls");
        user.showData();
        separator();
        drawProfileViewMenu(pos);
        key = _getch();
        switch (key)
        {
        case UP_RUS:
        case UP_ENG:
            if (pos != 1) pos--;
            else pos = 8;
            continue;
        case DOWN_RUS:
        case DOWN_ENG:
            if (pos != 8) pos++;
            else pos = 1;
            continue;
        case ENTER:
            system("cls");
            switch (pos)
            {
            case 1:
                user = changeLogin(user);
                break;
            case 2:
                user = changePassword(user);
                break;
            case 3:
                user = changeFIO(user);
                break;
            case 4:
                user.viewOrders();
                break;
            case 5:
                user = changeCard(user);
                break;
            case 6:
                user = addToBalance(user);
                break;
            case 7:
                deleteUser(user);
                break;
            case 8:
                return user;
                break;
            }
            break;
        default:
            continue;
        }
    }
}

User addToBalance(User user)
{
    double sum;
    system("cls");
    if (user.getBankCardData() == "NULL")
    {
        cout << "Card is not linked!\n";
        system("pause");
        return user;
    }
    cout << "Enter the amount of money you would like to replenish your wallet with? ";
    while (true)
    {
        sum = enterDouble();
        if (sum > 0 && user.getBalance() + sum < 99999) break;
        cout << "Wrong input! ";
    }
    user.addToBalance(sum);
    rewriteObjectToFile(USER_DATA_FILE, user, user.getId());
    return user;
}

User changeFIO(User user)
{
    cout << "Enter new name (up to 20 symbols): ";
    string str;
    str = enterLineWithCertainSize(20);
    user.setFIO(str);
    rewriteObjectToFile(USER_DATA_FILE, user, user.getId());
    return user;
}

User changeCard(User user)
{
    cout << "Enter new card number: ";
    string str;
    getline(cin, str);
    user.setBankCardData(str);
    rewriteObjectToFile(USER_DATA_FILE, user, user.getId());
    return user;
}

void printOrdersFromVector(vector<Order> vec)
{
    int kol = vec.size();
    for (int i = 0; i < kol; i++)
    {
        std::cout << "\n|| " << setiosflags(ios::left) << setw(4) << i + 1;
        std::cout << " | " << setw(12) << vec[i].getStatusString();
        std::cout << " | " << setw(12) << vec[i].getTickets().size();
    }
}

void deleteUser(User user)
{
    int pos = 1;
    int key = 0;
    while (true)
    {
        key = 0;
        system("cls");
        drawDeleteAccountMenu(pos);
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
            system("cls");
            switch (pos)
            {
            case 1:
                return;
            case 2:
                if (user.getLogin() == "Midori")
                {
                    cout << "Cannot delete that account! :(\n";
                    system("pause");
                    return;
                }
                deleteAccount(user);
                cout << "Enter any key to exit the program\n";
                system("pause");
                exit(0);
            }
            break;
        default:
            continue;
        }
    }
}

void deleteAccount(User user)
{
    User s;
    vector<User> vec = readObjectsFromFile(USER_DATA_FILE, s);
    user.setNeedsToBeShown(0);
    vec[user.getId()] = user;
    writeVectorOfObjectsToFile(USER_DATA_FILE, vec);
    return;
}

User changeRole(User user)
{
    int choice;
    switch (user.getRole())
    {
    case 0:
        cout << "Choose:\n1. Change to administrator\n2. Change to show manager\n3. Change to content manager\n - ";
        while (true)
        {
            choice = enterDigit();
            if (choice == 1 || choice == 2 || choice == 3) break;
        }
        switch (choice)
        {
        case 1:
            user.setRole(2);
            break;
        case 2:
            user.setRole(3);
            break;
        case 3:
            user.setRole(4);
            break;
        }
        break;
    case 2:
        cout << "Choose:\n1. Change to user\n2. Change to show manager\n3. Change to content manager\n - ";
        while (true)
        {
            choice = enterDigit();
            if (choice == 1 || choice == 2 || choice == 3) break;
        }
        switch (choice)
        {
        case 1:
            user.setRole(0);
            break;
        case 2:
            user.setRole(3);
            break;
        case 3:
            user.setRole(4);
            break;
        }
        break;
    case 3:
        cout << "Choose:\n1. Change to user\n2. Change to administrator\n3. Change to content manager\n - ";
        while (true)
        {
            choice = enterDigit();
            if (choice == 1 || choice == 2 || choice == 3) break;
        }
        switch (choice)
        {
        case 1:
            user.setRole(0);
            break;
        case 2:
            user.setRole(2);
            break;
        case 3:
            user.setRole(4);
            break;
        }
        break;
    case 4:
        cout << "Choose:\n1. Change to user\n2. Change to administrator\n3. Change to show manager\n - ";
        while (true)
        {
            choice = enterDigit();
            if (choice == 1 || choice == 2 || choice == 3) break;
        }
        choice--;
        switch (choice)
        {
        case 1:
            user.setRole(0);
            break;
        case 2:
            user.setRole(2);
            break;
        case 3:
            user.setRole(3);
            break;
        }
        break;
    default:
        break;
    }
    rewriteObjectToFile(USER_DATA_FILE, user, user.getId());
    return user;
}

User changeAccess(User user)
{
    if (user.getAccess() == 1) user.setAccess(2);
    else user.setAccess(1);
    rewriteObjectToFile(USER_DATA_FILE, user, user.getId());
    return user;
}




void showHallData(Hall hall)
{
    std::cout << " | " << setw(4) << "Rows";
    std::cout << " | " << setw(7) << "In rows";
    std::cout << " | " << setw(8) << "Seat count";
    cout << endl;
    std::cout << " | " << setw(4) << hall.getN();
    std::cout << " | " << setw(7) << hall.getM();
    std::cout << " | " << setw(8) << hall.getN() * hall.getM();
    cout << "\n-------\n";
    hall.showData();
}

void showCinemaInDetail(vector<Cinema> cinemas)
{
    Hall hall;
    vector<int> vecInt;
    int id;
    while (true)
    {
        cout << "Enter the number of a cinema you would like to see detailed information about, or 0 to exit: ";
        id = enterAnyDigit();
        if (id == 0) return;
        if (id > cinemas.size() || cinemas[id - 1].getNeedsToBeShown() == 0)
        {
            cout << "Wrong input!\n";
            system("pause");
            continue;
        }
        else break;
    }
    id--;
    int pos = 1;
    int key;
    while (true)
    {
        system("cls");
        cinemas[id].showData();
        separator();
        drawCinemaChangeMenu(pos);
        key = 0;
        key = _getch();
        switch (key)
        {
        case UP_ENG:
        case UP_RUS:
            if (pos != 1) pos--;
            else pos = 6;
            continue;
        case DOWN_ENG:
        case DOWN_RUS:
            if (pos != 6) pos++;
            else pos = 1;
            continue;
        case ENTER:
            system("cls");
            switch (pos)
            {
            case 1:
                cinemas[id].changeName();
                break;
            case 2:
                cinemas[id].changeAdress();
                break;
            case 3:
                hall.createNewObject(cinemas[id].getHalls().size() + 1);
                vecInt = cinemas[id].getHalls();
                vecInt.push_back(hall.getId());
                cinemas[id].setHalls(vecInt);
                rewriteObjectToFile(CINEMA_DATA_FILE, cinemas[id], cinemas[id].getId());
                break;
            case 4:
                cinemas[id].deleteOneHall();
                break;
            case 5:
                cinemas[id] = viewHalls(cinemas[id]);
                break;
            case 6:
                return;
                break;
            }
            break;
        default:
            continue;
        }
        break;
    }
}

Cinema viewHalls(Cinema cinema)
{
    int pos = 1;
    int key;
    Hall hall;
    vector<int> vecInt;
    vector<Hall> halls = cinema.getHallsVector();
    if (halls.size() == 0)
    {
        while (true)
        {
            system("cls");
            cout << "Empty here. Would you like to create a hall?\n";
            drawYesNo(pos);
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
                system("cls");
                switch (pos)
                {
                case 1:
                    try
                    {
                        vecInt = cinema.getHalls();
                        hall.createNewObject(1);
                        vecInt.push_back(hall.getId());
                        cinema.setHalls(vecInt);
                        rewriteObjectToFile(CINEMA_DATA_FILE, cinema, cinema.getId());
                    }
                    catch (...)
                    {
                        cout << "Oops! An error has occured!\n";
                        system("pause");
                    }
                    return cinema;
                    break;
                case 2:
                    return cinema;
                    break;
                }
                break;
            default:
                continue;
            }
        }
        system("pause");
        return cinema;
    }
    printHallTableHeader();
    showHallsVector(halls);
    separator();
    int id;
    while (true)
    {
        cout << "Enter the number of a hall you would like to see detailed information about, or 0 to exit: ";
        id = enterDigit();
        if (id > halls.size())
        {
            cout << "Неверный ввод!\n";
            system("pause");
            continue;
        }
        if (id == 0) return cinema;
        id--;
        while (true)
        {
            system("cls");
            showHallData(halls[id]);
            drawHallChangeMenu(pos);
            key = 0;
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
                system("cls");
                switch (pos)
                {
                case 1:
                    halls[id].changeSeatClasses(halls[id].getId());
                    return cinema;
                    break;
                case 2:
                    return cinema;
                    break;
                }
                break;
            default:
                continue;
            }
            break;
        }
    }
}

vector<Cinema> deleteCinema(vector<Cinema> cinemas)
{
    int id;
    while (true)
    {
        cout << "Enter the number of a cinema you would like to delete: ";
        id = enterAnyDigit();
        if (id > cinemas.size())
        {
            cout << "Wrong input!\n";
            system("pause");
            continue;
        }
        else break;
    }
    id--;
    if (cinemas[id].getUsingCount() > 0)
    {
        cout << "Error! Unable to delete the cinema since it is used!\n";
        system("pause");
        return cinemas;
    }
    cinemas[id].setNeedsToBeShown(0);
    rewriteObjectToFile(CINEMA_DATA_FILE, cinemas[id], cinemas[id].getId());
    return cinemas;
}

vector<Cinema> sortCinemas(vector<Cinema> cinemas)
{
    int pos = 1;
    int key;
    while (true)
    {
        system("cls");
        drawCinemaSortFilterMenu(pos);
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
            switch (pos)
            {
            case 1:
                sort(cinemas.begin(), cinemas.end(), CompareCinemaName());
                break;
            case 2:
                sort(cinemas.begin(), cinemas.end(), CompareCinemaHalls());
                break;
            case 3: 
            default:
                break;
            }
            break;
        default:
            continue;
        }
        cinemas = reverseSortingOrNot(cinemas);
        return cinemas;
    }
}

void printCinemasFromVector(vector<Cinema> cinemas)
{
    for (int i = 0; i < cinemas.size(); i++)
    {
        if (cinemas[i].getNeedsToBeShown() == 0) continue;
        std::cout << "\n|| " << setiosflags(ios::left) << setw(4) << i + 1;
        std::cout << " | " << setw(30) << cinemas[i].getAdress();
        std::cout << " | " << setw(15) << cinemas[i].getName();
        std::cout << " | " << setw(4) << (cinemas[i].getHalls()).size();
    }
}

void filterCinemas(vector<Cinema> cinemas)
{
    vector<Cinema> foundCinemas = {};
    int pos = 1;
    int key;
    string str1, str2;
    int number1, number2, number3;
    while (true)
    {
        system("cls");
        drawCinemaSortFilterMenu(pos);
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
                system("cls");
            case 1:
                cout << "Enter desired name: ";
                getline(cin, str1);
                str1 = myToLower(str1);
                for (int i = 0; i < cinemas.size(); i++)
                {
                    str2 = cinemas[i].getName();
                    str2 = myToLower(str2);
                    if (str1 == str2)
                        foundCinemas.push_back(cinemas[i]);
                }
                break;
            case 2:
                cout << "Lower limit of hall count: \n";
                number1 = enterDigit();
                cout << "Upper limit of hall count: \n";
                number2 = enterDigit();
                for (int i = 0; i < cinemas.size(); i++)
                {
                    number3 = cinemas[i].getHalls().size();
                    if (number3 >= number1 && number3 <= number2) foundCinemas.push_back(cinemas[i]);
                }
                break;
            default:
                break;
            }
            cout << endl;
            if (foundCinemas.size() == 0) cout << "\nFound nothing :(\n";
            else
            {
                printCinemaTableHeader();
                printCinemasFromVector(foundCinemas);
            }
            cout << endl;
            system("pause");
            return;
        default:
            continue;
        }
    }
}

void showCinemaInfo()
{
    int id = 0;
    int pos = 1;
    int key;
    Cinema cinema;
    while (true)
    {
        vector<Cinema> cinemas = readObjectsFromFile(CINEMA_DATA_FILE, cinema);
        cinemas = onlyShowable(cinemas);
        system("cls");
        if (cinemas.size() == 0)
        {
            while (true)
            {
                system("cls");
                cout << "Empty here. WOuld you like to create a cinema?\n";
                drawYesNo(pos);
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
                    system("cls");
                    switch (pos)
                    {
                    case 1:
                        try
                        {
                            cinema.createNewObject();
                        }
                        catch (AlreadyHere a)
                        {
                            cout << "There is already such an object on the database!\n";
                        }
                        catch (...)
                        {
                            cout << "Oops! An error occured!";
                            system("pause");
                        }
                        return;
                        break;
                    case 2:
                        return;
                        break;
                    }
                    system("pause");
                    break;
                default:
                    continue;
                }
            }
            system("pause");
            return;
        }
        pos = 1;
        while (true)
        {
            key = 0;
            system("cls");
            drawCinemaSelectMenu(pos);
            key = _getch();
            switch (key)
            {
            case UP_ENG:
            case UP_RUS:
                if (pos != 1) pos--;
                else pos = 7;
                continue;
            case DOWN_ENG:
            case DOWN_RUS:
                if (pos != 7) pos++;
                else pos = 1;
                continue;
            case ENTER:
                system("cls");
                switch (pos)
                {
                case 1:
                    printCinemaTableHeader();
                    printCinemasFromVector(cinemas);
                    separator();
                    try
                    {
                        showCinemaInDetail(cinemas);
                    }
                    catch (...)
                    {
                        break;
                    }
                    break;
                case 2:
                    try
                    {
                        cinema.createNewObject();
                    }
                    catch (...)
                    {
                        cout << "Oops! An error occured!";
                        system("pause");
                    }
                    return;
                    break;
                case 3:
                    printCinemaTableHeader();
                    printCinemasFromVector(cinemas);
                    separator();
                    cinemas = deleteCinema(cinemas);
                    break;
                case 4:
                    cinemas = sortCinemas(cinemas);
                    continue;
                case 5:
                    searchCinemas(cinemas);
                    break;
                case 6:
                    filterCinemas(cinemas);
                    break;
                case 7:
                    return;
                    break;
                }
                break;
            default:
                continue;
            }
            break;
        }
    }
    return;
}


Movie changeName(Movie movie)
{
    string str;
    cout << "Current name: " << movie.getName();
    cout << "\nNew name (up to 30 symbols): ";
    str = enterLineWithCertainSize(30);
    if(str == "") str = enterLineWithCertainSize(30);
    movie.setName(str);
    rewriteObjectToFile(MOVIES_DATA_FILE, movie, movie.getId());
    return movie;
}

Movie changeMovieDurability(Movie movie)
{
    string str;
    int choice;
    cout << "Current durability: " << movie.getDurability();
    cout << "\nNew durability (hours): ";
    while (true)
    {
        choice = enterDigit();
        if (choice < 100) break;
        cout << "Wrong input! Too long ";
    }
    str = "";
    if (choice >= 0 && choice <= 9) str += "0";
    str += to_string(choice);
    str += ":";
    cout << "New durability (minutes): ";
    while (true)
    {
        choice = enterDigit();
        if (choice < 60) break;
        cout << "Wrong input! ";
    }
    if (choice >= 0 && choice <= 9) str += "0";
    str += to_string(choice);
    movie.setDurability(str);
    rewriteObjectToFile(MOVIES_DATA_FILE, movie, movie.getId());
    return movie;
}

Movie changeMovieAudience(Movie movie)
{
    string str;
    cout << "Current audience: " << movie.getAudience();
    cout << "\nFrom what age it is allowed to see the movie? ";
    str = enterLineWithCertainSize(2);
    str = enterLineWithCertainSize(2);
    str += "+";
    movie.setAudience(str);
    rewriteObjectToFile(MOVIES_DATA_FILE, movie, movie.getId());
    return movie;
}

Movie changeMovieDescription(Movie movie)
{
    string str;
    cout << "Current description: " << movie.getDescription();
    cout << "\nNew description (up to 255 symbols): ";
    str = enterLineWithCertainSize(255);
    str = enterLineWithCertainSize(255);
    movie.setDescription(str);
    rewriteObjectToFile(MOVIES_DATA_FILE, movie, movie.getId());
    return movie;
}

vector<Movie> showMovieInDetail(vector<Movie> movies)
{
    int id;
    while (true)
    {
        cout << "Enter the number of a movie you would like to see detailed information about, or 0 to exit: ";
        id = enterAnyDigit();
        if (id == 0) return movies;
        if(id > movies.size() || movies[id - 1].getNeedsToBeShown() == 0)
        {
            cout << "Wrong input! ";
            continue;
        }
        else break;
    }
    id--;
    int pos = 1;
    int key;
    while (true)
    {
        system("cls");
        movies[id].showData();
        separator();
        drawMovieChangeMenu(pos);
        key = 0;
        key = _getch();
        switch (key)
        {
        case UP_ENG:
        case UP_RUS:
            if (pos != 1) pos--;
            else pos = 5;
            continue;
        case DOWN_ENG:
        case DOWN_RUS:
            if (pos != 5) pos++;
            else pos = 1;
            continue;
        case ENTER:
            system("cls");
            switch (pos)
            {
            case 1:
                movies[id] = changeName(movies[id]);
                break;
            case 2:
                movies[id] = changeMovieDurability(movies[id]);
                break;
            case 3:
                movies[id] = changeMovieAudience(movies[id]);
                break;
            case 4:
                movies[id] = changeMovieDescription(movies[id]);
                break;
            case 5:
                return movies;
                break;
            }
            break;
        default:
            continue;
        }
        return movies;
    }
}

vector<Movie> deleteMovie(vector<Movie> movies)
{
    int id;
    while (true)
    {
        cout << "Enter the number of a movie you would like to delete, or 0 to exit: ";
        id = enterAnyDigit();
        if (id == 0) return movies;
        if (id > movies.size() || movies[id - 1].getNeedsToBeShown() == 0)
        {
            cout << "Wrong input! ";
            continue;
        }
        else break;
    }
    id--;
    if (movies[id].getUsingCount()> 0)
    {
        cout << "Cannot delete the movie since it is used.\n";
        return movies;
    }
    movies[id].setNeedsToBeShown(0);
    rewriteObjectToFile(MOVIES_DATA_FILE, movies[id], movies[id].getId());
    return movies;
}

vector<Movie> sortMovies(vector<Movie> movies)
{
    int pos = 1;
    int key;
    while (true)
    {
        system("cls");
        drawMovieSortFilterMenu(pos);
        key = _getch();
        switch (key)
        {
        case UP_ENG:
        case UP_RUS:
            if (pos != 1) pos--;
            else pos = 4;
            continue;
        case DOWN_ENG:
        case DOWN_RUS:
            if (pos != 4) pos++;
            else pos = 1;
            continue;
        case ENTER:
            switch (pos)
            {
            case 1:
                sort(movies.begin(), movies.end(), CompareMovieName());
                break;
            case 2:
                sort(movies.begin(), movies.end(), CompareMovieDurability());
                break;
            case 3:
                sort(movies.begin(), movies.end(), CompareMovieAudience());
                break;
            case 4:
                return movies;
            default:
                break;
            }
            break;
        default:
            continue;
        }
        movies = reverseSortingOrNot(movies);
        return movies;
    }
}

vector<Seance> sortSeances(vector<Seance> seances)
{
    int pos = 1;
    int key;
    while (true)
    {
        system("cls");
        drawSeanceSortFilterMenu(pos);
        key = _getch();
        switch (key)
        {
        case UP_ENG:
        case UP_RUS:
            if (pos != 1) pos--;
            else pos = 4;
            continue;
        case DOWN_ENG:
        case DOWN_RUS:
            if (pos != 4) pos++;
            else pos = 1;
            continue;
        case ENTER:
            switch (pos)
            {
            case 1:
                sort(seances.begin(), seances.end(), CompareSeanceDate());
                break;
            case 2:
                sort(seances.begin(), seances.end(), CompareSeanceTime());
                break;
            case 3:
                sort(seances.begin(), seances.end(), CompareSeanceMovie());
                break;
            case 4:
                sort(seances.begin(), seances.end(), CompareSeanceCinema());
                break;
            default:
                break;
            }
            break;
        default:
            continue;
        }
        seances = reverseSortingOrNot(seances);
        return seances;
    }
}

void filterMovies(vector<Movie> movies)
{
    vector<Movie> foundMovies = {};
    int pos = 1;
    int key;
    string str1, str2, str3;
    int number1, number2, number3;
    while (true)
    {
        system("cls");
        drawMovieSortFilterMenu(pos);
        key = _getch();
        switch (key)
        {
        case UP_ENG:
        case UP_RUS:
            if (pos != 1) pos--;
            else pos = 4;
            continue;
        case DOWN_ENG:
        case DOWN_RUS:
            if (pos != 4) pos++;
            else pos = 1;
            continue;
        case ENTER:
            switch (pos)
            {
                system("cls");
            case 1:
                cout << "Enter desired name: ";
                getline(cin, str1);
                str1 = myToLower(str1);
                for (int i = 0; i < movies.size(); i++)
                {
                    str2 = movies[i].getName();
                    str2 = myToLower(str2);
                    if (str2.find(str1) != string::npos)
                        foundMovies.push_back(movies[i]);
                }
                break;
            case 2:
                cout << "Enter lower limit...\n";
                str1 = enterDurabilityForMovie();
                cout << "Enter upper limit...\n";
                str2 = enterDurabilityForMovie();
                for (int i = 0; i < movies.size(); i++)
                {
                    str3 = movies[i].getDurability();
                    if (str3 >= str1 && str3 <= str2) foundMovies.push_back(movies[i]);
                }
                break;
            case 3:
                cout << "Lower age limit: \n";
                number1 = enterDigit();
                cout << "Upper age limit: \n";
                number2 = enterDigit();
                for (int i = 0; i < movies.size(); i++)
                {
                    str3 = movies[i].getAudience();
                    str3.pop_back();
                    number3 = stoi(str3);
                    if (number3 >= number1 && number3 <= number2)
                        foundMovies.push_back(movies[i]);
                }
                break;
            case 4:
                return;
            default:
                break;
            }
            cout << endl;
            if (foundMovies.size() == 0) cout << "\nFound nothing :(\n";
            else
            {
                printMovieTableHeader();
                for (int i = 0; i < foundMovies.size(); i++)
                {
                    std::cout << "\n|| " << setiosflags(ios::left) << setw(4) << i;
                    std::cout << " | " << setw(30) << foundMovies[i].getName();
                    std::cout << " | " << setw(10) << foundMovies[i].getDurability();
                    std::cout << " | " << setw(7) << foundMovies[i].getAudience();
                }
            }
            cout << endl;
            return;
        default:
            continue;
        }
    }
}

void filterSeances(vector<Seance> seances)
{
    vector<Seance> foundSeances = {};
    int pos = 1;
    int key;
    string str1, str2, str3;
    int number1, number2;
    while (true)
    {
        system("cls");
        drawSeanceSortFilterMenu(pos);
        key = _getch();
        switch (key)
        {
        case UP_ENG:
        case UP_RUS:
            if (pos != 1) pos--;
            else pos = 4;
            continue;
        case DOWN_ENG:
        case DOWN_RUS:
            if (pos != 4) pos++;
            else pos = 1;
            continue;
        case ENTER:
            switch (pos)
            {
                system("cls");
            case 1:
                cout << "Enter lower date limit: ";
                str1 = enterDate();
                cout << "Enter upper date limit: ";
                str2 = enterDate();
                if (str2 < str1)
                {
                    str3 = str1;
                    str1 = str2;
                    str2 = str3;
                }
                for (int i = 0; i < seances.size(); i++)
                {
                    str3 = seances[i].getDate();
                    if (str3 > str1 && str3 < str2)
                        foundSeances.push_back(seances[i]);
                }
                break;
            case 2:
                cout << "Entering lower limit...\n";
                str1 = enterTime();
                cout << "Entering upper limit...\n";
                str2 = enterTime();
                for (int i = 0; i < seances.size(); i++)
                {
                    str3 = seances[i].getTime();
                    if (str3 >= str1 && str3 <= str2) foundSeances.push_back(seances[i]);
                }
                break;
            case 3:
                cout << "Enter the name of a movie: \n";
                str1 = enterLineWithCertainSize(29);
                str1 = myToLower(str1);
                for (int i = 0; i < seances.size(); i++)
                    if (toLower(seances[i].getMovieTitle()).find(str1) != string::npos) foundSeances.push_back(seances[i]);
                break;
            case 4:
                cout << "Enter the name of a cinema: \n";
                str1 = enterLineWithCertainSize(14);
                str1 = myToLower(str1);
                for (int i = 0; i < seances.size(); i++)
                    if (toLower(seances[i].getCinemaName()).find(str1) != string::npos) foundSeances.push_back(seances[i]);
                break;
            case 5:
                return;
            default:
                break;
            }
            system("cls");
            if (foundSeances.size() == 0) cout << "\nFound nothing :(\n";
            else
            {
                printSeanceTableHeader();
                showSeanceVector(foundSeances);
            }
            cout << endl;
            system("pause");
            return;
        default:
            continue;
        }
    }
}

void searchMovies(vector<Movie> movies)
{
    vector<Movie> foundMovies;
    string str;
    cout << "Enter something that should be in the title, description or length of the movie: ";
    str = enterLineWithCertainSize(255);
    str = myToLower(str);
    for (int i = 0; i < movies.size(); i++)
    {
        if (myToLower(movies[i].getName()).find(str) != string::npos) foundMovies.push_back(movies[i]); continue;
        if (myToLower(movies[i].getDescription()).find(str) != string::npos) foundMovies.push_back(movies[i]); continue;
        if (myToLower(movies[i].getAudience()).find(str) != string::npos) foundMovies.push_back(movies[i]); continue;
        if (myToLower(movies[i].getDurability()).find(str) != string::npos) foundMovies.push_back(movies[i]); continue;
    }
    separator();
    if (foundMovies.size() == 0)
    {
        cout << "Found nothing :(\n";
        return;
    }
    printMovieTableHeader();
    showMoviesVector(foundMovies);
    cout << endl;
}

void searchCinemas(vector<Cinema> cinemas)
{
    vector<Cinema> foundCinemas;
    string str;
    cout << "Enter the name of a cinema or its adress: ";
    str = enterLineWithCertainSize(255);
    str = myToLower(str);
    for (int i = 0; i < cinemas.size(); i++)
    {
        if (myToLower(cinemas[i].getName()).find(str) != string::npos) foundCinemas.push_back(cinemas[i]); continue;
        if (myToLower(cinemas[i].getAdress()).find(str) != string::npos) foundCinemas.push_back(cinemas[i]); continue;
    }
    separator();
    if (foundCinemas.size() == 0)
    {
        cout << "Found nothing :(\n";
        return;
    }
    printCinemaTableHeader();
    printCinemasFromVector(foundCinemas);
    cout << endl;
}

void searchSeances(vector<Seance> seances)
{
    vector<Seance> foundSeances;
    string str;
    cout << "Enter something that should be in the name of the movie, cinema, or something related to the date or time of the showing: ";
    str = enterLineWithCertainSize(255);
    str = myToLower(str);
    for (int i = 0; i < seances.size(); i++)
    {
        if (myToLower(seances[i].getCinemaName()).find(str) != string::npos) foundSeances.push_back(seances[i]);
        else if (myToLower(seances[i].getMovieTitle()).find(str) != string::npos) foundSeances.push_back(seances[i]);
        else  if (myToLower(seances[i].getDate()).find(str) != string::npos) foundSeances.push_back(seances[i]);
        else  if (myToLower(seances[i].getTime()).find(str) != string::npos) foundSeances.push_back(seances[i]);
    }
    separator();
    if (foundSeances.size() == 0)
    {
        cout << "Found nothing :(\n";
        system("pause");
        return;
    }
    cout << endl;
    printSeanceTableHeader();
    showSeanceVector(foundSeances);
    cout << endl << endl;
    system("pause");
}

void showMoviesVector(vector<Movie> movies)
{
    for (int i = 0; i < movies.size(); i++)
    {
        if (movies[i].getNeedsToBeShown() == 0) continue;
        std::cout << "\n|| " << setiosflags(ios::left) << setw(4) << i + 1;
        std::cout << " | " << setw(30) << movies[i].getName();
        std::cout << " | " << setw(10) << movies[i].getDurability();
        std::cout << " | " << setw(7) << movies[i].getAudience();
    }
}

void showMovieInfo()
{
    int id = 0;
    int pos = 1;
    int key;
    Movie movie;
    while (true)
    {
        vector<Movie> movies = readObjectsFromFile(MOVIES_DATA_FILE, movie);
        movies = onlyShowable(movies);
        system("cls");
        if (movies.size() == 0)
        {
            pos = 1;
            while (true)
            {
                system("cls");
                cout << "Empty here. Would you like to create a movie?\n";
                drawYesNo(pos);
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
                    system("cls");
                    switch (pos)
                    {
                    case 1:
                        try
                        {
                            movie.createNewObject();
                        }
                        catch(AlreadyHere a)
                        {
                            cout << "There is already such an object!\n";
                        }
                        catch (...)
                        {
                            cout << "Oops! An error occured!";
                        }
                        return;
                        break;
                    case 2:
                        return;
                        break;
                    }
                    system("pause");
                    break;
                default:
                    continue;
                }
            }
            system("pause");
            return;
        }
        pos = 1;
        while (true)
        {
            key = 0;
            system("cls");
            drawMovieSelectMenu(pos);
            key = _getch();
            switch (key)
            {
            case UP_ENG:
            case UP_RUS:
                if (pos != 1) pos--;
                else pos = 7;
                continue;
            case DOWN_ENG:
            case DOWN_RUS:
                if (pos != 7) pos++;
                else pos = 1;
                continue;
            case ENTER:
                system("cls");
                switch (pos)
                {
                case 1:
                    printMovieTableHeader();
                    showMoviesVector(movies);
                    separator();
                    try
                    {
                        movies = showMovieInDetail(movies);
                    }
                    catch (...)
                    {
                        break;
                    }
                    break;
                case 2:
                    try
                    {
                       movie.createNewObject();
                    }
                    catch (...)
                    {
                        cout << "Oops! An error occured!";
                        system("pause");
                    }
                    return;
                    break;
                case 3:
                    printMovieTableHeader();
                    showMoviesVector(movies);
                    separator();
                    movies = deleteMovie(movies);
                    break;
                case 4:
                    movies = sortMovies(movies);
                    break;
                case 5:
                    searchMovies(movies);
                    break;
                case 6:
                    filterMovies(movies);
                    break;
                case 7:
                    return;
                    break;
                }
                system("pause");
                break;
            default:
                continue;
            }
        }
    }
}

void showSeanceVector(vector<Seance> seances)
{
    for (int i = 0; i < seances.size(); i++)
    {
        if (seances[i].getNeedsToBeShown() == 0) continue;
        std::cout << "\n|| " << setiosflags(ios::left) << setw(4) << i + 1;
        std::cout << " | " << setw(30) << seances[i].getMovie().getName();
        std::cout << " | " << setw(15) << seances[i].getCinema().getName();
        std::cout << " | " << setw(10) << seances[i].getDate();
        std::cout << " | " << setw(5) << seances[i].getTime();
        std::cout << " | " << setw(3) << seances[i].getHall().getNumber();
    }
}

void changeMovie(Seance& seance, vector<Movie> movies)
{
    printMovieTableHeader();
    showMoviesVector(movies);
    separator();
    int id;
    cout << "Current movie: " << seance.getMovie().getName();
    movies[seance.getMovie().getId ()].addToUsingCount(-1);
    cout << "\nNew movie (number): ";
    while (true)
    {
        id = enterNumber();
        if (id <= movies.size()) break;
        cout << "Wrong input! ";
    }
    id--;
    seance.setMovie(movies[id].getId());
    seance.setMovieTitle(movies[id].getName());
    movies[id].addToUsingCount(1);
    rewriteObjectToFile(MOVIES_DATA_FILE, movies[id], movies[id].getId());
}

void changeDate(Seance& seance)
{
    cout << "Current date: " << seance.getDate();
    cout << "\nNew date..." << endl;
    seance.setDate(enterDate());
}

void changeTime(Seance& seance)
{
    cout << "Current time: " << seance.getTime();
    cout << "\nNew time..." << endl;
    seance.setTime(enterTime());
}

void changeVisibility(Seance& seance)
{
    int choice;
    cout << "Enter 0 to hide from the billboard, or 1 to show on the billboard: ";
    while (true)
    {
        choice = enterDigit();
        if (choice == 1 || choice == 0) break;
        cout << "Wrong input! ";
    }
    if (choice == 0) seance.setNeedsToBeShown(-1);
    else seance.setNeedsToBeShown(1);
}

void changePlace(Seance& seance, vector<Cinema> cinemas)
{
    printCinemaTableHeader();
    printCinemasFromVector(cinemas);
    separator();
    int id;
    Cinema cinema = seance.getCinema();
    cout << "Current cinema: " << cinema.getName();
    cinema.addToUsingCount(-1);
    Hall hall;
    hall = seance.getHall();
    hall.addToUsingCount(-1);
    rewriteObjectToFile(HALLS_DATA_FILE, hall, hall.getId());
    cinemas[cinema.getId()] = cinema;
    cout << "\nNew cinema (number): ";
    while (true)
    {
        id = enterNumber();
        if (id <= cinemas.size()) break;
        cout << "\nWeong input! ";
    }
    id--;
    cinemas[id].addToUsingCount(1);
    writeVectorOfObjectsToFile(CINEMA_DATA_FILE, cinemas);
    seance.setCinema(cinemas[id].getId());
    seance.setCinemaName(cinemas[id].getName());
    system("cls");
    printHallTableHeader();
    vector<Hall> halls = cinemas[id].getHallsVector();
    showHallsVector(halls);
    cout << "\nEnter the hall number: ";
    while (true)
    {
        id = enterNumber();
        if (id <= halls.size()) break;
        cout << "\nWrong input! ";
    }
    id--;
    seance.setHall(halls[id].getId());
    halls[id].addToUsingCount(1);
    rewriteObjectToFile(HALLS_DATA_FILE, halls[id], id);
}

vector<Seance> showSeanceInDetail(vector<Seance> seances, vector<Movie> movies, vector<Cinema> cinemas)
{
    int id;
    while (true)
    {
        cout << "Enter the number of a showing zou would like to see detailed information about, or enter 0 to exit: ";
        id = enterAnyDigit();
        if (id == 0) return seances;
        if (id > seances.size())
        {
            cout << "Wrong input!\n";
            system("pause");
            continue;
        }
        else break;
    }
    id--;
    int pos = 1;
    int key;
    while (true)
    {
        system("cls");
        seances[id].showData();
        separator();
        drawSeanceChangeMenu(pos);
        key = 0;
        key = _getch();
        switch (key)
        {
        case UP_ENG:
        case UP_RUS:
            if (pos != 1) pos--;
            else pos = 6;
            continue;
        case DOWN_ENG:
        case DOWN_RUS:
            if (pos != 6) pos++;
            else pos = 1;
            continue;
        case ENTER:
            system("cls");
            switch (pos)
            {
            case 1:
                if (seances[id].getUsingCount() > 0)
                {
                    cout << "Cannot cancel the showing! ";
                    system("pause");
                    return seances;
                }
                changeMovie(seances[id], movies);
                break;
            case 2:
                if (seances[id].getUsingCount() > 0)
                {
                    cout << "Cannot cancel the showing! ";
                    system("pause");
                    return seances;
                }
                changeDate(seances[id]);
                break;
            case 3:
                if (seances[id].getUsingCount() > 0)
                {
                    cout << "Cannot cancel the showing! ";
                    system("pause");
                    return seances;
                }
                changeTime(seances[id]);
                break;
            case 4:
                if (seances[id].getUsingCount() > 0)
                {
                    cout << "Cannot cancel the showing! ";
                    system("pause");
                    return seances;
                }
                changePlace(seances[id], cinemas);
                break;
            case 5:
                changeVisibility(seances[id]);
                break;
            case 6:
                break;
            }
            rewriteObjectToFile(SEANCES_DATA_FILE, seances[id], seances[id].getId());
            return seances;
            break;
        default:
            continue;
        }
        break;
    }
}

vector<Seance> deleteSeance(vector<Seance> seances)
{
    int id;
    while (true)
    {
        cout << "Enter the number of a showing you would like to delete: ";
        id = enterAnyDigit();
        if (id > seances.size())
        {
            cout << "Wrong input!\n";
            system("pause");
            continue;
        }
        else break;
    }
    id--;
    if (seances[id].getHaveTickets() > 0)
    {
        cout << "Cannot delete the showing since it is used.\n";
        system("pause");
        return seances;
    }
    seances[id].setNeedsToBeShown(0);
    writeVectorOfObjectsToFile(SEANCES_DATA_FILE, seances);
    return seances;
}



void showTicketsVector(vector<pair<vector<double>, vector<Ticket>>> vec)
{
    int kol = vec.size();
    Seance s;
    for(int i = 0; i < kol; i++)
    {
        if (vec[i].first[5] == 0) continue;
        s = vec[i].second[0].getSeance();
        std::cout << "\n|| " << setiosflags(ios::left) << setw(4) << i + 1;
        std::cout << " | " << setw(30) << s.getMovie().getName();
        std::cout << " | " << setw(15) << s.getCinema().getName();
        std::cout << " | " << setw(10) << s.getDate();
        std::cout << " | " << setw(5) << s.getTime();
        std::cout << " | " << setw(3) << s.getHall().getNumber();
        std::cout << " | " << setw(6);
        if (vec[i].first[0] == -1) cout << "-";
        else cout << vec[i].first[0];
        std::cout << " | " << setw(6);
        if (vec[i].first[1] == -1) cout << "-";
        else cout << vec[i].first[1];
        std::cout << " | " << setw(6);
        if (vec[i].first[2] == -1) cout << "-";
        else cout << vec[i].first[2];
    }
}

pair<vector<double>, vector<Ticket>> ticketEditing(pair<vector<double>, vector<Ticket>> p)
{
    int pos = 1;
    int key = 0;
    double st = p.first[0];
    double comf = p.first[1];
    double vip = p.first[2];
    double choice;
    while (true)
    {
        system("cls");
        drawTicketEditMenu(pos);
        key = _getch();
        switch (key)
        {
        case UP_ENG:
        case UP_RUS:
            if (pos != 1) pos--;
            else pos = 4;
            continue;
        case DOWN_ENG:
        case DOWN_RUS:
            if (pos != 4) pos++;
            else pos = 1;
            continue;
        case ENTER:
            system("cls");
            switch (pos)
            {
            case 1:
                if (st == -1) { cout << "No such tickets!\n"; break; }
                cout << "Current price: " << st;
                cout << "\nNew price: ";
                while (true)
                {
                    choice = enterDouble();
                    if (choice > 0 && choice < 99999) break;
                    cout << "Wrong input! ";
                }
                st = choice;
                break;
            case 2:
                if (comf == -1) { cout << "No such tickets!\n"; break; }
                cout << "Current price: " << comf;
                cout << "\nNew price: ";
                while (true)
                {
                    choice = enterDouble();
                    if (choice > 0 && choice < 99999) break;
                    cout << "Wrong input! ";
                }
                comf = choice;
                break;
            case 3:
                if (vip == -1) { cout << "No such tickets!\n"; break; }
                cout << "Current price: " << vip;
                cout << "\nNew price: ";
                while (true)
                {
                    choice = enterDouble();
                    if (choice > 0 && choice < 99999) break;
                    cout << "Wrong input! ";
                }
                vip = choice;
                break;
            case 4:
                p.first[0] = st;
                p.first[1] = comf;
                p.first[2] = vip;
                return p;
                break;
            }
            system("pause");
            break;
        default:
            continue;
        }
    }
}

vector<pair<vector<double>, vector<Ticket>>> editTickets(vector<pair<vector<double>, vector<Ticket>>> vec)
{
    int choice;
    cout << "The price of what set of tickets would you like to change? Enter 0 to exit: ";
    while (true)
    {
        choice = enterDigit();
        if (choice == 0) return vec;
        if (choice > vec.size() || vec[choice - 1].first[5] == 0)
        {
            cout << "Wrong input! ";
            continue;
        }
        break;
    }
    vec[choice - 1] = ticketEditing(vec[choice - 1]);
    writeVectorOfObjectsToFile(TICKETS_DATA_FILE, vec);
    return vec;
}

void ticketViewing(pair<vector<double>, vector<Ticket>> p)
{
    vector<double> a = p.first;
    vector<Ticket> tickets = p.second;
    Hall h = tickets[0].getSeance().getHall();
    int M = h.getM();
    int N = h.getN();
    int num = 0;
    cout << endl << endl;
    int cap = capacity(N);
    cout << " ";
    for (int i = 0; i < cap; i++) cout << " ";
    for (int i = 1; i <= M; i++) cout << i << " ";
    for (int i = 0; i < N; i++)
    {
        cout << "\n";
        cout << i + 1 << " ";
        for (int j = 0; j < M; j++, num++)
        {
            if (tickets[num].getStatus() == 0)  colorChanging(LIME);
            else if (tickets[num].getStatus() == 1) colorChanging(RED);
            switch (h.getPlaces()[i][j].getClassOfPlace())
            {
            case 1:
                cout << "S ";
                break;
            case 2:
                cout << "C ";
                break;
            case 3:
                cout << "V ";
            }
            colorChanging(WHITE);
        }
        cout << endl;
    }
    separator();
    cout << "S - standard: ";
    a[0] == -1 ? cout << "X" : cout << a[0];
    cout << " eur, C - comfort: ";
    a[1] == -1 ? cout << "X" : cout << a[1];
    cout << " eur, V - VIP: ";
    a[2] == -1 ? cout << "X" : cout << a[2];
    cout << " eur; ";
    colorChanging(LIME);
    cout << "free, ";
    colorChanging(RED);
    cout << "occupied.\n";
    colorChanging(WHITE);
}

void showTicketsInDetail(vector<pair<vector<double>, vector<Ticket>>> vec)
{
    int choice;
    cout << "What set or tickets would you like to see in detail? Press 0 to exit: ";
    while (true)
    {
        choice = enterDigit();
        if (choice > vec.size() || vec[choice - 1].first[5] == 0)
        {
            cout << "Wrong input! ";
            continue;
        }
        break;
    }
    ticketViewing(vec[choice - 1]);
}

void showTickets()
{
    int id = 0;
    int pos = 1;
    int key;
    Ticket t;
    Seance s;
    Cinema c;
    vector<pair<vector<double>, vector<Ticket>>> ticketsVec = {};
    vector<Ticket> tickets = {};
    vector<Seance> seances = readObjectsFromFile(SEANCES_DATA_FILE, s);
    seances = onlyShowable(seances);
    vector<Cinema> cinemas = readObjectsFromFile(CINEMA_DATA_FILE, c);
    cinemas = onlyShowable(cinemas);
    while (true)
    {
        ticketsVec = readObjectsFromFile(TICKETS_DATA_FILE, ticketsVec);
        system("cls");
        if (ticketsVec.size() == 0)
        {
            cout << "Empty here. WOuld you like to register tickets?\n";
            drawYesNo(pos);
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
                system("cls");
                switch (pos)
                {
                case 1:
                    try
                    {
                        t.createTicketsForSeance(seances, cinemas);
                    }
                    catch (...)
                    {
                        cout << "Oops! An error occured!";
                    }
                    return;
                    break;
                case 2:
                    return;
                    break;
                }
                system("pause");
                break;
            default:
                continue;
            }
        }
        pos = 1;
        while (true)
        {
            key = 0;
            system("cls");
            drawTicketSelectMenu(pos);
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
                    try
                    {
                        t.createTicketsForSeance(seances, cinemas);
                    }
                    catch (...)
                    {
                        cout << "Oops! An error occured!";
                        system("pause");
                    }
                    return;
                    break;
                case 2:
                    printTicketTableHeader();
                    showTicketsVector(ticketsVec);
                    separator();
                    ticketsVec = editTickets(ticketsVec);
                    break;
                case 3:
                    return;
                    break;
                }
                system("pause");
                break;
            default:
                continue;
            }
        }
    }
}

void showSeancesInfo()
{
    int id = 0;
    int pos = 1;
    int key;
    Seance seance;
    Movie movie;
    Cinema cinema;
    vector<Movie> movies = readObjectsFromFile(MOVIES_DATA_FILE, movie);
    movies = onlyShowable(movies);
    vector<Cinema> cinemas = readObjectsFromFile(CINEMA_DATA_FILE, cinema);
    cinemas = onlyShowable(cinemas);
    while (true)
    {
        vector<Seance> seances = readObjectsFromFile(SEANCES_DATA_FILE, seance);
        seances = onlyShowable(seances);
        system("cls");
        if (movies.size() == 0 || cinemas.size() == 0)
        {
            cout << "There is no movies and/or cinemas in the database!\n";
            system("pause");
            return;
        }
        if (seances.size() == 0)
        {
            pos = 1;
            while (true)
            {
                system("cls");
                cout << "Empty here. Would you like to create a showing?\n";
                drawYesNo(pos);
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
                    system("cls");
                    switch (pos)
                    {
                    case 1:
                        try
                        {
                            seance.createNewObject(movies, cinemas);
                        }
                        catch (AlreadyHere a)
                        {
                            cout << "There is already such an object!\n";
                        }
                        catch (...)
                        {
                            cout << "Oops! An error ocured!";
                        }
                        return;
                        break;
                    case 2:
                        return;
                        break;
                    }
                    system("pause");
                    break;
                default:
                    continue;
                }
            }
            system("pause");
            return;
        }
        pos = 1;
        while (true)
        {
            seances = onlyShowable(seances);
            key = 0;
            system("cls");
            drawSeanceSelectMenu(pos);
            key = _getch();
            switch (key)
            {
            case UP_ENG:
            case UP_RUS:
                if (pos != 1) pos--;
                else pos = 7;
                continue;
            case DOWN_ENG:
            case DOWN_RUS:
                if (pos != 7) pos++;
                else pos = 1;
                continue;
            case ENTER:
                system("cls");
                switch (pos)
                {
                case 1:
                    printSeanceTableHeader();
                    showSeanceVector(seances);
                    separator();
                    try
                    {
                        seances = showSeanceInDetail(seances, movies, cinemas);
                    }
                    catch (...)
                    {
                        break;
                    }
                    break;
                case 2:
                    try
                    {
                        seance.createNewObject(movies, cinemas);
                    }
                    catch (...)
                    {
                        cout << "Oops! An error ocured!";
                        system("pause");
                    }
                    return;
                    break;
                case 3:
                    printSeanceTableHeader();
                    showSeanceVector(seances);
                    separator();
                    seances = deleteSeance(seances);
                    break;
                case 4:
                    seances = sortSeances(seances);
                    break;
                case 5:
                    searchSeances(seances);
                    break;
                case 6:
                    filterSeances(seances);
                    break;
                case 7:
                    return;
                    break;
                }
                break;
            default:
                continue;
            }
        }
    }
}

void showAfishaTable(vector<Seance> seances)
{
    for (int i = 0; i < seances.size(); i++)
    {
        if (seances[i].getNeedsToBeShown() == 0) continue;
        std::cout << "\n|| " << setiosflags(ios::left) << setw(4) << i + 1;
        std::cout << " | " << setw(30) << seances[i].getMovie().getName();
        std::cout << " | " << setw(15) << seances[i].getCinema().getName();
        std::cout << " | " << setw(10) << seances[i].getDate();
        std::cout << " | " << setw(5) << seances[i].getTime();
        std::cout << " | " << setw(3) << seances[i].getHall().getNumber();
    }
}

vector<Seance> onlyShowable(vector<Seance> seances)
{
    vector<Seance> showable;
    int size = seances.size();
    for (int i = 0; i < size; i++) if (seances[i].getNeedsToBeShown() == 1 || seances[i].getNeedsToBeShown() == -1) showable.push_back(seances[i]);
    return showable;
}

vector<Seance> onlyShowableAfisha(vector<Seance> seances)
{
    vector<Seance> showable;
    int size = seances.size();
    for (int i = 0; i < size; i++) if (seances[i].getNeedsToBeShown() == 1 && seances[i].getUsingCount() > 0) showable.push_back(seances[i]);
    return showable;
}

vector<Movie> onlyShowable(vector<Movie> movies)
{
    vector<Movie> showable;
    int size = movies.size();
    for (int i = 0; i < size; i++) if (movies[i].getNeedsToBeShown() == 1) showable.push_back(movies[i]);
    return showable;
}

vector<Cinema> onlyShowable(vector<Cinema> cinemas)
{
    vector<Cinema> showable;
    int size = cinemas.size();
    for (int i = 0; i < size; i++) if (cinemas[i].getNeedsToBeShown() == 1) showable.push_back(cinemas[i]);
    return showable;
}

void showAfishaInDetail(Seance seance)
{
    int choice;
    Cinema cinema = seance.getCinema();
    changeColor(LIME);
    cout << "Cinema: " << cinema.getName() << endl;
    changeColor(WHITE);
    cout << "Hall: " << seance.getHall().getNumber();
    separator();
    cout << "Date: " << seance.getDate() << "\t\t" << "Time: " << seance.getTime();
    separator();
    Movie movie = seance.getMovie();
    changeColor(LIME);
    cout << "~~~" << movie.getName() << "~~~\n";
    changeColor(WHITE);
    cout << "Description: " << movie.getDescription() << endl;
    cout << "Duration: " << movie.getDurability() << endl;
    cout << "Audience: " << movie.getAudience();
    separator();
}

User showAfisha(User user)
{
    Seance s;
    vector<Seance> seancesList;
    Seance seance;
    vector<pair<vector<double>, vector<Ticket>>> tickets;
    pair<vector<double>, vector<Ticket>> p;
    Order order;
    order.setIdOfLastObjectPlusOne(order);
    order.setUsingCount(0);
    order.setNeedsToBeShown(0);
    order.setStatus(0);
    Hall hall;
    int choice;
    int key;
    int pos = 1;
    int toExit = 0;
    int number;
    int id;
    int choiceN, choiceM;
    while (true)
    {
        seancesList = readObjectsFromFile(SEANCES_DATA_FILE, s);
        seancesList = onlyShowableAfisha(seancesList);
        tickets = readObjectsFromFile(TICKETS_DATA_FILE, tickets);
        system("cls");
        if (seancesList.size() == 0)
        {
            cout << "Empty here! But do not worry, please return sooner :)\n";
            system("pause");
            return user;
        }
        printAfishaHeader();
        showAfishaTable(seancesList);
        separator();
        cout << "Enter the number of a showing you would like to see detailed information about, or enter 0 to exit: ";
        while (true)
        {
            choice = enterDigit();
            if (choice == 0)
            {
                while (true)
                {
                    if (toExit == 1) break;
                    key = 0;
                    system("cls");
                    drawAfishaMenu(pos);
                    key = _getch();
                    switch (key)
                    {
                    case UP_ENG:
                    case UP_RUS:
                        if (pos != 1) pos--;
                        else pos = 5;
                        continue;
                    case DOWN_ENG:
                    case DOWN_RUS:
                        if (pos != 5) pos++;
                        else pos = 1;
                        continue;
                    case ENTER:
                        switch (pos)
                        {
                        case 1:
                            searchSeances(seancesList);
                            break;
                        case 2:
                            filterSeances(seancesList);
                            break;
                        case 3:
                            seancesList = sortSeances(seancesList);
                            break;
                        case 4:
                            toExit = 1;
                            break;
                        case 5:
                            return user;
                        }
                        break;
                    default:
                        continue;
                    }
                }
                if (toExit == 1) break;
            }
            if (choice <= seancesList.size()) break;
            cout << "Wrong input! ";
        }
        if (toExit == 1)
        {
            toExit = 0;
            continue;
        }
        choice--;
        seance = seancesList[choice];
        system("cls");
        showAfishaInDetail(seance);
        unique_ptr<Hall> hall = seance.getHallPointer();
        cout << "Enter 1 to exit or 2 to order tickets: ";
        while (true)
        {
            choice = enterDigit();
            if (choice == 2 || choice == 1) break;
            cout << "Wrong input! ";
        }
        if (choice == 1) continue;
        system("cls");
        for (id = 0; id < tickets.size(); id++)
            if (tickets[id].second[0].getSeanceInt() == seance.getId()) break;
        p = tickets[id];
        while (true)
        {
            system("cls");
            ticketViewing(p);
            cout << "Enter 0 to exit. Which row? ";
            while (true)
            {
                choiceN = enterDigit();
                if (choiceN == 0)
                {
                    if (order.getTickets().size() > 0)
                    {
                        tickets[id] = p;
                        order.setUsingCount(1);
                        order.setNeedsToBeShown(1);
                        order.setIdOfLastObjectPlusOne(order);
                        writeNewObjectToFile(ORDERS_DATA_FILE, order);
                        writeVectorOfObjectsToFile(TICKETS_DATA_FILE, tickets);
                        user.addOrder(order.getId());
                        rewriteObjectToFile(USER_DATA_FILE, user, user.getId());
                    }
                    return user;
                }
                if (choiceN <= hall->getN()) break;
                cout << "Wrong input! ";
            }
            choiceN--;
            cout << "Enter 0 to exit. Which place? ";
            while (true)
            {
                choiceM = enterDigit();
                if (choiceM == 0)
                {
                    if (order.getTickets().size() > 0)
                    {
                        tickets[id] = p;
                        writeNewObjectToFile(ORDERS_DATA_FILE, order);
                        writeVectorOfObjectsToFile(TICKETS_DATA_FILE, tickets);
                        user.addOrder(order.getId());
                        rewriteObjectToFile(USER_DATA_FILE, user, user.getId());
                    }
                    return user;
                }
                if (choiceM <= hall->getN()) break;
                cout << "Wrong input! ";
            }
            choiceM--;
            number = choiceN * hall->getM() + choiceM;
            if (p.second[number].getStatus() == 1)
            {
                cout << "The place is occupied!\n";
                system("pause");
                continue;
            }
            p.second[number].setStatus(1);
            order.addTicket(p.second[number]);
            cout << "Success!\n";
            system("pause");
        }
    }
}


void createACheck(Order order, string name)
{
    ofstream fout;
    int size;
    double sum;
    vector<Ticket> tickets;
    fout.open("Checks\\Checks" + name + ".txt", ios::app);
    fout << "~~~~Receipt. PAID~~~~~\n";
    fout << "----------------------------------------";
    tickets = order.getTickets();
    size = tickets.size();
    sum = 0;
    for (int i = 0; i < size; i++)
    {
        Seance seance = tickets[i].getSeance();
        Hall hall = tickets[i].getHall();
        fout << "\nCinema: " << seance.getCinema().getName();
        fout << "\nMovie: " << seance.getMovie().getName();
        fout << "\nDate: " << seance.getDate();
        fout << "\nTime: " << seance.getTime();
        string coordinates = hall.getCoordinatesOfPlace(tickets[i].getPlace());
        fout << "\nHall: " << hall.getNumber() << "; row: ";
        if (coordinates.size() == 5)
            fout << coordinates[0] + coordinates[1] << ", place: " << coordinates[3] + coordinates[4] << endl;
        else if (coordinates.size() == 3)
            fout << coordinates[0] << ", place: " << coordinates[2] << endl;
        sum += tickets[i].getPrice();
        fout << "\n-----------------\n";
    }
    fout << "Sum: " << sum << " eur.\n";
    fout << "Thank you for your support. Enjoy! :)\n\n";
}

vector<Report> readReportsFromFile()
{
    ifstream fin;
    Report report;
    vector<Report> reports;
    fin.open(MOVIE_REPORT_FILE);
    while (true)
    {
        try
        {
            fin >> report;
        }
        catch (...)
        {
            break;
        }
        reports.push_back(report);
    }
    fin.close();
    return reports;
}

void UpdateReport(Movie movie, double price, int count)
{
    vector<Report> reports = readReportsFromFile();
    int found = 0;
    double money;
    int kol;
    Report report;
    for (int i = 0; i < reports.size(); i++)
    {
        if (reports[i].getMovieName() == movie.getName())
        {
            money = reports[i].getMoney();
            kol = reports[i].getBilets();
            found = 1;
            reports[i].setMoney(money + price);
            reports[i].setBilets(count + kol);
            break;
        }
    }
    if (found == 0)
    {
        report.setMovie(movie.getId());
        report.setBilets(count);
        report.setMoney(price);
        reports.push_back(report);
    }
    writeVectorOfObjectsToFile(MOVIE_REPORT_FILE, reports);
}

vector<Movie> mergeVectors(vector<Movie> biggerOne, vector<Movie> smallerOne)
{
    int size = smallerOne.size();
    for (int i = 0; i < size; i++)
        biggerOne[smallerOne[i].getId()] = smallerOne[i];
    return biggerOne;
}

Report mostPopularMovie(vector<Report> reports)
{
    Report temp;
    int max = reports[0].getBilets();
    int ind = 0;
    for (int i = 1; i < reports.size(); i++)
    {
        if (reports[i].getBilets() > max)
        {
            max = reports[i].getBilets();
            ind = i;
        }
    }
    return reports[ind];
}

Report mostMoneyMovie(vector<Report> reports)
{
    Report temp;
    double max = reports[0].getMoney();
    int ind = 0;
    for (int i = 0; i < reports.size(); i++)
    {
        if (reports[i].getMoney() > max)
        {
            max = reports[i].getMoney();
            ind = i;
        }
    }
    return reports[ind];
}

void showStatistics()
{
    vector<Report> reports = readReportsFromFile();
    Report r;
    system("cls");
    if (reports.size() == 0)
    {
        cout << "No statistics! :(\n";
        system("pause");
        return;
    }
    printHeader("Movie statistics", LIME);
    r = mostPopularMovie(reports);
    cout << "The most popular movie: " << r.getMovieName() << ", tickets bought: " << r.getBilets() << ", money got: " << r.getMoney() << endl;
    r = mostMoneyMovie(reports);
    cout << "Highest grossing movie: " << r.getMovieName() << ", money got: " << r.getMoney() << ", tickets bought: " << r.getBilets() << endl;
    cout << endl;
    system("pause");
}

