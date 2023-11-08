//프그 lv2 뒤에 있는 큰 수 찾기
#include <string>
#include<stack>
#include<iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    //후반부부터 탐색한다. stack의 top과 비교하여 클 때까지 pop한다.
    stack<int> max_s;
    answer.push_back(-1);
    for (int i = numbers.size() - 1; i > 0; i--) {
        //전후 비교해본다.
        if (numbers[i - 1] < numbers[i]) {
            max_s.push(numbers[i]);
            answer.push_back(numbers[i]); //역순으로 넣으니 뒤집어야 함.
        }
        else {
            while (max_s.size() > 0 && max_s.top() <= numbers[i - 1]) {
                max_s.pop();
            }
            if (max_s.size() != 0) {
                answer.push_back(max_s.top());
            }
            else {
                answer.push_back(-1);
            }
            max_s.push(numbers[i - 1]);
        }
    }
    vector<int>ans;
    for (int i = answer.size() - 1; i >= 0; i--) {
        ans.push_back(answer[i]);
    }
    return ans;
}