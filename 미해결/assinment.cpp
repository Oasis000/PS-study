//프그 lv2 과제 진행하기

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include<algorithm>
using namespace std;

//시간 str을 분으로 변경해주는 함수
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
    //시간 -> 분으로 변경 후 시간 순 정렬한다.
    for (int i = 0; i < plans.size(); i++) {
        vec.push_back({ change(plans[i][1]),stoi(plans[i][2]), i });
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < plans.size(); i++) {
        cout << vec[i][0] << " " << vec[i][1] <<" " << plans[vec[i][2]][0] << endl;
    }
    int index = 0;
    while (index < plans.size()) {
        //마지막 과목인 경우
        if (index == plans.size() - 1) {
            answer.push_back(plans[vec[index][2]][0]);
            break;
        }
        //다음 과제가 있다면, 고려
        while (index + 1 < plans.size()) {
            int next_start_time = vec[index + 1][0];
            int cur_end_time = vec[index][0] + vec[index][1];
            if (next_start_time < cur_end_time) {
                //다음 과제를 해야하는 경우 스위치한다.
                cout << "다음과제로 스위치 " << next_start_time << " " << cur_end_time << endl;
                time = next_start_time;
                //다 못한 과제를 스택에 넣어 줌.
                s.push({ vec[index][1] - (vec[index + 1][0] - vec[index][0]), vec[index][2] });
                cout << "s.top is " << s.top()[0] << " " << s.top()[1] << endl;
            }
            else {
                cout << "과제 완료 " << cur_end_time << plans[vec[index][2]][0] << endl;
                answer.push_back(plans[vec[index][2]][0]);
                time = cur_end_time;
                index++;
                break;
            }
            index++;
        }
        //중간에 term이 생기는 경우 -> 기존에 하던 과제를 끝낸다.
        //time 설정??
        while (!s.empty()) {
            int next_start_time = vec[index][0];
            int left_min = s.top()[0];
            cout << "기존 과제 실행 " << endl;
            cout << time + left_min << " " << next_start_time << endl;
            if (time + left_min > next_start_time) { //과제를 다 못함
                s.top()[0] = (left_min - (next_start_time - time));
                break;
            }
            else { //과제를 다 함.
                cout << "과제 완 " << plans[s.top()[1]][0] << endl;
                answer.push_back(plans[s.top()[1]][0]);
                s.pop();
            }
        }
        
    }
    //남은 과제만 다 하면 되는 경우
    while (!s.empty()) {
        answer.push_back(plans[s.top()[1]][0]);
        cout << "과제 완 " << plans[s.top()[1]][0] << endl;
        s.pop();
    }
    return answer;
}

int main() {
    vector<vector<string>>plan = { {"korean", "11:40", "30"},{"english", "11:10", "20"},{"math", "11:20", "40"} };
    //vector<vector<string>>plan = { {"science", "12:40", "50"},{"music", "12:20", "40"},{"history", "14:00", "30"},{"computer", "12:30", "100"} };
    //vector<vector<string>>plan = { {"A", "11:40", "30"},{"B", "12:10", "20"},
      //  {"C", "12:30", "40"} ,{"D", "12:50", "40"} ,{"E", "13:30", "40"} ,{"F", "11:30", "40"} };

    vector<string>ans = solution(plan);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}