// proc1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "windows.h"
#include "container.h"

using namespace std;

void Init(container& c);
void Input(container& c, ifstream& ifst);
void Output(container& c, ofstream& ofst);
void Clear(container& c);
void Sorting(container &c, bool sort);

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if (argc != 3) 
	{
		cout << "Incorrect command line! Waited: command in_file out_file" << endl;
		exit(1);
	}
	ifstream in(argv[1]);
	ofstream out(argv[2]);

	cout << "Start" << endl;
	container c;
	Init(c);
	Input(c, in);
	Sorting(c,true);
	Output(c, out);
	Clear(c);
	out << "Empty container." << endl;
	Output(c, out);
	cout << "Stop" << endl;
	in.close();
	out.close();
	system("pause");
    return 0;
}

