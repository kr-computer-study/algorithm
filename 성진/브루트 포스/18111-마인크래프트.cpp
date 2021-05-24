#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, B;

bool mysort(pair<int,int>a,pair<int,int>b)
{
	if (a.first == b.first)
		return a.second > b.second;

	return a.first < b.first;
}
//오름차순, 만일 첫번재 인자 값이 같다면 뒷 인자값을 내림차순으로!

int main() {
	cin >> N >> M >> B;
	vector<short>* MineCraft = new vector<short>[N];
	vector<pair<int, int>> Resultvec;
	int x;
	int Search=-1;
	int less = 256;
	//탐색할 범위를 지정하는 변수
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> x;
			MineCraft[i].push_back(x);
			if (x > Search) Search = x;
			if (x < less)less = x;
		}
	}
//값을 입력받고 최소값과 최대값을 구해준다.
	while (Search>=less)
	{
		int DigBlock = 0, PutBlock = 0, Inventory = B;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (Search < MineCraft[i][j]) { DigBlock += MineCraft[i][j] - Search; }
				else if (Search > MineCraft[i][j]) { PutBlock += Search - MineCraft[i][j]; }
				else continue;
			}
		}
//만약 검색하는 겂보다 크면 DigBlock에, 작으면 PutBlock에 그 차이의 절대값을 넣는다.
//인벤토리가 음수가 되지 않으면 결과 값 저장 벡터에 넣는다.
		if (Inventory + DigBlock - PutBlock >= 0)
			Resultvec.push_back(make_pair(DigBlock * 2 + PutBlock * 1, Search));

		Search--;
	}

	sort(Resultvec.begin(), Resultvec.end(),mysort);
	cout << Resultvec[0].first<<" "<<Resultvec[0].second << endl;
	delete[] MineCraft;

}
