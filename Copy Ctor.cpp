// 복사생성자
/*
#include<iostream>
using namespace std;

class SoSimple {
private:
	int num1, num2;
public:
	SoSimple(int n1, int n2) :num1(n1), num2(n2) {} // 그냥 생성자
	SoSimple(const SoSimple &copy) :num1(copy.num1), num2(copy.num2) {} // 디폴트 복사 생성자 = 복사생성자를 이렇게 굳이 선언안해도 자동적으로 복사생성자를 만든다.
																  // 많은 경우에 있어 복사생성자가 이렇게 만들어지니까 굳이 만들 필요가 없는 경우가 많다. 하지만,
																  // 그렇지 않은 경우도 있다. 
	void ShowSimpleData() { cout << num1 << ", " << num2 << endl; }
};

void main()
{
	SoSimple sim1(15, 20);
	SoSimple sim2(sim1);

	sim1.ShowSimpleData();
	sim2.ShowSimpleData();
}
*/
/*
얕은복사 깊은복사
#include <iostream>
using namespace std;
class Person {
	char * name;
	int age;
public:
	Person(const char * name, int myage) {
		int len = strlen(name) + 1;
		this->name = new char[len];
		strcpy(this->name, name);
		age = myage;
	}
	// 이녀석이 깊은 복사를 할 수 있게 해준다.
	Person(const Person& copy)
	{
		this->name = new char[strlen(copy.name) + 1];
		strcpy(this->name, copy.name);
		age = copy.age;
	}


	void ShowPerson() const {
		cout << "이름 :" << name << endl;
		cout << "나이 :" << age << endl;
	}
	~Person()
	{
		delete[]name;
	}
};

void main()
{
	Person man1("Lee Dong Woo", 29);
	Person man2(man1); // 디폴트 복사생성자를 사용한다.
	man1.ShowPerson();
	man2.ShowPerson();
}
//-> 디폴트복사생성자를 사용하게 되면 멤버대 멤버를 단순히 복사만하므로, man1객체와 man2객체가 가리키는 포인터가 같다.
// 그런데, 소멸자를 한명만 사용해도 나머지 한명이 가리키고 있던 포인터를 소멸시켜버리므로, 에러가 빡! 하고 난다.
// 따라서, 둘 다 각각의 포인터를 가리키게 만들어줘야 한다.
*/

/*
복사생성자의 호출시점
1. 기존에 생성된 객체를 이용하여 새로운 객체를 초기화하는 경우
2. Call By Value방식의 함수호출 과정에서 객체를 인자로 전달하는 경우
3. 객체를 반환하되, 참조형으로 반환하지 않는 경우
이 세가지 case의 공통점은 객체를 새로 생성해야한다. 단, 생성과 동시에 동일한 자료형의 객체로 초기화 해야 한다.

메모리 공간의 할당과 초기화가 동시에 일어나는 상황
-> int num1= num2; 이런식
*/

/*
#include  <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) :num(n) {}
	SoSimple(const SoSimple &copy):num(copy.num){}
	void ShowData() {
		cout << "num: " << num << endl;
	}
};

void SimpleFuncObj(SoSimple ob) {
	ob.ShowData();
}

void main()
{
	SoSimple obj(7); //복사생성자 호출 x
	cout << "함수호출 전:" << endl;
	SimpleFuncObj(obj); // 복사생성자 호출 o
	cout << "함수호출 후" << endl;
}
*/

/*
#include <iostream>
using namespace std;

class SoSimple {
private:
	int num;
public:
	SoSimple(int n):num(n){}
	SoSimple(const SoSimple & copy) :num(copy.num) {
		cout << "called copy ctor!" << endl;
	}
	SoSimple& AddNum(int n) 
	{
		this->num += n;
		return *this;
	}
	void ShowData()
	{
		cout << "num: " << num << endl;
	}
};

SoSimple Simplefuncobj(SoSimple ob)
{
	cout << "return 이전" << endl;
	return ob;
}

int main()
{
	SoSimple obj(7);
	Simplefuncobj(obj).AddNum(30).ShowData(); // 임시객체의 복사생성자 호출, 임시객체의 내용이 나옴.
	obj.ShowData();
	return 0;
}
*/

//반환할 때 만들어진 객체(임시객체)는 언제 사라지나?
// 임시객체는 임시변수와 마찬가지로 임시로 생성되었다가 소멸되는 객체이다.


/*
#include <iostream>
using namespace std;
class Temporary {
private:
	int num;
public:
	Temporary(int n) :num(n) {
		cout << "create Obj" << num<<endl;
	}
	~Temporary()
	{
		cout << "destroy Obj" << num << endl;
	}
	void ShowTempInfo()
	{
		cout << "My Num is :" << num << endl;
	}
};

void main()
{
	Temporary(100);
	cout << "after make" << endl;
	Temporary(200).ShowTempInfo();
	cout << "after make" << endl;
	const Temporary & ref = Temporary(300);
	cout << "end of Main" << endl;
} // 임시객체는 다음행으로 넘어가면 바로 소멸된다.
  // 참조자에 참조되는 임시객체는 바로 소멸되지 않는다.

*/