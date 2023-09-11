#include<stdio.h>
#include<iostream>
#include<math.h>
#include<utility>
using namespace std;
int arr[25][25];
bool check[25];
int n;
int ans = INT_MAX;

//dfs�� Ǯ��. �湮(true)�� count�� n/2�̵� ������ Ž���ϰ�, ���� ����Ͽ� max�� �����غ���.
//��� & �湮 check => dfs

void dfs(int count, int pos) {
	if (count == n / 2) {
		//���� ������ max�� �����غ���.
		int sum_1 = 0;
		int sum_2 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if (check[i] == true && check[j] == true) sum_1 = sum_1 + arr[i][j] + arr[j][i]; //��ŸƮ��
				if (check[i] == false && check[j] == false) sum_2 = sum_2 + arr[i][j] + arr[j][i]; //��ũ��
			}
		}
		//max����
		int abss = abs(sum_1 - sum_2);
		if (abss < ans) ans = abss;
		return;
	}
	//������ �����Ѵ�.
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