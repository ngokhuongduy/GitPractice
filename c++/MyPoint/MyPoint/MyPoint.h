#pragma once
class MyPoint
{
private:
	int mPosX;
	int mPosY;
public:
	MyPoint();
	MyPoint(int _mPosX, int _mPosY);
	void Display();
	void SetX(int _mPosX);
	int GetX();
	void SetY(int _mPosY);
	int GetY();
	double Distance(MyPoint *p);
};
