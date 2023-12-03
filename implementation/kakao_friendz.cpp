//���� lv2 ������4��� ����.
#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int MAX = 30;
int go[4][2] = { {0,0}, {0,1}, {1,0}, {1,1} };
vector<string> board;

//find method
int find(int m, int n) {
    //��� ��Ͽ� ���� �ǽ��Ѵ�.
    int answer = 0;
    bool arr[MAX][MAX]; //�湮 üũ 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = false;
        }
    }
    //ã�ƺ���.
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            //arr index overflow ���ɼ� ����ϱ� (-1)
            char fz = board[i][j];
            if (fz == '_') continue;
            if (board[i + 1][j] == fz && board[i][j + 1] == fz && board[i + 1][j + 1] == fz) {
                for (int k = 0; k < 4; k++) {
                    int r = i + go[k][0];
                    int c = j + go[k][1];
                    if (arr[r][c] == false) {
                        arr[r][c] = true;
                        answer++;
                    }
                }
            }
        }
    }
    //���带 �����Ѵ� (2*2 �κ� �����ش�.)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == true) board[i][j] = '_';
        }
    }
    return answer;
}

//drop method - ����� ����߸���.
void drop(int m, int n) {
    int row = 0;
    int col = 0;
    while (col < n) {
        string str = "";
        while (row < m) {
            if (board[row][col] != '_') str += board[row][col];
            row++;
        }
        int size = str.length();
        for (int i = 0; i < m - size; i++) {
            board[i][col] = '_';
        }
        int foo = 0;
        for (int i = m - size; i < m; i++) {
            board[i][col] = str[foo++];
        }
        row = 0;
        col++;
    }

}

int solution(int m, int n, vector<string> b) {
    int answer = 0;
    board = b; //deep shallow?
    //find - drop�� �ݺ��Ѵ�.
    int erase = 1;
    while (erase > 0) {
        erase = find(m, n);
        answer += erase;

        drop(m, n);
    }
    return answer;
}