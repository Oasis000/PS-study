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
	
	//��ġ���ش�.
	//������ ÷�� �߸��ؼ� ���������Ф�
	int cur = 0;
	int local_min = 0;
	
	//�������� �� ���� ó��@
	while (cur < w - 1) {
		local_min = cur + 1;
		for (int i = cur + 1; i < w; i++) {
			//cur���� ������ Ž���غ���.
			if (arr[i] >= arr[cur]) {
				local_min = i;
				break;
			}
			else if (arr[local_min] < arr[i] && arr[i] < arr[cur]) {
				local_min = i;
			}
		}
		//cur~local_min���� �� ������ �����ش�.
		int min_val = min(arr[local_min], arr[cur]);
		for (int i = cur + 1; i < local_min; i++) {
			sum += (min_val - arr[i]);
		}
		cur = local_min;
	}
	cout << sum;
}