#pragma once

#include <array>
#include <iostream>
#include <windows.h>
#include "fork.h"
#include <string>
#include <vector>

using namespace std;

const int numberOfForks = 5;

class Table
{
public:
	bool ready = false;
	array<Fork, numberOfForks> forks;
	vector<vector<string>> arrayOfStates;
	void pushState(string name, string state);
	void printStates();
	void popState();
	static unsigned __stdcall callThread(void* pArguments);
	HANDLE mutex;
	HANDLE thread;
	Table();
	~Table();

private:

};

