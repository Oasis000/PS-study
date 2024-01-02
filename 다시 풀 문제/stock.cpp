#include <string>
#include <vector>
#include<iostream>

using namespace std;
vector<int>solution(vector<int>prices) {
    vector<int> answer;
    int size = prices.size() - 1;
    for (int i = 0; i < size; i++) {
        int temp = prices[i];
        if (temp > prices[i + 1]) { //가격이 추후에 떨어짐
            answer.push_back(1);
        }
        else { //떨어지지 않음.
            int index = i;
            for (; index < size; index++) {
                if (temp > prices[index]) {
                    answer.push_back(index - i); break;
                }
            }
            if (index == size) {
                answer.push_back(index - i);
            }

        }
    }
    answer.push_back(0);
    return answer;
}
// vector<int> solution(vector<int> prices) {
//     vector<int> answer;
//     int size = prices.size();
//     int local_max = prices[size-1];
//     int local_index = size-1;
//     answer.push_back(0);
//     for(int i=size-2;i>=0;i--){ //가격이 떨어지지 않은 기간!
//         cout<<local_max<<" "<<prices[i]<<endl;
//        if(prices[i] <= prices[i+1]){
//            //향후 가격이 상승할 경우
//            answer.push_back(local_index - i);
//        }
//        else{
//            //향후 가격이 하락할 경우 -> 현재를 local max로 놓는다.
//            answer.push_back(1);
//            local_max = prices[i];
//            local_index = i;
//        }
//     }
//     return answer;
// }