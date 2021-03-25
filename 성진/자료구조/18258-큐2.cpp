#include <iostream>
#include <queue>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin.sync_with_stdio(0);
	/*
	입출력 시간을 줄여주는 코드!
	c++과 c의 표준 스트림의 동기화 끄기!
	*/
	queue<int> qu;

	int n, repeat;
	cin >> repeat;

	string cmd;

	for (int i = 0; i < repeat; i++) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> n;
			qu.push(n);
		}
		else if (cmd == "pop") {
			if (qu.empty()) cout << "-1" << "\n";
			else {
				cout << qu.front() << "\n";
				qu.pop();
			}
		}
		else if (cmd == "size") {
			cout << qu.size() << "\n";
		}
		else if (cmd == "empty") {
			cout << qu.empty() << "\n";
		}
		else if (cmd == "front") {
			if (qu.empty()) cout << "-1" << "\n";
			else cout << qu.front() << "\n";
		}
		else if (cmd == "back") {
			if (qu.empty()) cout << "-1" << "\n";
			else cout << qu.back() << "\n";
		}
	}
}

//큐만 구현하면 되는 간단한 문제이다.
//C++ 의 STL을 이용했다.
