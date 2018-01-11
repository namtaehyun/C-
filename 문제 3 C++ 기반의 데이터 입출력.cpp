#include <iostream>
using namespace std;

/*
명함을 의미하는 NameCard클래스를 정의 해보자. 이 클래스에는 다음의 정보가 저장되어야 한다.
-성명, 회사이름, 전화번호, 직급
단, 직급정보를 제외한 나머지는 문자열의 형태로 저장을 하되, 길이에 딱 맞는 메모리 공간을 할당받는 형태로 정의하자.
그리고 직급 정보는 int형 멤버변수를 선언하여 저장을 하되, 아래의 enum 선언을 활용 해야한다.
enum {CLERK,SENIOR,ASSIST,MANAGER};
*/

class NameCard {
private:
	char * name;
	char * comp;
	char * phoneNum;
	int position;
public:
	NameCard(const char *name,const char *compname,const char *phoneNum,int position) 
	{
		int len = strlen(name) + 1;
		this->name = new char[len];
		strcpy(this->name, name);
		len = strlen(compname) + 1;
		this->comp = new char[len];
		strcpy(this->comp, compname);
		len = strlen(phoneNum) + 1;
		this->phoneNum = new char[len];
		strcpy(this->phoneNum, phoneNum);
		this->position = position;
		// 문자열들은 동적할당.
	}
	~NameCard()
	{
		delete name;
		delete phoneNum;
		delete comp;
		cout << "dtor called" << endl;
	} // 소멸자를 호출해서 동적할당 해제
	void ShowNameCardInfo() const
	{
		cout << "이름 :" << name << endl;
		cout << "회사 :" << comp << endl;
		cout << "전화번호 :" << phoneNum<< endl;
		cout << "직급 :" ;
		if (position == 0)
		{
			cout << "CLERK" << endl << endl;
		}
		else if (position == 1)
		{
			cout << "SENIOR" << endl << endl;
		}
		else if(position ==2)
		{
			cout << "ASSIST" << endl << endl;
		}
		else
		{
			cout << "MANAGER" << endl << endl;
		}
	}
};
enum COMP_POS {
	CLERK, SENIOR, ASSIST, MANAGER
};
void main()
{
	NameCard manClerk("Lee", "ABCEng", "000-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "000-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "000-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
}