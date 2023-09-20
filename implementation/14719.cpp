#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int arr[500];

int main() {
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < w; i++) {
		cin >> arr[i];
	}
	int sum = 0;
	
	//서치해준다.
	//구현을 첨에 잘못해서 꼬여버림ㅠㅠ
	int cur = 0;
	int local_min = 0;
	
	//마지막에 찬 빗물 처리@
	while (cur < w - 1) {
		local_min = cur + 1;
		for (int i = cur + 1; i < w; i++) {
			//cur부터 끝까지 탐색해본다.
			if (arr[i] >= arr[cur]) {
				local_min = i;
				break;
			}
			else if (arr[local_min] < arr[i] && arr[i] < arr[cur]) {
				local_min = i;
			}
		}
		//cur~local_min까지 찬 빗물을 더해준다.
		int min_val = min(arr[local_min], arr[cur]);
		for (int i = cur + 1; i < local_min; i++) {
			sum += (min_val - arr[i]);
		}
		cur = local_min;
	}
	cout << sum;
}