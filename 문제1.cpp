#include <iostream>
using namespace std;

/*
계산기 기능의 Calculator 클래스를 정의해보자. 기본적으로 지니는 기능은 덧셈, 뺄셈, 곱셈, 나눗셈이며
연산을 할 때마다 어떠한 연산을 몇 번 수행했는지 기록되어야 한다. 아래의 main함수와 실행의 예에 부합하는
Calculator 클래스를 정의하면 된다. 단, 멤버변수는 private로, 멤버함수는 public으로 선언하자. 
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