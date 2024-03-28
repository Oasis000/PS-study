#include<vector>
#include<queue>
#include<iostream>
using namespace std;
int n, m;
vector<vector<int>> vec;
int arr[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int bfs() {
    //0,0 to n,m-1
    queue<pair<int, int>>q;
    queue<int> ans;
    vec[0][0] = 0;
    q.push({ 0,0 }); ans.push(1);

    int x, y, pre;
    int new_x, new_y;

    while (q.size() > 0) {
        x = q.front().first;
        y = q.front().second;
        pre = ans.front();
        if (x == n - 1 && y == m - 1) {
            return pre;
        }
        q.pop(); ans.pop();
        //¹æ¹®
        for (int i = 0; i < 4; i++) {
            new_x = x + arr[i][0];
            new_y = y + arr[i][1];
            if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= m) continue;
            if (vec[new_x][new_y] == 1) {
                vec[new_x][new_y] = 0;
                q.push({ new_x,new_y });
                ans.push(pre + 1);
            }
        }
    }
    return -1;
}
int solution(vector<vector<int> > maps)
{
    n = maps.size(); m = maps[0].size();
    vec = maps;
    int answer = bfs();
    return answer;
}