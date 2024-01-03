//프그 땅따먹기, 쉬운 dp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 3;
int arr[MAX][4];

int solution(vector<vector<int>> land)
{
    int answer = 0;
    arr[0][0] = land[0][0]; arr[0][1] = land[0][1];
    arr[0][2] = land[0][2]; arr[0][3] = land[0][3]; //init
    int local_max = 0;
    for (int i = 1; i < land.size(); i++) {
        for (int j = 0; j < 4; j++) {
            int temp = 0;
            for (; temp < 4; temp++) {
                if (temp == j) continue;
                if (local_max < arr[i - 1][temp]) local_max = arr[i - 1][temp];
            }
            arr[i][j] = local_max + land[i][j];
            local_max = 0;
        }
    }
    int size = land.size() - 1;
    answer = max(max(arr[size][2], arr[size][3]), max(arr[size][0], arr[size][1]));

    return answer;
}

//+) arr 선언해줄 필요 없다.