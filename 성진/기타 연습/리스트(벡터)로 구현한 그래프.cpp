#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // 정점과 간선의 개수를 입력받음

    vector<int> * graph = new vector<int>[n+1];


    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        // 단방향의 경우 graph[u].push_back(v);만 작성
        // 가중치가 있는 경우 vector<pair<int,int>> graph[n+1];로 만들거나 구조체를 만들어서 가중치와 함께 저장
        // graph[u].push_back(make_pair(v,w)); u->v 가중치: w
    }


    for (int i = 0; i < n + 1; i++){
        cout << i << "번의 리스트" << endl;
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << "  ";
        }
        cout << endl;
    }
}
