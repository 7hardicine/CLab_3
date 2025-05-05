#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include "Menu.h"
#include "Funcs.h"
#define MAXSIZE 20
#define MENU_ITEM_COUNT 5

/*
Самолёт
Поля: бортовой номер, марка, вместимость, грузоподъемность, год выпуска	
- вывести информацию о самолетах заданной марки с максимальной грузоподъемностью;
- вывести информацию о самолетах, произведенных до указанного года
*/

struct Planes* plane;
int plane_count = 0;

void Input()
{
	puts("Введите информацию о самолётах:");
	InputPlane(&plane, &plane_count);
}

void Output()
{
	if (plane_count > 0)
	{
		OutputPlane(plane, plane_count);
	}
	else
	{
		puts("Информация отсутствует!");
	}
}

void OutputMaxWeightCapacity()
{
	if (plane_count > 0)
	{
		MaxWeightCapacityAndMark(plane, plane_count);
	}
	else
	{
		puts("Информация отсутствует!");
	}
}

void OutputBeforeCurrentYear()
{
	if (plane_count > 0)
	{
		BeforeCurrentYear(plane, plane_count);
	}
	else
	{
		puts("Информация отсутствует!");
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	SetConsoleTitle(L"Самолёты");
	plane = (struct Planes*)calloc(plane_count, sizeof(struct Planes));
	struct MenuItem menuItems[MENU_ITEM_COUNT] =
	{
		"Ввод данных", Input,
		"Вывод данных", Output,
		"Самолёты с заданной маркой и максимальной грузоподъёмностью", OutputMaxWeightCapacity,
		"Самолёты, произведённые до указанного года", OutputBeforeCurrentYear,
		"Выход", exit
	};

	mainMenu(menuItems, MENU_ITEM_COUNT);
	free(plane);

	system("pause");
	return 0;
}