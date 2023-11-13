//11_13 프그 숫자변환하기 lv2
#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
//자료구조 선언
queue<int>q;
const int MAX = 1e6 + 3;
int arr[MAX];

bool check(int n) {
    if (n > MAX) return false;
    if (arr[n] != -1) return false;
    return true;
}

void bfs(int x, int y, int n) {
    for (int i = 0; i < MAX; i++) arr[i] = -1;
    //초기 숫자
    arr[x] = 0;
    q.push(x);
    while (q.size() > 0) {
        if (arr[y] != -1) return;
        int front = q.front();
        q.pop();
        if (check(front * 3)) {
            //방문가능하면 방문한다.
            q.push(front * 3); arr[front * 3] = arr[front] + 1;
        }
        if (check(front * 2)) {
            q.push(front * 2); arr[front * 2] = arr[front] + 1;
        }
        if (check(front + n)) {
            q.push(front + n); arr[front + n] = arr[front] + 1;
        }
    }
}

int solution(int x, int y, int n) {
    int answer = 0;
    bfs(x, y, n);
    return arr[y];
}