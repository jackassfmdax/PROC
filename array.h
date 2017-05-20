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

struct triangle_ar
{
	int count;
	int** ar_tr;
};

struct arrays
{
	enum way {String, Column, Vector};
	enum key { Diagonal, Usual, Triangle };
	key k;
	way w;
	int count;
	int sum = 0;//
	union
	{
		diagonal_ar d;
		usual_ar us;
		triangle_ar tr;
	};
};