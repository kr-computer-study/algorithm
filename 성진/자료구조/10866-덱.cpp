#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(void) {
	deque<int> mydeque;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "push_front")
		{
			int X;
			cin >> X;
			mydeque.push_front(X);
		}
		else if (cmd == "push_back")
		{
			int X;
			cin >> X;
			mydeque.push_back(X);
		}
		else if (cmd == "pop_front")
		{
			if (mydeque.size() > 0)
			{
				cout<<mydeque.front() << "\n";
				mydeque.pop_front();
			}
			else
				cout << "-1" << "\n";
		}
		else if (cmd == "pop_back")
		{
			if (mydeque.size() > 0)
			{
				cout << mydeque.back() << "\n";
				mydeque.pop_back();
			}
			else
				cout << "-1" << "\n";
		}
		else if (cmd == "size")
			cout << mydeque.size() << "\n";
		else if (cmd == "empty")
		{
			cout << mydeque.empty() << "\n";
		}
		else if (cmd == "front")
		{
			if (mydeque.size() > 0)
				cout << mydeque.front() << "\n";
			else
				cout << "-1" << "\n";
		}
		else if (cmd == "back")
		{
			if (mydeque.size() > 0)
				cout << mydeque.back() << "\n";
			else
				cout << "-1" << "\n";
		}
	}
}

/*
덱에 대한 개념을 복습해보고자 풀어보았다.
*/
