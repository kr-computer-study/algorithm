#include <iostream>
#include <vector>
#include <string>

using namespace std;

int case1(vector<vector<int>> tt,int ve,int ho)
{
	int result = 0;
	int tmpresult = 0;
	for (int a = 0; a < ve; a++)
	{
		for (int b = 0; b < ho - 3; b++)
		{
			tmpresult = 0;
			for(int c=b;c<b+4;c++)
			tmpresult += tt[a][c];
		}
		if (result < tmpresult)
			result = tmpresult;
	}

	for (int a = 0; a < ho; a++)
	{
		for (int b = 0; b < ve - 3; b++)
		{
			tmpresult = 0;
			for (int c = b; c < b + 4; c++)
				tmpresult += tt[c][a];
		}
		if (result < tmpresult)
			result = tmpresult;
	}

	return result;
}
int case2(vector<vector<int>> tt, int ve, int ho)
{
	int result = 0;
	int tmpresult = 0;
	for (int a = 0; a < ve-1; a++)
	{
		for (int b = 0; b < ho - 1; b++)
		{
			tmpresult = 0;
			tmpresult += tt[a][b] + tt[a][b + 1] + tt[a + 1][b] + tt[a + 1][b + 1];
			if (result < tmpresult)
				result = tmpresult;
		}

	}

	return result;
}
int case3(vector<vector<int>> tt, int ve, int ho)
{
	int result = 0;
	int tmpresult = 0;
	for (int a = 1; a < ve - 1; a++)
	{
		for (int b = 0; b < ho - 1; b++)
		{
			tmpresult = 0;
			tmpresult += tt[a][b] + tt[a-1][b + 1] + tt[a][b+1] + tt[a + 1][b + 1];
			if (result < tmpresult)
				result = tmpresult;
		}
	}

	for (int a =0; a < ve - 2; a++)
	{
		for (int b = 0; b < ho - 1; b++)
		{
			tmpresult = 0;
			tmpresult += tt[a][b] + tt[a + 1][b] + tt[a+2][b] + tt[a + 1][b + 1];
			if (result < tmpresult)
				result = tmpresult;
		}
	}

	for (int a =0; a < ve - 1; a++)
	{
		for (int b = 1; b < ho - 1; b++)
		{
			tmpresult = 0;
			tmpresult += tt[a][b] + tt[a + 1][b-1] + tt[a + 1][b] + tt[a + 1][b + 1];
			if (result < tmpresult)
				result = tmpresult;
		}
	}

	for (int a = 0; a < ve - 1; a++)
	{
		for (int b = 0; b < ho - 2; b++)
		{
			tmpresult = 0;
			tmpresult += tt[a][b] + tt[a][b+1] + tt[a][b+2] + tt[a + 1][b + 1];
			if (result < tmpresult)
				result = tmpresult;
		}
	}

	return result;
}
int case4(vector<vector<int>> tt, int ve, int ho)
{
	int result = 0;
	int tmpresult = 0;
	for (int a = 1; a < ve - 1; a++)
	{
		for (int b = 0; b < ho - 1; b++)
		{
			tmpresult = 0;
			tmpresult += tt[a][b] + tt[a - 1][b + 1] + tt[a][b + 1] + tt[a + 1][b + 1];
			if (result < tmpresult)
				result = tmpresult;
		}
	}

	for (int a = 0; a < ve - 2; a++)
	{
		for (int b = 0; b < ho - 1; b++)
		{
			tmpresult = 0;
			tmpresult += tt[a][b] + tt[a + 1][b] + tt[a + 2][b] + tt[a + 1][b + 1];
			if (result < tmpresult)
				result = tmpresult;
		}
	}

	for (int a = 0; a < ve - 1; a++)
	{
		for (int b = 1; b < ho - 1; b++)
		{
			tmpresult = 0;
			tmpresult += tt[a][b] + tt[a + 1][b - 1] + tt[a + 1][b] + tt[a + 1][b + 1];
			if (result < tmpresult)
				result = tmpresult;
		}
	}

	for (int a = 0; a < ve - 1; a++)
	{
		for (int b = 0; b < ho - 2; b++)
		{
			tmpresult = 0;
			tmpresult += tt[a][b] + tt[a][b + 1] + tt[a][b + 2] + tt[a + 1][b + 1];
			if (result < tmpresult)
				result = tmpresult;
		}
	}

	return result;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> tetromino(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int cmd;
			cin >> cmd;
			tetromino[i].push_back(cmd);
		}
	}

}
