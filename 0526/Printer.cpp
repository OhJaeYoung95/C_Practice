#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Printer.h"

using namespace std;

void Printer::SetString(const char* inputWords)
{
	strcpy(words, inputWords);
}
void Printer::ShowString()
{
	cout << words << endl;
}
