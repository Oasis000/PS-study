#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> play;

bool cmp(int a, int b) {
    return play[a] > play[b];
}
bool cmp_rev(pair<int, string> a, pair<int, string> b) {
    return a.first > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    play = plays;
    vector<int> answer;
    unordered_map<string, vector<int>> um;     //장르에 따른 index를 담는 um;
    unordered_map<string, int> sum_m;
    for (int i = 0; i < genres.size(); i++) {
        //검색
        auto iter = um.find(genres[i]);
        if (iter == um.end()) {
            vector<int> new_vec;
            new_vec.push_back(i);
            um[genres[i]] = new_vec;
            sum_m[genres[i]] = plays[i];
        }
        else {
            iter->second.push_back(i);
            sum_m[genres[i]] += plays[i];
        }
    }
    vector<pair<int, string>> vec;
    for (pair<string, int>a : sum_m) {
        vec.push_back({ a.second, a.first });
    }
    sort(vec.begin(), vec.end(), cmp_rev);

    for (pair<int, string>a : vec) {
        string gen = a.second;
        vector<int> gen_sec = um[gen];
        sort(gen_sec.begin(), gen_sec.end(), cmp);
        answer.push_back(gen_sec[0]);
        if (gen_sec.size() > 1) answer.push_back(gen_sec[1]);
    }
    return answer;
}