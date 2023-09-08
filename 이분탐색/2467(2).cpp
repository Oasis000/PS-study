#include<stdio.h>
#include<iostream>
#include<math.h>
#include<climits>

using namespace std;
const int MAX = 100005;
int arr[MAX];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//이분탐색 실행
	int begin = 0;
	int end = n - 1;
	int answer = INT_MAX;
	int begin_index, end_index;

	while (begin < end) {
		//최솟값 갱신
		int sum = arr[begin] + arr[end];
		if (abs(sum) < answer) {
			answer = abs(sum);
			begin_index = begin; end_index = end;
		}
		if (sum > 0) { //양수를 작게
			end--;
		}
		else {
			begin++;
		}
	}
	cout << arr[begin_index] << " " << arr[end_index];
}