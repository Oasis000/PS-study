//프그 lv3 가장 먼 노드 2:55
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 20000 + 3;
int check[MAX];
vector<vector<int>>graph(MAX);

void dfs(int node) {
    for (int i : graph[node]) {
        if (check[node] + 1 < check[i] || check[i] == MAX * 3) {
            check[i] = check[node] + 1;
            dfs(i);
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for (int i = 1; i <= n; i++) check[i] = MAX * 3;
    for (vector<int>e : edge) {
        int start = e[0]; int end = e[1];
        graph[start].push_back(end); graph[end].push_back(start);
    }
    check[1] = 0;
    dfs(1);
    //find ans
    sort(check, check + n);
    int count = check[n - 1];
    for (int i = 1; i <= n; i++) {
        if (check[i] == count) answer++;
    }
    return answer;
}