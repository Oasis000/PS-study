#include<stdio.h>
#include<iostream>
using namespace std;
int n; int d;//��ӵ����� ��ġ
int arr[15][3]; //����, ��, ����ġ
int ans = 10005;

void dfs(int sum, int cur_location) {
	if (cur_location > d) return;
	else if (cur_location == d) {
		if (sum < ans) ans = sum;
		return;
	}
	for (int i = 0; i < n; i++) {
		//�����ִ� ��ӵ��ΰ� ������ �������ش�.
		if (arr[i][0] >= cur_location) {
			int len = arr[i][0] - cur_location;
			dfs(sum + len + arr[i][2], arr[i][1]);
		}
	}
	dfs(sum + d - cur_location, d); //������ġ���� �������� �ٷ� �̵��ϴ� ���
}

int main() {
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	dfs(0, 0);
	cout << ans;
}