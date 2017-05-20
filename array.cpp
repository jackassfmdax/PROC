#include "stdafx.h"
#include <fstream>
#include "array.h"

using namespace std;

void ReadDiagonal(diagonal_ar &d_ar, ifstream &ifst)
{
	ifst >> d_ar.count;
	d_ar.ar_d = new int[d_ar.count];
	for (int i = 0; i < d_ar.count; i++)
		ifst >> d_ar.ar_d[i];
}

void WriteDiagonal(diagonal_ar &d_ar, ofstream &ofst)
{
	ofst << "It is Diagonal Matrix: count of elements = " << d_ar.count << endl << "Matrix:" << endl;
	for (int i = 0; i < d_ar.count; i++)
	{
		for (int j = 0; j < d_ar.count; j++)
			if (i == j)
				ofst << d_ar.ar_d[i] << '\t';
			else
				ofst << "0\t";
		ofst << endl;
	}
}

int DiagonalSum(diagonal_ar &d_ar)
{
	int sum = 0;
	for (int i = 0; i < d_ar.count; i++)
		sum += d_ar.ar_d[i];
	return sum;
}

void ReadUsual(usual_ar &us_ar, ifstream &ifst)
{
	ifst >> us_ar.count;
	us_ar.ar_us = new int*[us_ar.count];
	for (int i = 0; i < us_ar.count; i++)
		us_ar.ar_us[i] = new int[us_ar.count];
	for (int i = 0; i < us_ar.count; i++)
		for (int j = 0; j < us_ar.count; j++)
			ifst >> us_ar.ar_us[i][j];
}

void WriteUsual(usual_ar &us_ar, ofstream &ofst)
{
	ofst << "It is Usual Matrix: count of elements = " << us_ar.count << endl << "Matrix:" << endl;
	for (int i = 0; i < us_ar.count; i++)
	{
		for (int j = 0; j < us_ar.count; j++)
			ofst << us_ar.ar_us[i][j] << '\t';
		ofst << endl;
	}
}

int UsualSum(usual_ar &us_ar)
{
	int sum = 0;
	for (int i = 0; i < us_ar.count; i++)
		for (int j = 0; j < us_ar.count; j++)
			sum += us_ar.ar_us[i][j];
	return sum;
}


int Sum(arrays &ar)
{
	switch (ar.k)
	{
	case arrays::key::Diagonal:
		return DiagonalSum(ar.d);
	case arrays::key::Usual:
		return UsualSum(ar.us);
	default:
		return NULL;
	}
}

arrays* ReadArray(ifstream& ifst)
{
	arrays* ar = new arrays;
	int key;
	ifst >> key;
	switch (key)
	{
	case 1:
		ar->k = arrays::key::Diagonal;
		ReadDiagonal(ar->d, ifst);
		return ar;
	case 2:
		ar->k = arrays::key::Usual;
		ReadUsual(ar->us, ifst);
		return ar;
	default:
		return NULL;
	}
}

void WriteArray(arrays &write_ar, ofstream &ofst)
{
	switch (write_ar.k)
	{
	case arrays::key::Diagonal:
		WriteDiagonal(write_ar.d, ofst);
		ofst << "The sum of the elements = " << DiagonalSum(write_ar.d) << endl;
		break;
	case arrays::key::Usual:
		WriteUsual(write_ar.us, ofst);
		ofst << "The sum of the elements = " << UsualSum(write_ar.us) << endl;

		ofst << "The sum of the elements = " << Sum(write_ar) << endl;
		break;
	case arrays::key::Usual:
		WriteUsual(write_ar.us, ofst);
		ofst << "The sum of the elements = " << Sum(write_ar) << endl;
		break;
	default:
		ofst << "Incorrect array!" << endl;
	}
}