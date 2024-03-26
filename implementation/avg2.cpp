//소프티어 lv3 성적평균
#include<iostream>
#include<cmath>
using namespace std;

const int S = 1e6 + 1;
int accum_arr[S];

int main(int argc, char** argv)
{
    int n, k, s, a, b; //학생수, 구간수
    cin >> n >> k;
    accum_arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        accum_arr[i] = accum_arr[i - 1] + s;
    }
    double ans;
    for (int i = 0; i < k; i++) {
        //구간별 평균 구하기
        cin >> a >> b;
        int acc = accum_arr[b] - accum_arr[a - 1];
        ans = double(acc) / (b - a + 1);
        double a = round(ans * 100) / 100;
        printf("%.2f\n", a); //포맷팅하여 print
    }
    return 0;
}