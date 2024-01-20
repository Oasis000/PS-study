#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;

int find_gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
//�ݺ��� ã�´� - gcd �̿��Ͽ� ����Ѵ�.
long long solution(int w, int h) {
    ll answer = 0;
    //��Ŭ���� ȣ���� : gcd(a,b) = gcd(b,a%b); -> 0 �ɶ����� �ݺ��Ѵ�.
    int gcd = find_gcd(w, h);
    int local_h = h / gcd;
    int local_w = w / gcd;
    answer = ll(local_h + local_w - 1) * gcd;
    answer = ll(w) * ll(h) - answer;
    return answer;
}

//�� Ǯ�� - 80����

//���� �׷��� ��
//prev_b�� b�� ���̸�ŭ ����
//o(1��) -> ���� 
//�� �ڵ尡 �� �� ���� -> �ε��Ҽ��� ���� ceil(5.0000001) = 6 ���� ����
// long long solution(int w,int h) {
//     long long answer = 0.;
//     double rate = -1*(double(h)/w);
//     double prev_b = 0.0;
//     double b;
//     for(int a=1;a<=h;a++){
//         b = a * (-1.0/rate);
//         answer = answer + (ceil(b)- floor(prev_b));
//         prev_b = b;
//     }
//     long long temp = ll(w)*ll(h); //int ���� �� overflow�߻�
//     answer = temp - answer;
//     return answer;
// }