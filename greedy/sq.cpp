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
//반복을 찾는다 - gcd 이용하여 계산한다.
long long solution(int w, int h) {
    ll answer = 0;
    //유클리드 호제법 : gcd(a,b) = gcd(b,a%b); -> 0 될때까지 반복한다.
    int gcd = find_gcd(w, h);
    int local_h = h / gcd;
    int local_w = w / gcd;
    answer = ll(local_h + local_w - 1) * gcd;
    answer = ll(w) * ll(h) - answer;
    return answer;
}

//내 풀이 - 80점대

//선형 그래프 식
//prev_b와 b의 차이만큼 적립
//o(1억) -> 예상 
//이 코드가 안 된 이유 -> 부동소숫점 문제 ceil(5.0000001) = 6 등의 문제
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
//     long long temp = ll(w)*ll(h); //int 연산 시 overflow발생
//     answer = temp - answer;
//     return answer;
// }