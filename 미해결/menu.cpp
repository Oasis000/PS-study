//���� lv2 �޴� ������ 
//���� or ����ȭ
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

//2���� �̾Ƽ�
//��� ������ ���� set�� �־��ְ� find���ش�. -> �׳� alpha �迭�� �����ϸ� ��.
//���� ���� �ֹ���!!
//�ڵ� ��ȿ������..

map<string,int> answer;
const int MAX = 26;

void find(string a, string b, vector<int> course) {
    int index = 0;
    int alpha[MAX] = { 0, };
    while (index < a.length()) {
        alpha[a[index] - 65]++;
        index++;
    }
    index = 0;
    vector<string>v;

    while (index < b.length()) {
        if (alpha[b[index] - 65] == 1) {
            int size = v.size();
            for (int i = 0; i < size; i++) {
                cout << v[i] << " " << b[index] << endl;
                string str = v[i] + to_string(b[index]); //str �� �� 65?
                v.push_back(str); //���� ���ڵ鿡 �߰��ϴ� ���
            }
            v.push_back(to_string(char(b[index]))); //���� ���ں��� ����
        }
        index++;
    }
    //course�� ����Ѵ�.
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < course.size(); j++) {
            if (v[i].length() != course[j]) continue;
            if (answer.find(v[i]) != answer.end()) {
                auto iter = answer.find(v[i]);
                iter->second++;
            }
            else {
                answer.insert({ v[i],0 });
            }
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    //2���� �̴´�.
    int num = orders.size();
    for (int i = 0; i < num - 1; i++) {
        for (int j = i + 1; j < num; j++) {
            string a = orders[i];
            string b = orders[j];
            cout << a << endl << b << endl;
            find(a, b, course);
        }
    }

    vector<string>answer1;
    int index = 0;
    //�ߺ�

    while (index <course.size()) {

        auto iter = answer.begin();
        auto keep = iter;
        int max = 0;

        int size = course[index++];

        while (iter != answer.end()) {
            if (iter ->first.length() == size) {
                if (max < iter->second) {
                    keep = iter; 
                    max = keep->second;
                }
            }
            iter++;
        }

  
        answer1.push_back(keep->first);
    }
    return answer1;
}

int main() {
    vector<string>orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<int>course = {4,6,8};
    vector<string> ans = solution(orders, course);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}