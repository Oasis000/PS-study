#include<stdio.h>
#include<iostream>
using namespace std;
int n;
const int MAX = 100000;
int arr[MAX];
int yesan;

int search() {
	int start = 0;
	int end = arr[0];
	for (int i = 0; i < n; i++) {
		if (end < arr[i]) end = arr[i];
	}
	int mid;

	int result = 0; //�ִ� ���� ����
	int ans = 0; //�ִ� ���Ѱ��� ����

	while (start <= end) {
		mid = (start + end) / 2;
		//���� ���� ����.
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] < mid) {
				sum += arr[i];
			}
			else {
				sum += mid;
			}
		}
		if (sum <= yesan) { //���꿡 ���� ����� ���� ã��
			//���� ���� �ȿ� ������ ��� -> ���Ѽ��� �÷�����.
			if (result < sum) {
				result = sum;
				ans = mid;
			}
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return ans;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> yesan;
	int ans = search();
	cout << ans;
}