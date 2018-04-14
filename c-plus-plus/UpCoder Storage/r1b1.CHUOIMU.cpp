#include <iostream>
using namespace std;

int main() {
	/*int k; cin >> k;
	string str;
	for (int i = 0; i < k; i++) {
		str += "1";
		for (int j = 0; j < i; j++) {
			str += "0";
		}
	}
	cout << str[k - 1];*/
	long long k;
	cin >> k;
	long long dem = 1;
	long long i = 1;
	while (dem < k) {
		dem += i++;
	}
	dem == k ? cout << 1 : cout << 0;

	return 0;
}
/*
Cho 1 con số dài vô tận được xây dựng bởi các con số 10i (i=0,1,2,3….) được viết liền nhau liên tiếp.
Ví dụ đây là phần đầu của số: 110100100010000… (10^0 10^1 10^2 10^3 10^4…).
Yêu cầu xác định chữ số ở vị trí k (đếm từ trái sang phải, bắt đầu từ chỉ số 1) là chữ số nào? (1 ≤ k ≤ 231 − 1).

Ví dụ 1:
Input	Output
3		0

Ví dụ 2:
Input	Output
7		1
*/