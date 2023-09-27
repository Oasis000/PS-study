//���� 20055 ��5 ����

#include<stdio.h>
#include<iostream>
using namespace std;

const int MAX = 100*2;
int arr[MAX];
bool robot[MAX] = { false, };
int n, k;

void first_step() {
	//ù��°) ȸ����Ų��.
	//ȸ����Ű��,, �κ��� ȸ����¡.. ����?
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
	//�ι�°) �̵��Ѵ�. �տ� �κ��� �ְų�, �������� 0�̸� �̵��� �� ����.
	for (int index = n - 1; index > 0; index--) {
		if (robot[index] == true) {
			continue;
		}
		if (robot[index - 1] == true && arr[index] > 0) { //������ �־��� �κ��� �ķ� �ű��.
			arr[index]--;
			robot[index] = true;
			robot[index - 1] = false;
		}
	}
	robot[n / 2 - 1] = false;

}
bool third() {
	//�ø��� ���� �ø���.
	if (arr[0] > 0 && robot[0]==false) {
		arr[0]--;
		robot[0] = true;
	}
	//������ 0�� ĭ�� ���� üũ�Ѵ�.
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