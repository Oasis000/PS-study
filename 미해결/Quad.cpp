//���� ���� �� ���� ���� lv2 ����
//1117 ���� ���ذ�.

#include <string>
#include <vector>
#include<iostream>
using namespace std;

//bottom up���� �Ľ��Ѵ�.
int global_1 = 0;
int global_0 = 0;

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    
    int size = arr[0].size();
    for (int i = 2; i <= size; i *= 2) {
        if (i == 2) {
            int r = 0; int c = 0;
            while (r < size) { //i�� 2�� ���� ���� �簢���� ������ �� �ش�. -> global���� �ݿ��Ѵ�.
                int num_of_1 = 0;
                int num_of_0 = 0;
                for (int j = r; j < r + i; j++) {
                    for (int k = c; k < c + i; k++) {
                        if (arr[j][k] == 1) num_of_1++;
                        else num_of_0++;
                    }
                }
                if (num_of_0 == 0 || num_of_1 == 0) { //���� �����ϴ�.
                    if (num_of_0 == 0) global_1 += 1;
                    else global_0 += 1;
                }
                else {
                    global_0 += num_of_0;
                    global_1 += num_of_1;
                }
                //r�� c 
                if (r + i < size) {
                    c = c + i;
                }
                else {
                    r = r + i;
                    c = 0;
                }
            }
        }
        else { //bottom���� �ö�� ������ ���� �����ش�.
            int r = 0; int c = 0;
            while (r < size) { //���� �簢���� �±׸� ����
                bool check = true;
                int tag = arr[r][c];
                for (int j = r; j < r + i; j++) {
                    for (int k = c; k < c + i; k++) {
                        if (arr[j][k] == tag && arr[j][k] != -1) {
                            arr[j][k] = tag;
                        }
                        else {
                            check = false;
                            return;
                        }
                    }
                }
                if (check == false) { //false�� ��� �±��Ѵ�.
                    arr[r][c] = -1;
                }
                else {
                    if (arr[r][c] == 0) global_0 -= 3;
                    else global_1 -= 3;
                }
                //r�� c 
                if (r + i < size) {
                    c = c + i;
                }
                else {
                    r = r + i;
                    c = 0;
                }
            }
        }
    }
    answer.push_back(global_0);
    answer.push_back(global_1);
    return answer;
}

int main() {
    vector<vector<int>>arr = { {1, 1, 1, 1, 1, 1, 1, 1},{0, 1, 1, 1, 1, 1, 1, 1},{0, 0, 0, 0, 1, 1, 1, 1},
        {0, 1, 0, 0, 1, 1, 1, 1},{0, 0, 0, 0, 0, 0, 1, 1},{0, 0, 0, 0, 0, 0, 0, 1},{0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 1, 1, 1} };
    vector<int> answer = solution(arr);
    cout << answer[0] << " " << answer[1];
}