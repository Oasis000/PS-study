//프그 구명보트 lv2
#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    //sort하고 투포인터로 풀이한다.
    int size = people.size();
    int begin = 0;
    int end = size - 1;
    while (begin <= end) {
        if (people[begin] + people[end] <= limit) {
            answer++; begin++; end--;
        }
        else {
            answer++; //bigger one
            end--;
        }
    }
    return answer;
}