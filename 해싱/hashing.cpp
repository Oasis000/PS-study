//프그 lv2 의상 : 문제 잘 읽기 ㅎㅎ

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    //종류 : 얼굴, 상의, 하의, 겉옷 /  아님.. -> 예제만.

    vector<int>sort;
    vector<string>sort_str;

    for (int i = 0; i < clothes.size(); i++) {
        string type = clothes[i][1];
        int index = -1;
        for (int j = 0; j < sort.size(); j++) {
            if (sort_str[j] == type) {
                index = j; break;
            }
        }
        if (index == -1) {
            sort_str.push_back(type);
            sort.push_back(1);
        }
        else {
            //찾은 경우
            sort[index]++;
        }
    }
    int answer = 1; //조합을 계산해준다.
    for (int i = 0; i < sort.size(); i++) {
        answer *= (sort[i] + 1);
    }
    answer--;
    return answer;
}