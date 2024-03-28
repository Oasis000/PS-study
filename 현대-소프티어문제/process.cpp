//프로세스 프그 lv2
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(vector<int> p, int location) {
    int answer = 0;
    vector<int>vec = p;
    int n = p.size();
    sort(vec.begin(), vec.end());
    int index = 0;
    int vec_i = n - 1;
    int count = 0;

    while (true) {
        for (; index < n; index++) {
            if (p[index] == vec[vec_i]) {
                count++;
                if (index == location) return count;
                vec_i--;
            }
        }
        index = (index) % n;
    }
    return answer;
}