//프그 lv2 테이블 해시 함수
#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
int g_col;

int XOR(int x, int y) {
    return x ^ y;
}

bool cmp(vector<int> a, vector<int> b) {
    if (a[g_col] == b[g_col] && a.size() > 1) return a[0] > b[0];
    else return a[g_col] < b[g_col];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    col--; row_begin--; row_end--;
    g_col = col;

    sort(data.begin(), data.end(), cmp);
    //3
    vector<int>temp;
    for (int i = row_begin; i <= row_end; i++) {
        int sum = 0;
        for (int a : data[i]) {
            sum = sum + (a % (i + 1));
        }
        temp.push_back(sum);
    }
    int answer;
    if (temp.size() > 1) {
        answer = XOR(temp[0], temp[1]);
        for (int i = 2; i < temp.size(); i++) {
            answer = XOR(answer, temp[i]);
        }
    }
    else {
        answer = temp[0];
    }
    return answer;
}