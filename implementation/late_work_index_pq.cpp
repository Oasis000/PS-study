#include <string>
#include <vector>
#include<queue>
using namespace std;
typedef long long ll;
priority_queue<int> pq; //pq는 우선순위가 높은(큰) 순서대로 자동정렬되는 자료구조임. -> 내림차순

// 오름차순 pq
priority_queue<int, vector<int>, greater<int>> pq_ascending;

ll solution(int n, vector<int> works) {
    ll answer = 0;
    //vector를 pq에 복사
    for (int i = 0; i < works.size(); i++) {
        pq.push(works[i]);
    }
    for (int i = 0; i < n; i++) {
        int temp = pq.top();
        pq.pop();
        pq.push(temp - 1);
    }
    while (pq.size() > 0) {
        int temp = pq.top();
        pq.pop();
        if (temp < 0) continue;
        answer += (ll)temp * (ll)temp;
    }

    return answer;
}