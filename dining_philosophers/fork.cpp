#include "fork.h"

#include <iostream>
#include <windows.h>

void Fork::wait() {
	WaitForSingleObject(mutex, INFINITE);
}

void Fork::release() {
	ReleaseMutex(mutex);
}