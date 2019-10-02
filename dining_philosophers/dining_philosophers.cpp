﻿#include <array>
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

using namespace std;

mutex g_lockprint;
const int no_of_philosophers = 5;

struct fork
{
public:
	void wait() {
		WaitForSingleObject(mutex, INFINITE);
	}
	void release() {
		ReleaseMutex(mutex);
	}
private:
	HANDLE mutex = CreateMutex(NULL, FALSE, NULL);
};

struct table
{
public:
	bool ready = false;
	array<fork, 5> forks;

private:

};

unsigned __stdcall callThread(void* pArguments);


struct philosopher
{
private:
	string const name;
	table const& dinnertable;
	fork& left_fork;
	fork& right_fork;
	HANDLE lifeThread;

public:



	philosopher(string_view n, table const& t, fork& l, fork& r) :
		name(n), dinnertable(t), left_fork(l), right_fork(r)
	{
		unsigned threadID;
		lifeThread = (HANDLE)_beginthreadex(NULL, 0, &callThread, (void*)this, 0, &threadID);
	}

	
	~philosopher() {
	}

	void dine()
	{
		while (!dinnertable.ready);

		do
		{
			think();
			eat();
		} while (dinnertable.ready);
	}

	void print(string_view text)
	{
		lock_guard<std::mutex> cout_lock(g_lockprint);
		cout
			<< left << setw(10) << setfill(' ')
			<< name << text << endl;
	}

	void eat()
	{
		

		print(" started eating.");
		print(" finished eating.");
	}

	void think()
	{
		

		print(" is thinking ");
	}
};
unsigned __stdcall callThread(void* pArguments)
{
	philosopher* ph = (philosopher*)(pArguments);
	if (ph) {
		ph->dine();
	}
	_endthreadex(0);


	return 0;
}
void dine()
{
	//thread sleep
	cout << "Dinner started!" << endl;

	{
		table table;
		array<philosopher, no_of_philosophers> philosophers
		{
		   {
			  { "Aristotle", table, table.forks[0], table.forks[1] },
			  { "Platon",    table, table.forks[1], table.forks[2] },
			  { "Descartes", table, table.forks[2], table.forks[3] },
			  { "Kant",      table, table.forks[3], table.forks[4] },
			  { "Nietzsche", table, table.forks[4], table.forks[0] },
		   }
		};

		
	}

	cout << "Dinner done!" << endl;
}

int main()
{
	dine();

	return 0;
}