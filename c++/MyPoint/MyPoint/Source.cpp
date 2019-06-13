#include "stdafx.h"
#include "MyPoint.h"
#include <iostream>
using namespace std;

void main()
{
	MyPoint* p1 = new MyPoint(4,5);
	MyPoint* p2 = new MyPoint(1,2);
	p1->Display();
	p2->Display();
	cout << "distance between p1 and p2: " << p1->Distance(p2) << endl;
	system("pause");
}