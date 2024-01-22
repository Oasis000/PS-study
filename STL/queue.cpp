//프그 lv3 이중우선순위큐
#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> a;
    for (int i = 0; i < operations.size(); i++) {
        char ch = operations[i][0];
        int num = stoi(operations[i].substr(2));
        if (ch == 'I') {
            a.push_back(num);
            sort(a.begin(), a.end());
        }
        else if (ch == 'D' && a.size() > 0) {
            if (num == 1) {
                auto iter = a.end() - 1;
                a.erase(iter);
            }
            else {
                a.erase(a.begin());
            }
        }
    }
    vector<int> ans;
    if (a.size() > 0) {
        ans.push_back(a[a.size() - 1]);
        ans.push_back(a[0]);
    }
    else { ans.push_back(0); ans.push_back(0); }
    return ans;
}