#pragma once

class Calculator
{
private:
	double num1;
	double num2;
	int addCount;
	int minCount;
	int mulCount;
	int divCount;

public:

	void Init();
	double Add(double num1, double num2);
	double Min(double num1, double num2);
	double Mul(double num1, double num2);
	double Div(double num1, double num2);
	void ShowOpCount();
	//void GetCount(int num);
};