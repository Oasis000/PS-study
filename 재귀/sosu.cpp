//프그 소수 찾기 lv2 (금)
#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int MAX = 1e8; //not 10e8!
int arr[MAX] = { 0, }; //합성수이면 1
set<int>s;
int ncount[10] = { 0, };

void combination(int size, string str) {
    if (size < str.length()) return;
    cout << str << endl;

    if (str != "") {
        if (arr[stoi(str)] == 0 && s.find(stoi(str)) == s.end()) { //stoi(str) -> str이 ""일때 out of range가 뜬다. 프린트해서 확인해보기
            s.insert(stoi(str));
        }
    }
    
    for (int i = 0; i < 10; i++) {
        if (ncount[i] > 0) {
            ncount[i]--;
            combination(size, str + char(i + 48)); //한 문자는 string X char O
            ncount[i]++;
        }
    }
}

int solution(string numbers) {
    cout << stoi(numbers);
    for (int i = 0; i < numbers.length(); i++) {
        ncount[numbers[i] - '0']++; //직관적!
    }
    int answer = 0;
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i < sqrt(MAX); i++) {
        if (arr[i] == 0) {
            for (int j = 2; j * i < MAX; j++) {
                arr[i * j] = 1;
            }
        }
    }
    combination(numbers.length(), "");
    //조합 알고리즘을 이용하여 수를 만들고 check하여 set에 저장한다.
    return s.size();
}

int main() {
    cout << solution("125")<<endl;
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << endl;
    }
}