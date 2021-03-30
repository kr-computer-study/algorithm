#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> word;
string cmd, result = "";
//스택, 명령어, 결과값 변수 선언.
void popstack()
{
	while (!word.empty())
	{
		result += word.top();
		word.pop();
	}
}
//스택의 값을 꺼내 결과를 보여줄 변수에 저장하는 함수

int main()
{
	getline(cin, cmd);
	bool check = false;
//<>안의 상태인지 확인을 위한 bool
	for (int i = 0; i < cmd.length(); i++)
	{
		if (cmd[i] == ' ')
		{
			if (check)
				result += " ";
			else {
				popstack();
				result += " ";
			}
			//만일 괄호안의 공백이라면 그냥 result에 공백을 하나 더해주고,
			//괄호 안이 아니라면, 스택의 값들을 빼내고 고백하나 추가!
		}
		else if (cmd[i] == '<')
		{
			popstack();
			result += "<";
			check = true;
		}
		//괄호의 시작부분, 이전까지의 내용을 저장하고 체크해준다!
		else if (cmd[i] == '>')
		{
			result += ">";
			check = false;
		}
		//괄호의 끝부분이 인식되면 체크를 풀어준다!
		else if (i == cmd.length() - 1)
		{
			word.push(cmd[i]);
			popstack();
		}
		//문제가 생긴다. 마지막은 공백이 아니니 출력이 되지 않는다!
		//이를 방지하여 마직막 글자를 탐색시 공백과 같은 역할을 추가시킨다
		else
		{
			if (check)
				result += cmd[i];
			else
				word.push(cmd[i]);
		}
		//만일 체크상태면 push없이 그냥 추가, 아니면 push
	}
	cout << result << endl;
}
