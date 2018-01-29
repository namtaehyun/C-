#include <iostream>
using namespace std;

class MyFriendInfo
{
private:
	char * name;
	int age;
public:
	void ShowMyFriendInfo()
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}
	MyFriendInfo(const char * name,int age):age(age)
	{
		int len = strlen(name)+1;
		this->name = new char[len];
		strcpy(this->name, name);
	}
	~MyFriendInfo()
	{
		delete name;
	}
};

class MyFriendDetailInfo:public MyFriendInfo
{
private:
	char * addr;
	char * phone;
public:
	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "주소 : " << addr << endl;
		cout << "전화 : " << phone << endl;
	}
	MyFriendDetailInfo(const char * addr,const char * phone,const char * name,int age):MyFriendInfo(name,age)
	{
		int len = strlen(addr) + 1;
		this->addr = new char[len];
		strcpy(this->addr, addr);
		
		len = strlen(phone) + 1;
		this->phone = new char[len];
		strcpy(this->phone, phone);
	}
	~MyFriendDetailInfo()
	{
		delete phone;
		delete addr;
	}
};

void main()
{
	MyFriendDetailInfo a("천안", "01011022011", "ㅇㅇㅇ", 15);
	a.ShowMyFriendDetailInfo();
	a.ShowMyFriendInfo();
}