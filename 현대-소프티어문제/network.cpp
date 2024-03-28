//네트워크 lv3프그
#include <string>
#include <vector>
#include <queue>
using namespace std;
const int S = 200;
int check[S];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int node;

    while (1) {
        queue<int>q;
        int i;
        for (i = 0; i < n; i++) {
            if (check[i] == 0) {
                q.push(i);
                check[i] = 1;
                break;
            }
        }
        if (i == n) break;
        while (q.size() > 0) {
            node = q.front();
            q.pop();
            for (int i = 0; i < n; i++) {
                //연결되어있고 가지 않았으면 탐색
                if (check[i] == 0 && computers[i][node] == 1) {
                    check[i] = 1;
                    q.push(i);
                }
            }
        }
        answer++;
    }

    return answer;
}