//gcd ���� ã�� ��� - gcd(a,b) = gcd(b,a%b) �̴�. a%b==0�� �� ������ �ݺ��Ѵ�.
//��Ŭ���� ȣ����

int find_gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
