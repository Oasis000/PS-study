//프그 lv2 거리두기 확인하기
#include <string>
#include <vector>
#include<iostream>
using namespace std;
int vec1[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int vec2[4][2] = { {1,1},{-1,-1},{1,-1},{-1,1} };

int check(int x, int y) {
    if (x < 0 || y < 0 || x >= 5 || y >= 5) return 0;
    else return 1;
}
int find_ans(vector<string>vec) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (vec[i][j] == 'P') {
                //맨해튼 거리 2 이하의 주변 대기실을 서치한다.
                int new_x, new_y;
                for (int temp = 0; temp < 4; temp++) {
                    new_x = i + vec1[temp][0]; new_y = j + vec1[temp][1]; //선형 1,2
                    if (check(new_x, new_y) == 1) {
                        if (vec[new_x][new_y] == 'P') return 0;
                        if (vec[new_x][new_y] == 'O') {
                            new_x += vec1[temp][0]; new_y += vec1[temp][1];
                            if (check(new_x, new_y) == 1 && vec[new_x][new_y] == 'P') {
                                return 0;
                            }
                        }
                    }
                    new_x = i + vec2[temp][0]; new_y = j + vec2[temp][1]; //대각선
                    if (check(new_x, new_y) == 1 && vec[new_x][new_y] == 'P') {
                        if (vec[new_x][new_y - vec2[temp][1]] != 'X'
                            || vec[new_x - vec2[temp][0]][new_y] != 'X') return 0;
                    }
                }
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int i = 0; i < 5; i++) {
        //find ans
        int ans = find_ans(places[i]);
        answer.push_back(ans);
    }
    return answer;
}