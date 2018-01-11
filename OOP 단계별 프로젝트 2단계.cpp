#include <iostream>
using namespace std;
/*
프로그램 설명
은행계좌 관리 프로그램
기능 1. 계좌개설
기능 2. 입    금
기능 3. 출    금
기능 4. 계좌정보 전체 출력
기능 5. 프로그램 종료

통장의 계좌번호는 중복되지 않는다.
입금 및 출금액은 무조건 0보다 크다.
고객의 계좌정보는 계좌번호, 고객이름, 고객의 잔액만 저장, 관리한다.
둘 이상의 고객 정보 저장을 위해서 배열을 사용한다.
계좌번호는 정수의 형태이다.
*/

class Account 
{
private:
	char * name; 
	int money;
	char * DepositNum;
public:
	Account() {};//default 생성자
	void DataInsert(char * name,int money,char * DepositNum) // 계좌번호는 중복되면 안된다. 
	{
		this->money = money;

		int len = strlen(name) + 1;
		this->name = new char[len];
		strcpy(this->name, name);

		len = strlen(DepositNum) + 1;
		this->DepositNum = new char[len];
		strcpy(this->DepositNum, DepositNum);
	}
	void ShowDepositInfo() const
	{
		cout << "[계좌 개설]" << endl;
		cout << "이름 :" << this->name<<endl;
		cout << "계좌번호 : " << this->DepositNum << endl;
		cout << "잔액 : " << this->money << endl;
	}
	void InsertMoney(int money)
	{
		this->money += money;
	}
	void DeleteMoney(int money)
	{
		this->money -= money;
	}
	char * ReturnDepositNum()
	{
		return this->DepositNum;
	}
	~Account()
	{
		delete []name;
		delete []DepositNum;
	}
};

void PrintMain()
{
	cout << "기능 1 : 계좌개설" << endl;
	cout << "기능 2 : 입    금" << endl;
	cout << "기능 3 : 출    금" << endl;
	cout << "기능 4 : 계좌정보 전체 출력" << endl;
	cout << "기능 5 : 프로그램 종료" << endl;
}
void main()
{
	Account a[10];
	int count = 0;
	int choice;
	char name[50];
	char deposit[50];
	int money;
	
	while (1)
	{
		PrintMain();
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "이름을 입력하세요 : "; cin >> name;
			cout << "계좌번호을 입력하세요 : "; cin >> deposit;
			cout << "잔액을 입력하세요 : "; cin >> money;
			a[count++].DataInsert(name,money,deposit);
			break;
		case 2:
			cout << "[입     금]" << endl;
			cout << "계좌번호를 입력하세요."; cin >> deposit;
			for (int i = 0; i < count; i++)
			{
				if (!strcmp(a[i].ReturnDepositNum(), deposit))
				{
					cout << "입금할 돈을 넣어주세요."; cin >> money;
					a[i].InsertMoney(money);
					a[i].ShowDepositInfo();
				}
			}
			break;
		case 3:
			cout << "[출     금]" << endl;
			cout << "계좌번호를 입력하세요."; cin >> deposit;
			for (int i = 0; i < count; i++)
			{
				if (!strcmp(a[i].ReturnDepositNum(), deposit))
				{
					cout << "출금할 돈을 넣어주세요."; cin >> money;
					a[i].DeleteMoney(money);
					a[i].ShowDepositInfo();
				}
			}
			break;
		case 4:
			for (int i = 0; i < count; i++)
			{
				a[i].ShowDepositInfo();
			}
			break;
		case 5:
			exit(0);
			break;
		}
	}
}

