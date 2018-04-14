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
bool operator<(PHANSO ps1, PHANSO ps2) {
	return double(ps1.tu / (double)ps1.mau) < double(ps2.tu / (double)ps2.mau);
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
int main() {
	PHANSO ps, minps;
	bool firstflag = true;
	while (cin >> ps)
	{
		if (firstflag) {
			minps = ps;
			firstflag = false;
		}
		else if (rutGonPS(ps) < minps) {
			minps = rutGonPS(ps);
		}
	}
	cout << minps << endl;
	return 0;
}
/*
xây dựng 1 cấu trúc Phân Số (gồm tử và mẫu là số nguyên) với yêu cầu, xây dựng các hàm sau:
- Nhập, xuất phân số
- Hàm rút gọn.

Viết chương trình nhập vào N phân số, yêu cầu tìm phân số nhỏ nhất trong các phân số trên (sau khi tối giản)

input:
- Gồm nhiều dòng, mỗi dòng gồm 2 số nguyên là tử và mẫu của 1 phân số

output: phân số nhỏ nhất (sau khi rút gọn)

Ví dụ:

input
1 2
2 4
output
1/2

*/