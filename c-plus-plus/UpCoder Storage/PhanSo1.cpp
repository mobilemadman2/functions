#include <iostream>
using namespace std;

struct PHANSO{ int tu, mau; };

istream& operator>>(istream& is, PHANSO & ps){
	is >> ps.tu >> ps.mau;
	return is;
}

ostream& operator<<(ostream& os, PHANSO  ps){
	os << ps.tu << "/" << ps.mau;
	return os;
}

PHANSO operator+(PHANSO ps1, PHANSO ps2){
	PHANSO kq;
	kq.tu = ps1.tu*ps2.mau + ps1.mau*ps2.tu;
	kq.mau = ps1.mau * ps2.mau;
	return kq;
}

int UCLN(long a, long b)
{
	return b == 0 ? a : UCLN(b, a%b);
}

PHANSO rutGonPS(PHANSO ps){
	int mauChung = UCLN(ps.tu, ps.mau);
	ps.tu /= mauChung;
	ps.mau /= mauChung;
	return ps;
}

int main(){
	PHANSO phanSo1, phanSo2;
	cin >> phanSo1 >> phanSo2;
	if (phanSo1.mau == 0 || phanSo2.mau == 0){
		cout << -1;
	}
	else{
		cout << rutGonPS(phanSo1 + phanSo2);
	}

	system("pause");
	return 0;
}

/*
Yêu cầu xây dựng cấu trúc Phân số (gồm tử và mẫu).
Viết chương trình nhập vào 2 phân số, yêu cầu xuất phân số tổng của 2 phân số đó (sau khi rút gọn ra màn hình)

Nếu input có phân số nào có mẫu bằng 0 thì xuất kết quả ra -1

ví dụ 1:
input
1 2
1 3
output
5/6

ví dụ 1:
input
1 2
1 0
output
-1
*/