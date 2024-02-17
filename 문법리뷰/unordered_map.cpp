#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
//c++ 해시 - unordered_map

void print_func(unordered_map<int, string> m) {
    for (pair<int, string> a : m) {
        cout << a.first << " " << a.second << endl;
    }
}
int main() {
    unordered_map<int, string> myMap;
    //추가
    myMap.insert({ 1, "apple" }); 
    myMap[2] = "pear";

    print_func(myMap);

    //대체
    myMap[1] = "SB";
    print_func(myMap);

    //접근
    unordered_map<int, string> myMap1 = { {1, "apple"}, {2, "banana"} };
    cout << myMap1.at(1) << endl; // 출력: apple
    cout << myMap1[1] << endl; //index가 아닌 key로 접근
    print_func(myMap1);
    
    //검색
    auto it = myMap1.find(1);
    cout << "result :" << it->second << endl;

    //삭제
    myMap1.erase(2); 
    print_func(myMap1);

    cout << "Size: " << myMap1.size() << endl; // 출력: 2

    myMap.clear();

    return 0;
}
