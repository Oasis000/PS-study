//���� lv2 �޴� ������ 
//���� or ����ȭ
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

//2���� �̾Ƽ�
//��� ������ ���� set�� �־��ְ� find���ش�. -> �׳� alpha �迭�� �����ϸ� ��.

map<string, int> answer;
const int MAX = 26;
int arr[20][MAX];
vector<char>a;

void find(string str, int index, int num) {
    //�� index�� �����ϴ� ��� or ���� �ʴ� ���
    if (num == str.length()) {
        if (answer.find(str) == answer.end()) {
            //��� str�� �˻��Ͽ� Ȯ���Ѵ�?
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
    find(str + a[index], index + 1, num); //str +char �׳� �ٿ���. to_string(char) �ϸ� int�� �� ;;;��
    find(str, index + 1, num);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    std::fill(&arr[0][0], &arr[20 - 1][MAX], 0); //������ �迭�� Ư�� value������ �ʱ�ȭ�� �� ����Ѵ�. al-��� �߰����ֱ�.
    cout << arr[0][0];
    vector<string>ans;
    //�� string�� ���ĺ� ������ ���� �ش�.
    for (int i = 0; i < orders.size(); i++) {
        for (int j = 0; j < orders[i].length(); j++) {
            arr[i][orders[i][j] - 65]++;
        }
    }
    //orders���� �ΰ��� �̾Ƽ� ����� ���ĺ��� �̰� string�� ����� answer �¿� �������ش�.
    for (int i = 0; i < orders.size(); i++) {
        for (int j = i + 1; j < orders.size(); j++) {
            for (int temp = 0; temp < MAX; temp++) {
                if (arr[i][temp] > 0 && arr[j][temp] > 0) { //���� ���ĺ� ����
                    char ch = (char)(temp + 65);
                    a.push_back(ch);
                }
            }
            for (int temp = 0; temp < course.size(); temp++) {
                int size = course[temp];
                //�����Ѵ�.
                find("", 0, size); //str, index, num
            }
            a.clear(); //vector�� ��� ��
        }

    }
    for (auto iter = answer.begin(); iter != answer.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
    return ans;
}