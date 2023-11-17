//쿼드 압축 후 갯수 세기 lv2 프그
//1117 아직 미해결.

#include <string>
#include <vector>
#include<iostream>
using namespace std;

//bottom up으로 파싱한다.
int global_1 = 0;
int global_0 = 0;

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    
    int size = arr[0].size();
    for (int i = 2; i <= size; i *= 2) {
        if (i == 2) {
            int r = 0; int c = 0;
            while (r < size) { //i가 2일 때는 로컬 사각형의 갯수를 세 준다. -> global에도 반영한다.
                int num_of_1 = 0;
                int num_of_0 = 0;
                for (int j = r; j < r + i; j++) {
                    for (int k = c; k < c + i; k++) {
                        if (arr[j][k] == 1) num_of_1++;
                        else num_of_0++;
                    }
                }
                if (num_of_0 == 0 || num_of_1 == 0) { //압축 가능하다.
                    if (num_of_0 == 0) global_1 += 1;
                    else global_0 += 1;
                }
                else {
                    global_0 += num_of_0;
                    global_1 += num_of_1;
                }
                //r과 c 
                if (r + i < size) {
                    c = c + i;
                }
                else {
                    r = r + i;
                    c = 0;
                }
            }
        }
        else { //bottom에서 올라온 정보를 보고 합쳐준다.
            int r = 0; int c = 0;
            while (r < size) { //로컬 사각형의 태그를 본다
                bool check = true;
                int tag = arr[r][c];
                for (int j = r; j < r + i; j++) {
                    for (int k = c; k < c + i; k++) {
                        if (arr[j][k] == tag && arr[j][k] != -1) {
                            arr[j][k] = tag;
                        }
                        else {
                            check = false;
                            return;
                        }
                    }
                }
                if (check == false) { //false인 경우 태깅한다.
                    arr[r][c] = -1;
                }
                else {
                    if (arr[r][c] == 0) global_0 -= 3;
                    else global_1 -= 3;
                }
                //r과 c 
                if (r + i < size) {
                    c = c + i;
                }
                else {
                    r = r + i;
                    c = 0;
                }
            }
        }
    }
    answer.push_back(global_0);
    answer.push_back(global_1);
    return answer;
}

int main() {
    vector<vector<int>>arr = { {1, 1, 1, 1, 1, 1, 1, 1},{0, 1, 1, 1, 1, 1, 1, 1},{0, 0, 0, 0, 1, 1, 1, 1},
        {0, 1, 0, 0, 1, 1, 1, 1},{0, 0, 0, 0, 0, 0, 1, 1},{0, 0, 0, 0, 0, 0, 0, 1},{0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 1, 1, 1} };
    vector<int> answer = solution(arr);
    cout << answer[0] << " " << answer[1];
}