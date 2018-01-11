/*
#include <iostream>
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
	Person() // 디폴트생성자
	{
		name = nullptr;
		age = 0;
		cout << "called Person()" << endl;
	}

	void SetPersonInfo(char * myname , int myage)
	{
		name = myname;
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}
	~Person()
	{
		delete[]name;
		cout << "called dtor" << endl;
	}
};

void main()
{ 
	Person parr[3]; // 객체는 배열을 사용할 수도 있음.
	char namestr[100];
	char * strptr;
	int age;
	int len;

	for (int i = 0; i < 3; i++)
	{
		cout << "이름"; cin >> namestr;
		cout << "나이"; cin >> age;
		len = strlen(namestr) + 1;
		strptr = new char[len];
		strcpy(strptr, namestr);
		parr[i].SetPersonInfo(strptr, age);
	}
	for (int i = 0; i < 3; i++)
	{
		parr[i].ShowPersonInfo();
	}
}

*/

/*
#include <iostream>
using namespace std;

// this 포인터의 이해
// 객체 자기 자신을 가리키는 용도로 사용되는 포인터이다.

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{
		cout << "num = " << num << ", " << "address = " << this << endl;
	}
	void ShowSimpleData() {
		cout << num << endl;
	}
	SoSimple * GetThisPointer()
	{
		return this;
	}
};

void main()
{
	SoSimple sim1(100);
	SoSimple * ptr1 = sim1.GetThisPointer();
	cout << ptr1 << ", ";
	ptr1->ShowSimpleData();

	SoSimple sim2(200);
	SoSimple * ptr2 = sim2.GetThisPointer();
	cout << ptr2 << ", ";
	ptr2->ShowSimpleData();
}
*/
/*
#include <iostream>
using namespace std;

class TwoNumber {
private:
	int num1, num2;
public:
	TwoNumber(int num1, int num2) //멤버변수
	{
		this->num1 = num1;
		this->num2 = num2;
	}
//	TwoNumber(int num1,int num2):num1(num1),num2(num2){} 
//	멤버 이니셜라이저에서는 this포인터를 사용할 수 없다. 대신 저장하는 변수는 멤버변수로,
//  저장되는 값은 매개변수로 인식을 하기 때문에 여기서 보이는 형태의 문장구성이 가능하다.
	void ShowTwoNumber()
	{
		cout << this->num1 << endl;
		cout << this->num2 << endl;
	}
};

void main()
{
	TwoNumber two(2, 4);
	two.ShowTwoNumber();
}*/

#include <iostream>
using namespace std;

class SelfRef
{
private:
	int num;
public:
	SelfRef(int n) :num(n) {
		cout << "객체 생성" << endl;
	}
	SelfRef& Adder(int n)
	{
		num += n;
		return *this;
	}
	SelfRef& ShowTwoNumber()
	{
		cout << num << endl;
		return *this;
	}
};

void main()
{
	SelfRef obj(3);
	SelfRef &ref = obj.Adder(2);

	obj.ShowTwoNumber();
	ref.ShowTwoNumber();

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber(); //?!?!??!?!?!?!?!?!?!? 뭐지 이거
}