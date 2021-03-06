#include <iostream>
using namespace std;
namespace CAR_CONST // CAR에 대한 상수들
{
	enum {
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP= 2,
		ACC_STEP= 10,
		BRK_STEP = 10,
	};
}

struct CAR
{
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;
	void ShowCarState();
	void Accel();
	void Break();
};

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

int main()
{
	CAR run99 = { "run99",100,0 };
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
    return 0;
}



// 구조체를 사용해도 왠만한 것들은 클래스처럼 구현이 가능하다.
// 하지만, 클래스를 사용하는데는 이유가 있다.