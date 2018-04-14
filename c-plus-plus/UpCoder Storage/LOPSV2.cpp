#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
/*
class Diemm{};
class SinhVienn{};
*/
struct Diem {
	int n = 0;
	float a[100];
	float&  operator[](int i) { return a[i]; }
	float sum = 0;
	float& tbc() {

		for (int i = 0; i < n; i++) {
			sum += a[i];
		}
		sum /= n;
		return sum;
	}
};
istream& operator >> (istream& is, Diem& d) {
	while (is >> d[d.n]) {
		d.n++;
	}
	return is;
}
struct SinhVien {
	string ten, mssv;
	Diem d;
};
istream& operator >> (istream& is, SinhVien& sv) {
	getline(is, sv.ten);
	is >> sv.mssv >> sv.d;
	return is;
}
ostream& operator << (ostream& os, SinhVien sv) {
	os << "Ho Ten: " << sv.ten << endl;
	os << "Ma Sinh Vien: " << sv.mssv << endl;
	os << "DTB: " << fixed << setprecision(1) << sv.d.tbc() << endl;
	return os;
}
int main() {
	SinhVien a;
	cin >> a;
	cout << a;
	system("pause");
	return 0;
}
/*
Yêu cầu 1 xây dựng các lớp sau kèm theo các thao tác của nó:
- Lớp Điểm, gồm có các thuộc tính:
+ mảng số thực: lưu danh sách điểm các môn học (các điểm là các số thực >=0 và <=10)
+ số lượng phần tử của danh sách điểm.

Thao tác: xây dựng các toán tử >>, <<, [], =, lấy điểm trung bình cộng,
các phương thức khởi tạo (3 phương thức), phương thức hủy, các phương thức get và set.

- Lớp SinhViên, gồm có các thuộc tính
+ Họ tên (chuỗi có khoảng trắng)
+ Mã Sinh Viên (chuỗi không có khoảng trắng)
+ Điểm (thuộc lớp điểm khai báo ở trên).
Thao tác: xây dựng các toán tử >>, <<, =, < (dựa vào điểm trung bình), lấy điểm trung bình cộng, các phương thức khởi tạo (3 phương thức), phương thức hủy, các phương thức get và set.

Yêu cầu 2: Viết chương trình sử dụng lớp sinh viên và lớp điểm ở trên để giải bài sau:
-Input:
+ Dòng 1: Nhập họ tên sinh viên
+ Dòng 2: nhập mã sinh viên
+ Dòng 3: Gồm nhiều số thực (mỗi số cách nhau 1 khoảng trắng) là điểm của sinh viên này

- Output: Xuất theo cấu trúc
+ Dòng 1: Ho Ten: họ tên sinh viên
+ Dòng 2: Ma Sinh Vien: mã sinh viên
+ Dòng 3: DTB: Điểm trung bình của sinh viên

ví dụ:
input
Nguyen Van A
K42.11.22.33
10 10 5 5
output
Ho Ten: Nguyen Van A
Ma Sinh Vien: K42.11.22.33
DTB: 7.5
Lưu ý: điểm trung bình là số thực lấy chính xác 1 chữ số thập phân

Đọc thêm: Hướng dẫn nhập chuỗi
*/