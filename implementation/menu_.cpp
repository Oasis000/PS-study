//프그 lv2 메뉴 리뉴얼 
//구현 or 최적화
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

//2개를 뽑아서
//모든 조합을 만들어서 set에 넣어주고 find해준다. -> 그냥 alpha 배열에 저장하면 됨.

map<string, int> answer;
const int MAX = 26;
int arr[20][MAX];
vector<char>a;

void find(string str, int index, int num) {
    //현 index를 선택하는 경우 or 하지 않는 경우
    if (num == str.length()) {
        if (answer.find(str) == answer.end()) {
            //모든 str을 검사하여 확인한다?
            int count = 0;
            for (int i = 0; i < str.size(); i++) {
                int b = true;
                for (int j = 0; j < str.length(); j++) {
                    if (arr[i][str[j]] == 0) {
                        b = false;
                        break;
                    }
                }
                count++;
            }

            answer.insert({ str, count });

        }
        cout << str << endl;
        return;
    }
    if (index >= a.size()) return;
    find(str + a[index], index + 1, num); //str +char 그냥 붙여짐. to_string(char) 하면 int로 됨 ;;;ㅎ
    find(str, index + 1, num);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    std::fill(&arr[0][0], &arr[20 - 1][MAX], 0); //이차원 배열을 특정 value값으로 초기화할 때 사용한다. al-헤더 추가해주기.
    cout << arr[0][0];
    vector<string>ans;
    //각 string의 알파벳 개수를 세어 준다.
    for (int i = 0; i < orders.size(); i++) {
        for (int j = 0; j < orders[i].length(); j++) {
            arr[i][orders[i][j] - 65]++;
        }
    }
    //orders에서 두개를 뽑아서 공통된 알파벳을 뽑고 string을 만들어 answer 셋에 저장해준다.
    for (int i = 0; i < orders.size(); i++) {
        for (int j = i + 1; j < orders.size(); j++) {
            for (int temp = 0; temp < MAX; temp++) {
                if (arr[i][temp] > 0 && arr[j][temp] > 0) { //공통 알파벳 추출
                    char ch = (char)(temp + 65);
                    a.push_back(ch);
                }
            }
            for (int temp = 0; temp < course.size(); temp++) {
                int size = course[temp];
                //조합한다.
                find("", 0, size); //str, index, num
            }
            a.clear(); //vector를 비울 때
        }

    }
    for (auto iter = answer.begin(); iter != answer.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
    return ans;
}