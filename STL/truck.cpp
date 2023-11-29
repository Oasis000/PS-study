//���� �ٸ���_������_Ʈ�� lv2

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
        //Ż�������� �����Ѵ�.
        if (i == truck_weights.size() && bridge.size() == 0) {
            //������ ���� �� �ǳʰ� && �ð��� ������ break!!
            break;
        }
        int queue_size = bridge.size();
        //(weight, in_time)���� ����Ǿ� ����.
        //pop�Ѵ�. -> �� �ð� + bridge_length
        if (queue_size > 0 && bridge.front().second + bridge_length == cur_time) {
            total_weight -= bridge.front().first;
            bridge.pop();
        }
        //push�Ѵ�.
        if (i < truck_weights.size() && queue_size < bridge_length && truck_weights[i] + total_weight <= weight) {
            //push ������ ��츦 üũ�Ѵ�.
            bridge.push({ truck_weights[i], cur_time });
            total_weight = truck_weights[i] + total_weight;
            i++; //push �� ��� i�� ������Ų��.
        }
        cur_time++;
    }

    return cur_time;
}

