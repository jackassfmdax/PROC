#pragma once

using namespace std;

struct usual_ar
{
	int count;
	int** ar_us;
};

struct diagonal_ar
{
	int count;
	int* ar_d;
};

struct arrays
{
	enum key { Diagonal, Usual };
	enum way {String, Column, Vector};
	key k;
	way w;
	int count;
	union
	{
		diagonal_ar d;
		usual_ar us;
	};
};