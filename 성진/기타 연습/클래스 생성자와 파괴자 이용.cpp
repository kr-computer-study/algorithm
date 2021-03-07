#include <iostream>

using namespace std;

class classroom
{
private:
	string name = "0";
	int number = 0;
	int age = 0;
	float weight = 0;
	float height = 0;
	int eng = 0;
	int kor = 0;
	int math = 0;
	//접근 할 수 없는 값!

public:
	void changescore(int, int, int);
	void showstu();
	classroom(string, int, int, int, int);
	classroom();
	~classroom();
	//외부에서 접근 가능한 값
};
//암시적으로 디폴트 생성자 취급
classroom::classroom(string str, int n, int a, int w, int h)
{
	cout << "==============================================" << endl;
	cout << "현재 학생 정보" << endl;
	cout << "이름 : " << name << "  번호 : " << number << "  나이 : " << age << "  몸무게 : " << weight << "  키 : " << height << endl;
	cout << "수정 학생 정보" << endl;

	name = str;
	cout << "이름 : " << name << endl;
	number = n;
	cout << "번호 : " << number << endl;
	age = a;
	cout << "나이 : " << age << endl;
	weight = w;
	cout << "몸무게 : " << weight << endl;
	height = h;
	cout << "키 : " << height << endl;
	cout << "변경이 완료되었습니다!" << endl;
	cout << "==============================================" << endl;
}
classroom::classroom()
{
	 name = "0";
	 number = 0;
	 age = 0;
	 weight = 0;
	 height = 0;
	 eng = 0;
	 kor = 0;
	 math = 0;
}
//클래스 생성자
classroom::~classroom()
{

	cout << "==============================================" << endl;
	cout << "클래스가 소멸되었습니다!" << endl;
	cout << "==============================================" << endl;
}
//클래스 파괴자
//사용 범위 결정 연산자 ::
void classroom::changescore(int a, int b, int c)
{
	cout << "==============================================" << endl;
	cout << "현재 학생 성적" << endl;
	cout << "영어 : " << eng << "  국어 : " << kor << "  수학 : " << math << endl;
	cout << "바꿀 학생 성적" << endl;
	eng = a;
	cout << "영어 : " << a << endl;
	kor = b;
	cout << "국어 : " << b << endl;
	math = c;
	cout << "수학 : " << c << endl;
	cout << "변경이 완료되었습니다!" << endl;
	cout << "==============================================" << endl;
}
void classroom::showstu()
{
	cout << "==============================================" << endl;
	cout << "현재 학생 정보" << endl;
	cout << "이름 : " << name << "  번호 : " << number << "  나이 : " << age << "  몸무게 : " << weight << "  키 : " << height << endl;
	cout << "현재 학생 성적" << endl;
	cout << "영어 : " << eng << "  국어 : " << kor << "  수학 : " << math << endl;
	cout << "==============================================" << endl;
}

int main()
{
	classroom a1 = classroom("김성진", 13, 22, 71.5, 168.9);
	classroom a2 = classroom();
	a2 = a1;
	a1.showstu();
	a2.showstu();
	a1 = classroom("홍길동", 11, 23, 80, 180.25);
	a1.changescore(100, 100, 100);
	a1.changescore(50, 60, 70);
}