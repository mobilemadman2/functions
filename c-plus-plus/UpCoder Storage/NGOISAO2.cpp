#include <iostream>
using namespace std;
int main(){
	int a, b, xgHg = 0;
	cin >> a >> b;
	for (int i = 0; i < a*b; i++){
		cout << "*";
		xgHg++;
		if (xgHg == b) {
			cout << endl; xgHg = 0;
		}
	}
	//system("pause");
	return 0;
}
/*
Viết chương trình in ra màn hình hình chữ nhật sao với độ dài 2 cạnh nhập vào từ bàn phím.

Input: 2 số nguyên dương a, b.
Output: hình chữ nhật ngôi sao tương ứng độ dài 2 cạnh.

Ví dụ:

Input:
3 5

Output:
*****
*****
*****
*/