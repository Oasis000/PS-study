#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>arr;
bool check[10];
int route[10][3];
int ans;
int n, m;

//어려움 ,시간 많이 걸림, 특히 index돌려주는데 시간 많이걸림.. 왜 뭐든 index가 젤 어렵지..? ㅠ

vector<vector<int>> spin(vector<vector<int>>vec, int route_index) {
	int i, j, c; 
	vector<vector<int>> v(vec); //벡터 얕은복사
	c = route[route_index][2];
	i = route[route_index][0] - c - 1; j = route[route_index][1] - c - 1;
	c = c * 2;

	while (c > 1) {
		vector<int> save;

		for (int index = j; index < j + c; index++) {
			//값을 담아준다.
			save.push_back(v[i][index]);
		}
		for (int index = i; index < i + c; index++) {
			save.push_back(v[index][j + c]);
		}
		for (int index = j + c; index > j; index--) {
			save.push_back(v[i + c][index]);
		}
		for (int index = i + c; index > i; index--) {
			save.push_back(v[index][j]);
		}
		//다시 넣어준다.
		int save_index = 0;

		v[i][j] = save[save.size() - 1];
		save.pop_back();

		for (int index = j + 1; index < j + c; index++) {
			v[i][index] = save[save_index++];
		}
		for (int index = i; index < i + c; index++) {
			v[index][j + c] = save[save_index++];
		}
		for (int index = j + c; index > j; index--) {
			v[i + c][index] = save[save_index++];
		}
		for (int index = i + c; index > i; index--) {
			v[index][j] = save[save_index++];
		}
		i++; j++; c = c - 2;
	}
	return v;
}

void dfs(int count, int k, vector<vector<int>>v) {
	//탈출조건 -> 다 방문한 경우, spin해보고 ans갱신한다.
	if (count == k) {
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < m; j++) {
				sum += v[i][j];
			}
			if (ans > sum) ans = sum;
		}
		return;
	}
	for (int i = 0; i < k; i++) { //방문하지 않은 경우 방문해본다. // ;탈출조건;
		if (check[i] == true) continue;
		check[i] = true;
		dfs(count + 1, k, spin(v, i));
		check[i] = false;
	}
}

int main() {
	cin >> n >> m;
	int k; cin >> k;
	ans = 1000000000;

	int num;

	for (int i = 0; i < n; i++) {
		vector<int>v;
		for (int j = 0; j < m; j++) {
			cin >> num;
			v.push_back(num);
		}
		arr.push_back(v);
	}
	for (int i = 0; i < k; i++) {
		cin >> route[i][0] >> route[i][1] >> route[i][2];
	}
	dfs(0, k, arr);
	cout << ans;
}