//���� lv2 �ǻ� : ���� �� �б� ����

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    //���� : ��, ����, ����, �ѿ� /  �ƴ�.. -> ������.

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
            //ã�� ���
            sort[index]++;
        }
    }
    int answer = 1; //������ ������ش�.
    for (int i = 0; i < sort.size(); i++) {
        answer *= (sort[i] + 1);
    }
    answer--;
    return answer;
}