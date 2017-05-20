#pragma once

#include "stdafx.h"
#include "array.h"

struct element
{
	arrays* ar;
	element* next;
};

struct container
{
	element* data;
	int lenght = 0;
};