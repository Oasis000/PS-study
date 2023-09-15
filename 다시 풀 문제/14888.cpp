//백준 실버 1 연산자 끼워넣기
#include<stdio.h>
#include<iostream>
using namespace std;
int arr[15];
int four[5];
int ans_min, ans_max;
int n;

void dfs(int num, int index) {
	//탈출조건
	if (index == n) {
		if (ans_min > num) ans_min = num;
		if (ans_max < num) ans_max = num;
	}
	for (int i = 0; i < 4; i++) {
		if (four[i] == 0) continue;
		four[i]--;
		if (i == 0) dfs(num + arr[index], index + 1);
		if (i == 1) dfs(num - arr[index], index + 1);
		if (i == 2) dfs(num * arr[index], index + 1);
		if (i == 3) dfs(num / arr[index], index + 1);
		four[i]++;
	}
}

int main() {
	cin >> n;
	ans_min = 1000000000; 
	ans_max = -1000000000;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> four[i];
	}
	dfs(arr[0], 1);
	cout << ans_max << endl;
	cout << ans_min;
}