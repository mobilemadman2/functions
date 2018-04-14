#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int toInt(string str) {
	int result = 0, i = 0, am = 1;
	if (str[0] == '-') { i = 1; am = -1; }
	for (; i < str.size(); i++) {
		result = result * 10 + str[i] - 48;
	}
	return result*am;
}
struct Customer {
	string id, fullName;
	int cash;
};
istream& operator >> (istream& is, Customer &c) {
	string s; getline(is, s);
	int sep1 = s.find(" - ");
	int sep2 = s.rfind(" - ");
	c.id = s.substr(0, sep1);
	c.fullName = s.substr(sep1 + 3, sep2 - (sep1 + 3));
	c.cash = toInt(s.substr(sep2 + 3));
	return is;
}
ostream& operator << (ostream& os, Customer c) {
	cout << c.id << " - " << c.fullName << " - " << c.cash << endl;
	return os;
}
struct ListCus {
	Customer a[100];
	int n = 0;
	Customer& operator[](int i) { return a[i]; }
	int validCus() {
		int valid = 0;
		for (int i = 0; i < n; i++) {
			if (a[i].cash >= 0) { valid++; }
		}
		return valid;
	}
	Customer richestCus() {
		Customer max = a[0];
		for (int i = 1; i < n; i++) {
			if (a[i].cash > max.cash) { max = a[i]; }
		}
		return max;
	}
};
istream& operator >> (istream& is, ListCus& lc) {
	int n; is >> n;
	is.ignore();
	for (int i = 0; i < n; i++) {
		is >> lc[lc.n]; lc.n++;
	}
	return is;
}
int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	ListCus lc;
	int n; in >> n;
	in.ignore();
	for (int i = 0; i < n; i++) {
		string s;
		getline(in, s);
	}
	out << lc.validCus() << endl << lc.richestCus() << endl;
	system("pause");
	return 0;
}
/*
Xây dựng cấu trúc (hoặc lớp) Khách hàng với những thông tin mô tả như sau:
+ Mã khách hàng: chuỗi có độ dài cố định 3 kí tự.
+ Tên khách hàng: chuỗi có độ dài tối đa 25 kí tự.
+ Số tiền đang có: số nguyên. Có thể âm, dương hoặc = 0
Yêu cầu:
Đọc thông tin khách hàng từ file input.txt theo cú pháp như sau:
Dòng 1: Số lượng khách hàng
N dòng tiếp theo là thông tin của mỗi khách hàng theo định dạng Mã khách hàng - Tên khách hàng - Số tiền đang có.
Xuất thông tin khách hàng xuống file output.txt với cú pháp như sau:
Dòng 1: Số lượng khách hàng hợp lệ (dựa vào số tiền đang có >= 0).
Dòng 2: Thông tin khách hàng có số tiền đang có lớn nhất.
Ví dụ:
input.txt
5
100 - Tran Cong Bang - 15000000
200 - Dang Thanh Hai - -75950000
300 - Truong Gia Binh - 90000000
400 - Le Hien Linh - 0
500 - Ly Tieu Long - -300000000

output.txt
3
300 - Truong Gia Binh - 90000000

Giải thích: Khách hàng có mã 200, tên Dang Thanh Hai và khách hàng có mã 500, tên Ly Tieu Long số tiền đang có âm.
*/