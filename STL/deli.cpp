//0225 택배상자
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
const int MAX = 1e6 + 3;
int arr[MAX] = { 0, };
stack<int> s;
queue<int> q;

int solution(vector<int> order) {
    int answer = 0;

    for (int i = 1; i <= order.size(); i++) {
        q.push(i);
    }

    int i = 0; //index order

    while (i < order.size()) {
        int n = order[i];
        if (arr[n] == 0) {
            //queue에 있다.
            while (q.size() > 0 && q.front() != n) {
                s.push(q.front());
                arr[q.front()] = 1;
                q.pop();
            }
            q.pop(); answer++;
        }
        else {
            //stack에 있다.
            if (s.top() == n) {
                answer++; s.pop();
            }
            else {
                break;
            }
        }
        i++;
    }
    return answer;
}