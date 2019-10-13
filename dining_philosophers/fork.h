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

class Fork
{
public:
	void wait();
	void release();

private:
	HANDLE mutex = CreateMutex(NULL, FALSE, NULL);
};


