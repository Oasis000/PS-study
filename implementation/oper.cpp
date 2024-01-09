#include <string> //���� ���� �ִ�ȭ
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
//num, oper�� �и��Ͽ� vector�� �����Ѵ�.
//��� �˰��� ����(stack�̿��ؼ�)�Ѵ� -> ȿ���� ��� x & �׳� for�� �����ֱ�
//3���� ���깮�� �켱���� -> 3!���� ��츦 ����Ͽ� ���� �����Ѵ�.


ll operation(char temp, ll a, ll b) {
    if (temp == '+') return a + b;
    else if (temp == '-') return a - b;
    else if (temp == '*') return a * b;
    return -1;
}
ll cal(vector<char>vec, vector<ll> n, vector<char> op) {
    int temp = 0;

    while (temp < 3) {
        int fir = vec[temp++];
        for (int i = 0; i < op.size();) {
            if (op[i] == fir) {
                n[i] = operation(fir, n[i], n[i + 1]);
                op.erase(op.begin() + i); //���� 
                n.erase(n.begin() + i + 1);
            }
            else { i++; }   //�������ٶ� vector���� pop�ǹǷ� index�� �ǳʶپ��� -> ���� index�������� ���� ó��.
        }

    }

    return n[0];
}

long long solution(string expression) {
    long long answer = 0;
    vector<ll>number;
    vector<char>oper;

    //1.
    for (int i = 0; i < expression.size(); i++) { //string�� short�ݺ������� �������� char���� �޾ƾ�;;
        int temp = i;
        for (; temp < expression.size(); temp++) {
            char t = expression[temp];
            if (t == '+' || t == '-' || t == '*') break;
        }
        if (temp == expression.size() - 1) {
            number.push_back(stoi(expression.substr(i, temp - i)));
            break;
        }
        ll num = stoi(expression.substr(i, temp - i));
        char op = expression[temp];

        number.push_back(num);
        oper.push_back(op);
        i = temp;
    }
    //2. ��� �˰����� ����
    vector<char>per = { '*', '+', '-' };

    ll local_cal = cal(per, number, oper);
    cout << local_cal << endl;
    local_cal = abs(local_cal);
    answer = local_cal;

    while (next_permutation(per.begin(), per.end())) { //+ * -

        ll local_cal = cal(per, number, oper);
        cout << local_cal << endl;
        local_cal = abs(local_cal);
        answer = max(answer, local_cal);

        cout << endl;
    }
    return answer;
}