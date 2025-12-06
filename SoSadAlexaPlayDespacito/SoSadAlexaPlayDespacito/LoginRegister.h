#pragma once

#include "Classes.h"

string EnterLogin();
string EnterPassword();
bool doPasswrodsMatch(string a, string b);

int loginmenu(User& user);
User registermenu();

User changeLogin(User user);
User changePassword(User user);
