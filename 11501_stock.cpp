#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int t_c; cin >> t_c;
	int num; int a;
	long long ans;
	while(t_c--) {
		ans = 0;
		cin >> num;
		vector<int> v;
		while (num--) {
			cin >> a; v.push_back(a);
		}
		//역순으로 탐색하면서 max보다 작으면 차액 반영
		//max보다 더 클경우 max를 갱신한다.
		int max = v[v.size() - 1];
		for (int i = v.size() - 2; i >= 0; i--) {
			if (max >= v[i]) {
				//판매
				ans += (max - v[i]);
			}
			else {
				max = v[i];
			}
		}
		cout << ans << endl;
	}
}