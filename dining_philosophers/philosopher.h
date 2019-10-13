#pragma once

#include <array>
#include <mutex>
#include <thread>
#include <atomic>
#include <chrono>
#include <iostream>
#include <string>
#include <random>
#include <iomanip>
#include <string_view>
#include <windows.h>
#include "fork.h"
#include "table.h"

using namespace std;

class Philosopher
{
public:
	Philosopher(string_view n, Table const& t, Fork& l, Fork& r);
	~Philosopher();
	void dine();
	void print(string_view text);
	void eat();
	void think();
	static unsigned __stdcall callThread(void* pArguments);


private:
	string const name;
	Table const& dinnertable;
	Fork& left_fork;
	Fork& right_fork;
	HANDLE lifeThread;

};

