// 캡슐화
// 캡슐화는 객체지향기반의 클래스를 설계하는데 있어 기본적 원칙이다.
/*
#include <iostream>
using namespace std;

class SinivelCap { //콧물 처치용 캡슐
public:
	void Take() const { cout << "콧물이 싹~ 납니다." << endl; }
};

class SneezeCap { // 재채기 처치용 캡슐
public:
	void Take() const { cout << "재채기가 싹~ 납니다." << endl; }
};

class ShuffleCap {
public:
	void Take() const { cout << "코가 뻥 뚫립니다." << endl; }
};

class ColdPatient {
public:
	void TakeSinivelCap(const SinivelCap &cap) const { cap.Take(); }
	void TakeSneezeCap(const SneezeCap &cap) const { cap.Take(); }
	void TakeShuffleCap(const ShuffleCap &cap) const { cap.Take(); }
};

int main()
{
	SinivelCap scap;
	SneezeCap zcap;
	ShuffleCap ncap;
	ColdPatient sufferer;
	sufferer.TakeShuffleCap(ncap);
	sufferer.TakeSinivelCap(scap);
	sufferer.TakeSneezeCap(zcap);
    return 0;
}

// 코감기는 항상 콧물, 재채기 코막힘을 동반한다.
// SinivelCap, SneezeCap, ShuffleCap순으로 이뤄져야 한다.
// 이런 경우에 순서가 틀어지면 부작용을 초래한다.
// 따라서, 캡슐화가 무너지면, 객체의 활용이 어려워진다. 또한, 캡슐화가 무너지면 
// 클래스 상호관계가 복잡해지기 때문에 이는 프로그램전체의 복잡도를 높인다.
*/
// 따라서, 이런식으로 구현해야 한다.

#include <iostream>

using namespace std;


class SinivelCap { //콧물 처치용 캡슐
public:
	void Take() const { cout << "콧물이 싹~ 납니다." << endl; }
};

class SneezeCap { // 재채기 처치용 캡슐
public:
	void Take() const { cout << "재채기가 싹~ 납니다." << endl; }
};

class ShuffleCap { // 코막힘 처치용 캡슐
public:
	void Take() const { cout << "코가 뻥 뚫립니다." << endl; }
};

class Contac600
{
private:
	SinivelCap scap;
	SneezeCap zcap;
	ShuffleCap ncap;
public:
	void Take() const {
		ncap.Take();
		scap.Take();
		zcap.Take();
	} // 캡슐을 복용할 때 한번에 순서도 딱맞춰서 해결한다.
};

class ColdPatient
{
public:
	void TakeContac600(const Contac600 &cap)const { cap.Take(); }
};

int main()
{
	Contac600 cap;
	ColdPatient sufferer; // 환자
	sufferer.TakeContac600(cap);
	return 0;
}