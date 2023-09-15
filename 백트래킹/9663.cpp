// ���� 9663 n-queen
// ��Ʈ��ŷ, �ٽ� Ǯ� ����
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int n; 
int arr[15];
int ans = 0;

//���� �� ������ üũ�ϴ� �Լ�
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
		//���� row���� ���� �� �ִ� colüũ �� �����ش�.
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