#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>
using namespace std;
string first_str;
const int num_of_a = 26; //���ĺ��� �� 26��, �빮�� A�� �ƽ�Ű �ڵ� 65.

int first_arr[num_of_a] = { 0, };

int main() {
	int num; cin >> num;
	string a;
	cin >> first_str;
	for (int i = 0; i < first_str.size(); i++) {
		first_arr[first_str[i] - 65]++;
	}

	int ans = 0;

	for (int i = 1; i < num; i++) {
		cin >> a;
		int arr[num_of_a] = { 0, };
		bool can = false;

		//�ܾ� ���� �迭�� ����
		for (int i = 0; i < a.size(); i++) {
			arr[a[i] - 65]++;
		}
		//�� ���ĺ� ������ ���� ���
		int sum_1 = 0;
		for (int i = 0; i < num_of_a; i++) {
			if (first_arr[i] <= arr[i]) continue;
			sum_1 = sum_1 + (first_arr[i] - arr[i]);
		}
		int sum_2 = 0;
		for (int i = 0; i < num_of_a; i++) {
			if (first_arr[i] >= arr[i]) continue;
			sum_2 = sum_2 + (arr[i] - first_arr[i]);
		}
		
		if (sum_1 == 1 && sum_2 == 0) can = true; //�߰�
		if (sum_1 == 0 && sum_2 == 1) can = true; //����
		if (sum_1 == 1 && sum_2 == 1) can = true; //��ü
		if (sum_1 == 0 && sum_2 == 0) can = true; //��ġ

		if (can == true) ans++;
	}
	cout << ans;
}