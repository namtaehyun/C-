#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	void Init(int x, int y);
	void ShowPointInfo() const;
};

void Point::Init(int x, int y)
{
	xpos = x;
	ypos = y;
}
void Point::ShowPointInfo() const
{
	cout << "[" << xpos << ", " << ypos << "]" << endl;
}

class Circle {
private:
	Point center; // 원의 중심좌표
	int rad; // 원의 반지름
public:
	void Init(int x, int y, int rad);
	void ShowCircleInfo();
};

void Circle::Init(int x,int y,int r)
{
	rad = r;
	center.Init(x, y);
}
void Circle::ShowCircleInfo() {
	cout << "radius: " << rad << endl;
	center.ShowPointInfo();
}

class Ring {
private:
	Circle innerCircle;
	Circle outerCircle;
public:
	void Init(int x1, int y1, int rad1, int x2, int y2, int rad2);
	void ShowRingInfo();
};

void Ring::Init(int x1,int y1,int rad1,int x2,int y2,int rad2){
	innerCircle.Init(x1, y1, rad1);
	outerCircle.Init(x2, y2, rad2);
}

void Ring::ShowRingInfo() 
{
	cout << "Inner Circle Info..." << endl;
	innerCircle.ShowCircleInfo();
	cout << "Outer Circle Info..." << endl;
	outerCircle.ShowCircleInfo();
}

int main()
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}