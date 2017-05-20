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

void ReadTriangle(triangle_ar &tr_ar, ifstream &ifst)
{
	ifst >> tr_ar.count;
	tr_ar.ar_tr = new int*[tr_ar.count];
	for (int i = 0; i < tr_ar.count; i++)
		tr_ar.ar_tr[i] = new int[tr_ar.count];
	for (int i = 0; i < tr_ar.count; i++)
		for (int j = 0; j < tr_ar.count; j++)
			if (i >= j)
				ifst >> tr_ar.ar_tr[i][j];
}

void WriteTriangle(triangle_ar &tr_ar, ofstream &ofst)
{
	ofst << "It is Triangle Matrix: count of elements = " << tr_ar.count << endl << "Matrix:" << endl;
	for (int i = 0; i < tr_ar.count; i++)
	{
		for (int j = 0; j < tr_ar.count; j++)
			if (i >= j)
				ofst << tr_ar.ar_tr[i][j] << '\t';
			else
				ofst << "0\t";
		ofst << endl;
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
	case 3:
		ar->k = arrays::key::Triangle;
		ReadTriangle(ar->tr, ifst);
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
		break;
	case arrays::key::Usual:
		WriteUsual(write_ar.us, ofst);
		break;
	case arrays::key::Triangle:
		WriteTriangle(write_ar.tr, ofst);
		break;
	default:
		ofst << "Incorrect array!" << endl;
	}
}