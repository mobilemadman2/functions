#include <iostream>
using namespace std;
//GET >> tổng chữ số: 123 = 1+2+3 = 6
int tichOfInt(int num) {
	int tong = 1;
	while (num > 0) {
		tong *= num % 10;
		num /= 10;
	}
	return tong;
}
int main() {
	int num, i = 0, check = false;
	cin >> num;
	for (; i < 186; i++) {
		if (tichOfInt(i) == num) {
			check = 1;
			break;
		}
	}
	check == false ? cout << -1 : cout << i;
	system("pause");
	return 0;
}
/*
Hãy tìm số nguyên dương Q nhỏ nhất sao cho tích các chữ số của Q phải bằng N cho trước

Bạn hãy cũng giải thi với Phương xem ai giải nhanh hơn nhé !

Input
Số N duy nhất với 0 <= N <= 109

Output
In ra duy nhất số Q. Nếu không tìm được thì in ra -1
Sample
input
output
10
25*/