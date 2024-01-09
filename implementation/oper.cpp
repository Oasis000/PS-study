#include <string> //프그 수식 최대화
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
//num, oper을 분리하여 vector에 저장한다.
//계산 알고리즘 정의(stack이용해서)한다 -> 효율성 고려 x & 그냥 for문 돌려주기
//3개의 연산문자 우선순위 -> 3!개의 경우를 고려하여 답을 도출한다.


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
                op.erase(op.begin() + i); //복습 
                n.erase(n.begin() + i + 1);
            }
            else { i++; }   //연산해줄때 vector에서 pop되므로 index가 건너뛰어짐 -> 따라서 index증감문을 따로 처리.
        }

    }

    return n[0];
}

long long solution(string expression) {
    long long answer = 0;
    vector<ll>number;
    vector<char>oper;

    //1.
    for (int i = 0; i < expression.size(); i++) { //string을 short반복문으로 돌리려면 char으로 받아야;;
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
    //2. 계산 알고리즘을 정의
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