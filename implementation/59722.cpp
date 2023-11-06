#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MAX = 50005;
vector<vector<pair<int, int>>> arr(MAX); // ���� ������ ������ ���� ����Ʈ 
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min ������ ������ �켱���� ť
int node[MAX][2]; // �迭 ���� ���� (0: �ִ� �Ÿ�, 1: �湮 ����)

int dijkstra(int start, int end) {
    // ���ͽ�Ʈ�� �˰���
    for (int i = 1; i < MAX; i++) {
        node[i][0] = INT_MAX;
        node[i][1] = 0; // �湮 ���θ� 0���� �ʱ�ȭ
    }
    // ���� ��� ����
    node[start][0] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        int dist = p.first;
        int node_num = p.second;
        pq.pop();

        if (node[node_num][1]) {
            continue; // �̹� �湮�� ���� ��ŵ
        }
        node[node_num][1] = 1; // �湮 ǥ��

        for (int i = 0; i < arr[node_num].size(); i++) {
            pair<int, int> pa = arr[node_num][i];
            int connect_node = pa.first;
            int wei = pa.second;

            if (node[connect_node][0] > dist + wei) {
                node[connect_node][0] = dist + wei;
                pq.push({ node[connect_node][0], connect_node });
            }
        }
    }
    return node[end][0];
}

int main() {
    int a, b;
    cin >> a >> b;
    int n1, n2, w;
    for (int i = 0; i < b; i++) {
        cin >> n1 >> n2 >> w;
        arr[n1].push_back({ n2, w });
        arr[n2].push_back({ n1, w });
    }

    int start = 1;
    int end = a;
    int result = dijkstra(start, end);

    cout << result;

    return 0;
}
