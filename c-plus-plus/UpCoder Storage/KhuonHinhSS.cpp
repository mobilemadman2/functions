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
bool operator==(PHANSO ps1, PHANSO ps2) {
	return ps1.tu*ps2.mau == ps1.mau*ps2.tu;
}
template <typename var>
void compare() {
	var a, b; cin >> a >> b;
	if (a == b) { cout << "true"; }
	else { cout << "false"; }
}
int main() {
	char type;
	cin >> type;
	switch (type)
	{
	case 'a':
		compare<int>();
		break;
	case 'b':
		compare<float>();
		break;
	case 'c':
		compare<PHANSO>();
		break;
	}
	system("pause");
	return 0;
}
/*
Viết hàm khuôn hình so sánh 2 số
Nhập vào 2 số, xuất true nếu 2 số bằng nhau, ngược lại xuất false
qui ước:
kiểu a là số nguyên
kiểu b là số thực
kiểu c là phân số

ví dụ
a
1
2

output
false
*/