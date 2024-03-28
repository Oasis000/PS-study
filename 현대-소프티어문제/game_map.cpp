//프그 lv2 게임 맵 최단거리 dfs
#include<vector>
//#include<iostream>
using namespace std;
int n, m;
int answer;
vector<vector<int>> vec;

int arr[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

void dfs(int count, int i, int j) {
    if (count >= answer) return;
    if (i == n - 1 && j == m - 1) {
        if (count < answer) answer = count;
        return;
    }
    //동서남북 탐방
    //방문체크
    for (int index = 0; index < 4; index++) {
        int new_x = i + arr[index][0];
        int new_y = j + arr[index][1];
        if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) {
            continue;
        }
        else {
            if (vec[new_x][new_y] == 1) {
                vec[new_x][new_y] = 0;
                dfs(count + 1, new_x, new_y);
                vec[new_x][new_y] = 1;
            }
        }
    }
}

int solution(vector<vector<int>> maps)
{
    answer = 100 * 100 + 1;
    vec = maps;
    n = maps.size(); m = maps[0].size();
    //(0,0)에서 시작
    vec[0][0] = 0;
    dfs(1, 0, 0);

    if (answer == 100 * 100 + 1) answer = -1;
    return answer;
}