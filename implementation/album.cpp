#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<string, vector<int>>m;
struct PLAY {
    string key;
    int sum;
    vector<pair<int, int>>p; //plays, 고유번호
};
bool fun(PLAY a, PLAY b) {
    return a.sum > b.sum;
}
bool fun2(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<PLAY> vec;
    int index = 0;
    for (string str : genres) {
        bool check = false;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].key == str) {
                vec[i].sum += plays[index];
                vec[i].p.push_back({ plays[index],index });
                check = true;
                index++;
                break;
            }
        }
        if (check == true) continue;
        PLAY play;
        play.key = str;
        play.sum = plays[index];
        vector<pair<int, int>>v;
        v.push_back({ plays[index],index }); play.p = v;
        vec.push_back(play);

        index++;
    }
    cout << vec.size() << endl;
    sort(vec.begin(), vec.end(), fun);

    for (int i = 0; i < vec.size(); i++) {
        sort(vec[i].p.begin(), vec[i].p.end(), fun2);
        answer.push_back(vec[i].p[0].second);
        if (vec[i].p.size() > 1) answer.push_back(vec[i].p[1].second);
    }

    return answer;
}