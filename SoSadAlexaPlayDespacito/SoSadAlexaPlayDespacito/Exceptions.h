#pragma once

#include <string>
#include <iostream>

using namespace std;

class LoginErrorBan : public exception
{
public:
	string what()
	{
		return "Unable to log in. The account is blocked by administrator.\n";
	}
};

class LoginErrorNotConfirmed : public exception
{
public:
	string what()
	{
		return "Unable to log in. The account was not confirmed.\n";
	}
};

class EndOfFile : public exception
{
public:
	string what()
	{
		return "Reached the end of the file.\n";
	}
};

class AlreadyHere : public exception
{
public:
	string what()
	{
		return "There is such an object!\n";
	}
};

