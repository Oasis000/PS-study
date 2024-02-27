//입국심사 -> 이분탐색 어렵다 ㅠㅠ
//n이 지나치게 크거나, 균등 분배하는 문제일 경우 고려해보기..
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
    ll end = ll(times[times.size() - 1]) * n; //int*int 시 overflow
    ll mid;
    while (begin <= end) {
        mid = (begin + end) / 2;
        ll total = 0;
        for (ll a : times) {
            total = total + mid / (ll)a;
        }
        if (total >= n) { //시간을 줄인다.
            end = mid - 1;
            answer = mid;
        }
        else { //시간을 늘린다.
            begin = mid + 1;
        }
    }

    return answer;
}