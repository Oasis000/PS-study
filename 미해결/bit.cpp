#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
vector<ll> keep;

ll find(ll a) {
    ll count = 0;
    while (a % 2 != 0) {
        a = a / 2;
        count = count + 1;
    }
    if (a == 0) return keep[count - 1];
    return keep[count];
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    int count = 1;
    keep.push_back(1);
    while (count <= 100) {
        keep.push_back(keep[count - 1] * 2);
        count++;
    }
    for (ll n : numbers) {
        //cout<<find(n)<<endl;
        answer.push_back(find(n) + n);
    }
    return answer;
}