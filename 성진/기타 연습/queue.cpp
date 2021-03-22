#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
/*
FIFO (First in, First out) 방식으로 동작 됩니다.
스택과 달리 front원소와 back원소에 접근이 가능하다!
*/
int main()
{
	queue<int> qu;

	qu.push(1);
	qu.push(2);
	qu.push(3);
	qu.push(4);
	//큐에 값을 넣는 방법

	qu.pop();

	cout<<qu.front() << endl;
	cout << qu.back() << endl;
	//queue의 맨 앞원소,뒷원소를 반환해주는 함수
	cout << qu.size() << endl;
	cout << qu.empty() << endl;
	//큐의 현재 사이즈 반환
	//큐가 비어있는지 확인

	queue<int> qu2({1,2,3,4,5,6,7});
	swap(qu, qu2);
	//두 큐의 내용을 바꾸는 함수
}
