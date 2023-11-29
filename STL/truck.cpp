//프그 다리를_지나는_트럭 lv2

#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
queue<pair<int, int>> bridge;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int cur_time = 0;
    int total_weight = 0;
    int i = 0;
    while (true) {
        //탈출조건을 설정한다.
        if (i == truck_weights.size() && bridge.size() == 0) {
            //마지막 차가 다 건너고 && 시간이 지나야 break!!
            break;
        }
        int queue_size = bridge.size();
        //(weight, in_time)으로 저장되어 잇음.
        //pop한다. -> 들어간 시간 + bridge_length
        if (queue_size > 0 && bridge.front().second + bridge_length == cur_time) {
            total_weight -= bridge.front().first;
            bridge.pop();
        }
        //push한다.
        if (i < truck_weights.size() && queue_size < bridge_length && truck_weights[i] + total_weight <= weight) {
            //push 가능한 경우를 체크한다.
            bridge.push({ truck_weights[i], cur_time });
            total_weight = truck_weights[i] + total_weight;
            i++; //push 한 경우 i를 증가시킨다.
        }
        cur_time++;
    }

    return cur_time;
}

