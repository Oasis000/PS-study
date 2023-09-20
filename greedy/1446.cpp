#include<stdio.h>
#include<iostream>
using namespace std;
int n; int d;//고속도로의 위치
int arr[15][3]; //시작, 끝, 가중치
int ans = 10005;

void dfs(int sum, int cur_location) {
	if (cur_location > d) return;
	else if (cur_location == d) {
		if (sum < ans) ans = sum;
		return;
	}
	for (int i = 0; i < n; i++) {
		//갈수있는 고속도로가 있으면 연결해준다.
		if (arr[i][0] >= cur_location) {
			int len = arr[i][0] - cur_location;
			dfs(sum + len + arr[i][2], arr[i][1]);
		}
	}
	dfs(sum + d - cur_location, d); //현재위치에서 목적지로 바로 이동하는 경우
}

int main() {
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	dfs(0, 0);
	cout << ans;
}