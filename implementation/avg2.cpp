//����Ƽ�� lv3 �������
#include<iostream>
#include<cmath>
using namespace std;

const int S = 1e6 + 1;
int accum_arr[S];

int main(int argc, char** argv)
{
    int n, k, s, a, b; //�л���, ������
    cin >> n >> k;
    accum_arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        accum_arr[i] = accum_arr[i - 1] + s;
    }
    double ans;
    for (int i = 0; i < k; i++) {
        //������ ��� ���ϱ�
        cin >> a >> b;
        int acc = accum_arr[b] - accum_arr[a - 1];
        ans = double(acc) / (b - a + 1);
        double a = round(ans * 100) / 100;
        printf("%.2f\n", a); //�������Ͽ� print
    }
    return 0;
}