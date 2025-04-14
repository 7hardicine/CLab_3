#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
#include <string.h>
#define MAXSIZE 20

int InputInt(char mess[])
{
	int int_num;
	printf_s("%s ", mess);
	while (scanf_s("%d", &int_num) == 0)
	{
		while (getchar() != '\n');
		printf_s("Вы ввели что-то не то...\n%s ", mess);
	}
	return int_num;
}
double InputDouble(char mess[])
{
	double double_num;
	printf_s("%s ", mess);
	while (scanf_s("%lf", &double_num) == 0)
	{
		while (getchar() != '\n');
		printf_s("Вы ввели что-то не то...\n%s ", mess);
	}
	return double_num;
}
struct Planes
{
	int bort_num;
	char mark[MAXSIZE];
	int capacity;
	double lift_capacity;
	int year;
};
void InputPlane(struct Planes** plane, int* struct_size)
{
	int old_struct_size = *struct_size;
	*struct_size = InputInt("Введите количество самолётов:");
	*plane = (struct Planes*)realloc(*plane, (*struct_size + old_struct_size) * sizeof(struct Planes));
	for (int i = 0; i < *struct_size; i++)
	{
		printf_s("Введите данные о самолёте #%d:\n", old_struct_size + i + 1);
		puts("Введите название самолёта:");
		scanf_s("%s", (*plane + old_struct_size + i)->mark, (unsigned)sizeof((*plane + old_struct_size + i)->mark));
		(*plane + old_struct_size + i)->bort_num = InputInt("Введите бортовой номер:");
		(*plane + old_struct_size + i)->capacity = InputInt("Введите вместимость самолёта:");
		(*plane + old_struct_size + i)->lift_capacity = InputDouble("Введите грузоподъёмность самолёта:");
		(*plane + old_struct_size + i)->year = InputInt("Введите год выпуска самолёта:");
	}
}
void OutputPlane(struct Planes* plane, int struct_size)
{
	puts("|===================================================================|");
	printf_s("|%3s |%s|%s|%s| %s |%s|\n", "#", "Борт.номер", "Вместимость", "Грузоподъёмность", "Название", "Год выпуска");
	for (int i = 0; i < struct_size; i++)
	{
		puts("|===================================================================|");
		printf_s("|%3d |%10d|%11d|%16.2lf|%10s|%11d|\n", i + 1, (plane + i)->bort_num, (plane + i)->capacity, \
			(plane  + i)->lift_capacity, (plane + i)->mark, (plane + i)->year);
	}
	puts("|===================================================================|");
}
