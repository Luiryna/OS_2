
#include "table.h"
#include "fork.h"
#include "philosopher.h"

#include <iostream>
#include <iomanip>
#include <thread>
#include <array>

using namespace std;

Table::Table() {

	mutex = CreateMutex(NULL, FALSE, NULL);
	thread = (HANDLE)_beginthreadex(NULL, 0, &callThread, this, 0, NULL);
	headerPrinted = false;
	stop = CreateEvent(NULL, TRUE, FALSE, NULL);

	vector<string> names{ "Aristotle", "Platon", "Descartes", "Kant", "Nietzsche" };

	for (int i = 0; i < numberOfForks; i++) {
		int rightFork;
		if (i == numberOfForks - 1) {
			rightFork = 0;
		} else {
			rightFork = i + 1;
		}
		Philosopher* philosopher = new Philosopher(names.at(i), forks[i], forks[rightFork]);
		philosophers.push_back(philosopher);
	}
	ready = true;
}

unsigned __stdcall Table::callThread(void* pArguments) {
	Table* table = (Table*)(pArguments);
	if (table) {
		table->checkStateAndPrint();
	}
	_endthreadex(0);

	return 0;
}

Table::~Table() {
}

void Table::printState() {
	WaitForSingleObject(mutex, INFINITE);
	
	for (Philosopher* philosopher : philosophers) {
		cout << setw(15) << philosopher->state;
	}

	cout << endl;

	ReleaseMutex(mutex);
}

void Table::checkStateAndPrint() {
	while (ready && WaitForSingleObject(stop, 0) != WAIT_OBJECT_0) {
		if (headerPrinted == false) { printHeader(); }
		printState();
		Sleep(1000);
	}
	for (Philosopher* philosopher : philosophers) {
		philosopher->stopDining();
	}
}

void Table::printHeader() {
	for (Philosopher* philosopher : philosophers) {
		cout << setw(15) << philosopher->name;
	}
	cout << endl;
	headerPrinted = true;
}

void Table::stopDining() {
	SetEvent(stop);
}