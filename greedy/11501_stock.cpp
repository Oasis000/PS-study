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
		//�������� Ž���ϸ鼭 max���� ������ ���� �ݿ�
		//max���� �� Ŭ��� max�� �����Ѵ�.
		int max = v[v.size() - 1];
		for (int i = v.size() - 2; i >= 0; i--) {
			if (max >= v[i]) {
				//�Ǹ�
				ans += (max - v[i]);
			}
			else {
				max = v[i];
			}
		}
		cout << ans << endl;
	}
}