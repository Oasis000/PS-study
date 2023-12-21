#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

map<string, string>m;

string find(string str, bool is_uid) {
    //uid�� �̸��� ã���ִ� �Լ�
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
        //enter, change�� ���ؼ� (�г����� ����� �� �ִ� ��쿡 ���ؼ�) ���� ������ �г����� map�� �������ش�.
        if (record[i][0] == 'E' || record[i][0] == 'C') {
            string uid = find(record[i], true);
            if (m.find(uid) != m.end()) {
                auto iter = m.find(uid);
                iter->second = find(record[i], false);
            }
            else {
                //�߰����ֱ�
                m.insert({ find(record[i],true), find(record[i],false) });
            }
        }
    }
    //����� �г����� ����Ͽ� string�� �������ش�.
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
            ans_str = name + "���� ���Խ��ϴ�.";
        }
        else if (record[i][0] == 'L') {
            ans_str = name + "���� �������ϴ�.";
        }
        else {
            continue;
        }
        answer.push_back(ans_str);
    }
    return answer;
}