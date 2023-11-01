#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
const int MAX = 100000 + 2;
int check[MAX] = { 0, };
deque<int> q; // 덱을 이용한다. 
/* 이 문제는 기본적인 bfs와 다르다.
* 2*로 이동할 때는 가중치가 0이므로, 트리의 간선이 뻗어나갈 때 2* 부분이 먼저 고려되어야 한다. 따라서 덱을 사용하여, 2* 부분을 먼저 고려해준다.
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
		//방문하지 않앗으면 방문.
		if (2 * a < MAX && check[2 * a] == -1) {
			q.push_front(a * 2); //2*a는 weight이 0이므로 가장 최우선으로 고려하기 위해 맨 앞에 넣어준다.
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