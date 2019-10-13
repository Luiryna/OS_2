#pragma once

#include <array>
#include <iostream>
#include <windows.h>
#include "fork.h"

using namespace std;

class Table
{
public:
	bool ready = false;
	array<Fork, 5> forks;
	Table();
	~Table();

private:

};

