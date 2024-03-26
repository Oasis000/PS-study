//프그 2023현대모비스알고리즘경진대회예선 lv3
#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
//완전탐색
using namespace std;
vector<vector<int>>db;

int find_wait_time(int k, int req_num) { //k개의 멘토를 num에 할당
    int wait_time = 0;
    vector<int> table(k, 0);
    for (int i = 0; i < db.size(); i++) {
        //현재의 요청을 할당한다.
        //모두 상담 중인지 체크
        if (db[i][2] != req_num) continue;

        int start_time = db[i][0];
        int d_time = db[i][1];

        auto iter = min_element(table.begin(), table.end());
        int min_time = *iter;

        //바로 할당 가능한지
        if (min_time <= start_time) {
            *iter = start_time + d_time;
        }
        else {
            wait_time = wait_time + (min_time - start_time);
            *iter = min_time + d_time;
        }
    }
    cout << wait_time << endl;
    return wait_time;
}

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0;
    db = reqs;
    vector<int>table(k + 1, 1);
    vector<int>arr_time(k + 1, 0);

    for (int j = 1; j <= k; j++) {
        int time = find_wait_time(1, j);
        arr_time[j] = time;
    }

    for (int i = k; i < n; i++) {
        //상담원 할당.
        int max_time = 0;
        int max_num = 0;

        for (int j = 1; j <= k; j++) {
            int time = find_wait_time(table[j] + 1, j);
            time = arr_time[j] - time;
            if (time > max_time) {
                max_time = time;
                max_num = j;
            }
        }
        table[max_num]++;
        arr_time[max_num] = find_wait_time(table[max_num], max_num);
    }
    for (int i = 1; i <= k; i++) {
        answer += arr_time[i];
    }

    return answer;
}