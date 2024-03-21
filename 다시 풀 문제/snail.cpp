#include <string>
#include <vector>
#include<iostream>
using namespace std;
int arr[1005][1005];
const int x[3] = { 1,0,-1 };
const int y[3] = { 0,1,-1 };

vector<int> solution(int n) {
    vector<int> answer;

    int i, j, cnt, rot = 0; //모두 0으로 초기화 안됨.
    i = j = cnt = rot = 0;
    int len = n;
    int number = 1;
    while (len > 0) {
        arr[i][j] = number;
        number++;
        cnt++;
        //방향전환
        if (cnt == len) {
            rot = (rot + 1) % 3;
            cnt = 0;
            len--;
        }
        //변위조정
        i = x[rot] + i;
        j = y[rot] + j;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) answer.push_back(arr[i][j]);
    }
    return answer;
}