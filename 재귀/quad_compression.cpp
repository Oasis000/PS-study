#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> vec;
vector<int> answer = { 0,0 };

void quad(int i, int j, int n) {
    //(i,j)+n �簢���� ���డ�ɿ��θ� �Ǵ��Ͽ� ��ͷ� �����ش�.

    if (n == 0) return;
    bool can_com = true;
    int ele = vec[i][j];

    for (int r = i; r < i + n; r++) {
        for (int c = j; c < j + n; c++) {
            if (vec[r][c] != ele) {
                can_com = false; break;
            }
        }
    }
    if (can_com == false) {
        quad(i, j, n / 2);
        quad(i + n / 2, j, n / 2);
        quad(i, j + n / 2, n / 2);
        quad(i + n / 2, j + n / 2, n / 2);
    }
    else {
        answer[ele]++;
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vec = arr;
    int n = arr.size();
    quad(0, 0, n);
    return answer;
}