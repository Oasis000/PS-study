#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
vector<int>arr;

int main() {
	int n; cin >> n;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());

	long long ans = 0;

	for (int i = 0; i < n; i++) {
		ans = ans + abs((i + 1) - arr[i]);
	}
	cout << ans;
}