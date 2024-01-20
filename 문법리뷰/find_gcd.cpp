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
