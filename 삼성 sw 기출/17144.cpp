#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int r, c, t;
int cleaner_x, cleaner_y; //(i,j) (i+1,j)
const int MAX = 1005;
int arr[MAX][MAX];
int save_x[4] = {1,-1,0,0};
int save_y[4] = {0,0,1,-1};

int a[MAX][MAX]; //함수 내에 있을경우 stack overflow


//index 돌아가는 부분 구현시 넘 오래걸림.. ㅎ => 풀이 보깅?? 어떻게 빨리 코드로 옮기는지??

//미세먼지가 확산하는 함수
void go() {
	//미세먼지는 동시에 확산하므로 배열을 복사해준다.
	//freeze
	for (int i = 0; i < r; i++) {
		copy(begin(arr[i]), end(arr[i]), begin(a[i]));
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] > 0) {
				//확산한다.
				int num_go = 0;
				for (int index = 0; index < 4; index++) {
					int new_x = i + save_x[index];
					int new_y = j + save_y[index];
					if (new_x >= 0 && new_x < r && new_y >= 0 && new_y < c && arr[new_x][new_y]!=-1) {
						num_go++;
						arr[new_x][new_y] += a[i][j] / 5;
					}
				}
				arr[i][j] = arr[i][j] - (a[i][j] / 5) * num_go;
			}
		}
	}
}
//공기청정기가 작동하는 함수
void air_cleaner() {
	//위
	vector<int>save;
	cleaner_x--;
	int i = cleaner_x;
	int j = cleaner_y;
	for (int index = j + 1; index < c - 1; index++) {
		save.push_back(arr[cleaner_x][index]);
	}
	for (int index = cleaner_x; index > 0; index--) {
		save.push_back(arr[index][c - 1]);
	}
	for (int index = c - 1; index > 0; index--) {
		save.push_back(arr[0][index]);
	}
	for (int index = 0; index < cleaner_x; index++) {
		save.push_back(arr[index][0]);
	}
	for (int index = 0; index < cleaner_y; index++) {
		save.push_back(arr[cleaner_x][index]);
	}
	//다시 넣어 줌.
	arr[cleaner_x][j + 1] = 0;

	int save_index = 0;
	for (int index = j + 2; index < c - 1; index++) {
		arr[cleaner_x][index] = save[save_index++];
	}
	for (int index = cleaner_x; index > 0; index--) {
		arr[index][c - 1] = save[save_index++];
	}
	for (int index = c - 1; index > 0; index--) {
		arr[0][index] = save[save_index++];
	}
	for (int index = 0; index < cleaner_x; index++) {
		arr[index][0] = save[save_index++];
	}
	for (int index = 0; index < cleaner_y; index++) {
		arr[cleaner_x][index] =save[save_index++];
	}
	save.clear();
	cleaner_x++;	
	i = cleaner_x;

	for (int index = j + 1; index < c - 1; index++) {
		save.push_back(arr[cleaner_x][index]);
	}
	for (int index = cleaner_x; index < r - 1; index++) {
		save.push_back(arr[index][c - 1]);
	}
	for (int index = c - 1; index > 0; index--) {
		save.push_back(arr[r - 1][index]);
	}
	for (int index = r - 1; index > cleaner_x; index--) {
		save.push_back(arr[index][0]);
	}
	for (int index = 0; index < cleaner_y; index++) {
		save.push_back(arr[cleaner_x][index]);
	}

	//다시 넣어준다.
	save_index = 0;
	//공기청정기 옆은 정화된다.
	arr[cleaner_x][j + 1] = 0;
	for (int index = j + 2; index < c - 1; index++) {
		arr[cleaner_x][index] = save[save_index++];
	}
	for (int index = cleaner_x; index < r - 1; index++) {
		arr[index][c - 1] = save[save_index++];
	}
	for (int index = c - 1; index > 0; index--) {
		arr[r - 1][index] = save[save_index++];
	}
	for (int index = r - 1; index > cleaner_x; index--) {
		arr[index][0] = save[save_index++];
	}
	for (int index = 0; index < cleaner_y; index++) {
		arr[cleaner_x][index] = save[save_index++];
	}
}

int main() {
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				cleaner_x = i; cleaner_y = j;
			}
		}
	}
	while (t > 0) {
		go();
		air_cleaner();
		t--;
	}
	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] > 0) ans += arr[i][j];
		}
	}
	cout << ans;
}