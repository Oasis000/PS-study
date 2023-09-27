//백준 20055 골5 구현

#include<stdio.h>
#include<iostream>
using namespace std;

const int MAX = 100*2;
int arr[MAX];
bool robot[MAX] = { false, };
int n, k;

void first_step() {
	//첫번째) 회전시킨다.
	//회전시키면,, 로봇도 회전하징.. ㅎㅎ?
	int start = 0;
	int num = arr[n - 1];
	bool is = robot[n - 1];
	for (int index = n - 1; index > start; index--) {
		arr[index] = arr[index - 1];
		robot[index] = robot[index - 1];
	}
	arr[0] = num;
	robot[0] = is;
	robot[n / 2 - 1] = false;
}
void second() {
	//두번째) 이동한다. 앞에 로봇이 있거나, 내구도가 0이면 이동할 수 없음.
	for (int index = n - 1; index > 0; index--) {
		if (robot[index] == true) {
			continue;
		}
		if (robot[index - 1] == true && arr[index] > 0) { //이전에 있었던 로봇을 후로 옮긴다.
			arr[index]--;
			robot[index] = true;
			robot[index - 1] = false;
		}
	}
	robot[n / 2 - 1] = false;

}
bool third() {
	//올리는 곳에 올린다.
	if (arr[0] > 0 && robot[0]==false) {
		arr[0]--;
		robot[0] = true;
	}
	//내구도 0인 칸의 갯수 체크한다.
	int num = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) num++;
	}
	if (num >= k) return true;
	else return false; 
}
int simul() {
	int level = 1;
	while (true) {
		first_step();
		second();
		bool check = third();
		if (check == true) {
			return level;
		}
		level++;
	}
}
int main() {
	cin >> n >> k;
	n = n * 2;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = simul();
	cout << ans;
}