#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
//c++ �ؽ� - unordered_map

void print_func(unordered_map<int, string> m) {
    for (pair<int, string> a : m) {
        cout << a.first << " " << a.second << endl;
    }
}
int main() {
    unordered_map<int, string> myMap;
    //�߰�
    myMap.insert({ 1, "apple" }); 
    myMap[2] = "pear";

    print_func(myMap);

    //��ü
    myMap[1] = "SB";
    print_func(myMap);

    //����
    unordered_map<int, string> myMap1 = { {1, "apple"}, {2, "banana"} };
    cout << myMap1.at(1) << endl; // ���: apple
    cout << myMap1[1] << endl; //index�� �ƴ� key�� ����
    print_func(myMap1);
    
    //�˻�
    auto it = myMap1.find(1);
    cout << "result :" << it->second << endl;

    //����
    myMap1.erase(2); 
    print_func(myMap1);

    cout << "Size: " << myMap1.size() << endl; // ���: 2

    myMap.clear();

    return 0;
}
