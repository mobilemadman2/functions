#include <iostream>
#include <iomanip>
using namespace std;
struct HCN {
	double d, r;
	double chuVi() {
		return (d + r) * 2;
	}
};
istream& operator >> (istream& is, HCN& h) {
	is >> h.d >> h.r;
	return is;
}
ostream& operator << (ostream& os, HCN h) {
	os << "[HCN]" << h.d << "," << h.r << endl;
	return os;
}
double operator + (HCN h, double n) {
	return h.chuVi() + n;
}
bool operator < (HCN a, HCN b) {
	return a.chuVi() < b.chuVi();
}
void cau1() {
	HCN a, b;
	cin >> a >> b;
	cout << a << b;
	cout << (a < b ? "true" : "false");
}
template <class var>
struct Mang {
	var a[100];
	int n = 0;
	var& operator[](int i) { return a[i]; }
	var findMin() {
		var min = a[0];
		for (int i = 1; i < n; i++) {
			if (a[i] < min) { min = a[i]; }
		}
		return min;
	}
	double sum() {
		double sum = 0;
		for (int i = 0; i < n; i++) {
			sum = a[i] + sum;
		}
		return sum;
	}
};
template <class var>
istream& operator >> (istream& is, Mang<var>& m) {
	while (is >> m[m.n]) {
		m.n++;
	}
	return is;
}
void cau2() {
	char c;
	cin >> c;
	if (c == 'N') {
		Mang<int> a;
		cin >> a;
		cout << a.findMin() << endl << a.sum() << endl;
	}
	else {
		Mang<HCN> b;
		cin >> b;
		cout << b.findMin();
		cout << fixed << setprecision(1) << b.sum() << endl;
	}
}
int main() {
	cau1();
	cau2();
	system("pause");
	return 0;
}
/*
Yêu cầu 1:
Xây dựng cấu trúc HCN biểu diễn hình chữ nhật gồm các thông tin:
chiều dài a, chiều rộng b (a và b là 2 số thực lớn hơn 0 và bé hơn 1000)
Yêu cầu xây dựng các hàm sau:
1. Quá tải nhập và xuất HCN
2. Tính chu vi HCN
3. Quá tải so sánh < hai HCN dựa vào chu vi (chu vi của HCN nhỏ hơn thì sẽ
xác định là HCN đó bé hơn)
4. Quá tải cộng + với tham số là cộng 1 HCN và 1 số thực, nội dung hàm: lấy
chu vi HCN cộng với số thực, hàm trả về là 1 số thực.

Yêu cầu 2: sử dụng cấu trúc ở trên giải bài tập với các yêu cầu sau:
Input: gồm 2 dòng, mỗi dòng chứa 2 số thực đại diện cho chiều dài và chiều
rộng của 2 HCN

Output:
- Dòng 1: Xuất thông tin của HCN 1
- Dòng 2: Xuất thông tin của HCN 2
- Dòng 3: Xuất "true" nếu HCN 1 < HCN 2, ngược lại xuất "false"

Ví dụ:
Input:
2 1
3 4

Output:
[HCN] 2.1
[HCN] 3.4
true
*/