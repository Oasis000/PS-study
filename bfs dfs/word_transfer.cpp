//word transfer
#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<string> words;
int ans = 100;

void find_dfs(int count, string target, string now) {
    //exit
    cout << "now str is " << now << endl;
    if (target == now) {
        if (ans > count) ans = count;
        return;
    }
    if (ans < count) return;

    int words_index = 0;
    for (string str : words) {
        int diff = 0;
        //can transfer ->go
        for (int i = 0; i < str.length(); i++) {
            if (now[i] != str[i]) diff++;
        }
        if (diff == 1) {
            string save = words[words_index];
            words[words_index] = "AAA";
            find_dfs(count + 1, target, str);
            words[words_index] = save;
        }
        words_index++;
    }
}

int solution(string begin, string target, vector<string> word) {
    words = word;
    find_dfs(0, target, begin);
    if (ans == 100) ans = 0;
    return ans;
}