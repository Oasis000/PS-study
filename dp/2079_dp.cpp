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
				//부분 문자열이 팰린드롬이며, 양 끝 문자가 같은 경우 -> 팰린드롬 연장 가능
				dp[j - 1][j + size + 1] = true;
			}
		}
	}
}

int main() {
	cin >> str; //abaccbcb
	//초기 dp 셋팅
	for (int i = 0; i < str.length(); i++) {
		dp[i][i] = true;
	}
	for (int i = 0; i < str.length() - 1; i++) {
		if (str[i] == str[i + 1]) {
			dp[i][i + 1] = true; dp[i + 1][i] = true;
		}
	}
	func();
	//result를 계산해준다.
	result[0] = 1;
	for (int k = 1; k < str.length(); k++) {
		if (dp[0][k] == true) { //아예 팰린드롬
			result[k] = 1;
			continue;
		}

		int min = result[k - 1] + 1; //이전 + a

		for (int i = 0; i < k - 1; i++) { // 나누어보기
			if (dp[i + 1][k] == true && result[i] + 1 < min) {
				min = result[i] + 1;
			}
		}
		result[k] = min;
	}
	cout << result[str.length() - 1];
}

/*
DP[i][j] : Str[i] ~ Str[j]의 부분문자열이 팰린드롬인지 아닌지 알려주는 Boolean 배열
	dp[i][i]는 팰린드롬이다 ( 홀수 )
	같은 문자가 붙어잇는 경우는 팰린드롬이다 ( 짝수 )

Result[i] : Str[1]~Str[i]의 부분문자열에 존재하는 최소 팰린드롬 개수
*/