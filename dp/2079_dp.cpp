#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
#include<vector>
#include<math.h>
using namespace std;
vector<vector<int>>v;
const int MAX = 2005;
bool dp[MAX][MAX] = { false, };
int result[MAX];

string str;

void func() {
	for (int size = 0; size < str.length() - 1; size++) {
		for (int j = 1; j < str.length() - 1; j++) {
			if (dp[j][j + size] == true && str[j - 1] == str[j + size + 1]) {
				//�κ� ���ڿ��� �Ӹ�����̸�, �� �� ���ڰ� ���� ��� -> �Ӹ���� ���� ����
				dp[j - 1][j + size + 1] = true;
			}
		}
	}
}

int main() {
	cin >> str; //abaccbcb
	//�ʱ� dp ����
	for (int i = 0; i < str.length(); i++) {
		dp[i][i] = true;
	}
	for (int i = 0; i < str.length() - 1; i++) {
		if (str[i] == str[i + 1]) {
			dp[i][i + 1] = true; dp[i + 1][i] = true;
		}
	}
	func();
	//result�� ������ش�.
	result[0] = 1;
	for (int k = 1; k < str.length(); k++) {
		if (dp[0][k] == true) { //�ƿ� �Ӹ����
			result[k] = 1;
			continue;
		}

		int min = result[k - 1] + 1; //���� + a

		for (int i = 0; i < k - 1; i++) { // �������
			if (dp[i + 1][k] == true && result[i] + 1 < min) {
				min = result[i] + 1;
			}
		}
		result[k] = min;
	}
	cout << result[str.length() - 1];
}

/*
DP[i][j] : Str[i] ~ Str[j]�� �κй��ڿ��� �Ӹ�������� �ƴ��� �˷��ִ� Boolean �迭
	dp[i][i]�� �Ӹ�����̴� ( Ȧ�� )
	���� ���ڰ� �پ��մ� ���� �Ӹ�����̴� ( ¦�� )

Result[i] : Str[1]~Str[i]�� �κй��ڿ��� �����ϴ� �ּ� �Ӹ���� ����
*/