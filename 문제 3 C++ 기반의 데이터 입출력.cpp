#include <iostream>
using namespace std;

/*
������ �ǹ��ϴ� NameCardŬ������ ���� �غ���. �� Ŭ�������� ������ ������ ����Ǿ�� �Ѵ�.
-����, ȸ���̸�, ��ȭ��ȣ, ����
��, ���������� ������ �������� ���ڿ��� ���·� ������ �ϵ�, ���̿� �� �´� �޸� ������ �Ҵ�޴� ���·� ��������.
�׸��� ���� ������ int�� ��������� �����Ͽ� ������ �ϵ�, �Ʒ��� enum ������ Ȱ�� �ؾ��Ѵ�.
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
		// ���ڿ����� �����Ҵ�.
	}
	~NameCard()
	{
		delete name;
		delete phoneNum;
		delete comp;
		cout << "dtor called" << endl;
	} // �Ҹ��ڸ� ȣ���ؼ� �����Ҵ� ����
	void ShowNameCardInfo() const
	{
		cout << "�̸� :" << name << endl;
		cout << "ȸ�� :" << comp << endl;
		cout << "��ȭ��ȣ :" << phoneNum<< endl;
		cout << "���� :" ;
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