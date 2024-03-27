#include<iostream>
#include<string>
#include<vector>
using namespace std;

int D[4][2] = { {-2,0},{0,2},{2,0},{0,-2} };
int h, w;

const int S = 25;
int arr[S][S];
int answer;
string ans;

bool check(int a, int b, int dir) {
    int new_a = a + D[dir][0];
    int new_b = b + D[dir][1];
    if (new_a < 0 || new_b < 0 || new_a >= h || new_b >= w) return false;
    else return true;
}
void dfs(int count, int i, int j, string str, int dir) {
    cout << "������ǥ " << count << " " << i << " " << j << " " << dir << endl;
    cout << str << endl;
    if (count == 0) {
        //Ż������
        if (answer > count) {
            answer = count;
            ans = str;
        }
    }
    //�� �������� �̵� (���� üũ) -> 360���� ����?
    int new_dir = dir;
    vector<string> dir_str = { "","R","L" };

    for (int a = 0; a < 4; a++) {
        if (a == 2) continue; //360��
        cout << "new_dir" << new_dir << endl;
        if (check(i, j, new_dir) == true && arr[i + D[new_dir][0]][j + D[new_dir][1]] == '#') {

            //�� �� �ְ�, #�϶�..
            int new_x = D[new_dir][0]; int new_y = D[new_dir][1];
            //if(arr[new_x][new_y]=='.') continue; //���⼭ continue�ϸ� ���� ��ȯ �Ұ�

            cout << "�̵� " << new_x << " " << new_y << endl;

            arr[i + new_x][j + new_y] = '.';
            arr[i + new_x / 2][j + new_y / 2] = '.';
            dfs(count - 2, i + new_x, j + new_y, str + dir_str[a] + 'A', new_dir);
            arr[i + new_x][j + new_y] = '#';
            arr[i + new_x / 2][j + new_y / 2] = '#';
        }
        cout << "cant go" << endl;
        new_dir++;
        new_dir = (new_dir) % 4;
    }
}

int main(int argc, char** argv)
{
    cin >> h >> w;
    char ch;
    int num_of_check = -1;
    answer = 25 * 25 + 1;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> ch;
            if (ch == '#') num_of_check++;
            arr[i][j] = ch;
        }
    }

    //void dfs(int count, int i, int j, string str, int dir){
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (arr[i][j] == '#') {
                //dfs(num_of_check,i,j,"",0);
                arr[i][j] = '.';
                dfs(num_of_check, i, j, "", 1);
                arr[i][j] = '#';
                //dfs(num_of_check,i,j,"",2);
                //dfs(num_of_check,i,j,"",3);
            }
        }
    }
    cout << answer << endl;
    cout << ans << endl;
    return 0;
}