#include <string>
#include <vector>
#include<queue>
using namespace std;
typedef long long ll;
priority_queue<int> pq; //pq�� �켱������ ����(ū) ������� �ڵ����ĵǴ� �ڷᱸ����. -> ��������

// �������� pq
priority_queue<int, vector<int>, greater<int>> pq_ascending;

ll solution(int n, vector<int> works) {
    ll answer = 0;
    //vector�� pq�� ����
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