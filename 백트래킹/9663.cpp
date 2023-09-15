// 백준 9663 n-queen
// 백트래킹, 다시 풀어볼 문제
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int n; 
int arr[15];
int ans = 0;

//놓을 수 있을지 체크하는 함수
bool check(int row) {
	if (row == 0) return true;
	for (int i = 0; i < row; i++) {
		if (arr[i] == arr[row] || abs(i - row) == abs(arr[i] - arr[row])) {
			return false;
		}
	}
	return true;
}

void dfs(int row) {
	if (row == n) {
		ans++; 
		return;
	}
	for (int i = 0; i < n; i++) {
		//현재 row에서 놓을 수 있는 col체크 후 놓아준다.
		arr[row] = i;
		bool is_ok = check(row);
		if (is_ok == true) {
			dfs(row + 1);
		}
	}
}

int main() {
	cin >> n;
	dfs(0);
	cout << ans;
}