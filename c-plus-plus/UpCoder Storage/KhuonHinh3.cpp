#include <iostream>
using namespace std;
// PHANSO
struct PHANSO { int tu, mau; };
istream& operator >> (istream& is, PHANSO & ps) {
	is >> ps.tu >> ps.mau;
	return is;
}
ostream& operator<<(ostream& os, PHANSO  ps) {
	os << ps.tu << "/" << ps.mau;
	return os;
}
bool operator<(PHANSO ps1, PHANSO ps2) {
	return double(ps1.tu / (double)ps1.mau) < double(ps2.tu / (double)ps2.mau);
}
// MANG
template <typename var>
struct Mang {
	int n = 0;
	var a[100];
	var&  operator[](int i) { return a[i]; }
};
template <typename var>
var findMin(Mang<var> a) {
	var min = a[0];
	for (int i = 1; i < a.n; i++) {
		if (a[i] < min) { min = a[i]; }
	}
	return min;
}
template <typename var>
void nhap(Mang<var> &a) {
	cin >> a[a.n]; a.n++;
}
template <typename var>
void xuat(Mang<var> a) {
	if (a.n > 0) { cout << findMin(a); }
	else { cout << "khong co"; }
}
int main() {
	char type;
	Mang<int> in;
	Mang<float> fl;
	Mang<PHANSO> ps;
	while (cin >> type) {
		switch (type) {
		case 'a': nhap(in); break;
		case 'b': nhap(fl); break;
		case 'c': nhap(ps); break;
		}
	}
	xuat(in); xuat(fl); xuat(ps);
	system("pause");
	return 0;
}
/*
void findMin(Mang<var> a, int n) {
if (n > 0) {
var min = a[0];
for (int i = 1; i < n; i++) {
if (a[0] < min) { min = a[i]; }
}
cout << min << endl;
}
else { cout << "khong co" << endl; }
}
findMin(ain, iin); // loi su dung ma khong khoi tao
findMin(afl, ifl);
findMin(aps, ips);
*/
/*
Xây dựng 1 cấu trúc mảng có sử dụng khuôn hình, áp dụng cho bài sau:
Viết chương trình nhập vào 1 dãy số, yêu cầu xuất ra số nhỏ nhất của từng loại số ra màn hình.
Với các qui ước:
o   Kiểu a: là số nguyên
o   Kiểu b: là số thực
o   Kiểu c: là phân số

Dữ liệu đầu vào:
o   Gồm nhiều dòng còn lại, mỗi dòng chứa kiểu và 1 số thuộc kiểu đó

Dữ liệu đầu ra:
Ghi ra 3 dòng:
o   Dòng 1: số nhỏ nhất của loại số nguyên
o   Dòng 2: số nhỏ nhất của loại số thực.
o   Dòng 3: số nhỏ nhất của loại phân số.

Nếu không tìm thấy số nhỏ nhất của loại nào thì xuất kết quả “khong co” (chữ thường, không dấu) tại vị trí của loại đó

Ví dụ 1:
Input:
a 1
b 1.2
c  1 2
b  2.4
c  2 3
Output:
1
1.2
1/2

Ví dụ 2:
Input:
b 1.2
c  1 2
b  2.4
c  2 3

Output:
khong co
1.2
1/2
*/