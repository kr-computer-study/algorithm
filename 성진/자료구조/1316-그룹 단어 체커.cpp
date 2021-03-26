#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int repeat;
    cin >> repeat;
    int answer = 0;
    //답을 적을 변수이다.
    for (int i = 0; i < repeat; i++)
    {
        vector<char> checker;
        //이미 나온 알파벳들을 저장해둘 char형
        //벡터를 선언해준다!

        string cmd;
        cin >> cmd;

        bool result = false;

        char temp = ' ';
        /*
        반복문을 통해 이전과 다른 문자를 찾아야 하므로
        가장 최근에 적은 문자를 기록할 변수를 선언해준다.

        문자열을 전체 탐색해준다.
        만일 이전 문자가 이번에 탐색할 문자와 다르다면
        벡터의 값들을 모두 검사해 이번 문자가 있었는지 찾아본다.
        없다면 result는 false 있었다면 true후 반복문 탈출!
        */
        for (int j = 0; j < cmd.length(); j++)
        {
            if (cmd[j] != temp)
            {
                for (int k = 0; k < checker.size(); k++)
                {
                    if (checker[k] == cmd[j])
                    {
                        result = true;
                        break;
                    }
                }
                temp = cmd[j];
                checker.push_back(cmd[j]);
            }
        }

        if (result == false)
            answer++;
    }
    cout << answer << endl;

}


/*
구조를 생각해 내는데 살짝 어려움이 있었다.
*/
