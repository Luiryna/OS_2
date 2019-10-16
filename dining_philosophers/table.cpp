#include <iostream>
#include "table.h"
#include <thread>

Table::Table() {
	mutex = CreateMutex(NULL, FALSE, NULL);
	thread = (HANDLE)_beginthreadex(NULL, 0, &callThread, this, 0, NULL);
}

unsigned __stdcall Table::callThread(void* pArguments) {
	Table* table = (Table*)(pArguments);
	if (table) {
		//ph->dine();
		table->
	}
	_endthreadex(0);


	return 0;
}

Table::~Table() {
}

void Table::pushState(string name, string state) {
	WaitForSingleObject(mutex, INFINITE);
	vector<string> nameAndState = {name, state};
	arrayOfStates.push_back(nameAndState);
	ReleaseMutex(mutex);
}

void Table::printStates() {
	for (vector<string> nameAndState : arrayOfStates) {
		if (nameAndState.size() == 2) {
			std::cout << nameAndState.at(0) << nameAndState.at(1) << '\n';
		}
	}
}

void Table::popState() {
	WaitForSingleObject(mutex, INFINITE);
	if (arrayOfStates.size() > 0) {
		vector<string> nameAndState = arrayOfStates.at(0);
		if (nameAndState.size() == 2) {
			cout << nameAndState.at(0) << nameAndState.at(1) << "\n";
		}
	}
	ReleaseMutex(mutex);
}