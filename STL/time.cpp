//프그 lv2 호텔대실

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> e;

int time(string str) { //더 쉽게 풀기 위해 min으로 변경!! -> 원래대로 str로 구현 시 되게 복잡해짐.
    int min = stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3, 2));
    if (min >= 24 * 60) return min - 24 * 60;
    return min;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;

    vector<pair<int,int>> book;
    for (int i = 0; i < book_time.size(); i++) {
        book.push_back({ time(book_time[i][0]), time(book_time[i][1]) });
    }
    sort(book.begin(), book.end());
    int index = 0;
    vector<int> end;
    while (index < book.size()) {
        //end에서 찾아본다.
        sort(end.begin(), end.end());
        int start_time = book[index].first;
        int end_time = book[index].second;
        int this_index = -1;
        for (int i = end.size() - 1; i >= 0; i--) {
            if (end[i] + 10 <= start_time) {
                this_index = i;
                break;
            }
        }
        if (this_index == -1) {
            //새롭게 추가
            end.push_back(end_time);
        }
        else {
            //기존에 추가
            end[this_index] = end_time;
        }
        index++;
    }
    answer = end.size();
    return answer;
}

int main() {
    vector<vector<string>>vec = { {"00:00", "23:00"},{"23:40", "03:20"},{"00:20", "00:30"},{"01:10", "19:20"},{"19:40", "21:20"} };
    int ans = solution(vec);
    cout << ans;
}