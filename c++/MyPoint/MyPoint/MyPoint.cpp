// MyPoint.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "MyPoint.h"
#include <iostream>
#include <cmath>
using namespace std;

MyPoint::MyPoint():

	mPosX(0),
	mPosY(0)
{
}

MyPoint::MyPoint(int _mPosX, int _mPosy):
	mPosX(_mPosX),
	mPosY(_mPosy)
{
}

void MyPoint::Display()
{
	cout << mPosX << endl;
	cout << mPosY << endl;
}

void MyPoint::SetX(int _mPosX)
{
	this->mPosX = _mPosX;
}
int MyPoint::GetX()
{
	return this->mPosX;
}
void MyPoint::SetY(int _mPosY)
{
	this->mPosY = _mPosY;
}
int MyPoint::GetY()
{
	return this->mPosY;
}
double MyPoint::Distance(MyPoint *p)
{
	return sqrt(pow(this->mPosX - p->GetX(), 2) + pow(this->mPosY - p->GetY(), 2));
}