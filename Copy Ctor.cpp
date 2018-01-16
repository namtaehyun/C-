// ���������
/*
#include<iostream>
using namespace std;

class SoSimple {
private:
	int num1, num2;
public:
	SoSimple(int n1, int n2) :num1(n1), num2(n2) {} // �׳� ������
	SoSimple(const SoSimple &copy) :num1(copy.num1), num2(copy.num2) {} // ����Ʈ ���� ������ = ��������ڸ� �̷��� ���� ������ص� �ڵ������� ��������ڸ� �����.
																  // ���� ��쿡 �־� ��������ڰ� �̷��� ��������ϱ� ���� ���� �ʿ䰡 ���� ��찡 ����. ������,
																  // �׷��� ���� ��쵵 �ִ�. 
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
�������� ��������
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
	// �̳༮�� ���� ���縦 �� �� �ְ� ���ش�.
	Person(const Person& copy)
	{
		this->name = new char[strlen(copy.name) + 1];
		strcpy(this->name, copy.name);
		age = copy.age;
	}


	void ShowPerson() const {
		cout << "�̸� :" << name << endl;
		cout << "���� :" << age << endl;
	}
	~Person()
	{
		delete[]name;
	}
};

void main()
{
	Person man1("Lee Dong Woo", 29);
	Person man2(man1); // ����Ʈ ��������ڸ� ����Ѵ�.
	man1.ShowPerson();
	man2.ShowPerson();
}
//-> ����Ʈ��������ڸ� ����ϰ� �Ǹ� ����� ����� �ܼ��� ���縸�ϹǷ�, man1��ü�� man2��ü�� ����Ű�� �����Ͱ� ����.
// �׷���, �Ҹ��ڸ� �Ѹ� ����ص� ������ �Ѹ��� ����Ű�� �ִ� �����͸� �Ҹ���ѹ����Ƿ�, ������ ��! �ϰ� ����.
// ����, �� �� ������ �����͸� ����Ű�� �������� �Ѵ�.
*/

/*
����������� ȣ�����
1. ������ ������ ��ü�� �̿��Ͽ� ���ο� ��ü�� �ʱ�ȭ�ϴ� ���
2. Call By Value����� �Լ�ȣ�� �������� ��ü�� ���ڷ� �����ϴ� ���
3. ��ü�� ��ȯ�ϵ�, ���������� ��ȯ���� �ʴ� ���
�� ������ case�� �������� ��ü�� ���� �����ؾ��Ѵ�. ��, ������ ���ÿ� ������ �ڷ����� ��ü�� �ʱ�ȭ �ؾ� �Ѵ�.

�޸� ������ �Ҵ�� �ʱ�ȭ�� ���ÿ� �Ͼ�� ��Ȳ
-> int num1= num2; �̷���
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
	SoSimple obj(7); //��������� ȣ�� x
	cout << "�Լ�ȣ�� ��:" << endl;
	SimpleFuncObj(obj); // ��������� ȣ�� o
	cout << "�Լ�ȣ�� ��" << endl;
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
	cout << "return ����" << endl;
	return ob;
}

int main()
{
	SoSimple obj(7);
	Simplefuncobj(obj).AddNum(30).ShowData(); // �ӽð�ü�� ��������� ȣ��, �ӽð�ü�� ������ ����.
	obj.ShowData();
	return 0;
}
*/

//��ȯ�� �� ������� ��ü(�ӽð�ü)�� ���� �������?
// �ӽð�ü�� �ӽú����� ���������� �ӽ÷� �����Ǿ��ٰ� �Ҹ�Ǵ� ��ü�̴�.


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
} // �ӽð�ü�� ���������� �Ѿ�� �ٷ� �Ҹ�ȴ�.
  // �����ڿ� �����Ǵ� �ӽð�ü�� �ٷ� �Ҹ���� �ʴ´�.

*/