#include <iostream>
using namespace std;
struct PHANSO { int tu, mau; };
istream& operator >> (istream& is, PHANSO & ps) {
	is >> ps.tu >> ps.mau;
	return is;
}
ostream& operator<<(ostream& os, PHANSO  ps) {
	os << ps.tu << "/" << ps.mau;
	return os;
}
bool operator>(PHANSO ps1, PHANSO ps2) {
	return double(ps1.tu / (double)ps1.mau) > double(ps2.tu / (double)ps2.mau);
}
template <class var>
var findMax() {
	var a, b, c;
	cin >> a >> b >> c;
	if (a > b && a > c) { return a; }
	if (b > a && b > c) { return b; }
	if (c > a && c > b) { return c; }
}
int main() {
	char type;
	cin >> type;
	switch (type)
	{
	case 'a':
		cout << findMax<int>();
		break;
	case 'b':
		cout << findMax<float>();
		break;
	case 'c':
		cout << findMax<PHANSO>();
		break;
	}
	system("pause");
	return 0;
}
/*
Viết 1 hàm template tìm phần tử lớn nhất trong 3 số
Yêu cầu xuất phần tử lớn nhất trong 3 số

qui ước: a là số nguyên, b là số thực, c là phân số
(các số nhập <= 100)

ví dụ:
a 1 2 3 tức là nhập 3 số nguyên

Dữ liệu vào:
Dòng 1: là nhập vào loại số
3 dòng tiếp theo: mỗi dòng chứa 1 số thuộc kiểu của dòng 1

Dữ liệu ra: gồm 1 dòng là số lớn nhất tìm thấy

ví dụ 1:

input
a
1
2
3
output
3

ví dụ 2:
input:
c
1 2
1 1
2 3

output
1/1

*/