//프그 lv2 가장 큰 수

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//a[i] == 0으로 비교함; ;; ㅋㅠ
// seg falut -> for문 증감식 ->조건식
//사용자 정렬 함수
bool compare(string a, string b) { //3 < 34 // 만약  0 <null < 1
    int i = 0;
    int j = 0;

    while (true) {
        if (i >= a.length()) { //3 300, 3 34
            if (b[j] == '0')  return false;
            else return true;
        }
        if (j >= b.length()) {
            if (a[i] == '0') return true;
            else return false;
        }
        if (a[i] == b[j]) {
            i++;
            j++;
        }
        else if (a[i] < b[j]) return true;
        else if (a[i] > b[j]) return false;
    }
}

string solution(vector<int> numbers) {
    //int를 string으로 변환하고 정렬한다.
    vector<string> vec;
    for (int i = 0; i < numbers.size(); i++) {
        vec.push_back(to_string(numbers[i]));
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < numbers.size(); i++) {
        cout << vec[i] << endl;
    }
    string answer = "";
    for (int i = vec.size() - 1; i >= 0; i--) {
        string str = vec[i];
        if (i > 0 && str[0] == vec[i - 1][0]) {
            //0. 이슈 해결해야 함.
            //1. 위로 올라가면서 끝을 찾는다.
            int final_index = i - 1;
            while (final_index >= 0 && vec[final_index][0] == str[0]) {
                final_index--;
            }
            final_index++;
            //final_index부터 i까지 사용자 정렬한다.

            cout << *(vec.begin() + final_index) << " " << *(vec.begin() + i) << endl;


            sort(vec.begin() + final_index, vec.begin() + i + 1, compare);


            for (int temp = i; temp >= final_index; temp--) {
                answer += vec[temp];
            }
            i = final_index;
        }
        else {
            answer += str;
        }
    }
    return answer;
}

int main() {
    vector<int> v = { 45,454 };
    cout << solution(v);
}