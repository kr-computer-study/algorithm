#include <iostream>

using namespace std;

class Car
{
	string name;
	int speed;
	float weight;
	string color;

public:
	void show()
	{
		cout << "\n====================" << endl;
		cout << "차의 이름 : " << name << endl;
		cout << "차의 속도 : " << speed << endl;
		cout << "차의 무게 : " << weight << endl;
		cout << "차의 색깔 : " << color << endl;
		cout << "====================" << endl;
	}
	Car compare(Car s)
	{
		if (s.speed > speed)
			return s;
		else
			return *this;
	}
	//this는 포인터 변수이기 때문에 *를 붙혀주어야 한다
	Car(string a,int b,float c,string d)
	{
		name = a;
		speed = b;
		weight = c;
		color = d;
	}
	/*
	생성자와 파괴자를 이용한 함수
	*/
	~Car() {
		cout << "\n====================" << endl;
		cout << name<<"차가 소멸되었습니다!" << endl;
		cout << "====================" << endl;
	}
};

int main()
{
	Car c1("김성진",40,190.32,"Red");
	Car c2("채민규", 80, 140.315, "Black");
	c1.show();
	c2.show();

	c1.compare(c2).show();
}
