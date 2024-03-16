#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int rem = 1000000007;
const int arr_size = 60001;
int arr[arr_size];

int solution(int n) {
    int answer = 0;
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i <= n; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % rem;
    }
    answer = arr[n];
    return answer;
}