//���� ��4 2580�� ������

#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int arr[100][2]; //zero index�� ��� �迭
vector<vector<int>>vec;

int zero_num = 0;
bool if_find = false;

// �Ҷ����� vector�迭�� �����ؼ� �ð��ʰ� �߻��ϴµ�. 
// �迭�� �������� �ʿ� ���� ����Լ����� �� ����, ���������� ���� ���ؼ� Ǯ �� ����.. -> ����Լ��� ����!!

vector<int> check(int i, int j) { //Ư�� ĭ�� ���� �� �ִ� ���� ��ȯ���ִ� �Լ�
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
		//�ϼ�
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
	//���� ĭ�� ���� �� �ִ� ���� Ȯ��
	vector<int> save = check(x, y);
	for (int i = 0; i < save.size(); i++) {
		//���� �Լ��� ȣ���Ѵ�.
		vec[x][y] = save[i];
		backtracking(count + 1, index + 1);
	}
	//������� �Դٴ� ���� �ظ� ã�� ���ؼ� back�� ���̹Ƿ�
	//�ٽ� 0���� ���󺹱�...!!!
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

	//��Ʈ��ŷ ����
	backtracking(0, 0);
}