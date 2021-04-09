#include <iostream>

using namespace std;

int main()
{
	bool selfnumber[10001] = { false, };
//셀프 넘버인지 아닌지 값을 저장할 변수 선언

	for (int i = 1; i < 10000; i++)
	{
		if (selfnumber[i])
			continue;
//만일 이미 true라면 할 필요가 없다! 시간 단축.
		int check = i;
		while (check < 10001)
		{
			int a = check / 1000;
			int b = check % 1000 / 100;
			int c = check % 100 / 10;
			int d = check % 10;
//각 자리수를 구한 다음, 기존의 탐색값에 더해주는 작업을 취한다.
			check = check + a + b + c + d;
			if(check<10001)//만일 새로운 check값이 10000을 초과한다면 오류발생한다. 이를 방지
			selfnumber[check] = true;
		}
	}

	for (int i = 1; i < 10001 ; i++)
		if (selfnumber[i] == false)
			cout << i << "\n";
}
