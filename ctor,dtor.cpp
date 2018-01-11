// 생성자와 소멸자
/*
생성자의 특징
1. 클래스의 이름과 함수의 이름이 동일하다.
2. 반환형이 선언되어있지 않으며, 실제로 반환하지 않는다.
3. 객체 생성시 딱 한번만 호출된다.
4. 오버로딩이 가능하다.
5. 매개변수에 디폴트값을 설정할 수 있다.
*/

/* 생성자 오버로딩

#include <iostream>
using namespace std;

class SimpleClass {
private:
	int num1, num2;
public:
	SimpleClass()// 생성자
	{
		num1 = 0; num2 = 0;
	}
	SimpleClass(int n)
	{
		num1 = n;
		num2 = 0;
	}
	SimpleClass(int n1, int n2)
	{
		num1 = n1;
		num2 = n2;
	}

	void ShowData() const
	{
		cout << num1 << ' ' << num2 << endl;
	}
};

int main()
{
	SimpleClass sc1;
	sc1.ShowData();

	SimpleClass sc2(100);
	sc2.ShowData();

	SimpleClass sc3(100, 200);
	sc3.ShowData();
	return 0;
}*/

/*
#include <iostream>
using namespace std;

class FruitSeller {
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	FruitSeller(int price,int num, int money):APPLE_PRICE(price),numOfApples(num),myMoney(money){}// 멤버 이니셜라이저를 이용한 생성자의 초기화
	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult() const {
		cout << "남은 사과: " << numOfApples << endl;
		cout << "판매 수익: " << myMoney << endl << endl;
	}
};

class FruitBuyer {
private:
	int myMoney;
	int numOfApples;
public:
	FruitBuyer(int money) :myMoney(money), numOfApples(0) {} // 멤버 이니셜라이저를 이용한 생성자의 초기화
	void BuyApples(FruitSeller &seller, int money)
	{
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult() const {
		cout << "현재 잔액" << myMoney << endl;
		cout << "사과 개수" << numOfApples << endl << endl;
	}

};

int main()
{
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);
	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();
}
*/
/*
// 멤버변수로 참조자를 선언할 수 있다.
//디폴트 생성자 -> 객체가 되기 위해서는 반드시 하나의 생성자가 호출되어야 한다. 디폴트 생성자는 생성자가 호출은 되는데 아무것도 안하는 것이다.

#include <iostream>
using namespace std;

class AAA {
private:
	int num;
public:
	int GetNum(){ return num; }
	AAA()  // 디폴트생성자 -> 아무것도안함.
	{
	}
	void ShowYourName()
	{
		cout << "I'm class AAA" << endl;
	}
};

class BBB {
	AAA & ref;
	const int &num;
public:
	BBB(AAA &r, const int &n) :ref(r),num(n) {}; // 이런식으로 생성자와 상수도 이니셜라이저를 이용하여 초기화 할 수 있다.
	void ShowYourName()
	{
		ref.ShowYourName();
		cout << "and" << endl;
		cout << "I'm ref num" << endl;
	}
};

void main()
{
	AAA obj1;
	BBB obj2(obj1,20);
	obj2.ShowYourName();
}

*/

/*
// private 생성자
// 클래스 내부에서 객체를 생성한다면, 생성자가 private로 선언 되어도된다.
#include <iostream>
using namespace std;

class AAA {
private:
	int num;
public:
	AAA():num(0){}
	AAA& CreateInitObj(int n) const 
	{
		AAA * ptr = new AAA(n);
		return *ptr;
	}
	void ShowNum()const {
		cout << num << endl;
	}
private:
	AAA(int n) :num(n){} //private로 선언된 생성자도 선언이 가능하다. -> 객체의 생성방법을 제한하고자 하는 경우에 매우 유용함.
};

void main()
{
	AAA base;
	base.ShowNum();

	AAA &obj1 = base.CreateInitObj(3); // 이런식으로!
	obj1.ShowNum();
	AAA &obj2 = base.CreateInitObj(12);
	obj2.ShowNum();

	delete &obj1;
	delete &obj2;
}

*/

// 소멸자
// 소멸자는 생성자에서 할당한 리소스의 소멸에 사용된다.
// 예를 들어 생성자 내에서 new연산자를 이용해서 할당해놓은 메모리 공간이 있다면,
// 소멸자에서는 delete 연산자를 이용해 이 메모리 공간을 소멸한다.
#include<iostream>
using namespace std;

class Person {
private:
	char * name;
	int age;
public:
	Person(const char * myname, int myage) {
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}
	~Person()
	{
		delete []name;
		cout << "called dtor" << endl;
	}
};

void main()
{
	Person man1("Lee dong woo", 29);
	Person man2("jang dong gun", 41);

	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
}