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

Fork::wait() {
	WaitForSingleObject(mutex, INFINITE);
}

Fork::release() {
	ReleaseMutex(mutex);
}