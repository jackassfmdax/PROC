#pragma once

using namespace std;

struct usualArray
{
	int count;
	int** arUs;
};

struct diagonalArray
{
	int count;
	int* arD;
};

struct triangleArray
{
	int count;
	int** arTr;
};

struct arrays
{
	enum way {String, Column, Vector};
	enum key {Diagonal, Usual, Triangle};
	key k;
	way w;
	int count;
	int sum = 0;//
	union
	{
		diagonalArray d;
		usualArray us;
		triangleArray tr;
	};
};