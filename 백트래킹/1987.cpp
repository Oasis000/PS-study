#include<stdio.h>
#include<iostream> //use python.., ��Ȯ�� �ð��ʰ� ���� ���
#include<set>
#include<string>
using namespace std;
int n, m;
char arr[21][21];
bool check[21][21] = { false, }; //��� �湮üũ�� �� �ʿ� ����. �Դ����� ���ĺ� �ߺ����� ������ ������.. 
//�׳� ���ĺ� check���ָ� ��. 
//set�� ���� �ð����⵵�� logn������, ����Լ��� ��������� ���� ������ set�� ����Ǵ� ������ �ݺ��Ǳ� ������ �ð��ʰ� �߻��ϴµ�.
//��Ʈ��ŷ �� �� ���ʿ��� �ڷᱸ�� ������� �ʵ���.. ����!
bool alpha[26] = { false, };
int ans = 1;

int go[4][2] = { {0,1},{0,-1},{1,0},{ -1,0} };

void back(int count, int x, int y) {
	//Ż�� - ���̻� ��������.
	if (count > 26) { //ans�� max�� ���ĺ�������.
		return;
	}
	for (int i = 0; i < 4; i++) {
		int n_x = x + go[i][0];
		int n_y = y + go[i][1];
		if (n_x < 0 || n_y < 0 || n_x == n || n_y == m) continue;
		if (check[n_x][n_y] == false && alpha[arr[n_x][n_y] - 65] == false) {
			alpha[arr[n_x][n_y] - 65] = true; check[n_x][n_y] = true;
			back(count + 1, n_x, n_y);
			alpha[arr[n_x][n_y] - 65] = false; check[n_x][n_y] = false;
		}
	}
	if (count > ans) ans = count;
}
int main() {
	cin >> n >> m;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i][j]=str[j];
		}
	}
	check[0][0] = true;
	alpha[arr[0][0] - 65] = true;
	back(1, 0, 0);
	cout << ans;
}