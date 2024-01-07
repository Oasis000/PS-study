#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
using namespace std;

int main() {
    //1. c++�� next_permutation �Լ�
    
    vector<int> vec = { 1, 2, 3 };

    // ������ ����
    while (next_permutation(vec.begin(), vec.end())) {
        cout << "3";
        std::cout << "\n";
    }

    //2. string + char
    string str = "hell";
    char c = 'o';
    cout << str + c << endl;; //string�� char�� �׳� +�� �ٿ��ָ� �� (char->string���� �ʿ� ��)

    //int to string, string to int
    int i = 65;
    cout << char(i) << endl; //char�� int�� �ƽ�Ű�ڵ� �������� ����ȴ�.
    cout << int('C') << endl;
    cout << 'C' - 'A' << endl;
    cout << to_string(123) << endl;
    cout << stoi("123") << endl;
   
    //1e5
    int a = 1e5;
    cout << a << endl; //not 10e5

    vector<int>v = { 1,2,3,4 };
    while (next_permutation(v.begin(), v.end())) {
        for (int i: v) { //arr, set, map, list������ ������.
            cout << i << " ";
        }
        cout << endl;
    }
}
