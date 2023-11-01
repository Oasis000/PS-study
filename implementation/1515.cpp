#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main() {
	string str; //3000자이므로 string으로 설정.
	cin >> str;
	string num = "0"; 

	//str과 num을 비교해준다.
	int index = 0;
	while (str.length() > index) {
		//num을 1증가시킨다.
		int i_num = stoi(num);
		i_num++;
		num = to_string(i_num);
		
		int a_index = 0;
		while (num.length() > a_index) {
			char a = str[index]; // char to int -> 명시적 형변환 왜 까먹었지..? (string -> stoi, to_string)
			if (a == num[a_index]) {
				index++;
				a_index++;
			}
			else {
				a_index++;
			}
		}
		
	}
	//print ans
	cout << num;
}