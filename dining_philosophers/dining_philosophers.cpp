#include <array>
#include <iostream>
#include <string_view>
#include <windows.h>

#include "philosopher.h"
#include "fork.h"
#include "table.h"

using namespace std;

const int no_of_philosophers = 5;

void dine()
{

	cout << "Press F to pay respects" << endl;

	cout << "Dinner started!" << endl;

	Table table;
	array<Philosopher, no_of_philosophers> philosophers
	{
		{
			{ "Aristotle", table, table.forks[0], table.forks[1] },
			{ "Platon",    table, table.forks[1], table.forks[2] },
			{ "Descartes", table, table.forks[2], table.forks[3] },
			{ "Kant",      table, table.forks[3], table.forks[4] },
			{ "Nietzsche", table, table.forks[4], table.forks[0] },
		}
	};

	table.ready = true;

	Sleep(100000);

	cout << "Dinner done!" << endl;
}

int main()
{
	dine();

	return 0;
}