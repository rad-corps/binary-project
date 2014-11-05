/*
File:		Source.cpp
Author:		Jeremy Eade
Brief:		Source / Main class file
*/


#include <cstdlib>
#include "Application.h"
//#include <Windows.h>

int main()
{
	//HWND console = GetConsoleWindow();
	//RECT r;
	//GetWindowRect(console, &r);
	//MoveWindow(console, 0, 0, 1000, 400, TRUE);

	Application app;
	app.Run();
	return 0;
}



