#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool wordrule(string a, string b)
{
	if (a.length() == b.length())
		return a < b;
	else
		return a.length() < b.length();
//기본적으로는 길이가 적은순!
//만일 길이가 같다면 원래 사전순으로 정렬!!!!
}
int main()
{
	vector<string> wordarray;
	int N;
	cin >> N;
	string cmd;
	for (int i = 0; i < N; i++) {
		cin >> cmd;
		wordarray.push_back(cmd);
		wordlen[cmd.length()] = true;
	}

	sort(wordarray.begin(), wordarray.end(),wordrule);//사용자 정의 함수를 통해 정렬한다!

	for (int i = 0; i < wordarray.size() - 1; i++)
		if (wordarray[i] == wordarray[i + 1]) {
			wordarray.erase(wordarray.begin() + i);
			i--;
		}
//중복된 값들을 없애주는 부분!
//find를 이용하면 시간이 넘 오래 걸린다! ㅠㅠ

		for (int i = 0; i < wordarray.size(); i++)
			cout << wordarray[i] << "\n";

}
