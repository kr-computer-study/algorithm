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
	Car()
	{
		name = "";
		speed = 0;
		weight = 0;
		color = "";
	}
	Car(string a, int b, double c, string d)
	{
		name = a;
		speed = b;
		weight = c;
		color = d;
	}
	/*
	생성자와 파괴자를 이용한 함수
	*/
	~Car()
	{


	}
};

int main()
{
	Car Kia[4] = {
	Car("가나다",150,852.4,"RED"),
	Car("라마바",140,159.6,"Black"),
	Car("사아자",180,456.9,"Orange"),
	Car("차카타",190,759.6,"White")
	};

	Car com;
	for (int i = 0; i < 4; i++)
		com = com.compare(Kia[i]);
	//com을 선언하고 모든 자동차를 탐색하며 가장 큰 자동차를 받는다.
	cout << "\n====================" << endl;
	cout << "속도가 가장 빠른 자동차" << endl;
	com.show();

}
