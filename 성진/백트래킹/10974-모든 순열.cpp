#include <iostream>
#include <algorithm>
using namespace std;

int arr[9];
bool visit[9];

void permutation(int number,int start)
{
	if (start == number + 1)
	{
		for (int i = 1; i <= number; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
//기본적인 백트트래킹 문제이다!
//N과M 문제랑 같다!!!
	for (int i = 1; i <= number; i++)
	{
		if (visit[i] == false) {
			arr[start] = i;
			visit[i] = true;
			permutation(number, start + 1);
			visit[i] = false;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	permutation(n,1);
}
