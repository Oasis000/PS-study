#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 1e9;
    int local_min = stones[0];
    for (int j = 0; j < k; j++) {
        if (local_min < stones[j]) local_min = stones[j];
    }
    for (int i = 1; i < stones.size() - k; i++) {
        if (local_min == stones[i - 1]) {
            local_min = 0;
            for (int j = i; j < k + i; j++) {
                if (local_min < stones[j]) local_min = stones[j];
            }
        }
        else {
            local_min = max(local_min, stones[i + k]);
        }
        //cout<<local_min<<endl;
        answer = min(answer, local_min);
    }
    if (stones.size() == 1) answer = stones[0];
    return answer;
}