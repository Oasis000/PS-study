//프그 lv2 모음사전

#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

int count = 0;
char arr[5] = { 'A','E','I','O','U' };
vector<string> vec;

void find(string str, int count) {
    //완전탐색 : 모든 단어를 만들어서 vector에 넣어준 뒤, 정렬하여 답을 찾을 것임.
    if (count > 5) return;
    if (str != "") vec.push_back(str);
    for (int i = 0; i < 5; i++) {
        find(str + arr[i], count + 1);
    }
}

int solution(string word) {
    string str = "";
    find(str, 0);
    //vector를 정렬한다.
    sort(vec.begin(), vec.end());
    //찾아준다.
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == word) return i + 1;
    }
}