#include <iostream>
using namespace std;
//GET >> tổng chữ số: 123 = 1+2+3 = 6
int sumOfInt(int num) {
	int tong = 0;
	while (num > 0) {
		tong += num % 10;
		num /= 10;
	}
	return tong;
}
int main()
{
	int n;
	cin >> n;
	cout << sumOfInt(n);
	return 0;
}
/*
Viết một chương trình đệ quy tính tổng các chữ số của số N cho trước
Ví dụ:
Input: 123
Ouput: 6 (vì : 1+2+3 =6)
*/