//프그 lv3 야근지수 (효율성)
#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
//sort 해서 큰것부터 줄여봄.
typedef long long ll;

ll solution(int n, vector<int> works) {
    ll answer = 0;
    sort(works.begin(), works.end());
    int size = works.size() - 1;
    int temp = size;

    for (int i = 0; i < n; i++) {
        works[size]--;
        if (size > 0 && works[size - 1] > works[size]) {
            size = size - 1;
        }
        else {
            size = temp;
        }
    }
    int i = 0;
    size = works.size() - 1;
    while (i != size + 1) {
        cout << works[i] << endl;
        ll temp = ll(works[i++]);
        if (temp < 0) continue;
        answer += temp * temp;
    }
    return answer;
}