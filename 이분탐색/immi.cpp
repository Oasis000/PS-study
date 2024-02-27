//�Ա��ɻ� -> �̺�Ž�� ��ƴ� �Ф�
//n�� ����ġ�� ũ�ų�, �յ� �й��ϴ� ������ ��� ����غ���..
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<int>times;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());

    ll begin = 1;
    ll end = ll(times[times.size() - 1]) * n; //int*int �� overflow
    ll mid;
    while (begin <= end) {
        mid = (begin + end) / 2;
        ll total = 0;
        for (ll a : times) {
            total = total + mid / (ll)a;
        }
        if (total >= n) { //�ð��� ���δ�.
            end = mid - 1;
            answer = mid;
        }
        else { //�ð��� �ø���.
            begin = mid + 1;
        }
    }

    return answer;
}