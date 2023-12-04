//프그 lv2 메뉴 리뉴얼 
//구현 or 최적화
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

//2개를 뽑아서
//모든 조합을 만들어서 set에 넣어주고 find해준다. -> 그냥 alpha 배열에 저장하면 됨.
//가장 많이 주문된!!
//코드 비효율적임..

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
                string str = v[i] + to_string(b[index]); //str 이 왜 65?
                v.push_back(str); //이전 문자들에 추가하는 경우
            }
            v.push_back(to_string(char(b[index]))); //현재 문자부터 시작
        }
        index++;
    }
    //course를 고려한다.
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
    //2개를 뽑는다.
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
    //중복

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