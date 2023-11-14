//���� lv2 ������ũ �ڸ���

#include <string>
#include <vector>
using namespace std;

//�ڸ��� �κ� �������� ��, �� ����ũ ������ ���� �迭
int front[10000 + 1] = { 0, };
int back[10000 + 1] = { 0, };

int solution(vector<int> topping) {
    int answer = 0;
    int count_front = 0;
    int count_end = 0;
    //���� ������ ���� �ش�.
    for (int i = 0; i < topping.size(); i++) {
        back[topping[i]]++;
        if (back[topping[i]] == 1) count_end++;
    }
    for (int i = 0; i < topping.size() - 1; i++) {
        //i��°���� �����Ͽ� �ڸ��� ��츦 ������.
        //�̵��ϰ� �Ǹ� front�� �߰�, end���� ������ ��.
        int top = topping[i];
        front[top]++;
        if (front[top] == 1) { //����Ʈ�� ���� �߰��� ���
            count_front++;
        }
        back[top]--;
        if (back[top] == 0) {
            count_end--;
        }
        if (count_front == count_end) answer++;
    }
    return answer;
}