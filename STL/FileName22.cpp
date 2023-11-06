//프그 lv2 요격 시스템
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> vec;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    //정렬시킨다.
    for (int i = 0; i < targets.size(); i++) {
        vec.push_back({ targets[i][0], targets[i][1] });
    }
    sort(vec.begin(), vec.end());
    //찾아본다.
    int i = 0;
    while (i < vec.size()) {
        //front와 함께 묶일 수 있는 집합을 찾는다.
        int front = vec[i].first;
        int front_min = vec[i].first;
        int end_min = vec[i].second;
        while (true) {
            if (front_min <= vec[i + 1].first && vec[i + 1].first < end_min) {
                //묶일 수 있는 경우
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