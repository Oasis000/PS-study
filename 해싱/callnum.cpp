#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    int size = phone_book.size();
    string sstr;

    for (int i = 0; i < size - 1; i++) {
        string str = phone_book[i];
        string str_a = phone_book[i + 1]; //정렬 후 선형탐색(효율성)

        if (str.length() < str_a.length()) {
            sstr = str_a.substr(0, str.length());
            if (sstr.compare(str) == 0) return false;
        }
        else {
            sstr = str.substr(0, str_a.length());
            if (sstr.compare(str_a) == 0) return false;
        }
    }

    return answer;
}