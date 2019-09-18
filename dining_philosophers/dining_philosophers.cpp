// crt_BEGTHRD.C
// compile with: /MT /D "_X86_" /c
// processor: x86
#include <windows.h>
#include <process.h>    /* _beginthread, _endthread */
#include <stddef.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

using namespace std;

void Eat(void*);
void CheckKey(void*);
void Think(void*);
void exist();

// GetRandom returns a random integer between min and max.
#define GetRandom( min, max ) ((rand() % (int)(((max) + 1) - (min))) + (min))
// GetGlyph returns a printable ASCII character value
#define GetGlyph( val ) ((char)((val + 32) % 93 + 33))

BOOL repeat = TRUE;                 // Global repeat flag
HANDLE hStdOut;                     // Handle for console window
CONSOLE_SCREEN_BUFFER_INFO csbi;    // Console information structure

struct Philosopher {
	bool leftFork;
	bool rightFork;
	string name;
};

int main()
{
	int param = 0;
	int* pparam = &param;

	// Launch CheckKey thread to check for terminating keystroke.
	_beginthread(CheckKey, 0, NULL);

	// Loop until CheckKey terminates program or 1000 threads created.
	while (repeat && param < 5)
	{
		// launch another character thread.
		_beginthread(Eat, 0, (void*)pparam);

		// increment the thread parameter
		param++;

		// Wait one second between loops.
		Sleep(1000L);
	}
}

// CheckKey - Thread to wait for a keystroke, then clear repeat flag.
void CheckKey(void* ignored)
{
	_getch();
	repeat = 0;    // _endthread implied
}

// Bounce - Thread to create and control a colored letter that moves
// around on the screen.
//
// Params: parg - the value to create the character from
void Eat(void* parg)
{
	cout << "I'm eating" << endl;
	// _endthread given to terminate
	_endthread();
}

void Think(void* parg)
{
	while (repeat)
	{
		cout << "I'm thinking";
	}
	// _endthread given to terminate
	_endthread();
}

void exist(Philosopher &philosopher) {
	

	while (repeat) {
		cout << philosopher.name << endl;
	}

	_endthread();
}