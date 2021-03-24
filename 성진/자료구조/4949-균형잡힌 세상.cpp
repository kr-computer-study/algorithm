#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    while (true)
    {
        stack<char> sta;
        string cmd;
        getline(cin, cmd);
        //공백을 포함해 한줄을 입력받는다.
        bool check = false;

        if (cmd == ".")
            break;
        //만약 사용자가 .를 입력하면 무한 루프를 탈출한다!

            for (int i = 0; i < cmd.length(); i++)
            {
                if (cmd[i] == '(' || cmd[i] == '[')
                    sta.push(cmd[i]);
                //사용자가 (나[를 입력하는경우 스택에 푸시한다.
                else if (!sta.empty() && cmd[i] == ')' && sta.top() == '(')
                    sta.pop();
                else if (!sta.empty() && cmd[i] == ']' && sta.top() == '[')
                    sta.pop();
                /*
                ( 의 경우 [ 의 경우로 나눌 수 있다.
                스택이 비어있지 않으면서, 탐색하는 문자와
                스택의 가장 위에 있는 문자가 짝을 이루는 경우
                스택에서 pop한다!
                */
                else if (cmd[i] == ')' || cmd[i] == ']')
                    check = true;
                /*
                여기서 문제가 발생한다.
                만일 ()) 이렇게 입력한다면
                한 쌍은 정상적으로 빠지지만 뒤에 입력된 )는
                처리가 되지 않아서 나중에 yes로 출력되는 경우가
                발생한다. 조건문을 하나 추가해서 위의 경우에서
                처리되지 않으면서 ) 나 ] 가 입력된 부분을 확인해준다
                */
            }
            if (check)
                cout << "no" << "\n";
            //check되있다면 무조건 no!
            else if (sta.empty())
                cout << "yes" << "\n";
            //check가 되지 않고 스택이 비어있다면 yes!
            else
                cout << "no" << "\n";
            //무야호~
        }
    }
