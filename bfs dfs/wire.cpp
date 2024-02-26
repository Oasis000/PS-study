#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int MAX = 100 + 1;
int arr[MAX][MAX] = { 0, };

int search(int n, int num, int node[]) {
    int con_node = 1;
    node[n] = 1;
    for (int i = 1; i <= num; i++) {
        if (arr[n][i] == 1 && node[i] == 0) {
            node[i] = 1;
            con_node += search(i, num, node);
        }
    }
    return con_node;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = MAX;
    for (vector<int> vec : wires) {
        int a = vec[0]; int b = vec[1];
        arr[a][b] = 1; arr[b][a] = 1;
    }
    for (vector<int>vec : wires) {
        int a = vec[0]; int b = vec[1];
        arr[a][b] = 0; arr[b][a] = 0;
        int node[MAX] = { 0, };
        int ans_a = search(a, n, node);
        int ans_b = search(b, n, node);
        arr[a][b] = 1; arr[b][a] = 1;

        int cha = ans_a - ans_b;
        if (cha < 0) cha = cha * -1;
        if (answer > cha) answer = cha;
    }
    return answer;
}