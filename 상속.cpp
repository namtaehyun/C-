// ��� - ������
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
	// ��Ʈ�� Ŭ����
	//��Ʈ�� Ŭ������ ��������� �ٽ��� �Ǳ� ������ ��� ��ü���� ���α׷����� �ݵ�� �����ؾ� �ϴ� Ŭ�����̴�.
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
// �� ������ �����ϱ� ������ ��ӿ� �ǹ̰� ����. ������, ���⿡ �������� �ƴ� �ӽ����� �������� �ִ´ٸ�? �Ȱ��� ���·� 2������ Ŭ������ �Ǹ������Ѵ�.
// ���� �׷��� �������ϳ�? �Ȱ��� �����ϴ� �������� �ִµ�.. �׷��� �����ϴ� ���� ��� �����̴�.
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

