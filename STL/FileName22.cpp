//���� lv2 ��� �ý���
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> vec;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    //���Ľ�Ų��.
    for (int i = 0; i < targets.size(); i++) {
        vec.push_back({ targets[i][0], targets[i][1] });
    }
    sort(vec.begin(), vec.end());
    //ã�ƺ���.
    int i = 0;
    while (i < vec.size()) {
        //front�� �Բ� ���� �� �ִ� ������ ã�´�.
        int front = vec[i].first;
        int front_min = vec[i].first;
        int end_min = vec[i].second;
        while (true) {
            if (front_min <= vec[i + 1].first && vec[i + 1].first < end_min) {
                //���� �� �ִ� ���
                front_min = vec[i + 1].first;
                end_min = min(end_min, vec[i + 1].second);
                i++;
            }
            else {
                i++;
                break;
            }
        }
        answer++;
    }
    return answer;
}