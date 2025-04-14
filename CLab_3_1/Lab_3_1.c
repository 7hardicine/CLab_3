#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include "Menu.h"
#include "Funcs.h"
#define MAXSIZE 20
#define MENU_ITEM_COUNT 4

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
		"Иди нахуй", Output,
		"Выход", exit
	};

	mainMenu(menuItems, MENU_ITEM_COUNT);
	free(plane);

	system("pause");
	return 0;
}