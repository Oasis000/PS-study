//ÇÁ±× lv2 Ä«Æê
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int temp = brown + yellow;
    int i;
    for (i = 1; i <= sqrt(temp); i++) {
        if (temp % i == 0) {
            int j = temp / i;
            if (i * 2 + j * 2 - 4 == brown) break;
        }
    }
    answer.push_back(temp / i);
    answer.push_back(i);
    return answer;
}