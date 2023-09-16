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

	int result = 0; //최대 합을 저장
	int ans = 0; //최대 상한값을 저장

	while (start <= end) {
		mid = (start + end) / 2;
		//합을 구해 본다.
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] < mid) {
				sum += arr[i];
			}
			else {
				sum += mid;
			}
		}
		if (sum <= yesan) { //예산에 가장 가까운 값을 찾기
			//합이 예산 안에 들어오는 경우 -> 상한선을 늘려본다.
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