#include "stdafx.h";
#include "container.h"
#include <fstream>

using namespace std;

arrays* ReadArray(ifstream& ifst);
void WriteArray(arrays &write_ar, ofstream &ofst);

void Init(container& c)
{
	c.data = NULL;
}

void Input(container& c, ifstream& ifst)
{
	while (!ifst.eof())
	{
		element* temp = new element;
		temp->ar = ReadArray(ifst);
		temp->next = c.data;
		c.data = temp;
		c.lenght++;
	}
}

void Output(container& c, ofstream &ofst)
{
	ofst << "Container content " << c.lenght << " elements." << endl;
	element* temp = c.data;
	int num = c.lenght;
	while (temp != NULL)
	{
		ofst << num << ": ";
		WriteArray(*(temp->ar), ofst);
		temp = temp->next;
		num--;
	}
}

void Clear(container& c)
{
	while (c.data != 0)
	{
		element* temp = c.data->next;
		delete c.data;
		c.data = temp;
	}
	c.lenght = 0;
}