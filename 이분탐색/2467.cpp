//2467
//t_c ������ �̺�Ž�� => lower bound�� Ǯ��
// lower_bound(begin, end, num) => num '�̻�'(upper_bound�� �ʰ�)�� ���ڰ� ó������ ������ ��ġ�� index�� ��ȯ 
// (��, �迭�� ���ĵǾ��־�� ��.)
//iter�� ��ȯ�Ѵ�. l_b-arr

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

const int MAX = 100005;
int arr[MAX];
int n;
int pos_index = -1; //����� ó�� �����ϴ� index
int zero_index;
int neg_index;

bool if_zero = false;
int ans_1, ans_2;

void plus_function(int index_1, int index_2) {
	if (index_1 >= n || index_1<0 || index_2>=n || index_2 < 0) { //index ���ܴ� �� ���⼭ �ɷ���.
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

	//��� + ���� ��찡 ������ ���
	for (int i = 0; arr[i] <=  0 && pos_index != -1; i++) {
		int index = lower_bound(arr + pos_index , arr + n, -1 * arr[i]) - arr;
		plus_function(i, index);	
		plus_function(i, index - 1);
	
	}
	//�������
	plus_function(pos_index, pos_index + 1);
	//��������
	plus_function(neg_index, neg_index - 1);
	//0
	plus_function(zero_index - 1, zero_index);
	plus_function(zero_index, zero_index + 1);
	
	cout << min(arr[ans_1], arr[ans_2]) << " " << max(arr[ans_1], arr[ans_2]);
}