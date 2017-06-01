#include "stdafx.h";
#include "container.h"
#include <fstream>

using namespace std;

arrays* ReadArray(ifstream& ifst);
void WriteArray(arrays &write_ar, ofstream &ofst);

int Sum(arrays &ar);

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
	while (temp != 0)
	{
		if (temp->ar->k == 1)
			WriteArray(*(temp->ar), ofst);
		temp = temp->next;
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

void Sorting(container &c, bool sort)
{
	element *current = c.data, *temp = NULL, *prev = NULL;
	bool flag;
	do
	{
		flag = false;
		current = c.data;
		while (current->next)
		{
			if (sort == true)
			{
				if (Sum(*(current->ar)) > Sum(*(current->next->ar)))
				{
					if (current == c.data)
					{
						temp = current;
						current = temp->next;
						temp->next = current->next;
						current->next = temp;
						c.data = current;
						flag = true;
					}
					else
					{
						temp = current;
						current = temp->next;
						temp->next = current->next;
						current->next = temp;
						prev->next = current;
						flag = true;
					}
				}
			}
			else
			{
				if (Sum(*(current->ar)) < Sum(*(current->next->ar)))
				{
					if (current == c.data)
					{
						temp = current;
						current = temp->next;
						temp->next = current->next;
						current->next = temp;
						c.data = current;
						flag = true;
					}
					else
					{
						temp = current;
						current = temp->next;
						temp->next = current->next;
						current->next = temp;
						prev->next = current;
						flag = true;
					}
				}
			}
			prev = current;
			current = current->next;
		}
	} while (flag);
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
				case arrays::Triangle:
					ofst << "Diagonal & Triangle arrays" << endl;
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
				case arrays::Triangle:
					ofst << "Usual & Triangle arrays" << endl;
					break;
				default:
					ofst << "Unknown type" << endl;
					break;
				}
				break;
			case arrays::Triangle:
				switch (temp2->ar->k)
				{
				case arrays::Diagonal:
					ofst << "Triangle & Diagonal arrays" << endl;
					break;
				case arrays::Usual:
					ofst << "Triangle & Usual arrays" << endl;
					break;
				case arrays::Triangle:
					ofst << "Triangle & Triangle arrays" << endl;
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