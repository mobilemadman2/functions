#include <iostream>
#include <string>
using namespace std;
struct PHANSO {
	int tu, mau;
};
istream& operator >> (istream& is, PHANSO & ps) {
	is >> ps.tu >> ps.mau;
	return is;
}
ostream& operator<<(ostream& os, PHANSO  ps) {
	os << ps.tu << "/" << ps.mau;
	return os;
}
PHANSO operator++(PHANSO &ps, int) {
	ps.tu += 1;
	return ps;
}
PHANSO operator--(PHANSO &ps, int) {
	ps.tu -= 1;
	return ps;
}
int main() {
	PHANSO a;
	cin >> a;
	cout << a;
	cin.ignore();
	string s;
	cin >> s;
	if (s[0] == '+') { cout << a++; }
	else { cout << a--; }
	system("pause");
	return 0;
}
/*
Xây dựng cấu trúc Phân Số với 2 thành phần là tử và mẫu (là 2 số nguyên <=100), yêu cầu xây dựng các toán tử sau:

- Toán tử nhập >>
- Toán tử xuất<<
- 2 toán tử ++ và -- với ý nghĩa là tăng và giảm tử số lên 1 đơn vị.


Yêu cầu áp dụng cấu trúc trên và 2 toán tử trên để giải bài sau:
Input:

- Dòng 1: Nhập vào 1 Phân Số gồm 2 số nguyên, mỗi cách nhau 1 khoảng trắng.
- Dòng 2: Nhập toán tử ++ hoặc --


Output:

- Dòng 1: Xuất Phân Số ban đầu.
- Dòng 2: Thực hiện phép toán trong input, sau đó xuất phân số sau khi thực hiện toán phép


ví dụ:

input
1 2
++
output
1/2
2/2
*/