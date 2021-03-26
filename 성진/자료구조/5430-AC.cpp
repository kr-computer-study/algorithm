#include <iostream>
#include <deque>
#include<string>

using namespace std;

int main()
{

    int repeat;
    cin >> repeat;

    for (int i = 0; i < repeat; i++)
    {

        deque<int> AC;

        string func;
        cin >> func;

        int arrnumber;
        cin >> arrnumber;

        string arrcmd;
        cin >> arrcmd;
/*
명령어를 받을 변수,배열원소 개수 받을 변수
배열을 받을 변수로 값을 받는다.
이 값은 테스트 케이스마다 새롭게 정의된다.
*/

        string temp="";

        for (int j = 0; j < arrcmd.length(); j++)
        {
            if ('0' <= arrcmd[j] && arrcmd[j] <= '9')
                temp += arrcmd[j];
            else if (arrcmd[j] == ',' || arrcmd[j] == ']') {
                if (temp!="") {
                    AC.push_back(stoi(temp));
                    temp="";
                }
            }
        }
/*
쉼표나 닫는 대괄호가 나오면 여태 모아왔던 수를 형변환시켜
덱에 넣는다. 이때 사용자가 아무 값을 안넣는 0개배열의
경우의 수도 있으므로 temp가 비어있지 않을때만 덱에 넣는다.
*/
        bool error = false;
        bool reverse = false;
//만일 에러가 난다면 error를 참으로,
//R이 입력된다면 덱을 정리하지 않고 빼내는 위치만 다르게 할 것이다.

        for (int j = 0; j < func.length(); j++)
        {
           if (func[j] == 'R')
               reverse=!reverse;
               //NOT연산자를 통해 거꾸로 뒤집는다. 실제로는X
           if (func[j] == 'D') {
              if (AC.empty()) {
                 error = true;
                 break;
              }
              else {
                  if(reverse)AC.pop_back();
                  else AC.pop_front();
              }
              //만일 reverse가 true이면 순서는 역순이다.
              //뒤에서 pop한다 아니면 앞에서 pop한다
           }
        }

//에러가 true이면 그냥 에러를 출력시킨다.
        if (error)
        {
           cout << "error" << "\n";
        }
        else
        {
            cout << "[";
            if (reverse) {
                while (!AC.empty())
                {
                    cout << AC.back();
                        if (AC.size() != 1)
                        cout<<",";
                    AC.pop_back();
                }
            }
            else {
                while (!AC.empty())
                {
                    cout << AC.front();
                    if (AC.size() != 1)
                        cout << ",";
                    AC.pop_front();
                }
            }

            cout << "]" << endl;
        }
//아닐 경우에는 배열 모양에 맞춰서 출력시킨다.

    }
}

/*
느낀 점
매우매우 힘들었다.
꼼꼼하게 모든 경우의 수를 생각하며 코딩하는것이 어렵다.
*/
