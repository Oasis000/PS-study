#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int MAX = 100005;
priority_queue<int,vector<int>, greater<int>> can; //컴퓨터번호
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> out_time; //out시간, 컴퓨터번호
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
		//종료된 컴퓨터를 빼준다.
		while (out_time.size() > 0 && out_time.top().first <= start) {
			can.push({ out_time.top().second});
			out_time.pop();
		}
		//가능한 컴퓨터가 없으면, 컴퓨터를 추가한다.
		if (can.size() == 0) {
			out_time.push({end, num_of_com});
			computer[num_of_com++] = 1;
		}
		else {
			//가능한 컴퓨터가 있으면, 배치하고 큐에서 빼준다.
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