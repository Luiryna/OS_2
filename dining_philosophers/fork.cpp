#include <iostream>
#include <windows.h>
#include "fork.h"

void Fork::wait() {
	WaitForSingleObject(mutex, INFINITE);
}

void Fork::release() {
	ReleaseMutex(mutex);
}