#include <iostream>
#include <windows.h>
#include "Functions.h"

using namespace std;

#define length 255

int main()
{
	int size = 1;
	char **tasks = new char*[size];
	FILE *f;

	tasks[size - 1] = new char[length];
	tasks[size - 1] = "Add task...";

	char path[_MAX_PATH];
	char txtpath[_MAX_PATH];
	char buffer[100];
	sprintf(path, "%s%s", getenv("USERPROFILE"), "//Desktop//Example//Task.dat");
	sprintf(txtpath, "%s%s", getenv("USERPROFILE"), "//Desktop//Example//Base.txt");

	//if ((f = fopen(path, "rb")) != 0)
	//	load(f, tasks, path, size);

	menu(tasks, size);

	itoa(size, buffer, 10);
	f = fopen(txtpath, "w");
	fputs(buffer, f);

	for (size_t i = 1; i < size; i++)
	{
		fputs(tasks[i], f);
	}

	//f = fopen(path, "wb");
	//fwrite(&size, sizeof(size), 1, f);

	////for (size_t i = 1; i < size; i++)
	////	fwrite(tasks[i], sizeof(tasks), 1, f);

	//fwrite(tasks, sizeof(tasks), 1, f);

	fclose(f);

	//save(f, tasks, path, size);

	//	delete[] tasks;
	cout << endl;
}