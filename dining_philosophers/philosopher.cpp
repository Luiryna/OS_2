#include "philosopher.h"

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

Philosopher::Philosopher(string_view n, Table const& t, Fork& l, Fork& r) :
	name(n), dinnertable(t), left_fork(l), right_fork(r)
{
	unsigned threadID;
	lifeThread = (HANDLE)_beginthreadex(NULL, 0, &callThread, (void*)this, 0, &threadID);
}

Philosopher::~Philosopher() {
}

unsigned __stdcall Philosopher::callThread(void* pArguments) {
	Philosopher* ph = (Philosopher*)(pArguments);
	if (ph) {
		ph->dine();
	}
	_endthreadex(0);


	return 0;
}

Philosopher::dine() {
	while (dinnertable.ready)
	{
		think();

		eat();
	}
}

Philosopher::print(string_view text) {
	cout << " "
		<< name << text << endl;
}

Philosopher::eat() {
	print(" started eating.");

	Sleep(1000);

	left_fork.release();
	right_fork.release();
	print(" finished eating.");
}

Philosopher::think() {
	left_fork.wait();
	right_fork.wait();
	Sleep(1000);

	print(" is thinking ");
}