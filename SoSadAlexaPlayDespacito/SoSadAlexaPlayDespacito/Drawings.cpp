#include <iostream>
#include <windows.h>

#include "Constants.h"
#include "Decor.h"
#include "Drawings.h"

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void drawFirstLogo(int pos)
{
	cout << "                 :^~!!!~^:  :^^.                                                                              " << endl;
	cout << "             ^?PB&@@@@@@@&#PY?JPB5!.                                                                          " << endl;
	cout << "          .7G@@@@@B?~~!Y#@@@@@GJ?G@&5~                                                                        " << endl;
	cout << "         7#@@@@@@J      .G@@@@@@#?7#@@G^                                                                      " << endl;
	cout << "       :G@@@@@@@#        ^@@@@@@@@G~YPPY!!?J7~!7~.                                                            " << endl;
	cout << "      ^#@@@@@@@@#.       ~@@@@@@@@@&^!###P::~J!~~J7                                                           " << endl;
	cout << "     :#@@P?!7JB@@P.     ^#@@P?!7JB@@&^P@@@5  !Y.:^P?                                                          " << endl;
	cout << "     P@&~      ?@@&5?7JP@@&~      ?@@G:&@@@7  G!:::G. .:^~!!7??Y7                                             " << endl;
	cout << "    ~@@?        P@@@@@@@@@?        P@@~J@@@B  57...P^ ?&?!!~^^:YB                  Welcome!                   " << endl;
	cout << "    Y@@?        P@@@&B&@@@7        P@@5^@@@@^ YY^^^P^ ~@^      !&.       What would you like to do now:       " << endl;
	cout << "    P@@&~      ?@@@#: :#@@#~      ?@@@G:&@@@! 5!   5: .@?      :@~                                            " << endl;
	switch (pos)
	{
	case 1:
		cout << "    P@@@@P?!!JB@@@@&!:!&@@@@P?!!JG@@@@G:&@@@! G?~~!G.  BY       #7     ";
		changeColor(YELLOW);
		cout << ">   Log in into existing account       " << endl;
		changeColor(WHITE);
		cout << "    J@@@@@@@@@&#&@@@@@@@@@&#@@@@@@@@@@Y~@@@@^:B.  :5   PG.:^^^~~#Y         Register                           " << endl;
		cout << "    ^@@@@@@@5~...~5@@@@&J^..:!G@@@@@@@~Y@@@B 7P . !Y   Y&777!!!~GP         Exit                               " << endl;
		break;
	case 2:
		cout << "    P@@@@P?!!JB@@@@&!:!&@@@@P?!!JG@@@@G:&@@@! G?~~!G.  BY       #7         Log in into existing account       " << endl;
		cout << "    J@@@@@@@@@&#&@@@@@@@@@&#@@@@@@@@@@Y~@@@@^:B.  :5   PG.:^^^~~#Y     ";
		changeColor(YELLOW);
		cout << ">   Register                           " << endl;
		changeColor(WHITE);
		cout << "    ^@@@@@@@5~...~5@@@@&J^..:!G@@@@@@@~Y@@@B 7P . !Y   Y&777!!!~GP         Exit                               " << endl;
		break;
	case 3:
		cout << "    P@@@@P?!!JB@@@@&!:!&@@@@P?!!JG@@@@G:&@@@! G?~~!G.  BY       #7         Log in into existing account       " << endl;
		cout << "    J@@@@@@@@@&#&@@@@@@@@@&#@@@@@@@@@@Y~@@@@^:B.  :5   PG.:^^^~~#Y         Register                 " << endl;
		cout << "    ^@@@@@@@5~...~5@@@@&J^..:!G@@@@@@@~Y@@@B 7P . !Y   Y&777!!!~GP     ";
		changeColor(YELLOW);
		cout << ">   Exit                               " << endl;
		changeColor(WHITE);
		break;
	}
	cout << "     5@@@@@?       ?@@&~       P@@@@@P:&@@@! GJ~~~Y7   ?&       JG                                            " << endl;
	cout << "     .B@@@&.       .&@P        ~@@@@#:P@@@Y ^B.   Y~   7&.      ?B                                            " << endl;
	cout << "      :B@@@~       ~@@#.       J@@@#^5@@@Y  ?5    P^   7@.      7#                                            " << endl;
	cout << "       .P@@#!.   .7&@@@G^    .J@@@P~P@@&?   PY!!!!B:   7@7!777?7P#             W - up                         " << endl;
	cout << "         !B@@#P5P#@@@@@@@BP5G&@@B77&@@P^   .B:    G^   ?&~^^::. J#             S - down                       " << endl;
	cout << "           !P&@@@@@@@@@@@@@@@&P??B@#Y^     ^B     G~   YB       5G                                            " << endl;
	cout << "             :7YG#&@@@@@&#B5J?YPGJ~.       ^#~~~~~55   G5       #Y                                            " << endl;
	cout << "                 .:^~~~^:.  :^:.            B7:::..57 .&?:^^~~~?&^                                            " << endl;
	cout << "                                            !G.     ?YY#7!!!~~7#7                                             " << endl;
	cout << "                                             7P7!!!!!P&Y!~^^^!?^                                              " << endl;
	cout << "                                              .7J?!~~7: .:^::.                                                " << endl;
}


void drawUserMenu(int pos)
{
	printHeader("Menu", 13);
	switch (pos)
	{
	case 1:
		changeColor(YELLOW);
		cout << ">   Check the billboard\n";
		changeColor(WHITE);
		cout << "    Check order history\n";
		cout << "    Check account information\n";
		cout << "    Log out\n";
		break;
	case 2:
		cout << "    Check the billboard\n";
		changeColor(YELLOW);
		cout << ">   Check order history\n";
		changeColor(WHITE);
		cout << "    Check account information\n";
		cout << "    Log out\n";
		break;
	case 3:
		cout << "    Check the billboard\n";
		cout << "    Check order history\n";
		changeColor(YELLOW);
		cout << ">   Check account information\n";
		changeColor(WHITE);
		cout << "    Log out\n";
		break;
	case 4:
		cout << "    Check the billboard\n";
		cout << "    Check order history\n";
		cout << "    Check account information\n";
		changeColor(YELLOW);
		cout << ">   Log out\n";
		changeColor(WHITE);
		break;
	}
	cout << "\n  W - up\n";
	cout << "  S - down\n";
}

void drawCashierMenu(int pos)
{
	printHeader("Menu", 13);
	switch (pos)
	{
	case 1:
		changeColor(YELLOW);
		cout << ">   Check the billboard\n";
		changeColor(WHITE);
		cout << "    Check order history\n";
		cout << "    Check account information\n";
		cout << "    Check ticket information\n";
		cout << "    Log out\n";
		break;
	case 2:
		cout << "    Check the billboard\n";
		changeColor(YELLOW);
		cout << ">   Check order history\n";
		changeColor(WHITE);
		cout << "    Check account information\n";
		cout << "    Check ticket information\n";
		cout << "    Log out\n";
		break;
	case 3:
		cout << "    Check the billboard\n";
		cout << "    Check order history\n";
		changeColor(YELLOW);
		cout << ">   Check account information\n";
		changeColor(WHITE);
		cout << "    Check ticket information\n";
		cout << "    Log out\n";
		break;
	case 4:
		cout << "    Check the billboard\n";
		cout << "    Check order history\n";
		cout << "    Check account information\n";
		changeColor(YELLOW);
		cout << ">   Check ticket information\n";
		changeColor(WHITE);
		cout << "    Log out\n";
		break;
	case 5:
		cout << "    Check the billboard\n";
		cout << "    Check order history\n";
		cout << "    Check account information\n";
		cout << "    Check ticket information\n";
		changeColor(YELLOW);
		cout << ">   Log out\n";
		changeColor(WHITE);
		break;
	}
	cout << "\n  W - up\n";
	cout << "  S - down\n";
}

void drawSeanceManagerMenu(int pos)
{
	printHeader("Menu", 13);
	switch (pos)
	{
	case 1:
		changeColor(YELLOW);
		cout << ">   Check the billboard\n";
		changeColor(WHITE);
		cout << "    Check order history\n";
		cout << "    Check account information\n";
		cout << "    Check showings information\n";
		cout << "    Check ticket information\n";
		cout << "    Log out\n";
		break;
	case 2:
		cout << "    Check the billboard\n";
		changeColor(YELLOW);
		cout << ">   Check order history\n";
		changeColor(WHITE);
		cout << "    Check account information\n";
		cout << "    Check showings information\n";
		cout << "    Check ticket information\n";
		cout << "    Log out\n";
		break;
	case 3:
		cout << "    Check the billboard\n";
		cout << "    Check order history\n";
		changeColor(YELLOW);
		cout << ">   Check account information\n";
		changeColor(WHITE);
		cout << "    Check showings information\n";
		cout << "    Check ticket information\n";
		cout << "    Log out\n";
		break;
	case 4:
		cout << "    Check the billboard\n";
		cout << "    Check order history\n";
		cout << "    Check account information\n";
		changeColor(YELLOW);
		cout << ">   Check showings information\n";
		changeColor(WHITE);
		cout << "    Check ticket information\n";
		cout << "    Log out\n";
		break;
	case 5:
		cout << "    Check the billboard\n";
		cout << "    Check order history\n";
		cout << "    Check account information\n";
		cout << "    Check showings information\n";
		changeColor(YELLOW);
		cout << ">    Check ticket information\n";
		changeColor(WHITE);
		cout << "    Log out\n";
		break;
	case 6:
		cout << "    Check the billboard\n";
		cout << "    Check order history\n";
		cout << "    Check account information\n";
		cout << "    Check showings information\n";
		cout << "    Check ticket information\n";
		changeColor(YELLOW);
		cout << ">   Log out\n";
		changeColor(WHITE);
		break;
	}
	cout << "\n  W - up\n";
	cout << "  S - down\n";
}

void drawContentManagerMenu(int pos)
{
	printHeader("Menu", 13);
	switch (pos)
	{
	case 1:
		changeColor(YELLOW);
		cout << ">   Check the billboard\n";
		changeColor(WHITE);
		cout << "    Check order history\n";
		cout << "    Check account information\n";
		cout << "    Check movies information\n";
		cout << "    Log out\n";
		break;
	case 2:
		cout << "    Check the billboard\n";
		changeColor(YELLOW);
		cout << ">   Check order history\n";
		changeColor(WHITE);
		cout << "    Check account information\n";
		cout << "    Check movies information\n";
		cout << "    Log out\n";
		break;
	case 3:
		cout << "    Check the billboard\n";
		cout << "    Check order history\n";
		changeColor(YELLOW);
		cout << ">   Check account information\n";
		changeColor(WHITE);
		cout << "    Check movies information\n";
		cout << "    Log out\n";
		break;
	case 4:
		cout << "    Check the billboard\n";
		cout << "    Check order history\n";
		cout << "    Check account information\n";
		changeColor(YELLOW);
		cout << "    Check movies information\n";
		changeColor(WHITE);
		cout << "    Log out\n";
		break;
	case 5:
		cout << "    Check the billboard\n";
		cout << "    Check order history\n";
		cout << "    Check account information\n";
		cout << "    Check movies information\n";
		changeColor(YELLOW);
		cout << ">   Log out\n";
		changeColor(WHITE);
		break;
	}
	cout << "\n  W - up\n";
	cout << "  S - down\n";
}

void drawAdminMenu(int pos)
{
	printHeader("Menu", 13);
	switch (pos)
	{
	case 1:
		changeColor(YELLOW);
		cout << ">   Check the billboard\n";
		changeColor(WHITE);
		cout << "    Check order history\n";
		cout << "    Check account information\n";
		cout << "    Check ticket information\n";
		cout << "    Check users information\n";
		cout << "    Check cinema information\n";
		cout << "    Check movies information\n";
		cout << "    Check showings information\n";
		cout << "    Check statistics about the most grossing movie\n";
		cout << "    Log out\n";
		break;
	case 2:
		cout << "    Check the billboard\n";
		changeColor(YELLOW);
		cout << ">   Check order history\n";
		changeColor(WHITE);
		cout << "    Check account information\n";
		cout << "    Check ticket information\n";
		cout << "    Check users information\n";
		cout << "    Check cinema information\n";
		cout << "    Check movies information\n";
		cout << "    Check showings information\n";
		cout << "    Check statistics about the most grossing movie\n";
		cout << "    Log out\n";
		break;
	case 3:
		cout << "    Check the billboard\n";
		cout << "    Check order history\n";
		changeColor(YELLOW);
		cout << ">   Check account information\n";
		changeColor(WHITE);
		cout << "    Check ticket information\n";
		cout << "    Check users information\n";
		cout << "    Check cinema information\n";
		cout << "    Check movies information\n";
		cout << "    Check showings information\n";
		cout << "    Check statistics about the most grossing movie\n";
		cout << "    Log out\n";
		break;
	case 4:
		cout << "    Check the billboard\n";
		cout << "    Check order history\n";
		cout << "    Check account information\n";
		changeColor(YELLOW);
		cout << ">   Check ticket information\n";
		changeColor(WHITE);
		cout << "    Check users information\n";
		cout << "    Check cinema information\n";
		cout << "    Check movies information\n";
		cout << "    Check showings information\n";
		cout << "    Check statistics about the most grossing movie\n";
		cout << "    Log out\n";
		break;
	case 5:
		cout << "    Check the billboard\n";
		cout << "    Check order history\n";
		cout << "    Check account information\n";
		cout << "    Check ticket information\n";
		changeColor(YELLOW);
		cout << ">   Check users information\n";
		changeColor(WHITE);
		cout << "    Check cinema information\n";
		cout << "    Check movies information\n";
		cout << "    Check showings information\n";
		cout << "    Check statistics about the most grossing movie\n";
		cout << "    Log out\n";
		break;
	case 6:
		cout << "    Check the billboard\n";
		cout << "    Check order history\n";
		cout << "    Check account information\n";
		cout << "    Check ticket information\n";
		cout << "    Check users information\n";
		changeColor(YELLOW);
		cout << ">   Check cinema information\n";
		changeColor(WHITE);
		cout << "    Check movies information\n";
		cout << "    Check showings information\n";
		cout << "    Check statistics about the most grossing movie\n";
		cout << "    Log out\n";
		break;
	case 7:
		cout << "    Check the billboard\n";
		cout << "    Check order history\n";
		cout << "    Check account information\n";
		cout << "    Check ticket information\n";
		cout << "    Check users information\n";
		cout << "    Check cinema information\n";
		changeColor(YELLOW);
		cout << ">   Check movies information\n";
		changeColor(WHITE);
		cout << "    Check showings information\n";
		cout << "    Check statistics about the most grossing movie\n";
		cout << "    Log out\n";
		break;
	case 8:
		cout << "    Check the billboard\n";
		cout << "    Check order history\n";
		cout << "    Check account information\n";
		cout << "    Check ticket information\n";
		cout << "    Check users information\n";
		cout << "    Check cinema information\n";
		cout << "    Check movies information\n";
		changeColor(YELLOW);
		cout << ">   Check showings information\n";
		changeColor(WHITE);
		cout << "    Check statistics about the most grossing movie\n";
		cout << "    Log out\n";
		break;
	case 9:
		cout << "    Check the billboard\n";
		cout << "    Check order history\n";
		cout << "    Check account information\n";
		cout << "    Check ticket information\n";
		cout << "    Check users information\n";
		cout << "    Check cinema information\n";
		cout << "    Check movies information\n";
		cout << "    Check showings information\n";
		changeColor(YELLOW);
		cout << ">   Check statistics about the most grossing movie\n";
		changeColor(WHITE);
		cout << "    Log out\n";
		break;
	case 10:
		cout << "    Check the billboard\n";
		cout << "    Check order history\n";
		cout << "    Check account information\n";
		cout << "    Check ticket information\n";
		cout << "    Check users information\n";
		cout << "    Check cinema information\n";
		cout << "    Check movies information\n";
		cout << "    Check showings information\n";
		cout << "    Check statistics about the most grossing movie\n";
		changeColor(YELLOW);
		cout << ">   Log out\n";
		changeColor(WHITE);
		break;
	}
	cout << "\n  W - up\n";
	cout << "  S - down\n";
}

void drawProfileViewMenu(int pos)
{
	printHeader("Profile", 13);
	switch (pos)
	{
	case 1:
		changeColor(YELLOW);
		cout << ">   Change login\n";
		changeColor(WHITE);
		cout << "    Change password\n";
		cout << "    Change name\n";
		cout << "    Check orders\n";
		cout << "    Update billing data\n";
		cout << "    Replenish the balance\n";
		cout << "    Delete account\n";
		cout << "    Back\n";
		break;
	case 2:
		cout << "    Change login\n";
		changeColor(YELLOW);
		cout << ">   Change password\n";
		changeColor(WHITE);
		cout << "    Change name\n";
		cout << "    Check orders\n";
		cout << "    Update billing data\n";
		cout << "    Replenish the balance\n";
		cout << "    Delete account\n";
		cout << "    Back\n";
		break;
	case 3:
		cout << "    Change login\n";
		cout << "    Change password\n";
		changeColor(YELLOW);
		cout << ">   Change name\n";
		changeColor(WHITE);
		cout << "    Check orders\n";
		cout << "    Update billing data\n";
		cout << "    Replenish the balance\n";
		cout << "    Delete account\n";
		cout << "    Back\n";
		break;
	case 4:
		cout << "    Change login\n";
		cout << "    Change password\n";
		cout << "    Change name\n";
		changeColor(YELLOW);
		cout << ">   Check orders\n";
		changeColor(WHITE);
		cout << "    Update billing data\n";
		cout << "    Replenish the balance\n";
		cout << "    Delete account\n";
		cout << "    Back\n";
		break;
	case 5:
		cout << "    Change login\n";
		cout << "    Change password\n";
		cout << "    Change name\n";
		cout << "    Check orders\n";
		changeColor(YELLOW);
		cout << ">   Update billing data\n";
		changeColor(WHITE);
		cout << "    Replenish the balance\n";
		cout << "    Delete account\n";
		cout << "    Back\n";
		break;
	case 6:
		cout << "    Change login\n";
		cout << "    Change password\n";
		cout << "    Change name\n";
		cout << "    Check orders\n";
		cout << "    Update billing data\n";
		changeColor(YELLOW);
		cout << ">   Replenish the balance\n";
		changeColor(WHITE);
		cout << "    Delete account\n";
		cout << "    Back\n";
		break;
	case 7:
		cout << "    Change login\n";
		cout << "    Change password\n";
		cout << "    Change name\n";
		cout << "    Check orders\n";
		cout << "    Update billing data\n";
		cout << "    Replenish the balance\n";
		changeColor(YELLOW);
		cout << ">   Delete account\n";
		changeColor(WHITE);
		cout << "    Back\n";
		break;
	case 8:
		cout << "    Change login\n";
		cout << "    Change password\n";
		cout << "    Change name\n";
		cout << "    Check orders\n";
		cout << "    Update billing data\n";
		cout << "    Replenish the balance\n";
		cout << "    Delete account\n";
		changeColor(YELLOW);
		cout << ">   Back\n";
		changeColor(WHITE);
		break;
	}
	cout << "\n  W - up\n";
	cout << "  S - down\n";
}

void drawDeleteAccountMenu(int pos)
{
	cout << "Delete? Are you sure? :(\n";
	switch (pos)
	{
	case 1:
		changeColor(YELLOW);
		cout << ">   Yes\n";
		changeColor(WHITE);
		cout << "    No\n";
		break;
	case 2:
		cout << "    Yes\n";
		changeColor(YELLOW);
		cout << ">   No\n";
		changeColor(WHITE);
		break;
	}
}

void drawAdminUserChangeMenu(int pos)
{
	cout << "What do you want to do??\n";
	switch (pos)
	{
	case 1:
		changeColor(YELLOW);
		cout << ">   Change role\n";
		changeColor(WHITE);
		cout << "    Change access\n";
		cout << "    Back\n";
		break;
	case 2:
		cout << "    Change role\n";
		changeColor(YELLOW);
		cout << ">   Change access\n";
		changeColor(WHITE);
		cout << "    Back\n";
		break;
	case 3:
		cout << "    Change role\n";
		cout << "    Change access\n";
		changeColor(YELLOW);
		cout << ">   Back\n";
		changeColor(WHITE);
		break;
	}
}

void drawCinemaChangeMenu(int pos)
{
	cout << "What do you want to do??\n";
	switch (pos)
	{
	case 1:
		changeColor(YELLOW);
		cout << ">   Change name\n";
		changeColor(WHITE);
		cout << "    Change adress\n";
		cout << "    Add hall\n";
		cout << "    Delete hall\n";
		cout << "    Check halls\n";
		cout << "    Back\n";
		break;
	case 2:
		cout << "    Change name\n";
		changeColor(YELLOW);
		cout << ">   Change adress\n";
		changeColor(WHITE);
		cout << "    Add hall\n";
		cout << "    Delete hall\n";
		cout << "    Check halls\n";
		cout << "    Back\n";
		break;
	case 3:
		cout << "    Change name\n";
		cout << "    Change adress\n";
		changeColor(YELLOW);
		cout << ">   Add hall\n";
		changeColor(WHITE);
		cout << "    Delete hall\n";
		cout << "    Check halls\n";
		cout << "    Back\n";
		break;
	case 4:
		cout << "    Change name\n";
		cout << "    Change adress\n";
		cout << "    Add hall\n";
		changeColor(YELLOW);
		cout << ">   Delete hall\n";
		changeColor(WHITE);
		cout << "    Check halls\n";
		cout << "    Back\n";
		break;
	case 5:
		cout << "    Change name\n";
		cout << "    Change adress\n";
		cout << "    Add hall\n";
		cout << "    Delete hall\n";
		changeColor(YELLOW);
		cout << ">   Check halls\n";
		changeColor(WHITE);
		cout << "    Back\n";
		break;
	case 6:
		cout << "    Change name\n";
		cout << "    Change adress\n";
		cout << "    Add hall\n";
		cout << "    Delete hall\n";
		cout << "    Check halls\n";
		changeColor(YELLOW);
		cout << ">   Back\n";
		changeColor(WHITE);
		break;
	}
}

void drawMovieChangeMenu(int pos)
{
	cout << "What do you want to do??\n";
	switch (pos)
	{
	case 1:
		changeColor(YELLOW);
		cout << ">   Change name\n";
		changeColor(WHITE);
		cout << "    Change duration\n";
		cout << "    Change audience\n";
		cout << "    Change description\n";
		cout << "    Back\n";
		break;
	case 2:
		cout << "    Change name\n";
		changeColor(YELLOW);
		cout << ">   Change duration\n";
		changeColor(WHITE);
		cout << "    Change audience\n";
		cout << "    Change description\n";
		cout << "    Back\n";
		break;
	case 3:
		cout << "    Change name\n";
		cout << "    Change duration\n";
		changeColor(YELLOW);
		cout << ">   Change audience\n";
		changeColor(WHITE);
		cout << "    Change description\n";
		cout << "    Back\n";
		break;
	case 4:
		cout << "    Change name\n";
		cout << "    Change duration\n";
		cout << "    Change audience\n";
		changeColor(YELLOW);
		cout << ">   Change description\n";
		changeColor(WHITE);
		cout << "    Back\n";
		break;
	case 5:
		cout << "    Change name\n";
		cout << "    Change duration\n";
		cout << "    Change audience\n";
		cout << "    Change description\n";
		changeColor(YELLOW);
		cout << ">   Back\n";
		changeColor(WHITE);
		break;
	}
}

void drawMovieSelectMenu(int pos)
{
	switch (pos)
	{
	case 1:
		changeColor(YELLOW);
		cout << ">   Show detailed information about movie\n";
		changeColor(WHITE);
		cout << "    Add movie\n";
		cout << "    Delete movie\n";
		cout << "    Sort movies\n";
		cout << "    Seacrh movie\n";
		cout << "    Filter movies\n";
		cout << "    Back\n";
		break;
	case 2:
		cout << "    Show detailed information about movie\n";
		changeColor(YELLOW);
		cout << ">   Add movie\n";
		changeColor(WHITE);
		cout << "    Delete movie\n";
		cout << "    Sort movies\n";
		cout << "    Seacrh movie\n";
		cout << "    Filter movies\n";
		cout << "    Back\n";
		break;
	case 3:
		cout << "    Show detailed information about movie\n";
		cout << "    Add movie\n";
		changeColor(YELLOW);
		cout << ">   Delete movie\n";
		changeColor(WHITE);
		cout << "    Sort movies\n";
		cout << "    Seacrh movie\n";
		cout << "    Filter movies\n";
		cout << "    Back\n";
		break;
	case 4:
		cout << "    Show detailed information about movie\n";
		cout << "    Add movie\n";
		cout << "    Delete movie\n";
		changeColor(YELLOW);
		cout << ">   Sort movies\n";
		changeColor(WHITE);
		cout << "    Seacrh movie\n";
		cout << "    Filter movies\n";
		cout << "    Back\n";
		break;
	case 5:
		cout << "    Show detailed information about movie\n";
		cout << "    Add movie\n";
		cout << "    Delete movie\n";
		cout << "    Sort movies\n";
		changeColor(YELLOW);
		cout << ">   Seacrh movie\n";
		changeColor(WHITE);
		cout << "    Filter movies\n";
		cout << "    Back\n";
		break;
	case 6:
		cout << "    Show detailed information about movie\n";
		cout << "    Add movie\n";
		cout << "    Delete movie\n";
		cout << "    Sort movies\n";
		cout << "    Seacrh movie\n";
		changeColor(YELLOW);
		cout << ">   Filter movies\n";
		changeColor(WHITE);
		cout << "    Back\n";
		break;
	case 7:
		cout << "    Show detailed information about movie\n";
		cout << "    Add movie\n";
		cout << "    Delete movie\n";
		cout << "    Sort movies\n";
		cout << "    Seacrh movie\n";
		cout << "    Filter movies\n";
		changeColor(YELLOW);
		cout << ">   Back\n";
		changeColor(WHITE);
		break;
	}
}

void drawMovieSortFilterMenu(int pos)
{
	switch (pos)
	{
	case 1:
		changeColor(YELLOW);
		cout << ">   By name\n";
		changeColor(WHITE);
		cout << "    By duration\n";
		cout << "    By audience\n";
		cout << "    Back\n";
		break;
	case 2:
		cout << "    By name\n";
		changeColor(YELLOW);
		cout << ">   By duration\n";
		changeColor(WHITE);
		cout << "    By audience\n";
		cout << "    Back\n";
		break;
	case 3:
		cout << "    By name\n";
		cout << "    By duration\n";
		changeColor(YELLOW);
		cout << ">   By audience\n";
		changeColor(WHITE);
		cout << "    Back\n";
		break;
	case 4:
		cout << "    By name\n";
		cout << "    By duration\n";
		cout << "    By audience\n";
		changeColor(YELLOW);
		cout << ">   Back\n";
		changeColor(WHITE);
		break;
	}
}

void drawSeanceSortFilterMenu(int pos)
{
	switch (pos)
	{
	case 1:
		changeColor(YELLOW);
		cout << ">   By date\n";
		changeColor(WHITE);
		cout << "    By time\n";
		cout << "    By movie\n";
		cout << "    By cinema\n";
		break;
	case 2:
		cout << "    By date\n";
		changeColor(YELLOW);
		cout << ">   By time\n";
		changeColor(WHITE);
		cout << "    By movie\n";
		cout << "    By cinema\n";
		break;
	case 3:
		cout << "    By date\n";
		cout << "    By time\n";
		changeColor(YELLOW);
		cout << ">   By movie\n";
		changeColor(WHITE);
		cout << "    By cinema\n";
		break;
	case 4:
		cout << "    By date\n";
		cout << "    By time\n";
		cout << "    By movie\n";
		changeColor(YELLOW);
		cout << ">   By cinema\n";
		changeColor(WHITE);
		break;
	}
}

void drawMovieSearchMenu(int pos)
{
	switch (pos)
	{
	case 1:
		changeColor(YELLOW);
		cout << ">   By name\n";
		changeColor(WHITE);
		cout << "    By duration\n";
		cout << "    By audience\n";
		break;
	case 2:
		cout << "    By name\n";
		changeColor(YELLOW);
		cout << ">   By duration\n";
		changeColor(WHITE);
		cout << "    By audience\n";
		break;
	case 3:
		cout << "    By name\n";
		cout << "    By duration\n";
		changeColor(YELLOW);
		cout << ">   By audience\n";
		changeColor(WHITE);
		break;
	}
}

void drawSortTypeChoosing(int pos)
{
	switch (pos)
	{
	case 1:
		changeColor(YELLOW);
		cout << ">   Ascending\n";
		changeColor(WHITE);
		cout << "    Descending\n";
		break;
	case 2:
		cout << "    Ascending\n";
		changeColor(YELLOW);
		cout << ">   Descending\n";
		changeColor(WHITE);
		break;
	}
}

void drawYesNo(int pos)
{
	switch (pos)
	{
	case 1:
		changeColor(YELLOW);
		cout << ">   Yes\n";
		changeColor(WHITE);
		cout << "    No\n";
		break;
	case 2:
		cout << "    Yes\n";
		changeColor(YELLOW);
		cout << ">   No\n";
		changeColor(WHITE);
		break;
	}
}

void drawHallChangeMenu(int pos)
{
	switch (pos)
	{
	case 1:
		changeColor(YELLOW);
		cout << ">   Change seat status\n";
		changeColor(WHITE);
		cout << "    Back\n";
		break;
	case 2:
		cout << "    Change seat status\n";
		changeColor(YELLOW);
		cout << ">   Back\n";
		changeColor(WHITE);
		break;
	}
}

void drawCinemaSelectMenu(int pos)
{
	switch (pos)
	{
	case 1:
		changeColor(YELLOW);
		cout << ">   Show detailed information about cinema\n";
		changeColor(WHITE);
		cout << "    Add cinema\n";
		cout << "    Delete cinema\n";
		cout << "    Sort cinemas\n";
		cout << "    Find cinemas\n";
		cout << "    Filter cinemas\n";
		cout << "    Back\n";
		break;
	case 2:
		cout << "    Show detailed information about cinema\n";
		changeColor(YELLOW);
		cout << ">   Add cinema\n";
		changeColor(WHITE);
		cout << "    Delete cinema\n";
		cout << "    Sort cinemas\n";
		cout << "    Find cinemas\n";
		cout << "    Filter cinemas\n";
		cout << "    Back\n";
		break;
	case 3:
		cout << "    Show detailed information about cinema\n";
		cout << "    Add cinema\n";
		changeColor(YELLOW);
		cout << ">   Delete cinema\n";
		changeColor(WHITE);
		cout << "    Sort cinemas\n";
		cout << "    Find cinemas\n";
		cout << "    Filter cinemas\n";
		cout << "    Back\n";
		break;
	case 4:
		cout << "    Show detailed information about cinema\n";
		cout << "    Add cinema\n";
		cout << "    Delete cinema\n";
		changeColor(YELLOW);
		cout << ">   Sort cinemas\n";
		changeColor(WHITE);
		cout << "    Find cinemas\n";
		cout << "    Filter cinemas\n";
		cout << "    Back\n";
		break;
	case 5:
		cout << "    Show detailed information about cinema\n";
		cout << "    Add cinema\n";
		cout << "    Delete cinema\n";
		cout << "    Sort cinemas\n";
		changeColor(YELLOW);
		cout << ">   Find cinemas\n";
		changeColor(WHITE);
		cout << "    Filter cinemas\n";
		cout << "    Back\n";
		break;
	case 6:
		cout << "    Show detailed information about cinema\n";
		cout << "    Add cinema\n";
		cout << "    Delete cinema\n";
		cout << "    Sort cinemas\n";
		cout << "    Find cinemas\n";
		changeColor(YELLOW);
		cout << ">   Filter cinemas\n";
		changeColor(WHITE);
		cout << "    Back\n";
		break;
	case 7:
		cout << "    Show detailed information about cinema\n";
		cout << "    Add cinema\n";
		cout << "    Delete cinema\n";
		cout << "    Sort cinemas\n";
		cout << "    Find cinemas\n";
		cout << "    Filter cinemas\n";
		changeColor(YELLOW);
		cout << ">   Back\n";
		changeColor(WHITE);
		break;
	}
}

void drawCinemaSortFilterMenu(int pos)
{
	switch (pos)
	{
	case 1:
		changeColor(YELLOW);
		cout << ">   By name\n";
		changeColor(WHITE);
		cout << "    By hall count\n";
		cout << "    Back\n";
		break;
	case 2:
		cout << "    By name\n";
		changeColor(YELLOW);
		cout << ">   By hall count\n";
		changeColor(WHITE);
		cout << "    Back\n";
		break;
	case 3:
		cout << "    By name\n";
		cout << "    By hall count\n";
		changeColor(YELLOW);
		cout << ">   Back\n";
		changeColor(WHITE);
		break;
	}
}

void drawSeanceSelectMenu(int pos)
{
	switch (pos)
	{
	case 1:
		changeColor(YELLOW);
		cout << ">   Show detailed information about showing\n";
		changeColor(WHITE);
		cout << "    Add showing\n";
		cout << "    Delete showing\n";
		cout << "    Sort showings\n";
		cout << "    Search showings\n";
		cout << "    Filter showings\n";
		cout << "    Back\n";
		break;
	case 2:
		cout << "    Show detailed information about showing\n";
		changeColor(YELLOW);
		cout << ">   Add showing\n";
		changeColor(WHITE);
		cout << "    Delete showing\n";
		cout << "    Sort showings\n";
		cout << "    Search showings\n";
		cout << "    Filter showings\n";
		cout << "    Back\n";
		break;
	case 3:
		cout << "    Show detailed information about showing\n";
		cout << "    Add showing\n";
		changeColor(YELLOW);
		cout << ">   Delete showing\n";
		changeColor(WHITE);
		cout << "    Sort showings\n";
		cout << "    Search showings\n";
		cout << "    Filter showings\n";
		cout << "    Back\n";
		break;
	case 4:
		cout << "    Show detailed information about showing\n";
		cout << "    Add showing\n";
		cout << "    Delete showing\n";
		changeColor(YELLOW);
		cout << ">   Sort showings\n";
		changeColor(WHITE);
		cout << "    Search showings\n";
		cout << "    Filter showings\n";
		cout << "    Back\n";
		break;
	case 5:
		cout << "    Show detailed information about showing\n";
		cout << "    Add showing\n";
		cout << "    Delete showing\n";
		cout << "    Sort showings\n";
		changeColor(YELLOW);
		cout << ">   Search showings\n";
		changeColor(WHITE);
		cout << "    Filter showings\n";
		cout << "    Back\n";
		break;
	case 6:
		cout << "    Show detailed information about showing\n";
		cout << "    Add showing\n";
		cout << "    Delete showing\n";
		cout << "    Sort showings\n";
		cout << "    Search showings\n";
		changeColor(YELLOW);
		cout << ">   Filter showings\n";
		changeColor(WHITE);
		cout << "    Back\n";
		break;
	case 7:
		cout << "    Show detailed information about showing\n";
		cout << "    Add showing\n";
		cout << "    Delete showing\n";
		cout << "    Sort showings\n";
		cout << "    Search showings\n";
		cout << "    Filter showings\n";
		changeColor(YELLOW);
		cout << ">   Back\n";
		changeColor(WHITE);
		break;
	}
}

void drawSeanceChangeMenu(int pos)
{
	cout << "What do you want to do??\n";
	switch (pos)
	{
	case 1:
		changeColor(YELLOW);
		cout << ">   Change movie\n";
		changeColor(WHITE);
		cout << "    Change date\n";
		cout << "    Change time\n";
		cout << "    Change place\n";
		cout << "    Hide from the billboard\n";
		cout << "    Back\n";
		break;
	case 2:
		cout << "    Change movie\n";
		changeColor(YELLOW);
		cout << ">   Change date\n";
		changeColor(WHITE);
		cout << "    Change time\n";
		cout << "    Change place\n";
		cout << "    Hide from the billboard\n";
		cout << "    Back\n";
		break;
	case 3:
		cout << "    Change movie\n";
		cout << "    Change date\n";
		changeColor(YELLOW);
		cout << ">   Change time\n";
		changeColor(WHITE);
		cout << "    Change place\n";
		cout << "    Hide from the billboard\n";
		cout << "    Back\n";
		break;
	case 4:
		cout << "    Change movie\n";
		cout << "    Change date\n";
		cout << "    Change time\n";
		changeColor(YELLOW);
		cout << ">   Change place\n";
		changeColor(WHITE);
		cout << "    Hide from the billboard\n";
		cout << "    Back\n";
		break;
	case 5:
		cout << "    Change movie\n";
		cout << "    Change date\n";
		cout << "    Change time\n";
		cout << "    Change place\n";
		changeColor(YELLOW);
		cout << ">   Hide from the billboard\n";
		changeColor(WHITE);
		cout << "    Back\n";
		break;
	case 6:
		cout << "    Change movie\n";
		cout << "    Change date\n";
		cout << "    Change time\n";
		cout << "    Change place\n";
		cout << "    Hide from the billboard\n";
		changeColor(YELLOW);
		cout << ">   Back\n";
		changeColor(WHITE);
		break;
	}
}

void drawTicketSelectMenu(int pos)
{
	cout << "What do you want to do??\n";
	switch (pos)
	{
	case 1:
		changeColor(YELLOW);
		cout << ">   Create tickets\n";
		changeColor(WHITE);
		cout << "    Изменить билеты\n";
		cout << "    Back\n";
		break;
	case 2:
		cout << "    Create tickets\n";
		changeColor(YELLOW);
		cout << ">   Изменить билеты\n";
		changeColor(WHITE);
		cout << "    Back\n";
		break;
	case 3:
		cout << "    Create tickets\n";
		cout << "    Изменить билеты\n";
		changeColor(YELLOW);
		cout << ">   Back\n";
		changeColor(WHITE);
		break;
	}
}

void drawTicketEditMenu(int pos)
{
	cout << "What do you want to do??\n";
	switch (pos)
	{
	case 1:
		changeColor(YELLOW);
		cout << ">   Change price for Standard\n";
		changeColor(WHITE);
		cout << "    Change price for Comfort\n";
		cout << "    Change price for VIP\n";
		cout << "    Back\n";
		break;
	case 2:
		cout << "    Change price for Standard\n";
		changeColor(YELLOW);
		cout << ">   Change price for Comfort\n";
		changeColor(WHITE);
		cout << "    Change price for VIP\n";
		cout << "    Back\n";
		break;
	case 3:
		cout << "    Change price for Standard\n";
		cout << "    Change price for Comfort\n";
		changeColor(YELLOW);
		cout << ">   Change price for VIP\n";
		changeColor(WHITE);
		cout << "    Back\n";
		break;
	case 4:
		cout << "    Change price for Standard\n";
		cout << "    Change price for Comfort\n";
		cout << "    Change price for VIP\n";
		changeColor(YELLOW);
		cout << ">   Back\n";
		changeColor(WHITE);
		break;
	}
}


void drawAfishaMenu(int pos)
{
	cout << "Меню\n";
	switch (pos)
	{
	case 1:
		changeColor(YELLOW);
		cout << ">   Find in the billboard\n";
		changeColor(WHITE);
		cout << "    Filter the billboard\n";
		cout << "    Sort the billboard\n";
		cout << "    Back\n";
		cout << "    Go back to the user menu\n";
		break;
	case 2:
		cout << "    Find in the billboard\n";
		changeColor(YELLOW);
		cout << ">   Filter the billboard\n";
		changeColor(WHITE);
		cout << "    Sort the billboard\n";
		cout << "    Back\n";
		cout << "    Go back to the user menu\n";
		break;
	case 3:
		cout << "    Find in the billboard\n";
		cout << "    Filter the billboard\n";
		changeColor(YELLOW);
		cout << ">   Sort the billboard\n";
		changeColor(WHITE);
		cout << "    Back\n";
		cout << "    Go back to the user menu\n";
		break;
	case 4:
		cout << "    Find in the billboard\n";
		cout << "    Filter the billboard\n";
		cout << "    Sort the billboard\n";
		changeColor(YELLOW);
		cout << ">   Back\n";
		changeColor(WHITE);
		cout << "    Go back to the user menu\n";
		break;
	case 5:
		cout << "    Find in the billboard\n";
		cout << "    Filter the billboard\n";
		cout << "    Sort the billboard\n";
		cout << "    Back\n";
		changeColor(YELLOW);
		cout << ">   Go back to the user menu\n";
		changeColor(WHITE);
		break;
	}
}


void colorChanging(int color)
{
	changeColor(color);
}
