//그냥 탐색? 아니면 이분 탐색?
//일단 그냥 탐색으로 (1000만.)
#include <string>
#include <vector>
#include<iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 1;
    int up, down;
    sort(citations.begin(), citations.end());

    while (answer <= citations[citations.size() - 1]) {
        up = 0; down = 0;
        //세어 준다.
        for (int i = 0; i < citations.size(); i++) {
            if (answer <= citations[i])  up++;
            if (answer > citations[i])  down++;
        }
        if (up >= answer && down <= answer)  answer++;
        else  break;
    }
    return answer - 1;
}