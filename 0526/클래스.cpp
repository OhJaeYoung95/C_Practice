#include <iostream>
#include "Point.h"
#include "Calculator.h"
#include "Printer.h"

using namespace std;

void Practice1()
{
	Point pos1;
	Point pos2;
	pos1.PointInit(12, 4);
	pos2.PointInit(20, 30);
	
	cout << "ÁÂÇ¥ ÀÌµ¿" << endl;
	pos1.MovePos(-7, 10);
	pos1.ShowPosition();

	cout << "ÁÂÇ¥ Áõ°¡" << endl;
	pos1.AddPoint(pos2);
	pos1.ShowPosition();
}

void Practice2()
{
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 + 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "4.2 + 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 + 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
}

void Practice3()
{
	Printer pnt;
	pnt.SetString("Hello World!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();
}

int main()
{
	Practice3();
	return 0;
}