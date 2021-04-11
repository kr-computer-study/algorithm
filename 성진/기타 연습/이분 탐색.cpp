#include <iostream>
#include <algorithm>

using namespace std;

int Binarywhile(int arg[], int start, int end, int num) {
	int mid = 0;

	while (true)
	{
		mid = (start + end) / 2;

		cout << "start : " << start << "  mid : " << mid << "  end : " << end << endl;
		if (start > end)
			return -1;
		else if (arg[mid] > num)
			end = mid - 1;
		else if (arg[mid] < num)
			start = mid + 1;
		else
			return mid;
	}
}
int Binarysearch(int arg[],int start,int end,int num) {
	int mid = (start + end) / 2;

	cout << "start : " << start << "  mid : " << mid << "  end : " << end << endl;
	if (start > end)
		return -1;
	else if (arg[mid] == num)
		return mid;
	else if (arg[mid] > num)
		Binarysearch(arg, start, mid - 1, num);
	else
		Binarysearch(arg, mid + 1, end, num);
}
int main()
{
	int binarr[20] = { 1,6,3,2,5,4,7,8,9,56,21,54,59,87,63,52,11,15,16,18 };
	sort(binarr, binarr + 20);
	for (int i = 0; i < 20; i++)
		cout << binarr[i] << " ";

	cout << endl;
	Binarysearch(binarr, 0, 18, 21);
	Binarywhile(binarr, 0, 18, 21);

}
