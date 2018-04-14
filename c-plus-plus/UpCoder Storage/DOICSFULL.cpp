#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void chuyenCoSo(long soHe10, int heCoSoMoi);
long decimalTo(long num, int mode){
	//mảng lưu phần dư và chỉ số
	int mod = -1, amod[100];
	//vòng lặp chia lấy nguyên lưu dư
	while (num > 0)
	{
		mod++;
		amod[mod] = num % mode;
		num /= mode;
	}
	//lặp mảng ngược
	long res = 0;
	while (mod >= 0)
	{
		res = res + amod[mod] * (long)pow(10, mod);
		mod--;
	}
	return res;
}
string hexaDecimal(long num){
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
	long soHe10;
	int heCoSo;
	cin >> soHe10 >> heCoSo;
	chuyenCoSo(soHe10, heCoSo);
	system("pause");
	return 0;
}

void chuyenCoSo(long soHe10, int heCoSoMoi){
	switch (heCoSoMoi)
	{
	case 0:
		cout << decimalTo(soHe10, 2) << endl; break;
	case 1:
		cout << decimalTo(soHe10, 8) << endl; break;
	case 2:
		cout << hexaDecimal(soHe10) << endl; break;
	default:
		cout << decimalTo(soHe10, 2) << endl;
		break;
	}
}
/*
Viết một hàm chuyển đổi cơ số từ hệ 10 sang hệ 2, 8 và 16 theo prototype sau:

void chuyenCoSo(long soHe10, int heCoSoMoi);

nếu tham số heCoSoMoi có giá trị là 0 thì chuyển sang cơ số 2, nếu là 1 thì chuyển sang hệ 8 còn nếu là 2 thì chuyển sang hệ 16.
Mặc định tham số heCoSoMoi có giá trị là 0.

ví dụ:
chuyenCoSo(10)   => kết quả sẽ là: 1010
chuyenCoSo(10,0)   => kết quả sẽ là: 1010
chuyenCoSo(10,1)   => kết quả sẽ là: 12
chuyenCoSo(10,2)   => kết quả sẽ là: A

Yêu cầu viết chương trình nhập vào 1 số nguyên n (0 < n <= 2000) là hệ cần đổi (theo qui ước của tham số là 0,1,2)
Xuất ra  số đã được đổi sang hệ tương ứng

vi du 1:

input:
10 0
output
1010

vi du 2:

input:
10 1
output
12
*/