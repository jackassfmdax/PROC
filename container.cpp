#include "stdafx.h";
#include "container.h"
#include <fstream>

using namespace std;

arrays* ReadArray(ifstream& ifst);
void WriteArray(arrays &write_ar, ofstream &ofst);
//инициализация  контейнера
void Init(container& c)
{
	c.data = NULL;
}
//ввод матриц в контейнер из указанного потока
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
//вывод содержимого контейнера в заданный выходной поток
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
//удаление матриц, установка контейнера в начальное состояние
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