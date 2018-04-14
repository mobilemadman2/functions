#include<iostream>
#include<string>
using namespace std;
//CONVERT >> đổi số thập phân sang thập lục phân (hexadecimal)
string hexaDecimal(int num) {
	//mảng lưu phần dư và chỉ số
	int mod = -1, amod[100];
	//vòng lặp chia lấy nguyên lưu dư
	while (num > 0)
	{
		mod++;
		amod[mod] = num % 16;
		num /= 16;
	}
	//lặp mảng ngược
	string res, thaplucphan = "0123456789ABCDEF";
	while (mod >= 0)
	{
		res = res + thaplucphan[amod[mod]];
		mod--;
	}
	return res;
}
int main()
{
	int num;
	cin >> num;
	cout << hexaDecimal(num) << endl;
	system("pause");
	return 0;
}
/*
Viết chương trình chuyển đổi một số từ hệ thập phân sang hệ thập lục phân (hexa)

Dữ liệu vào: số nguyên dương n<=10^9 (ở hệ thập phân)
Dữ liệu ra: giá trị của n trong hệ hexa

Ví dụ:
Input: 816
Output: 330
*/