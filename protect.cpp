
#include "stdafx.h"
#include "protect.h"

using namespace std;

void CheckInputFile(ifstream &ifst)
{
	if (!ifst)
	{
		cerr << "Error: no input file!" << endl;
		getchar();
		getchar();
		exit(1);

	}
}

void CheckWrongInput(ifstream &ifst) // после каждого ifst //ошибка считывания
{
	if (ifst.fail())
	{
		cout << "Wrong input!" << endl;
		getchar();
		getchar();
		exit(1);
	}
}

void CheckOutputFile(ostream &ofst)//только перед самым первым ofst
{
	if (!ofst)
	{
		cerr << "Error: no output file!" << endl;
		getchar();
		getchar();
		exit(1);
	}
}

void CheckKey(int key)
{
	if (key < 1 || key > 2)
	{
		cout << "Incorrect input key." << endl;
		getchar();
		getchar();
		exit(1);
	}
}

void CheckWay(int way)
{
	if (way < 1 || way > 3)
	{
		cout << "Incorrect input way." << endl;
		getchar();
		getchar();
		exit(1);
	}
}

void CheckCount(int count)
{
	if (count < 0)
	{
		cout << "Incorrect input count." << endl;
		getchar();
		getchar();
		exit(1);
	}
}