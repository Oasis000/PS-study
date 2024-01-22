//gcd 쉽게 찾는 방법 - gcd(a,b) = gcd(b,a%b) 이다. a%b==0이 될 때까지 반복한다.
//유클리드 호제법

int find_gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//숫자 범위가 클 경우 연산 시 overflow주의하기
int a, b
ll temp
temp = a*b; //-> a*b연산 시 overflow 날 수 있음
