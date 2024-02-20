#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 50 + 3;
const int MAX = 500001;
int graph[SIZE][SIZE] = { 0, };

int da(int N, int K) {
    int arr[SIZE];
    int check[SIZE] = { 0, };
    for (int a = 0; a < SIZE; a++) arr[a] = MAX;
    //start node is 1
    arr[1] = 0;
    int node = 1;
    while (true) {
        //exit
        if (node == 51) break;
        //cout<<"visit node "<<node<<" weight is "<<arr[node]<<endl;
        check[node] = 1;
        int min_len = 50 + 1;
        for (int i = 1; i <= N; i++) {
            //if node is connected & min
            if (graph[node][i] > 0 && check[i] == 0) {
                if (arr[node] + graph[node][i] < arr[i]) {
                    //cout<<"connected node "<<i<<endl;
                    arr[i] = arr[node] + graph[node][i];
                }
            }
            if (check[i] == 0 && arr[min_len] > arr[i]) min_len = i;
        }
        //cout<<"next node "<<min_len<<endl;
        node = min_len;
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (arr[i] <= K) ans++;
    }
    return ans;
}

int solution(int N, vector<vector<int> > road, int K) {
    for (vector<int> vec : road) {
        int a = vec[0]; int b = vec[1];
        if (graph[a][b] > 0 && graph[a][b] < vec[2]) continue;
        graph[a][b] = vec[2];
        graph[b][a] = vec[2];
    }
    int answer = da(N, K);
    return answer;
}