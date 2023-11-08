//���� lv2 �ڿ� �ִ� ū �� ã��
#include <string>
#include<stack>
#include<iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    //�Ĺݺκ��� Ž���Ѵ�. stack�� top�� ���Ͽ� Ŭ ������ pop�Ѵ�.
    stack<int> max_s;
    answer.push_back(-1);
    for (int i = numbers.size() - 1; i > 0; i--) {
        //���� ���غ���.
        if (numbers[i - 1] < numbers[i]) {
            max_s.push(numbers[i]);
            answer.push_back(numbers[i]); //�������� ������ ������� ��.
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