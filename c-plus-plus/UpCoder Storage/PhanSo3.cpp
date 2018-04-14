#include <iostream>
using namespace std;

int UCLN(long a, long b)
{
	return b == 0 ? a : UCLN(b, a%b);
}
struct PHANSO { int tu, mau; };
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
PHANSO rutGonPS(PHANSO ps){
	int mauChung = UCLN(ps.tu, ps.mau);
	ps.tu /= mauChung;
	ps.mau /= mauChung;
	return ps;
}

int main(){
	PHANSO ps, sum;
	sum.tu = 0;
	sum.mau = 1;
	while (cin >> ps){
		sum = sum + ps;
	}
	cout << rutGonPS(sum);
	system("pause");
	return 0;
}
/*
xây dựng 1 cấu trúc Phân Số (gồm tử và mẫu là số nguyên) với yêu cầu, xây dựng các hàm sau:
- Nhập, xuất phân số
- Hàm rút gọn.

Viết chương trình nhập vào N phân số, yêu cầu phân số tổng của các phân số trên (sau khi tối giản)

input:
- Gồm nhiều dòng, mỗi dòng gồm 2 số nguyên là tử và mẫu của 1 phân số

output:
phân số tổng

ví dụ:
input
1 2
2 4

output:
1/1

// setprecision example
#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision

int main () {
double f =3.14159;
std::cout << std::setprecision(5) << f << '\n';
std::cout << std::setprecision(9) << f << '\n';
std::cout << std::fixed;
std::cout << std::setprecision(5) << f << '\n';
std::cout << std::setprecision(9) << f << '\n';
return 0;
}
*/