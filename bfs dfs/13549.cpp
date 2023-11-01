#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
const int MAX = 100000 + 2;
int check[MAX] = { 0, };
deque<int> q; // ���� �̿��Ѵ�. 
/* �� ������ �⺻���� bfs�� �ٸ���.
* 2*�� �̵��� ���� ����ġ�� 0�̹Ƿ�, Ʈ���� ������ ����� �� 2* �κ��� ���� ����Ǿ�� �Ѵ�. ���� ���� ����Ͽ�, 2* �κ��� ���� ������ش�.
*/
//bfs
void bfs(int n, int k) {
	//init
	for (int i = 0; i < MAX; i++) check[i] = -1;
	check[n] = 0;
	q.push_back(n);
	while (q.size() > 0) {
		//if (check[k] >= 0) return;
		int a = q.front();
		if (a == k) return;
		q.pop_front();
		//�湮���� �ʾ����� �湮.
		if (2 * a < MAX && check[2 * a] == -1) {
			q.push_front(a * 2); //2*a�� weight�� 0�̹Ƿ� ���� �ֿ켱���� ����ϱ� ���� �� �տ� �־��ش�.
			check[2 * a] = check[a];
		}
		if (a - 1 >= 0 && check[a - 1] == -1) {
			q.push_back(a - 1);
			check[a - 1] = check[a] + 1;
		}
		if (a + 1 < MAX && check[a + 1] == -1) {
			q.push_back(a + 1);
			check[a + 1] = check[a] + 1;
		}
	}
}

int main() {
	int n, k; cin >> n >> k;

	if(n != k) bfs(n,k); //n == k?
	cout << check[k];
}