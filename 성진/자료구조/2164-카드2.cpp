#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> cardq;

    int number;
    cin >> number;

    for (int i = 1; i <= number; i++)
        cardq.push(i);

    while (cardq.size()>1)
    {
        cardq.pop();
        cardq.push(cardq.front());
        cardq.pop();

    }

    cout << cardq.front() << endl;

}
//큐의 기본 개념을 이용하는 간단한 문제이다!
