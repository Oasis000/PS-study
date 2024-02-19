#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (string str : skill_trees) {
        //str에서 skill string에 있는 char을 뽑아낸다.
        string s = "";
        for (char a : str) {
            for (char b : skill) {
                if (a == b) s += a;
            }
        }
        //skill과 s를 비교한다.
        int index = 0;
        while (index < skill.length() && index < s.length() && skill[index] == s[index]) {
            index++;
        }
        if (min(skill.length(), s.length()) == index) answer++;
    }
    return answer;
}