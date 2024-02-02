//프그 lv3 단속카메라
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
//진입시간 기준 sort하고 선형탐색한다.
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
            //범위를 축소한다.
            start = max(start, routes[index][0]);
            end = min(end, routes[index][1]);
            index++;
        }
    }
    return answer;
}