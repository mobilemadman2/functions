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
bool operator==(PHANSO ps1, PHANSO ps2){
	return ps1.tu*ps2.mau == ps1.mau*ps2.tu;
}
bool operator!=(PHANSO ps1, PHANSO ps2){
	//return ps1.tu*ps2.mau != ps1.mau*ps2.tu;
	return !(ps1 == ps2);
}
PHANSO operator+(PHANSO ps1, PHANSO ps2){
	PHANSO kq;
	kq.tu = ps1.tu*ps2.mau + ps1.mau*ps2.tu;
	kq.mau = ps1.mau * ps2.mau;
	return kq;
}
int UCLN(int a, int b)
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
	PHANSO a, b;
	cin >> a >> b;
	cout << rutGonPS(a + b);
	//system("pause");
	return 0;
}
/*
Cho cấu trúc Phân số gồm tử và mẫu.
yêu cầu xây dựng các hàm quá tải sau:
Nhập
Xuất.
Gán
Cộng
So sánh bằng
So sánh khác
Viết một chương trình nhập vào 2 phân số, yêu cầu xuất như sau

xuất tổng 2 phân số (sau khi rút gọn)
ví dụ:

input:

1 2

2 4

output:

1/1
*/