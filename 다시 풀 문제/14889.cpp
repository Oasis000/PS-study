#include<stdio.h>
#include<iostream>
#include<math.h>
#include<utility>
using namespace std;
int arr[25][25];
bool check[25];
int n;
int ans = INT_MAX;

//dfs로 풀기. 방문(true)한 count가 n/2이될 때까지 탐색하고, 합을 계산하여 max를 갱신해본다.
//재귀 & 방문 check => dfs

void dfs(int count, int pos) {
	if (count == n / 2) {
		//합을 구한후 max를 갱신해본다.
		int sum_1 = 0;
		int sum_2 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if (check[i] == true && check[j] == true) sum_1 = sum_1 + arr[i][j] + arr[j][i]; //스타트팀
				if (check[i] == false && check[j] == false) sum_2 = sum_2 + arr[i][j] + arr[j][i]; //링크팀
			}
		}
		//max갱신
		int abss = abs(sum_1 - sum_2);
		if (abss < ans) ans = abss;
		return;
	}
	//팀원을 선택한다.
	for (int i = pos; i < n; i++) {
		check[i] = true;
		dfs(count + 1, i + 1);
		check[i] = false;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(0,0);
	cout << ans;
}