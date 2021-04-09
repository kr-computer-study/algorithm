#include <iostream>
#include <stack>
/*
스택을 이용해서 중앙을 기준으로 왼쪽과 오른쪽의
문자를 push해서 비교하였다.
*/
using namespace std;

int main()
{
	while (true)
	{

		stack<char> Palindromea;
		stack<char> Palindromeb;
		string cmd;
		cin >> cmd;
		bool result = true;

		if (cmd == "0")
			break;

		for (int i = 0; i < cmd.length() / 2; i++)
		{
			Palindromea.push(cmd[i]);
			Palindromeb.push(cmd[cmd.length()-1-i]);
		}
//입력된 문자열의 절반!
//짝수의 경우에는 그대로 진행, 홀수의 경우에도 가장 가운데를 비교할 필요 없다!
		while (!Palindromea.empty())
		{
			if (Palindromea.top() != Palindromeb.top()) {
				result = false;
				break;
			}
			Palindromea.pop();
			Palindromeb.pop();
		}
//다른 값이 나오면 즉시 빠져나오고 result를 false로 만들어준다!
//result의 값이 계속 true라면 yes!~
		if (result)
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";


	}

}
