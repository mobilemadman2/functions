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
PHANSO operator+(PHANSO ps, int n) {
	ps.tu += n;
	ps.mau += n;
	return ps;
}
PHANSO operator*(PHANSO ps1, PHANSO ps2) {
	ps1.tu *= ps2.tu;
	ps1.mau *= ps2.mau;
	return ps1;
}
int main() {
	PHANSO ps1; cin >> ps1;
	int n; cin >> n;
	cout << ps1.tu << ps1.mau;
	cout << ps1.mau << "/" << ps1.tu;
	cout << rutGonPS(ps1);
	PHANSO ps2 = ps1 + n;
	cout << ps2;
	cout << rutGonPS(ps1*ps2);

	system("pause");
	return 0;
}
/*
Xây dựng lớp phân số cho phép thực hiện các thao tác:
1. Nhập, xuất.
2. Lấy tử số, mẫu số.
3. Gán giá trị cho tử số, mẫu số.
4. Nghịch đảo, rút gọn.
5. Cộng, trừ, nhân, chia, so sánh với phân số khác
Viết chương trình sử dụng lớp phân số ở trên để giải quyết các yêu cầu sau
Input: Gồm 2 dòng
- Dòng 1 là phân số X có 2 số là tử và mẫu số
- Dòng 2: chứa 1 số nguyên k
Output:
- Dòng 1: Xuất tử của phân số X
- Dòng 2: Xuất mẫu phân số X
- Dòng 3: Phân số nghịch đảo của phân số X
- Dòng 4: Phân số rút gọn  của phân số X
- Dòng 5: xuất phân số Y (Phân số Y là phân số có tử và mẫu được tính như sau:
tử của Y = tử của X + k
mẫu của Y = mẫu của X + k)
- Dòng 6: Xuất phân số tích (sau khi rút gọn) của phân số X và phân số Y

Ví dụ:

input
2 4
1
output
2
4
4/2
1/2
3/5
3/10
*/