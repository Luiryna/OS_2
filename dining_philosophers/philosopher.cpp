#include "philosopher.h"
#include "table.h"
#include "fork.h"

#include <array>
#include <thread>
#include <iostream>
#include <string>
#include <string_view>
#include <windows.h>

using namespace std;

Philosopher::Philosopher(string_view n, Fork& l, Fork& r) :
	name(n), left_fork(l), right_fork(r)
{
	lifeThread = (HANDLE)_beginthreadex(NULL, 0, &callThread, this, 0, NULL);
	state = "start";
}

Philosopher::~Philosopher() {
}

unsigned __stdcall Philosopher::callThread(void *pArguments) {
	Philosopher* ph = (Philosopher*)(pArguments);
	if (ph) {
		ph->dine();
	}
	_endthreadex(0);

	return 0;
}

void Philosopher::setState(string stringState) {
	state = stringState;
}

void Philosopher::dine() {
	while (true)
	{
		think();
		eat();
	}
}

void Philosopher::eat() {
	setState("eating");
	Sleep(1000);

	left_fork.release();
	right_fork.release();
}

void Philosopher::think() {
	setState("thinking");
	Sleep(1000);

	left_fork.wait();
	right_fork.wait();
}