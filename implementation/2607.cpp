#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>
using namespace std;
string first_str;
const int num_of_a = 26; //알파벳은 총 26개, 대문자 A의 아스키 코드 65.

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

		//단어 구성 배열에 저장
		for (int i = 0; i < a.size(); i++) {
			arr[a[i] - 65]++;
		}
		//각 알파벳 구성의 차이 계산
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
		
		if (sum_1 == 1 && sum_2 == 0) can = true; //추가
		if (sum_1 == 0 && sum_2 == 1) can = true; //삭제
		if (sum_1 == 1 && sum_2 == 1) can = true; //교체
		if (sum_1 == 0 && sum_2 == 0) can = true; //일치

		if (can == true) ans++;
	}
	cout << ans;
}