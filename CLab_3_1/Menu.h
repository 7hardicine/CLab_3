﻿#pragma once
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include "Funcs.h"

#define KEY_ARROW_UP 72
#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_DOWN 80
#define KEY_ARROW_LEFT 75
#define ENTER 13
#define ESC 27

typedef void (*Handler)();
struct MenuItem
{
	char* text;
	Handler handler;
};
void mainMenu(struct MenuItem* items, int itemCount);
