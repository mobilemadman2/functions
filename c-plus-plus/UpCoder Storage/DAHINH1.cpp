#include <iostream>
#include <string>
using namespace std;
int main() {
	string chuoi;
	while (getline(cin, chuoi)) {
		if (chuoi[0] == 'a') {
			cout << (chuoi[2] - 48)*(chuoi[2] - 48);
		}
		if (chuoi[0] == 'b') {
			cout << (chuoi[2] - 48 + chuoi[4] - 48) * 2;
		}
	}
	return 0;
}
/*
Input:
Nhập vào 1 mảng N phần tử gồm các loại hình: hình vuông, hình chữ nhật.
(Hình vuông gồm 1 cạnh, hình chữ nhật gồm 2 cạnh)
Output:
Xuất chu vi của các hình đó.

Qui ước:
a - hình vuông
b - hình chữ nhật

Ví dụ:

input
a 3
b 1 2
a 4
output
12
6
16
*/