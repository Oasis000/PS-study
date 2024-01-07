#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
using namespace std;

int main() {
    //1. c++의 next_permutation 함수
    
    vector<int> vec = { 1, 2, 3 };

    // 순열로 변경
    while (next_permutation(vec.begin(), vec.end())) {
        cout << "3";
        std::cout << "\n";
    }

    //2. string + char
    string str = "hell";
    char c = 'o';
    cout << str + c << endl;; //string과 char은 그냥 +로 붙여주면 됨 (char->string변경 필요 없)

    //int to string, string to int
    int i = 65;
    cout << char(i) << endl; //char과 int는 아스키코드 기준으로 변경된다.
    cout << int('C') << endl;
    cout << 'C' - 'A' << endl;
    cout << to_string(123) << endl;
    cout << stoi("123") << endl;
   
    //1e5
    int a = 1e5;
    cout << a << endl; //not 10e5

    vector<int>v = { 1,2,3,4 };
    while (next_permutation(v.begin(), v.end())) {
        for (int i: v) { //arr, set, map, list에서도 가능함.
            cout << i << " ";
        }
        cout << endl;
    }
}
