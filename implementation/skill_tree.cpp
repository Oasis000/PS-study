#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (string str : skill_trees) {
        //str���� skill string�� �ִ� char�� �̾Ƴ���.
        string s = "";
        for (char a : str) {
            for (char b : skill) {
                if (a == b) s += a;
            }
        }
        //skill�� s�� ���Ѵ�.
        int index = 0;
        while (index < skill.length() && index < s.length() && skill[index] == s[index]) {
            index++;
        }
        if (min(skill.length(), s.length()) == index) answer++;
    }
    return answer;
}