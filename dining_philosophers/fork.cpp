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

void Fork::wait() {
	WaitForSingleObject(mutex, INFINITE);
}

void Fork::release() {
	ReleaseMutex(mutex);
}