//프그 lv2 롤케이크 자르기

#include <string>
#include <vector>
using namespace std;

//자르는 부분 기준으로 앞, 뒤 케이크 종류를 세는 배열
int front[10000 + 1] = { 0, };
int back[10000 + 1] = { 0, };

int solution(vector<int> topping) {
    int answer = 0;
    int count_front = 0;
    int count_end = 0;
    //토핑 종류를 세어 준다.
    for (int i = 0; i < topping.size(); i++) {
        back[topping[i]]++;
        if (back[topping[i]] == 1) count_end++;
    }
    for (int i = 0; i < topping.size() - 1; i++) {
        //i번째까지 포함하여 자르는 경우를 따진다.
        //이동하게 되면 front에 추가, end에서 빠지게 됨.
        int top = topping[i];
        front[top]++;
        if (front[top] == 1) { //프론트에 새로 추가된 경우
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