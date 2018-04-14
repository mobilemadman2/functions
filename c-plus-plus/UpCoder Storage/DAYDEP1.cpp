﻿#include<iostream>
using namespace std;

int main()
{
	int num, sum = 0;
	while (cin >> num && num != 0)
	{
		sum += num;
	}

	if (sum % 10 == 0){
		cout << "DEP";
	}
	else if (sum % 10 == 5){
		cout << "TRUNGBINH";
	}
	else{
		cout << "XAU";
	}
	return 0;
}
/*
Nhập vào một dãy số, yêu cầu xuất độ “đẹp” của dãy số đó.
Độ “đẹp” của dãy được xác định như sau:
- Nếu tổng của dãy có chữ số tận cùng là 0, xuất ra màn hình là “DEP”
- Nếu tổng của dãy có chữ số tận cùng là 5, xuất ra màn hình là “TRUNGBINH”
- Còn nếu không rơi vào 2 trường hợp trên, xuất ra là “XAU”

Dữ liệu nhập:
Gồm nhiều dòng, mỗi dòng là 1 số kết thúc là số 0
(lưu ý 0 chỉ là ký hiệu kết thúc, không tính vào dãy số)

Dữ liệu xuất:
Xuất ra độ “đẹp” của dãy số.

Ví dụ:
Input:
10
9
5
0

output:
XAU
*/