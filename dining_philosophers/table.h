#pragma once

//#include "philosopher.h"
#include "fork.h"

#include <array>
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

#define numberOfForks 5

class Philosopher;

class Table
{
public:
	bool ready = false;
	bool headerPrinted;
	std::array<Fork, numberOfForks> forks;
	std::vector<Philosopher*> philosophers;
	void printHeader();
	void checkStateAndPrint();
	void printState();
	static unsigned __stdcall callThread(void* pArguments);
	HANDLE mutex;
	HANDLE thread;
	Table();
	~Table();

private:

};

