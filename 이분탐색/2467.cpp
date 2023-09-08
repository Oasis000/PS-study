//2467
//t_c 나눠서 이분탐색 => lower bound로 풀기
// lower_bound(begin, end, num) => num '이상'(upper_bound는 초과)의 숫자가 처음으로 나오는 위치의 index를 반환 
// (단, 배열이 정렬되어있어야 함.)
//iter를 반환한다. l_b-arr

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

const int MAX = 100005;
int arr[MAX];
int n;
int pos_index = -1; //양수가 처음 등장하는 index
int zero_index;
int neg_index;

bool if_zero = false;
int ans_1, ans_2;

void plus_function(int index_1, int index_2) {
	if (index_1 >= n || index_1<0 || index_2>=n || index_2 < 0) { //index 예외는 다 여기서 걸러줌.
		return;
	}
	if (arr[index_1] == arr[index_2]) return;
	if (abs(arr[index_1] + arr[index_2]) < abs(arr[ans_1] + arr[ans_2])) {
		ans_1 = index_1;
		ans_2 = index_2;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == 0) {
			if_zero = true;
			zero_index = i;
		}
		if (arr[i] > 0 && pos_index == -1) {
			pos_index = i; 
		}
	}

	if (if_zero == true) neg_index = zero_index - 1;
	else if (pos_index != -1) neg_index = pos_index - 1;
	else neg_index = n - 1;

	ans_1 = 0; ans_2 = 1;

	//양수 + 음수 경우가 가능한 경우
	for (int i = 0; arr[i] <=  0 && pos_index != -1; i++) {
		int index = lower_bound(arr + pos_index , arr + n, -1 * arr[i]) - arr;
		plus_function(i, index);	
		plus_function(i, index - 1);
	
	}
	//양수끼리
	plus_function(pos_index, pos_index + 1);
	//음수끼리
	plus_function(neg_index, neg_index - 1);
	//0
	plus_function(zero_index - 1, zero_index);
	plus_function(zero_index, zero_index + 1);
	
	cout << min(arr[ans_1], arr[ans_2]) << " " << max(arr[ans_1], arr[ans_2]);
}