#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

	for (int a = 0; a < commands.size(); a++)
	{
		int i, j, k;
		i = commands[a][0];
		j = commands[a][1];
		k = commands[a][2];
		vector<int> result;

		for (int b = i - 1; b <=j-1; b++)
			result.push_back(array[b]);

		sort(result.begin(), result.end());

		answer.push_back(result[k - 1]);
	}
    return answer;
}
