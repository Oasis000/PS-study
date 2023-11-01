#include<stdio.h>
#include<iostream>
using namespace std;
int prime_num[7] = { 2,3,5,7,11,13, 17};
int a, b;
double no_prime_a, no_prime_b;

bool is_prime(int num) {
	for (int i = 0; i < 7; i++) {
		if (prime_num[i] == num) return true;
	}
	return false;
}

void prime(int depth, int percent, int number, double n, int ab) {
	if (depth == 18) { //16.. 아니져 ㅠ
		if (is_prime(number) == true) return;
		if (ab == 0) no_prime_a += n;
		else no_prime_b += n;
		return;
	}
	//넣은 경우
	prime(depth + 1, percent, number + 1, n * (percent / 100.), ab);
	//넣지 못한 경우
	prime(depth + 1, percent, number, n * (100 - percent) / 100., ab);
}

int main() {
	int a, b; cin >> a >> b;
	prime(0, a, 0, 1, 0);
	prime(0, b, 0, 1, 1);
	cout.precision(10);
	cout << 1. - no_prime_a * no_prime_b;
}