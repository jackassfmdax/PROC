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

int main(int argc, char* argv[])
{
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
	out << "Filled contienr." << endl;
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

