#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
int col;

bool cmp(vector<int> a, vector<int> b) {
    if (a[col] == b[col] && a.size() > 1) return a[0] > b[0];
    else return a[col] < b[col];
}


int main() {
    vector<vector<int>> vec = {
        {2, 2, 6},
        {1, 5, 10},
        {4, 2, 9},
        {3, 8, 3}
    };
    col = 2;
    sort(vec.begin(), vec.end(), cmp); //c++의 sort 함수 - cmp사용자 정의하여 여러 방면으로 응용 가능!
    //XOR
    x ^ y;
    x & y, x | y;

}