#include <fstream>
#include <iostream>
#ifndef _protect
#define _protect 

using namespace std;

void CheckInputFile(ifstream &ifst);
void CheckWrongInput(ifstream &ifst);
void CheckOutputFile(ostream &ofst);
void CheckKey(int key);
void CheckWay(int way);
void CheckCount(int count);

#endif // !_protect