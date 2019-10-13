#pragma once

#include <iostream>
#include <windows.h>

class Fork
{
public:
	void wait();
	void release();

private:
	HANDLE mutex = CreateMutex(NULL, FALSE, NULL);
};


