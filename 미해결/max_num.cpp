//���� lv2 ���� ū ��

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//a[i] == 0���� ����; ;; ����
// seg falut -> for�� ������ ->���ǽ�
//����� ���� �Լ�
bool compare(string a, string b) { //3 < 34 // ����  0 <null < 1
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
    //int�� string���� ��ȯ�ϰ� �����Ѵ�.
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
            //0. �̽� �ذ��ؾ� ��.
            //1. ���� �ö󰡸鼭 ���� ã�´�.
            int final_index = i - 1;
            while (final_index >= 0 && vec[final_index][0] == str[0]) {
                final_index--;
            }
            final_index++;
            //final_index���� i���� ����� �����Ѵ�.

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