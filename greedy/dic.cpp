//���� lv2 ��������

#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

int count = 0;
char arr[5] = { 'A','E','I','O','U' };
vector<string> vec;

void find(string str, int count) {
    //����Ž�� : ��� �ܾ ���� vector�� �־��� ��, �����Ͽ� ���� ã�� ����.
    if (count > 5) return;
    if (str != "") vec.push_back(str);
    for (int i = 0; i < 5; i++) {
        find(str + arr[i], count + 1);
    }
}

int solution(string word) {
    string str = "";
    find(str, 0);
    //vector�� �����Ѵ�.
    sort(vec.begin(), vec.end());
    //ã���ش�.
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == word) return i + 1;
    }
}