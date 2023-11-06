//프그 lv2 광물캐기
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int jewel(string a, string b) {
    if (a == "diamond") return 1;
    else if (a == "iron") {
        if (b == "diamond") return 5;
        else return 1;
    }
    else {
        if (b == "diamond") return 25;
        else if (b == "iron") return 5;
        else return 1;
    }
}
vector<int> picks;
vector<string> minerals;
int answer = 100000;

void recursive(int sum, int index) {
    if (index >= minerals.size()) {
        //최솟값 비교 후 저장.
        if (answer > sum) answer = sum;
        return;
    }
    if (picks[0] == 0 && picks[1] == 0 && picks[2] == 0) {
        if (answer > sum) answer = sum;

    }
    int part_sum1 = 0;
    int part_sum2 = 0;
    int part_sum3 = 0;

    for (int i = index; i < minerals.size() && i < index + 5; i++) {
        part_sum1 += jewel("diamond", minerals[i]);
        part_sum2 += jewel("iron", minerals[i]);
        part_sum3 += jewel("stone", minerals[i]);
    }
    if (picks[0] > 0) {
        picks[0]--;
        recursive(sum + part_sum1, index + 5);
        picks[0]++;
    }
    if (picks[1] > 0) {
        picks[1]--;
        recursive(sum + part_sum2, index + 5);
        picks[1]++;
    }
    if (picks[2] > 0) {
        picks[2]--;
        recursive(sum + part_sum3, index + 5);
        picks[2]++;
    }
}
int solution(vector<int> pick, vector<string> mineral) {
    picks = pick;
    minerals = mineral;
    recursive(0, 0);
    return answer;
}