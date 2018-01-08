#include <iostream>
#include <cstring>
using namespace std;
namespace CAR_CONST // CAR에 대한 상수들
{
	enum {
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10,
	};
}

class CAR
{
protected: // 상속관계에 놓여있을 때, 유도 클래스에서의 접근허용
private: // 클래스 내에서만 접근 허용
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;
public: // 어디서든 접근 허용
	void InitMembers(const char * ID, int fuel);
	void ShowCarState();
	void Accel();
	void Break();
};

void CAR::InitMembers(const char * ID, int fuel)
{
	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}
void CAR::ShowCarState()
{
	cout << "소유자 ID:" << gamerID << endl;
	cout << "연료량:" << fuelGauge << endl;
	cout << "현재속도:" << curSpeed << endl;
}

void CAR::Accel()
{
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= CAR_CONST::FUEL_STEP;

	if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
	{
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}
	curSpeed += CAR_CONST::ACC_STEP;
}

void CAR::Break()
{
	if (curSpeed < CAR_CONST::BRK_STEP)
	{
		curSpeed = 0;
		return;
	}
	curSpeed -= CAR_CONST::BRK_STEP;
}

//함수의 정의를 클래스 밖으로 빼도, 이는 클래스의 일부이기 때문에 함수 내에서는 private로 선언된 변수에 접근이 가능하다.
//class로 클래스를 정의했을 때 별도의 접근제어자를 선언하지 않으면 모든 변수와 함수는 private로 선언된다.
//struct로 구조체를 정의했을 때 별도의 접근제어자를 선언하지 않으면 모든 변수와 함수는 public로 선언된다.
int main()
{
	CAR run99;
	run99.InitMembers("run99", 100);
	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
	return 0;
}