#pragma once

#include "table.h"
#include "fork.h"

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Philosopher
{
public:
	Philosopher(string_view n, Fork& l, Fork& r);
	~Philosopher();
	void dine();
	void eat();
	void think();
	string state;
	void setState(string stringState);
	static unsigned __stdcall callThread(void* pArguments);
	string const name;
	void stopDining();
	HANDLE stopEating;

private:
	Fork& left_fork;
	Fork& right_fork;
	HANDLE lifeThread;
};

