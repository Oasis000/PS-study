#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int MAX = 100005;
priority_queue<int,vector<int>, greater<int>> can; //��ǻ�͹�ȣ
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> out_time; //out�ð�, ��ǻ�͹�ȣ
vector<pair<int, int>> arr;
int computer[MAX];

int main() {
	int n; cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		arr.push_back({ a, b });
	}
	
	sort(arr.begin(), arr.end());

	int num_of_com = 1;

	for (int i = 0; i < n; i++) {
		int start = arr[i].first;
		int end = arr[i].second;
		//����� ��ǻ�͸� ���ش�.
		while (out_time.size() > 0 && out_time.top().first <= start) {
			can.push({ out_time.top().second});
			out_time.pop();
		}
		//������ ��ǻ�Ͱ� ������, ��ǻ�͸� �߰��Ѵ�.
		if (can.size() == 0) {
			out_time.push({end, num_of_com});
			computer[num_of_com++] = 1;
		}
		else {
			//������ ��ǻ�Ͱ� ������, ��ġ�ϰ� ť���� ���ش�.
			out_time.push({ end, can.top() });
			computer[can.top()]++;
			can.pop();
		}
	}
	cout << num_of_com - 1<< endl;
	for (int i = 1; i < num_of_com; i++) {
		cout << computer[i] << ' ';
	}
}