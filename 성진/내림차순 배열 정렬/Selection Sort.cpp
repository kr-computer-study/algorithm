#include <iostream>
#include <string>
using namespace std;

void Selection(int arr[10], int n)
{
	int a = 0, b = 0, c = 0;
	int temp = 0, index = 0;
	int cnt1 = 0;

	for (a = 0; a < n - 1; a++)
	{
		index = a;
		for (b = a; b < n; b++)
		{
			if (arr[index] < arr[b])//새로운 큰 수 찾기
			{
				index = b;
				cnt1++;
			}
		}
		temp = arr[a];
		arr[a] = arr[index];
		arr[index] = temp;

		for (c = 0; c < n; c++)
			cout << arr[c] << "  ";
		cout << "큰 수를 찾기 위한 비교횟수  : " << cnt1;
		cout << "\n" << endl;
	}

}
int main()
{
	int arr[10] = { 50,23,84,49,71,15,99,62,46,8 };
	cout << "====================================Selection Sort Start====================================" << endl;
	Selection(arr, 10);
	cout << "====================================Selection Sort End====================================" << endl;
}
