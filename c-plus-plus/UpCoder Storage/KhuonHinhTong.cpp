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
PHANSO operator+(PHANSO ps1, PHANSO ps2) {
	PHANSO kq;
	kq.tu = ps1.tu*ps2.mau + ps1.mau*ps2.tu;
	kq.mau = ps1.mau * ps2.mau;
	return kq;
}
int UCLN(int a, int b)
{
	return b == 0 ? a : UCLN(b, a%b);
}
PHANSO rutGonPS(PHANSO ps) {
	int mauChung = UCLN(ps.tu, ps.mau);
	ps.tu /= mauChung;
	ps.mau /= mauChung;
	return ps;
}
// MANG
template <typename var>
struct Mang {
	int n = 0;
	var a[100];
	var&  operator[](int i) { return a[i]; }
};
template <typename var>
var findSum(Mang<var> a) {
	var sum = a[0];
	for (int i = 1; i < a.n; i++) {
		sum = sum + a[i];
	}
	return sum;
}
int main() {
	char type;
	Mang<int> in;
	Mang<PHANSO> ps;
	while (cin >> type) {
		switch (type)
		{
		case 'a':
			cin >> in[in.n]; in.n++;
			break;
		case 'b':
			cin >> ps[ps.n]; ps.n++;
			break;
		}
	}
	if (in.n > 0) { cout << findSum(in); }
	else { cout << "khong co" << endl; }
	if (ps.n > 0) {
		cout << rutGonPS(findSum(ps)) << endl;
	}
	else { cout << "khong co" << endl; }
	system("pause");
	return 0;
}
/*
Xây dựng chương trình có sử dụng khuôn hình, áp dụng cho bài sau:
Viết chương trình nhập vào 1 dãy số gồm nhiều loại số, yêu cầu xuất ra tổng của từng loại số ra màn hình.
Với các qui ước:
o   Kiểu a: là số nguyên
o   Kiểu b: là số phân số

Dữ liệu đầu vào:
o   Gồm nhiều dòng còn lại, mỗi dòng chứa kiểu và 1 số thuộc kiểu đó

Dữ liệu đầu ra:
Ghi ra 3 dòng:
o   Dòng 1: tổng của loại số nguyên
o   Dòng 2: tổng của loại phân số (kết quả đã được rút gọn)
Nếu không tìm thấy tổng của loại nào thì xuất kết quả “khong co” (chữ thường, không dấu) tại vị trí của loại đó

Ví dụ 1:
Input:
a 1
b  1 2
b  2 3

Output:
1
7/6

Ví dụ 1:
Input:
b  1 2
b  2 3

Output:
khong co
7/6
*/