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

