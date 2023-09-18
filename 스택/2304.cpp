//백준 창고 다각형(실2)

#include<stdio.h>
#include<iostream>
using namespace std;
int arr[1005] = { 0, };

int main() {
	int n; cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		arr[a] = b;
	}
	int min_index;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			min_index = i;
			break;
		}
	}
	int max_index;
	for (int i = 1000; i >= 0; i--) {
		if (arr[i] > 0) {
			max_index = i;
			break;
		}
	}
	int sum = 0;
	for (int i = min_index; i <= max_index; i++) { //앞에서부터 탐색
		if (arr[min_index] < arr[i]) {
			sum += (arr[min_index] * (i - min_index));
			min_index = i;
		}
	}
	for (int i = max_index; i >= 0; i--) {
		if (arr[max_index] < arr[i]) {
			sum += (arr[max_index] * (max_index - i));
			max_index = i;
		}
	}
	sum += ((max_index + 1 - min_index) * arr[min_index]);
	cout << sum;
}