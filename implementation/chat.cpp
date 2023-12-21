#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

map<string, string>m;

string find(string str, bool is_uid) {
    //uid나 이름을 찾아주는 함수
    if (str[0] == 'C') str = str.substr(7);
    else str = str.substr(6);
    int i;
    for (i = 0; i < str.length(); i++) {
        if (str[i] == ' ') break;
    }
    if (is_uid == true) return str.substr(0, i);
    else return str.substr(i + 1);
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    for (int i = 0; i < record.size(); i++) {
        //enter, change에 대해서 (닉네임이 변경될 수 있는 경우에 대해서) 가장 마지막 닉네임을 map에 저장해준다.
        if (record[i][0] == 'E' || record[i][0] == 'C') {
            string uid = find(record[i], true);
            if (m.find(uid) != m.end()) {
                auto iter = m.find(uid);
                iter->second = find(record[i], false);
            }
            else {
                //추가해주기
                m.insert({ find(record[i],true), find(record[i],false) });
            }
        }
    }
    //변경된 닉네임을 고려하여 string을 변경해준다.
    for (int i = 0; i < record.size(); i++) {
        string uid = find(record[i], true);
        string name;
        if (m.find(uid) == m.end()) {
            name = find(record[i], false);
        }
        else {
            name = m.find(uid)->second;
        }
        string ans_str;

        if (record[i][0] == 'E') {
            ans_str = name + "님이 들어왔습니다.";
        }
        else if (record[i][0] == 'L') {
            ans_str = name + "님이 나갔습니다.";
        }
        else {
            continue;
        }
        answer.push_back(ans_str);
    }
    return answer;
}