#include <iostream>
#include <string>
using namespace std;

int main() {
	string sdt; cin >> sdt;
	if (sdt.size() != 10) { cout << "Khong hop le"; }
	else if (sdt.find("04") == 0) { cout << "Ha Noi - " << sdt.substr(2, 9); }
	else if (sdt.find("08") == 0) { cout << "TPHCM - " << sdt.substr(2, 9); }
	else if (sdt.find("059") == 0) { cout << "Gia Lai - " << sdt.substr(3, 9); }
	else if (sdt.find("061") == 0) { cout << "Dong Nai - " << sdt.substr(3, 9); }
	else if (sdt.find("0511") == 0) { cout << "Da Nang - " << sdt.substr(4, 9); }
	else if (sdt.find("0710") == 0) { cout << "Can Tho - " << sdt.substr(4, 9); }
	return 0;
}

/*
Hãy viết chương trình nhập vào một chuỗi số và kiểm tra xem chuỗi nhập vào có phải là số điện thoại cố định hợp lệ hay không?
Nếu hợp lệ thì hãy cho biết số điện thoại đó thuộc tỉnh thành nào?
Biết rằng, số điện thoại cố định hợp lệ là một chuỗi có 10 chữ số bao gồm 2 phần: mã tỉnh thành và số điện thoại được quy định như sau:
Mã tỉnh thành có m chữ số và bắt buộc phải là một trong các mã sau:
- 04: Ha Noi
- 08: TPHCM
- 059: Gia Lai
- 061: Dong Nai
- 0511: Da Nang
- 0710: Can Tho
Số điện thoại có (10 - m) chữ số còn lại.

Input: chuỗi số điện thoại
Output:
- Nếu số điện thoại hợp lệ, in ra tên tỉnh thành tương ứng và số điện thoại theo định dạng: {tên tỉnh thành} - {số điện thoại}
- Nếu số điện thoại không hợp lệ, in ra chữ "Khong hop le"

Ví dụ:
Input: 0838352020
Output: TPHCM - 38352020

Input: 0613912985
Output: Dong Nai - 3912985

Input: 0511392396
Output: Da Nang - 392396

Input: 0123456789
Output: Khong hop le

Input: 0123abcd
Output: Khong hop le
*/
s[s.size()-1]