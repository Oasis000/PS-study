//프그 lv3 불량 사용자
//vector - find, equal 함수
#include <string>
#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
int answer = 0;
vector<vector<string>> db;

void check(vector<string>user_id, vector<string> banned_id, vector<string> save, int count) {
    if (count == banned_id.size()) {
        //db에서 확인한다.
        sort(save.begin(), save.end());
        for (vector<string> vec : db) {
            if (equal(vec.begin(), vec.end(), save.begin()) == true) return;
        }
        db.push_back(save);
        answer++;
        return;
    }
    string ban_str = banned_id[count];
    for (int i = 0; i < user_id.size(); i++) {
        string str = user_id[i];
        if (ban_str.length() != str.length()) continue;
        else {
            bool same = true;
            for (int index = 0; index < str.length(); index++) {
                if (ban_str[index] == '*') continue;
                if (ban_str[index] != str[index]) same = false;
            }
            if (same == true) {
                vector<string> new_save = save;
                new_save.push_back(str);
                string keep = str;
                user_id[i] = "X";
                check(user_id, banned_id, new_save, count + 1);
                user_id[i] = str;
            }
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    vector<string> save;
    check(user_id, banned_id, save, 0);
    return answer;
}