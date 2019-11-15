#include "philosopher.h"
#include "fork.h"
#include "table.h"

#include <array>
#include <iostream>
#include <string_view>
#include <windows.h>

using namespace std;

const int no_of_philosophers = 5;

void dine()
{

	cout << "Press F to pay respects" << endl;

	cout << "Dinner started!" << endl;

	Table table;
	Sleep(100000);
	table.stopDining();
	// сделать какое-то событие
	cout << "Dinner done!" << endl;
}

int main()
{
	dine();

	return 0;
}