//���� lv3 �ܼ�ī�޶�
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
//���Խð� ���� sort�ϰ� ����Ž���Ѵ�.
int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end());
    int start, end;
    int index = 0;
    while (index < routes.size()) {
        answer++;
        start = routes[index][0];
        end = routes[index][1];
        index++;
        while (index < routes.size() && routes[index][0] <= end) {
            //������ ����Ѵ�.
            start = max(start, routes[index][0]);
            end = min(end, routes[index][1]);
            index++;
        }
    }
    return answer;
}