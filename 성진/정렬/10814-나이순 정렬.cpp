#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool mysort(pair<int,string>a,pair<int,string>b) {
		return a.first < b.first;
}
//안정 정렬을 통해 정렬하므로 앞의 나이순으로만 정렬해준다.
int main()
{
	int repeat;
	cin >> repeat;

	vector<pair<int, string>> baekjoonmember(repeat);

	for (int i = 0; i < repeat; i++)
		cin >> baekjoonmember[i].first >> baekjoonmember[i].second;

	stable_sort(baekjoonmember.begin(), baekjoonmember.end(),mysort);


	for (int i = 0; i < repeat; i++)
	{
		cout << baekjoonmember[i].first<<" "<<baekjoonmember[i].second << "\n";
	}

}
