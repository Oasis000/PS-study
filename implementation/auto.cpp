//소프티어 자동차 테스트 lv3
#include<iostream>
#include<algorithm>

using namespace std;
const int S = 50005;
int arr[S];

int main(int argc, char** argv)
{
    //정렬 후 lowerbound이용한다.
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);
    int m;
    for (int i = 0; i < q; i++) {
        cin >> m;
        int below, high;
        auto iter = lower_bound(arr, arr + n, m);

        below = iter - arr;
        high = n - below - 1;
        if (*iter != m) below = 0;
        if (below < 0 || high < 0) below = 0;

        cout << below * high << endl;
    }

    return 0;
}