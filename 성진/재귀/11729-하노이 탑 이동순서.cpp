#include <iostream>

using namespace std;

void hanoi(int n, char from, char temp, char to) {
    if (n == 1) {
        cout << from << " "<<to <<"\n";
    }
    else {
        hanoi(n - 1, from, to, temp);
        cout << from << " " << to << "\n";
        hanoi(n - 1, temp, from, to);
    }
}
/*
시작 , 보조, 목표 막대를 정한 후
N개의 탑을 옮기기 위해서는 N-1개의 탑을 보조 막대에 옮기고, N을 목표 막대에 올린 다음에, 보조막대에 올린 N-1개의 탑을 다시 목표 막대에 올린다!

N-1개의 탑을 옮기기 위해서는 다시 N-2개의 탑을 보조 막대에.....

.......를 재귀적으로 반복한다.
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int result=1;
    for (int i = 1; i < n; i++)
        result = result * 2 + 1;
    //이전 결과횟수의 두배 +1은 이번 결과 횟수이다!
    cout << result << endl;
    hanoi(n,'1','2','3');
}
