// �����ڿ� �Ҹ���
/*
�������� Ư¡
1. Ŭ������ �̸��� �Լ��� �̸��� �����ϴ�.
2. ��ȯ���� ����Ǿ����� ������, ������ ��ȯ���� �ʴ´�.
3. ��ü ������ �� �ѹ��� ȣ��ȴ�.
4. �����ε��� �����ϴ�.
5. �Ű������� ����Ʈ���� ������ �� �ִ�.
*/

/* ������ �����ε�

#include <iostream>
using namespace std;

class SimpleClass {
private:
	int num1, num2;
public:
	SimpleClass()// ������
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
	FruitSeller(int price,int num, int money):APPLE_PRICE(price),numOfApples(num),myMoney(money){}// ��� �̴ϼȶ������� �̿��� �������� �ʱ�ȭ
	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult() const {
		cout << "���� ���: " << numOfApples << endl;
		cout << "�Ǹ� ����: " << myMoney << endl << endl;
	}
};

class FruitBuyer {
private:
	int myMoney;
	int numOfApples;
public:
	FruitBuyer(int money) :myMoney(money), numOfApples(0) {} // ��� �̴ϼȶ������� �̿��� �������� �ʱ�ȭ
	void BuyApples(FruitSeller &seller, int money)
	{
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult() const {
		cout << "���� �ܾ�" << myMoney << endl;
		cout << "��� ����" << numOfApples << endl << endl;
	}

};

int main()
{
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);
	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();
}
*/
/*
// ��������� �����ڸ� ������ �� �ִ�.
//����Ʈ ������ -> ��ü�� �Ǳ� ���ؼ��� �ݵ�� �ϳ��� �����ڰ� ȣ��Ǿ�� �Ѵ�. ����Ʈ �����ڴ� �����ڰ� ȣ���� �Ǵµ� �ƹ��͵� ���ϴ� ���̴�.

#include <iostream>
using namespace std;

class AAA {
private:
	int num;
public:
	int GetNum(){ return num; }
	AAA()  // ����Ʈ������ -> �ƹ��͵�����.
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
	BBB(AAA &r, const int &n) :ref(r),num(n) {}; // �̷������� �����ڿ� ����� �̴ϼȶ������� �̿��Ͽ� �ʱ�ȭ �� �� �ִ�.
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
// private ������
// Ŭ���� ���ο��� ��ü�� �����Ѵٸ�, �����ڰ� private�� ���� �Ǿ�ȴ�.
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
	AAA(int n) :num(n){} //private�� ����� �����ڵ� ������ �����ϴ�. -> ��ü�� ��������� �����ϰ��� �ϴ� ��쿡 �ſ� ������.
};

void main()
{
	AAA base;
	base.ShowNum();

	AAA &obj1 = base.CreateInitObj(3); // �̷�������!
	obj1.ShowNum();
	AAA &obj2 = base.CreateInitObj(12);
	obj2.ShowNum();

	delete &obj1;
	delete &obj2;
}

*/

// �Ҹ���
// �Ҹ��ڴ� �����ڿ��� �Ҵ��� ���ҽ��� �Ҹ꿡 ���ȴ�.
// ���� ��� ������ ������ new�����ڸ� �̿��ؼ� �Ҵ��س��� �޸� ������ �ִٸ�,
// �Ҹ��ڿ����� delete �����ڸ� �̿��� �� �޸� ������ �Ҹ��Ѵ�.
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
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
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