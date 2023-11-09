//���� lv2 ���� �����ϱ�
//������ 75 -> 100�� : ����ð� ���� ������ �κ� �־���.

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include<algorithm>
using namespace std;

//�ð� str�� ������ �������ִ� �Լ�
int change(string str) {
    int h = stoi(str.substr(0, 2));
    int m = stoi(str.substr(3, 2));
    return h * 60 + m;
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<vector<int>>vec;
    stack<vector<int>>s;
    int time = 0;
    //�ð� -> ������ ���� �� �ð� �� �����Ѵ�.
    for (int i = 0; i < plans.size(); i++) {
        vec.push_back({ change(plans[i][1]),stoi(plans[i][2]), i });
    }
    sort(vec.begin(), vec.end());

    int index = 0;
    while (index < plans.size()) {
        //������ ������ ���
        if (index == plans.size() - 1) {
            answer.push_back(plans[vec[index][2]][0]);
            break;
        }
        //���� ������ �ִٸ�, ���
        while (index + 1 < plans.size()) {
            int next_start_time = vec[index + 1][0];
            int cur_end_time = vec[index][0] + vec[index][1];
            if (next_start_time < cur_end_time) {
                //���� ������ �ؾ��ϴ� ��� ����ġ�Ѵ�.
                time = next_start_time;
                //�� ���� ������ ���ÿ� �־� ��.
                s.push({ (cur_end_time - next_start_time), vec[index][2] });
            }
            else {
                answer.push_back(plans[vec[index][2]][0]);
                time = cur_end_time;
                index++;
                break;
            }
            index++;
        }
        //�߰��� term�� ����� ��� -> ������ �ϴ� ������ ������.
        while (!s.empty()) {
            int next_start_time = vec[index][0];
            int left_min = s.top()[0];
            if (time + left_min > next_start_time) { //������ �� ����
                s.top()[0] = (left_min - (next_start_time - time));
                break;
            }
            else { //������ �� ��.
                answer.push_back(plans[s.top()[1]][0]);
                //����κ� ������ 75��.
                time = time + left_min;
                s.pop();
            }
        }

    }
    //���� ������ �� �ϸ� �Ǵ� ���
    while (!s.empty()) {
        answer.push_back(plans[s.top()[1]][0]);
        s.pop();
    }
    return answer;
}