/*
#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n):num(n){}
	SoSimple & addNum(int n) {
		num += n;
		return *this;
	}
	void ShowData()const
	{
		cout << "num: " << num << endl;
	}
};


void main()
{
	const SoSimple obj(7);
	SoSimple obj2(2);
	//obj.addNum(20); addNum�� const�Լ��� �ƴϱ⶧���� const��ü�� obj�� addNum�Լ��� ȣ���� �� ����.
	obj.ShowData();
	obj2.addNum(20).ShowData();
}
// ��ü�� const������ �Ǹ� �� ��ü�� ������δ� const����Լ��� ȣ���� �����ϴ�. �̴� const������ �� ��ü�� ������ ������ ������� �ʰڴٴ� �ǹ��̴�.
// ��������� ����� ���� �������� �ʴ� �Լ��� ������ const�� �����ؼ�, const ��ü������ ȣ���� �����ϵ��� �� �ʿ䰡 �ִ�.
*/
/*
#include <iostream>
using namespace std;
class SoSimple {
private:
	int num;
public:
	SoSimple(int n):num(n){}
	SoSimple& AddNum(int n) {
		num += n;
		return *this;
	}
	void SimpleFunc() {
		cout << "SimpleFunc : " << num << endl;
	}
	void SimpleFunc() const
	{
		cout << "const SimpleFunc: " << num << endl;
	}
};

void YourFunc(const SoSimple &obj) // �Ű������� const�̹Ƿ� constSimpleFunc�� ���´�. const�� ����� obj2�� �۵����� �ʾ� ������ �߻��Ѵ�.
{
	obj.SimpleFunc();
}
void main()
{
	SoSimple obj1(2);
	const SoSimple obj2(7);
	obj1.SimpleFunc();
	obj2.SimpleFunc();

	YourFunc(obj1);
	YourFunc(obj2);
}
*/

//friend �� ����. AŬ������ BŬ������ ������� friend������ �ϸ� BŬ������ AŬ������ private����� ���� ������ �����ϴ�.
//��, AŬ������ BŬ������ private����� ���� ������ �����Ϸ���, BŬ������ AŬ������ ������� Friend������ ������Ѵ�.

/*
#include <iostream>
using namespace std;

class Girl;

class Boy {
private:
	int height;
	friend class Girl; // GirlŬ������ ���� friend����
public:
	Boy(int len):height(len){}
	void ShowYourFriend(Girl &frn);
};

class Girl
{
private:
	char phNum[20];
public:
	Girl(const char *num)
	{
		strcpy(phNum, num);
	}
	void ShowYourFriendInfo(Boy &frn);
	friend class Boy; // BoyŬ������ ���� friend����
};

void Boy::ShowYourFriend(Girl &frn)
{
	cout << "Her phone number : " << frn.phNum << endl;
}

void Girl::ShowYourFriendInfo(Boy &frn)
{
	cout << "His height : " << frn.height << endl;
}

void main()
{
	Boy boy(170);
	Girl girl("010-2221-3321");
	boy.ShowYourFriend(girl);
	girl.ShowYourFriendInfo(boy);
	//�̷��� Ŭ������ friend�� �������ָ� ������ private����� ������ �� �ְԵȴ�.
}
//���̵ɼ��ֽ��ϴ�. friend�� ������ �����մϴ�.
*/

/*
#include<iostream>

using namespace std;

class Point;

class PointOP
{
private:
	int opcnt;
public:
	PointOP() : opcnt(0){}
	Point PointAdd(const Point &, const Point &);
	Point PointSub(const Point &, const Point&);
	~PointOP() 
	{
		cout << "Operation time" << opcnt << endl;
	}
};

class Point
{
private:
	int x, y;
public:
	Point (const int &xpos,const int &ypos):x(xpos),y(ypos){}
	friend Point PointOP::PointAdd(const Point&, const Point&);
	friend Point PointOP::PointSub(const Point&, const Point&); // �����ڸ� �����ε���.
	friend void ShowPointPos(const Point &);
};

Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2)
{
	opcnt++;
	return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y);
}

Point PointOP::PointSub(const Point& pnt1, const Point& pnt2)
{
	opcnt++;
	return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);	
}

void ShowPointPos(const Point& pos)
{
	cout << "x: " << pos.x << ", " << "y: " << pos.y << endl;
}

int main()
{
	Point pos1(1, 2);
	Point pos2(2, 4);
	PointOP op;
	ShowPointPos(op.PointAdd(pos1, pos2));
	ShowPointPos(op.PointSub(pos1, pos2));
	return 0;
}
*/

/*
#include <iostream>
using namespace std;

void Counter()
{
	static int cnt; //cnt�� ���������� �����ع�����. �̹����� �Լ�ȣ��� ������� �� �ѹ��� �����̵ȴ�.
	cnt++;
	cout << "Current cnt: " << cnt << endl;
}

int main()
{
	for (int i = 0; i < 10; i++)
		Counter();
	return 0;
}
*/
/*
#include<iostream>
using namespace std;

int simObjCnt = 0; // SoSimple��ü���� �����ϴ� �����̴�,
int cmxObjCnt = 0; // SoComplex��ü���� �����ϴ� �����̴�.

class SoSimple
{
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "��° SoSimple ��ü" << endl;
	}
};

class SoComplex
{
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}
	SoComplex(SoComplex &copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}
};

void main()
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex();
}

*/

#include <iostream>
using namespace std;

class SoSimple
{
private:
	static int simObjCnt;
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "��° SoSimple ��ü" << endl;
	}
};
int SoSimple::simObjCnt = 0;

class SoComplex
{
private:
	static int cmxObjCnt;
	const static int ob = 20; // ob�� SoComplex��ü��(+friend)������ �θ��� �ְ�, �� ������ ó�� �ʱ�ȭ�ϸ� ��. ��� ����̴�. 
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}
	SoComplex(SoComplex &copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}

};
int SoComplex::cmxObjCnt = 0;

void main()
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex cmx1;
	SoComplex cmx2 = cmx1;
	SoComplex();
}