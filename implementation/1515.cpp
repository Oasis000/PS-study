#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main() {
	string str; //3000���̹Ƿ� string���� ����.
	cin >> str;
	string num = "0"; 

	//str�� num�� �����ش�.
	int index = 0;
	while (str.length() > index) {
		//num�� 1������Ų��.
		int i_num = stoi(num);
		i_num++;
		num = to_string(i_num);
		
		int a_index = 0;
		while (num.length() > a_index) {
			char a = str[index]; // char to int -> ����� ����ȯ �� ��Ծ���..? (string -> stoi, to_string)
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