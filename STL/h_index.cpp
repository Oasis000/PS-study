//�׳� Ž��? �ƴϸ� �̺� Ž��?
//�ϴ� �׳� Ž������ (1000��.)
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
        //���� �ش�.
        for (int i = 0; i < citations.size(); i++) {
            if (answer <= citations[i])  up++;
            if (answer > citations[i])  down++;
        }
        if (up >= answer && down <= answer)  answer++;
        else  break;
    }
    return answer - 1;
}