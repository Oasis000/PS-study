#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;
bool cmp(vector<int>a, vector<int>b) {
    return a.size() < b.size();
}
vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>>vec;
    int i = 1;
    while (i < s.length()) {
        //{} 찾기
        vector<int> local_vec;
        int find_i = i + 1;
        while (s[find_i] != '}') {
            find_i++;
        }
        //}찾았다.
        string str = s.substr(i + 1, find_i - i - 1);
        //,기준쪼갠다.
        int start = 0;
        int index = 0;
        while (start < str.length()) {
            while (index < str.length() && str[index] != ',') index++;
            //cout<<stoi(str.substr(start,index-start))<<endl;
            local_vec.push_back(stoi(str.substr(start, index - start)));
            index++;
            start = index;
        }
        vec.push_back(local_vec);
        //cout<<s[find_i]<<endl<<s[i]<<endl;
        i = find_i + 2;
    }
    sort(vec.begin(), vec.end(), cmp);
    //find ans
    answer.push_back(vec[0][0]);
    int num = 0;
    while (num + 1 < vec.size()) {
        //sort(vec[num].begin(), vec[num].end());
        vec[num].push_back(1e5 + 1);
        sort(vec[num + 1].begin(), vec[num + 1].end());
        int index = 0;
        while (vec[num][index] == vec[num + 1][index]) index++;
        answer.push_back(vec[num + 1][index]);
        num++;
    }
    return answer;
}