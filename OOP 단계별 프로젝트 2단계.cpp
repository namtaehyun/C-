#include <iostream>
using namespace std;
/*
���α׷� ����
������� ���� ���α׷�
��� 1. ���°���
��� 2. ��    ��
��� 3. ��    ��
��� 4. �������� ��ü ���
��� 5. ���α׷� ����

������ ���¹�ȣ�� �ߺ����� �ʴ´�.
�Ա� �� ��ݾ��� ������ 0���� ũ��.
���� ���������� ���¹�ȣ, ���̸�, ���� �ܾ׸� ����, �����Ѵ�.
�� �̻��� �� ���� ������ ���ؼ� �迭�� ����Ѵ�.
���¹�ȣ�� ������ �����̴�.
*/

class Account 
{
private:
	char * name; 
	int money;
	char * DepositNum;
public:
	Account() {};//default ������
	void DataInsert(char * name,int money,char * DepositNum) // ���¹�ȣ�� �ߺ��Ǹ� �ȵȴ�. 
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
		cout << "[���� ����]" << endl;
		cout << "�̸� :" << this->name<<endl;
		cout << "���¹�ȣ : " << this->DepositNum << endl;
		cout << "�ܾ� : " << this->money << endl;
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
	cout << "��� 1 : ���°���" << endl;
	cout << "��� 2 : ��    ��" << endl;
	cout << "��� 3 : ��    ��" << endl;
	cout << "��� 4 : �������� ��ü ���" << endl;
	cout << "��� 5 : ���α׷� ����" << endl;
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
			cout << "�̸��� �Է��ϼ��� : "; cin >> name;
			cout << "���¹�ȣ�� �Է��ϼ��� : "; cin >> deposit;
			cout << "�ܾ��� �Է��ϼ��� : "; cin >> money;
			a[count++].DataInsert(name,money,deposit);
			break;
		case 2:
			cout << "[��     ��]" << endl;
			cout << "���¹�ȣ�� �Է��ϼ���."; cin >> deposit;
			for (int i = 0; i < count; i++)
			{
				if (!strcmp(a[i].ReturnDepositNum(), deposit))
				{
					cout << "�Ա��� ���� �־��ּ���."; cin >> money;
					a[i].InsertMoney(money);
					a[i].ShowDepositInfo();
				}
			}
			break;
		case 3:
			cout << "[��     ��]" << endl;
			cout << "���¹�ȣ�� �Է��ϼ���."; cin >> deposit;
			for (int i = 0; i < count; i++)
			{
				if (!strcmp(a[i].ReturnDepositNum(), deposit))
				{
					cout << "����� ���� �־��ּ���."; cin >> money;
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

