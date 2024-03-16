#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype> //tolower�Լ� ��� ���� cctype ��� �߰�.
using namespace std;

vector<string> return_head(string a) {
    vector<string> arr;
    int i;
    for (i = 0; i < a.length(); i++) {
        if (a[i] >= '0' && a[i] <= '9') {
            arr.push_back(a.substr(0, i));
            break;
        }
    }
    int k;
    for (k = i; k < a.length(); k++) {
        if (a[k] < '0' || a[k]>'9') {
            arr.push_back(a.substr(i, k - i));
            break;
        }
    }
    if (arr.size() == 1) arr.push_back(a.substr(i, k - i));
    return arr;
}
bool comp(string a, string b) {
    vector<string>vec1 = return_head(a);
    vector<string>vec2 = return_head(b);
    //���ϸ� ��
    int i;
    for (i = 0; i < vec1[0].length(); i++) {
        if (vec2[0].length() == i) return false;
        char al_a = tolower(vec1[0][i]);
        char al_b = tolower(vec2[0][i]);
        if (al_a != al_b) {
            return al_a < al_b;
        }
    }
    if (i < vec2[0].length()) return true;

    //���� ��
    int num_a = stoi(vec1[1]);
    int num_b = stoi(vec2[1]);
    return num_a < num_b;

}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    stable_sort(files.begin(), files.end(), comp);
    //sort�� �Ҿ�������(���� Ű���� �����Ҷ� ��� �������) -> stablesort����ϱ�(tc ����.)
    return files;
}