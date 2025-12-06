#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Classes.h"
#include "Drawings.h"
#include "Menus.h"
#include "LoginRegister.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int pos = 1;
    int key = 0;
    int result = -1;
    string name;
    User client;
    while (true)
    {
        key = 0;
        system("cls");
        drawFirstLogo(pos);
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
                result = loginmenu(client);
                switch (result)
                {
                case -1:
                    system("pause");
                    continue;
                case 0:
                    User::increaseLoggedIn();
                    UserMenu(client);
                    break;
                case 1:
                    User::increaseLoggedIn();
                    CashierMenu(client);
                    break;
                case 2:
                    User::increaseLoggedIn();
                    AdminMenu(client);
                    break;
                case 3:
                    User::increaseLoggedIn();
                    SeanceManagerMenu(client);
                    break;
                case 4:
                    User::increaseLoggedIn();
                    ContentManagerMenu(client);
                    break;
                }
                break;
            case 2:
                client = registermenu(); 
                switch (client.getRole())
                {
                case -1:
                    system("pause");
                    continue;
                case 0:
                    User::increaseLoggedIn();
                    UserMenu(client);
                    break;
                case 1:
                    User::increaseLoggedIn();
                    CashierMenu(client);
                    break;
                case 2:
                    User::increaseLoggedIn();
                    AdminMenu(client);
                    break;
                case 3:
                    User::increaseLoggedIn();
                    SeanceManagerMenu(client); 
                    break;
                case 4:
                    User::increaseLoggedIn();
                    ContentManagerMenu(client);
                    break;
                }
                break;
            case 3:
                writeReportInFile(); 
                return 0;
                break;
            }
            break;
        default:
            continue;
        }
    }
}

