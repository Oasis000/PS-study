#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//강의 시작시간은 고려 no, 종료시간만 고려!
//강의 종료시간 기준으로 정렬한 후, 선형탐색하며 이어준다.

vector<vector<int>>vec;

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        vec.push_back({ b,a });
    }
    sort(vec.begin(), vec.end());

    int ans = 1;
    int index = 0;
    int end_time = vec[0][0];
    while (index <= n) {
        //다음 위치를 찾는다.
        for (; index < n; index++) {
            if (vec[index][1] >= end_time) break;
        }
        if (index == n) break;
        ans++;
        end_time = vec[index][0];
        index++;
    }
    cout << ans;

    return 0;
}