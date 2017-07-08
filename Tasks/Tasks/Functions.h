#pragma once

//extern FILE *f;
//----------------------------------------------------
void menu(char **&tasks, int &size);
void load(FILE * f, char **&tasks, char * path, int &size);
void save(FILE * f, char **tasks, char * path, int size);