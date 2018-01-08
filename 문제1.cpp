#include <iostream>
using namespace std;

/*
���� ����� Calculator Ŭ������ �����غ���. �⺻������ ���ϴ� ����� ����, ����, ����, �������̸�
������ �� ������ ��� ������ �� �� �����ߴ��� ��ϵǾ�� �Ѵ�. �Ʒ��� main�Լ��� ������ ���� �����ϴ�
Calculator Ŭ������ �����ϸ� �ȴ�. ��, ��������� private��, ����Լ��� public���� ��������. 
*/

class Calculator
{
private:
	int count_Add;
	int count_Min;
	int count_Div;
public:
	void Init();
	double Add(double a, double b);
	double Div(double a, double b);
	double Min(double a, double b);
	void ShowOpCount();
};

void Calculator::Init()
{
	count_Add = 0;
	count_Min = 0;
	count_Div = 0;
}
double Calculator::Add(double a, double b)
{
	count_Add++;
	return a + b;
}
double Calculator::Div(double a, double b)
{
	count_Div++;
	return a / b;
}
double Calculator::Min(double a, double b)
{
	count_Min++;
	return a - b;
}
void Calculator::ShowOpCount() 
{
	cout << "Div_count:"<<count_Div << endl;
	cout << "Add_count:" << count_Add << endl;
	cout << "Min_count:" << count_Min << endl;

}
int main()
{
	Calculator cal;
	cal.Init();
	cout << "3.2+2.4=" << cal.Add(3.2, 2.4) << endl;
	cout << "3.5/1.7=" << cal.Div(3.5, 1.7) << endl;
	cout << "2.2-1.5=" << cal.Min(2.2, 1.5) << endl;
	cout << "2.2-1.2=" << cal.Min(2.2, 1.2) << endl;
	cal.ShowOpCount();
	return 0;
}