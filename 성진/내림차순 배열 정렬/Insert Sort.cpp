#include <iostream>
#include <string>
using namespace std;

void Insert(int arr[10], int n)
{
	int a = 0, b = 0, c = 0;
	int temp;
	int cnt1 = 0, cnt2 = 0;

	for (a = 0; a < n; a++)
	{
		for (b = a; b > 0; b--)
		{
			if (arr[b - 1] < arr[b])
			{
				temp = arr[b];
				arr[b] = arr[b - 1];
				arr[b - 1] = temp;
				cnt2++;
			}
			cnt1++;
		}
		for (c = 0; c < n; c++)
			cout << arr[c] << "  ";
		cout << "비교횟수 : " << cnt1;
		cout << "    교환횟수 : " << cnt2 << "\n" << endl;
	}

}
int main()
{
	int arr[10] = {50,23,84,49,71,15,99,62,46,8};
	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//int arr[10] = { 10,9,8,7,6,5,4,3,1,2 };
	cout << "====================================Insert Sort Start====================================" << endl;
	Insert(arr, 10);
	cout << "====================================Insert Sort End====================================" << endl;
}
