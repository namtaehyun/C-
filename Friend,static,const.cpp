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
	//obj.addNum(20); addNum은 const함수가 아니기때문에 const객체인 obj는 addNum함수를 호출할 수 없다.
	obj.ShowData();
	obj2.addNum(20).ShowData();
}
// 객체에 const선언이 되면 이 객체를 대상으로는 const멤버함수만 호출이 가능하다. 이는 const선언이 이 객체의 데이터 변경을 허용하지 않겠다는 의미이다.
// 멤버변수에 저장된 값을 수정하지 않는 함수는 가급적 const로 선언해서, const 객체에서도 호출이 가능하도록 할 필요가 있다.
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

void YourFunc(const SoSimple &obj) // 매개변수가 const이므로 constSimpleFunc가 나온다. const를 지우면 obj2가 작동하지 않아 에러가 발생한다.
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

//friend 에 대해. A클래스가 B클래스르 대상으로 friend선언을 하면 B클래스는 A클래스의 private멤버에 직접 접근이 가능하다.
//단, A클래스도 B클래스의 private멤버에 직접 접근이 가능하려면, B클래스가 A클래스를 대상으로 Friend선언을 해줘야한다.

/*
#include <iostream>
using namespace std;

class Girl;

class Boy {
private:
	int height;
	friend class Girl; // Girl클래스에 대한 friend선언
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
	friend class Boy; // Boy클래스에 대한 friend선언
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
	//이렇게 클래스에 friend를 선언해주면 서로의 private멤버에 접근할 수 있게된다.
}
//독이될수있습니다. friend의 선언은 자제합니다.
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
	friend Point PointOP::PointSub(const Point&, const Point&); // 연산자를 오버로딩함.
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
	static int cnt; //cnt를 전역변수로 선언해버린것. 이문장은 함수호출과 관계없이 딱 한번만 실행이된다.
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

int simObjCnt = 0; // SoSimple객체들이 공유하는 변수이다,
int cmxObjCnt = 0; // SoComplex객체들이 공유하는 변수이다.

class SoSimple
{
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "번째 SoSimple 객체" << endl;
	}
};

class SoComplex
{
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
	SoComplex(SoComplex &copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
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
		cout << simObjCnt << "번째 SoSimple 객체" << endl;
	}
};
int SoSimple::simObjCnt = 0;

class SoComplex
{
private:
	static int cmxObjCnt;
	const static int ob = 20; // ob는 SoComplex객체내(+friend)에서만 부를수 있고, 이 변수는 처음 초기화하면 끝. 멤버 상수이다. 
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
	SoComplex(SoComplex &copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
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