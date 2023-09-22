#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
int n;
int arr[10];
int graph[10][10] = { 0, };
bool check[10];
int ans = 100000;

int is_connected(int count) {
	queue<int>q;
	bool check_copy[10];
	copy(check, check + 10, check_copy);

	for (int i = 0; i < n; i++) {
		if (check_copy[i] == false) {
			q.push(i);
			check_copy[i] = true;
			break;
		}
	}
	int sum = 0;

	while (q.empty() == false) {
		int num = q.front();
		q.pop();		
		sum += arr[num];

		for (int i = 0; i < n; i++) {
			if (graph[i][num] == 1 && check_copy[i] == false) {
				count--;
				check_copy[i] = true;
				q.push(i);
			}
		}
	}
	if (count == 1) return sum;
	else return -1;
}
void dfs(int count, int node_num, int sum) {
	if (count >= 1) { //�ϳ��� ����Ǿ��ٸ� ã�ƺ���..
		int num = n - count;
		if (num < 1) return;

		int result = is_connected(num);
		if (result == -1) return;
		if (abs(result - sum) < ans) ans = abs(result - sum);
		return;
	}
	check[node_num] = true;
	//������ �� �ִ� ���� �����غ���.
	for (int i = 0; i < n; i++) {
		if (graph[i][node_num] == 1 && check[i] == false) { //����Ǿ��ְ� �湮���� �ʾҴٸ�, �湮�غ���.
			check[i] = true;
			dfs(count + 1, i, sum + arr[i]);
			check[i] = false;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int c_n, num;
	for (int i = 0; i < n; i++) {
		cin >> c_n;
		while (c_n--) {
			cin >> num;
			graph[i][num - 1] = 1; graph[num - 1][i] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		check[i] = true;
		dfs(1, i, arr[i]);
		check[i] = false;
	}
	cout << ans;
}

