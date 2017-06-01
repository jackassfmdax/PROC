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

void MultiMethod(container &c, ofstream &ofst)
{
	element *temp1 = c.data;
	element *temp2 = c.data;
	while (temp1->next != NULL)
	{
		temp2 = temp1->next;
		while (temp2 != NULL)
		{
			switch (temp1->ar->k)
			{
			case arrays::Diagonal:
				switch (temp2->ar->k)
				{
				case arrays::Diagonal:
					ofst << "Diagonal & Diagonal arrays" << endl;
					break;
				case arrays::Usual:
					ofst << "Diagonal & Usual arrays" << endl;
					break;
				default:
					ofst << "Unknown type" << endl;
					break;
				}
				break;
			case arrays::Usual:
				switch (temp2->ar->k)
				{
				case arrays::Diagonal:
					ofst << "Usual & Diagonal arrays" << endl;
					break;
				case arrays::Usual:
					ofst << "Usual & Usual arrays" << endl;
					break;
				default:
					ofst << "Unknown type" << endl;
					break;
				}
				break;
			default:
				ofst << "Unknown type" << endl;
				break;
			}
			WriteArray(*(temp1->ar), ofst);
			WriteArray(*(temp2->ar), ofst);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}