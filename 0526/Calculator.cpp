#include <iostream>
#include "Calculator.h"

using namespace std;

//void Init();
//int Add(int num1, int num2);
//int Min(int num1, int num2);
//int Mul(int num1, int num2);
//int Div(int num1, int num2);
//void ShowOpCount();

void Calculator::Init()
{
	num1 = 0;
	num2 = 0;
	addCount = 0;
	minCount = 0;
	divCount = 0;
	mulCount = 0;
}

double Calculator::Add(double num1, double num2)
{
	addCount++;
	return num1 + num2;
}
double Calculator::Min(double num1, double num2)
{
	minCount++;
	return num1 - num2;
}
double Calculator::Mul(double num1, double num2)
{
	mulCount++;
	return num1 * num2;
}
double Calculator::Div(double num1, double num2)
{
	divCount++;
	return num1 / num2;
}



void Calculator::ShowOpCount()
{
	cout << "µ¡¼À: " << addCount << "  »¬¼À: " << minCount << "  °ö¼À: " << mulCount << "  ³ª´«¼À: " << divCount;
}
