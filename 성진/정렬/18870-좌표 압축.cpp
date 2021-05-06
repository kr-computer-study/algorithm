#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool mysort(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}
int main()
{
	int repeat;
	cin >> repeat;
	int x;
	vector<pair<int, int>> xandy;
	//입력값을 값과 현재 인덱스를 저장할 pair의 벡터를 선언
	for (int i = 0; i < repeat; i++) {
		cin >> x;
		xandy.push_back(make_pair(x, i));
	}
	//일단 모든 원소를 벡터에 넣는다!
	sort(xandy.begin(), xandy.end());
	//압축을 위한 원소를 정렬해주고
	int score = 0;
	for (int i = 0; i < repeat-1;i++)
	{
		if (xandy[i].first < xandy[i + 1].first) {
			xandy[i].first = score;
			score++;
		}
		if (xandy[i].first == xandy[i + 1].first) {
			xandy[i].first = score;
		}
	}
	//만일 현재값과 다음값이 같다면 score를 증가시키지 않고,
	//다르다면 scroe를 증가시키는 방식으로 압축한다.
	xandy[repeat-1].first = score;
	//마지막 원소는 적용되지 않았으니 정리해준다.
	sort(xandy.begin(), xandy.end(),mysort);
	//pair에 저장했던 인덱스대로 다시 정렬해준다.
	for (int i = 0; i < repeat; i++)
		cout<<xandy[i].first << " ";
}
