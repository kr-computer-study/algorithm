#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int a_ans[5] = { 1,2,3,4,5 };
    int b_ans[8] = { 2,1,2,3,2,4,2,5};
    int  c_ans[10] = {3,3,1,1,2,2,4,4,5,5};
    //반복할 배열을 지장
    int score[3] = { 0, };
    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == a_ans[i % 5])
            score[0]++;
        if (answers[i] == b_ans[i % 8])
            score[1]++;
        if (answers[i] == c_ans[i % 10])
            score[2]++;
    }

    int m = max(score[0], max(score[1], score[2]));
    for (int i = 0; i < 3; i++){
        if (score[i] == m)
            answer.push_back(i + 1);
    }

    return answer;
}
