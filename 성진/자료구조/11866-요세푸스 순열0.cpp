#include <iostream>
#include <queue>
#include<string>

using namespace std;

int main()
{
	queue <int> yosepus;
	string result = "<";
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		yosepus.push(i);
//큐에 하나씩 넣어준
	while (!yosepus.empty()) {

		for (int j = 0; j < k - 1; j++) {
			yosepus.push(yosepus.front());
			yosepus.pop();
		}
/*만일 n번째를 출력한다고 가정해보자.
n-1번 을 가장 앞에 있는 수를 큐에 다시 삽입해주고,
n번째를 출력해준다음 빼낸다.*/
		result += to_string(yosepus.front())+", ";
		yosepus.pop();
	}
	for (int i = 0; i < result.length() - 2; i++)
		cout << result[i];
//뒤에서 문자2개를 지워준다!
	cout << ">";
}

//큐를 이용한 기본문제였다. 응용하는 문제를 풀어볼 예정이다.
