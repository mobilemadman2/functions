#include <iostream>
#include <cmath>
#include <string>
using namespace std;
//DIEM Oxy
struct Oxy { int x, y; };
istream& operator >> (istream& is, Oxy& d) {
	is >> d.x >> d.y;
	return is;
}
ostream& operator << (ostream& os, Oxy d) {
	os << "(" << d.x << "," << d.y << ")";
	return os;
}
double operator - (Oxy a, Oxy b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)); //sqrt((x1-x2)^2+(y1-y2)^2)
}
bool operator < (Oxy A, Oxy B) {
	if (A.x < B.x) { return true; }
	if (A.x == B.x && A.y < B.y) { return true; }
	return false;
}
// DIEM Oxyz
struct Oxyz { int x, y, z; };
istream& operator >> (istream& is, Oxyz& d) {
	is >> d.x >> d.y >> d.z;
	return is;
}
ostream& operator << (ostream& os, Oxyz d) {
	os << "(" << d.x << "," << d.y << "," << d.z << ")";
	return os;
}
double operator - (Oxyz a, Oxyz b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z));
}
bool operator < (Oxyz a, Oxyz b) {
	if (a.x < b.x) { return true; }
	if (a.x == b.x && a.y < b.y) { return true; }
	if (a.x == b.x && a.y == b.y && a.z < b.z) { return true; }
	return false;
}
// MANG
template <class var>
struct Mang {
	var a[100];
	int n = 0;
	var& operator[](int i) { return a[i]; }
};
template <class var>
istream& operator >> (istream& is, Mang<var>& d) {
	is >> d[d.n]; d.n++;
	return is;
}
template <class var>
ostream& operator << (ostream& os, Mang<var> d) {
	for (int i = 0; i < d.n; i++) {
		os << d[i] << " ";
	}
	cout << endl;
	return os;
}
template <class var>
double maxDis(Mang<var> a) {
	double max = 0;
	for (int i = 0; i < a.n - 1; i++) {
		for (int j = i + 1; j < a.n; j++) {
			if (max < a[i] - a[j]) { max = a[i] - a[j]; }
		}
	}
	return roundf(max * 1000) / 1000;
}
// QUICK SORT
template <class var>
int partition(var *a, int l, int r) {
	var key = a[r];
	int i = l - 1, j;
	for (j = l; j<r; j++)
		if (a[j] < key) {
			i++;
			var tmp = a[i]; a[i] = a[j]; a[j] = tmp;
		}
	var tmp = a[i + 1]; a[i + 1] = a[r]; a[r] = tmp;
	return i + 1;
}
template <class var>
void TailRecursiveQuicksort(var *a, int r, int l = 0) {
	r--;
	while (l<r)
	{
		int q = partition(a, l, r);
		if (q < (l + (r - l) / 2)) {
			TailRecursiveQuicksort(a, q - 1, l);
			l = q + 1;
		}
		else {
			TailRecursiveQuicksort(a, r, q + 1);
			r = q - 1;
		}
	}
}
int main() {
	Mang<Oxy> a;
	Mang<Oxyz> b;
	string s;
	while (cin >> s) {
		if (s == "Oxy") {
			cin >> a;
		}
		else { cin >> b; }
	}
	TailRecursiveQuicksort(a.a, a.n);
	TailRecursiveQuicksort(b.a, b.n);
	cout << a;
	for (int i = b.n - 1; i >= 0; i--) {
		cout << b[i];
	}
	cout << maxDis(a) << endl << maxDis(b);
	system("pause");
	return 0;
}
/*
Xây dựng cấu trúc điểm trong mặt phẳng Oxy
Viết quá tải toán tử nhập ( >> ) , xuất ( << ) (xuất theo dạng (x, y) )
viết quá tải toán tử trừ ( - ) để tính khoảng cách giữa 2 điểm
viết quá tải toán tử so sánh nhỏ hơn ( < ) để so sánh toạ độ của 2 điểm (theo thứ tự hoành độ rồi tới tung độ)

Xây dựng cấu trúc điểm trong không gian Oxyz
Viết quá tải toán tử nhập ( >> ) , xuất ( << ) (xuất theo dạng (x, y, z) )
viết quá tải toán tử trừ ( - ) để tính khoảng cách giữa 2 điểm
viết quá tải toán tử so sánh nhỏ hơn ( < ) để so sánh toạ độ của 2 điểm (theo thứ tự ưu tiên hoành độ, tung độ, cao độ)

Xây dựng cấu trúc mảng lưu trữ cấu trúc điểm ở trên sử dụng template
Viết quá tải toán tử nhập ( >> ) , xuất ( << ) ??
viết hàm tìm khoảng cách lớn nhất giữa 2 điểm trong mảng
(tìm trong mảng 2 điểm sao cho khoảng cách giữa 2 điềm đó là lớn nhất )
viết hàm sắp xếp mảng tăng dần
viết hàm sắp xếp mảng giảm dần

INPUT: nhập vào dãy (dùng while cin)
chuỗi "Oxy" và "Oxyz" và toạ độ điểm, nếu là Oxy thì nhập điểm trong mp Oxy , nếu là Oxyz thì nhập điểm trong không gian Oxyz

OUTPUT
dòng 1: xuất ra mảng toạ độ trong hệ toạ độ Oxy theo thứ tự tăng dần, mỗi phần tử cách nhau 1 khoảng trắng
dòng 2:  xuất ra mảng toạ độ trong hệ toạ độ Oxyz theo thứ tự giảm dần, mỗi phần tử cách nhau 1 khoảng trắng
dòng 3: xuất ra khoảng cách lớn nhất giữa 2 điểm trong mảng toạ độ Oxy, làm tròn đến 3 chữ số thập phân
dòng 4:  xuất ra khoảng cách lớn nhất giữa 2 điểm trong mảng toạ độ Oxyz, làm tròn đến 3 chữ số thập phân

lưu ý: sử dụng roundf(n * 1000) / 1000 ; để làm tròn n tới 3 chữ số thập phân

Input:
Oxy 1 2
Oxyz 1 2 3
Oxy 5 2
Oxyz 4 5 6
Oxy 7 8

Output:
(1,2) (5,2) (7,8)
(4,5,6) (1,2,3)
8.485
5.196
*/