#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

#define SetColor(color) SetConsoleTextAttribute(h, color)
#define SetCursor(col, row) SetConsoleCursorPosition(h, {(short)col, (short)row})

#define menuColor 10
#define defaultColor 7
#define length 255
//--------------------------------------------------------------------
char **AddTask(char **tasks, int &size);
void Print(char **tasks, int size, int sel);
char **RemoveTask(char **tasks, int &size, int sel);
//--------------------------------------------------------------------
void menu(char **tasks, int size)
{
	int sel = 1, key = 0;

	SetCursor(0, size - 1);
	SetColor(menuColor);
	cout << tasks[size - 1];
	SetColor(defaultColor);

	while (true)
	{
		key = getch();
		if (key == 224)
			key = getch();

		if (key == 72 && 0 < sel - 1) // Up
			sel--;
		else if (key == 80 && sel < size) // Down
			sel++;
		else if (key == 13)
		{
			if (sel == size)
				tasks = AddTask(tasks, size);
			else
				tasks = RemoveTask(tasks, size, sel);
		}
		else if (key == 27)
		{
			/*		for (int i = 0; i < size; i++)
			delete[] tasks[i];*/
			return;
		}

		Print(tasks, size, sel - 1);
	}
}
//--------------------------------------------------------------------
void clearTable(int size)
{
	for (size_t i = 0; i < size + 1; i++)
	{
		for (size_t j = 0; j < 40; j++)
		{
			SetCursor(j, i);
			cout << " ";
		}
	}
}
//--------------------------------------------------------------------
void clear(int row)
{
	SetCursor(0, row);
	for (size_t i = 0; i < 40; i++)
		cout << " ";
}
//--------------------------------------------------------------------
char **AddTask(char **tasks, int &size)
{
	//	size++;
	//tasks[size] = tasks[size - 1];
	//tasks[size - 1] = " ";
	char **temp = new char*[size + 1];

	memcpy(temp, tasks, sizeof(tasks) * size);

	//for (size_t i = 0; i < size; i++)
	//{
	//	temp[i] = tasks[i];
	//}

	temp[size] = new char[length];

	SetCursor(0, size);
	SetColor(defaultColor);
	cout << tasks[0];

	SetCursor(0, size - 1);
	clear(size - 1);
	SetCursor(0, size - 1);
	SetColor(menuColor);
	printf("%d. ", size);
	cin.getline(temp[size], length);
	//	scanf("%s", temp[size]);

	delete[] tasks;
	tasks = temp;
	size++;
	return tasks;
}
//--------------------------------------------------------------------
char **RemoveTask(char **tasks, int &size, int sel)
{
	char *temp = new char[size];

	if (size != 2)
		for (size_t i = sel; i < size - 1; i++)
		{
			temp = tasks[i];
			tasks[i] = tasks[i + 1];
			tasks[i + 1] = temp;
		}

	size--;
	char **tempTask = new char*[size];

	memcpy(tempTask, tasks, sizeof(tasks) * size);
	delete[] tasks;
	tasks = tempTask;

	//delete[] temp;
	//delete[] tempTask;
	return tasks;
}
//--------------------------------------------------------------------
void Print(char **tasks, int size, int sel)
{
	clearTable(size);
	for (short i = 1, k = 0; i <= size; i++, k++)
	{
		SetCursor(0, k);

		if (k == sel)
			SetColor(menuColor);
		else
			SetColor(defaultColor);

		if (i == size)
			printf("%s", tasks[0]);
		else
			printf("%d. %s", k + 1, tasks[i]);

		SetColor(defaultColor);
	}
}
//--------------------------------------------------------------------
void load(FILE *f, char * path, int &size)
{



	fclose(f);
}
//--------------------------------------------------------------------
void save(FILE *f, char **tasks, char * path, int size)
{
	fread(&size, sizeof(size), 1, f);

	fread(tasks, sizeof(tasks), 1, f);

	fclose(f);
}
//--------------------------------------------------------------------
