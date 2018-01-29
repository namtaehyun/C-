// 상속 - 다형성
/*
#include<iostream>
using namespace std;

class PermanentWorker
{
private:
	char name[100];
	int salary;
public:
	PermanentWorker(const char * name, int money) :salary(money) {
		strcpy(this->name, name);
	}
	int GetPay()const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		cout << "name: " << name << endl;
		cout << "salary: " << GetPay() << endl<<endl;
	}
};

class EmployeeHandler 
	// 컨트롤 클래스
	//컨트롤 클래스는 기능제공의 핵심이 되기 떄문에 모든 객체지향 프로그램에서 반드시 존재해야 하는 클래스이다.
{
private:
	PermanentWorker * empList[50];
	int empNum;
public:
	EmployeeHandler() :empNum(0) {}
	void AddEmployee(PermanentWorker*emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++) {
			empList[i]->ShowSalaryInfo();
		}
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
		{
			sum += empList[i]->GetPay();
		}
		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};
void main()
{
	EmployeeHandler handler;

	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	handler.ShowAllSalaryInfo();

	handler.ShowTotalSalary();
}
// 이 예제는 간단하기 때문에 상속에 의미가 없다. 하지만, 여기에 정규직이 아닌 임시직과 영업직을 넣는다면? 똑같은 형태로 2가지의 클래스를 또만들어야한다.
// 굳이 그렇게 만들어야하나? 똑같이 존재하는 정보들이 있는뎅.. 그래서 도입하는 것이 상속 개념이다.
*/

/*
#include <iostream>
using namespace std;

class Person
{
private:
	int age;
	char name[50];
public:
	Person(int myage,const char * myname) :age(myage)
	{
		strcpy(name, myname);
	}
	void WhatYourName()const
	{
		cout << "My name is " << name << endl;
	}
	void HowOldAreYou()const
	{
		cout << "I'm" << age << " years old" << endl;
	}
};

class UnivStudent :public Person
{
private:
	char major[50];
public:
	UnivStudent(const char * name, int myage,const char * mymajor) :Person(myage,name)
	{
		strcpy(major, mymajor);
	}
	void WhoAreYou() const
	{
		WhatYourName();
		HowOldAreYou();
		cout << "My Major is " << major << endl;
	}
};

void main()
{
	UnivStudent ustd1("Lee", 22, "Computer Engineering");
	ustd1.WhoAreYou();
	UnivStudent ustd2("Yoon", 21, "Electronic Engineering");
	ustd2.WhoAreYou();
}
*/
/*
#include <iostream>
using namespace std;

class SoBase
{
private:
	int baseNum;
public:
	SoBase() :baseNum(20)
	{
		cout << "SoBase()" << endl;
	}
	SoBase(int n) :baseNum(n)
	{
		cout << "SoBase(int n)" << endl;
	}
	void ShowBaseData()
	{
		cout << baseNum << endl;
	}
};

class SoDerived :public SoBase
{
private:
	int derivNum;
public:
	SoDerived() :derivNum(30)
	{
		cout << "SoDerived()" << endl;
	}
	SoDerived(int n) :derivNum(n)
	{
		cout << "SoDerived(int n)" << endl;
	}
	SoDerived(int n1,int n2) :SoBase(n2),derivNum(n1)
	{
		cout << "SoDerived(int n1,int n2)" << endl;
	}
	void ShowDerivData()
	{
		ShowBaseData();
		cout <<derivNum << endl;
	}
};

int main()
{
	cout << "case1....." << endl;
	SoDerived dr1;
	dr1.ShowDerivData();
	cout << "..........." << endl;
	cout << "case2....." << endl;
	SoDerived dr2(12);
	dr2.ShowDerivData();
	cout << "..........." << endl;
	cout << "case3....." << endl;
	SoDerived dr3(23,24);
	dr3.ShowDerivData();
	cout << "..........." << endl;

	return 0;
}
*/

//private<protected<public

