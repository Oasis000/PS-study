//���� 1469 ��Ʈ��ŷ(����) ��5

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
const int MAX = 8 + 1;
int arr[MAX];
int shome[MAX*2];
vector<string> save;

void back(int index, int n) {
	if (index > n) {
		//find
		string str = "";
		for (int i = 1; i <= n * 2; i++) {
			str = str + to_string(shome[i]);
			str += ' ';
		}
		save.push_back(str);
	}
	for (int i = 1; i <= n * 2; i++) {
		//��ġ�� �� �ִ� ��� ��ġ���ش�.
		int last_index = i + arr[index] + 1;
		if (last_index > 2 * n) break;
		if (shome[i] == -1 && shome[last_index] == -1) {
			shome[i] = arr[index];
			shome[last_index] = arr[index];
			back(index + 1, n);
			shome[i] = -1;
			shome[last_index] = -1;
		}
	}
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i+1];
		shome[i + 1] = -1;
		shome[i + n + 1] = -1;
	}
	//����
	sort(arr + 1, arr + n + 1);
	//��Ʈ��ŷ
	back(1,n);
	//print ans
	if (save.size() > 0) {
		sort(save.begin(), save.end());
		cout << save[0];
	}
	else {
		cout << "-1";
	}
}