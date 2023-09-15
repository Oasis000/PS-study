//백준 골4 2580번 스도쿠

#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int arr[100][2]; //zero index가 담긴 배열
vector<vector<int>>vec;

int zero_num = 0;
bool if_find = false;

// 할때마다 vector배열을 복사해서 시간초과 발생하는듯. 
// 배열을 복사해줄 필요 없음 재귀함수에서 값 저장, 이전값으로 갱신 통해서 풀 수 있음.. -> 재귀함수가 뭐니!!

vector<int> check(int i, int j) { //특정 칸에 넣을 수 있는 수를 반환해주는 함수
	int count[10] = { 0, };
	vector<int>v;
	for (int index = 0; index < 9; index++) {
		count[vec[index][j]]++;
	}
	for (int index = 0; index < 9; index++) {
		count[vec[i][index]]++;
	}
	for (int index = (i / 3) * 3; index < ((i / 3) * 3 +3); index++) {
		for (int in = (j / 3) * 3; in < ((j / 3) * 3 + 3); in++) {
			count[vec[index][in]]++;
		}
	}
	for (int index = 1; index <= 9; index++) {
		if (count[index] == 0) v.push_back(index);
	}
	return v;
}

void backtracking(int count, int index) {
	if (if_find == true) return;
	if (count == zero_num) {
		//완성
		if_find = true;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << vec[i][j] << ' ';
			}
			cout << endl;
		}
		return;
	}
	int x = arr[index][0]; int y = arr[index][1];
	//현재 칸에 넣을 수 있는 수를 확인
	vector<int> save = check(x, y);
	for (int i = 0; i < save.size(); i++) {
		//하위 함수를 호출한다.
		vec[x][y] = save[i];
		backtracking(count + 1, index + 1);
	}
	//여기까지 왔다는 것은 해를 찾지 못해서 back한 것이므로
	//다시 0으로 원상복귀...!!!
	vec[x][y] = 0;
}

int main() {
	int s;
	for (int i = 0; i < 9; i++) {
		vector<int>v;
		for (int j = 0; j < 9; j++) {
			cin >> s;
			if (s == 0) {
				arr[zero_num][0] = i;
				arr[zero_num++][1] = j;
			}
			v.push_back(s);
		}
		vec.push_back(v);
	}

	//백트래킹 진행
	backtracking(0, 0);
}