#include "stdafx.h"
#include <fstream>
#include "array.h"
#include "protect.h"

using namespace std;

void ReadDiagonal(diagonalArray &diagAr, ifstream &ifst)
{
	ifst >> diagAr.count;
	CheckCount(diagAr.count);//
	diagAr.arD = new int[diagAr.count];
	for (int i = 0; i < diagAr.count; i++)
		ifst >> diagAr.arD[i];
}

void WriteDiagonal(diagonalArray &diagAr, ofstream &ofst)
{
	ofst << "It is Diagonal Matrix: count of elements = " << diagAr.count << endl << "Matrix:" << endl;
	for (int i = 0; i < diagAr.count; i++)
	{
		for (int j = 0; j < diagAr.count; j++)
			if (i == j)
				ofst << diagAr.arD[i] << '\t';
			else
				ofst << "0\t";
		ofst << endl;
	}
}

int DiagonalSum(diagonalArray &diagAr)
{
	int sum = 0;
	for (int i = 0; i < diagAr.count; i++)
		sum += diagAr.arD[i];
	return sum;
}

void ReadUsual(usualArray &usualAr, ifstream &ifst)
{
	ifst >> usualAr.count;
	CheckCount(usualAr.count);//
	usualAr.arUs = new int*[usualAr.count];
	for (int i = 0; i < usualAr.count; i++)
		usualAr.arUs[i] = new int[usualAr.count];
	for (int i = 0; i < usualAr.count; i++)
		for (int j = 0; j < usualAr.count; j++)
			ifst >> usualAr.arUs[i][j];
}

void WriteUsual(usualArray &usualAr, ofstream &ofst)
{
	ofst << "It is Usual Matrix: count of elements = " << usualAr.count << endl << "Matrix:" << endl;
	for (int i = 0; i < usualAr.count; i++)
	{
		for (int j = 0; j < usualAr.count; j++)
			ofst << usualAr.arUs[i][j] << '\t';
		ofst << endl;
	}
}

void ReadTriangle(triangleArray &triangleAr, ifstream &ifst)
{
	ifst >> triangleAr.count;
	CheckCount(triangleAr.count);//
	triangleAr.arTr = new int*[triangleAr.count];
	for (int i = 0; i < triangleAr.count; i++)
		triangleAr.arTr[i] = new int[triangleAr.count];
	for (int i = 0; i < triangleAr.count; i++)
		for (int j = 0; j < triangleAr.count; j++)
			if (i >= j)
				ifst >> triangleAr.arTr[i][j];
			else
				triangleAr.arTr[i][j] = 0;
}

void WriteTriangle(triangleArray &triangleAr, ofstream &ofst)
{
	ofst << "It is Triangle Matrix: count of elements = " << triangleAr.count << endl << "Matrix:" << endl;
	for (int i = 0; i < triangleAr.count; i++)
	{
		for (int j = 0; j < triangleAr.count; j++)
			if (i >= j)
				ofst << triangleAr.arTr[i][j] << '\t';
			else
				ofst << "0\t";
		ofst << endl;
	}
}

int UsualSum(usualArray &usualAr)
{
	int sum = 0;
	for (int i = 0; i < usualAr.count; i++)
		for (int j = 0; j < usualAr.count; j++)
			sum += usualAr.arUs[i][j];
	return sum;
}

int TrianglSum(triangleArray &triangleAr)
{
	int sum = 0;
	for (int i = 0; i < triangleAr.count; i++)
		for (int j = 0; j < triangleAr.count; j++)
			sum += triangleAr.arTr[i][j];
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
	case arrays::key::Triangle:
		return TrianglSum(ar.tr);
	default:
		return NULL;
	}
}

arrays* ReadArray(ifstream& ifst)
{
	arrays* ar = new arrays;
	int key;
	CheckInputFile(ifst);//
	ifst >> key;
	CheckWrongInput(ifst);//
	CheckKey(key);//
	int w;
	ifst >> w;
	CheckWay(w);
	w--;
	ar->w = (arrays::way)w;
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

void WriteArray(arrays &writeAr, ofstream &ofst)
{
	switch (writeAr.k)
	{
	case arrays::key::Diagonal:
		WriteDiagonal(writeAr.d, ofst);
		ofst << "The sum of the elements = " << DiagonalSum(writeAr.d) << endl;
		break;
	case arrays::key::Usual:
		WriteUsual(writeAr.us, ofst);
		ofst << "The sum of the elements = " << UsualSum(writeAr.us) << endl;
		break;
	case arrays::key::Triangle:
		WriteTriangle(writeAr.tr, ofst);
		ofst << "The sum of the elements = " << TrianglSum(writeAr.tr) << endl;
		break;
	default:
		ofst << "Incorrect array!" << endl;
	}
	string w[3] = { "String", "Column", "Vector" };
	ofst << w[writeAr.w].c_str() << endl;
}