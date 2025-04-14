#pragma once
#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
#include <string.h>
#define MAXSIZE 20

int InputInt(char mess[]);
double InputDouble(char mess[]);
struct Planes
{
	int bort_num;
	char mark[MAXSIZE];
	int capacity;
	double lift_capacity;
	int year;
};
void InputPlane(struct Planes** plane, int* struct_size);
void OutputPlane(struct Planes* plane, int strutct_size);
