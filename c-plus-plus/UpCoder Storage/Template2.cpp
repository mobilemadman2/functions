#include <iostream>
using namespace std;
struct PHANSO { int tu, mau; };
istream& operator >> (istream& is, PHANSO & ps) {
	is >> ps.tu >> ps.mau;
	return is;
}
ostream& operator << (ostream& os, PHANSO  ps) {
	os << ps.tu << "/" << ps.mau;
	return os;
}
int UCLN(long a, long b)
{
	return b == 0 ? a : UCLN(b, a%b);
}
PHANSO rutGonPS(PHANSO ps) {
	int mauChung = UCLN(ps.tu, ps.mau);
	ps.tu /= mauChung;
	ps.mau /= mauChung;
	return ps;
}
PHANSO operator+(PHANSO ps1, PHANSO ps2) {
	PHANSO kq;
	kq.tu = ps1.tu*ps2.mau + ps1.mau*ps2.tu;
	kq.mau = ps1.mau * ps2.mau;
	return kq;
}
// MANG
template <typename var>
struct Mang {
	int n = 0;
	var a[100];
	var&  operator[](int i) { return a[i]; }
};
template <class var>
var getSum() {
	Mang<var> a;
	while (cin >> a[a.n]) {
		a.n++;
	}
	var sum = a[0];
	for (int i = 1; i < a.n; i++) {
		sum = sum + a[i];
	}
	return sum;
}
int main() {
	char type;
	cin >> type;
	if (type == 'a') {
		cout << getSum<int>();
	}
	else {
		cout << rutGonPS(getSum<PHANSO>());
	}
	system("pause");
	return 0;
}
/*
Xây dựng 1 cấu trúc mảng có sử dụng khuôn hình, áp dụng cho bài sau:
Viết chương trình nhập vào 1 dãy số, yêu cầu xuất ra tổng của các dãy số đó ra màn hình.
Với các qui ước:
-      Kiểu a: là số nguyên
-      Kiểu b: là phân số

Dữ liệu đầu vào:
-      Dòng đầu tiên: nhập vào loại kiểu của dãy số (kiểu a hoặc b)
-      Các dòng còn lại, mỗi dòng chứa 1 số thuộc kiểu của dòng đầu tiên

Dữ liệu đầu ra:
-      Gồm 1 số duy nhất (thuộc kiểu đã cho).

Lưu ý:
- Nếu kết quả là phân số thì phân số đó đã được rút gọn.

Ví dụ 1:
Input:
a
1
2
3
4

Output:
10

Ví dụ 2:
Input:
b
1 2
2 3
3 4
4 5

Output:
163/60
*/