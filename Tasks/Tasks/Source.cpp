#include <iostream>
#include <windows.h>
#include "Functions.h"

using namespace std;

#define length 255
FILE *f;

int main()
{
	int size = 1;
	char **tasks = new char*[size];

	tasks[size - 1] = new char[length];
	strcpy(tasks[size - 1], "Add task...");

	char path[_MAX_PATH] = "Task.dat";
	char buffer[100];
//	sprintf(path, "%s%s", getenv("USERPROFILE"), "//Desktop//Example//Task.dat");
//	sprintf(txtpath, "%s%s", getenv("USERPROFILE"), "//Desktop//Example//Base.txt");

	if ((f = fopen(path, "rb")) != 0)
		load(f, tasks, path, size);

	menu(tasks, size);

	save(f, tasks, path, size);

	//	delete[] tasks;
	cout << endl;
}
