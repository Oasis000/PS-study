#include<stdio.h>
#include<iostream> //use python.., 정확한 시간초과 측정 계산
#include<set>
#include<string>
using namespace std;
int n, m;
char arr[21][21];
bool check[21][21] = { false, }; //사실 방문체크를 할 필요 없다. 왔던곳은 알파벳 중복으로 못가기 때문임.. 
//그냥 알파벳 check해주면 됨. 
//set의 연산 시간복잡도는 logn이지만, 재귀함수가 깊어질수록 하위 루프에 set이 복사되는 과정이 반복되기 때문에 시간초과 발생하는듯.
//백트래킹 할 때 불필요한 자료구조 사용하지 않도록.. 생각!
bool alpha[26] = { false, };
int ans = 1;

int go[4][2] = { {0,1},{0,-1},{1,0},{ -1,0} };

void back(int count, int x, int y) {
	//탈출 - 더이상 갈곳없다.
	if (count > 26) { //ans의 max는 알파벳개수임.
		return;
	}
	for (int i = 0; i < 4; i++) {
		int n_x = x + go[i][0];
		int n_y = y + go[i][1];
		if (n_x < 0 || n_y < 0 || n_x == n || n_y == m) continue;
		if (check[n_x][n_y] == false && alpha[arr[n_x][n_y] - 65] == false) {
			alpha[arr[n_x][n_y] - 65] = true; check[n_x][n_y] = true;
			back(count + 1, n_x, n_y);
			alpha[arr[n_x][n_y] - 65] = false; check[n_x][n_y] = false;
		}
	}
	if (count > ans) ans = count;
}
int main() {
	cin >> n >> m;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i][j]=str[j];
		}
	}
	check[0][0] = true;
	alpha[arr[0][0] - 65] = true;
	back(1, 0, 0);
	cout << ans;
}