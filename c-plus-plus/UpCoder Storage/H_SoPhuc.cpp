#include <iostream>
#include <fstream>
using namespace std;
struct SOPHUC { int thuc, ao; };
istream& operator >> (istream& is, SOPHUC & sp) {
	is >> sp.thuc >> sp.ao;
	return is;
}
ostream& operator<<(ostream& os, SOPHUC  sp) {
	//a + b*i
	if (sp.ao > 0) {
		os << sp.thuc << " + " << sp.ao << "*i";
	}
	else if (sp.ao < 0) {
		os << sp.thuc << " - " << sp.ao*-1 << "*i";
	}

	return os;
}
SOPHUC operator+(SOPHUC sp1, SOPHUC sp2) {
	SOPHUC kq;
	kq.thuc = sp1.thuc + sp2.thuc;
	kq.ao = sp1.ao + sp2.ao;
	return kq;
}
SOPHUC operator-(SOPHUC sp1, SOPHUC sp2) {
	SOPHUC kq;
	kq.thuc = sp1.thuc - sp2.thuc;
	kq.ao = sp1.ao - sp2.ao;
	return kq;
}
SOPHUC operator*(SOPHUC sp1, SOPHUC sp2) {
	SOPHUC kq;
	//u = (sp1.thuc, sp1.ao), v = (sp2.thuc, sp2.ao)
	kq.thuc = sp1.thuc * sp2.thuc - sp1.ao * sp2.ao;//a*c - b*d
	kq.ao = sp1.thuc * sp2.ao + sp1.ao * sp2.thuc;//a*d + b*c
	return kq;
}
bool operator>(SOPHUC sp1, SOPHUC sp2) {
	return sp1.thuc > sp2.thuc && sp1.ao > sp2.ao;
}
int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int nmax;
	in >> nmax;

	SOPHUC spmax, sptich, sptong, sp;
	for (int i = 0; i < nmax; i++) {
		in >> sp;
		if (i == 0) {
			sptich = sp;
			spmax = sp;
			sptong = sp;
		}
		else {
			sptich = sptich * sp;
			sptong = sptong + sp;
			if (sp > spmax) { spmax = sp; }
		}
	}

	out << spmax << endl << sptong << endl << sptich << endl;

	in.close(); out.close();
	system("pause");
	return 0;
}
/*
Số phức z được biểu diễn dưới dạng z = a + b*i (với i2 = -1; a, b nguyên; a : phần thực; b : phần ảo).
Cho 2 số phức u = (a, b), v = (c, d). Ta có:
u + v = (a + c, b + d)
u - v = (a - c, b - d)
u * v = (a*c - b*d, a*d + b*c)
Yêu cầu:
Xây dựng cấu trúc SoPhuc.
Cài đặt quá tải toán tử nhập (>>) và xuất (<<) để hiển thị số phức ra màn hình dạng a + b*i (chú ý cho trường hợp b < 0).
Cài đặt quá tải toán tử so sánh lớn hơn (>)
Cài đặt quá tải toán tử cộng (+), nhân (*) để tính cộng, nhân 2 số phức.
Viết hàm main thực hiện các yêu cầu sau:
Khai báo mảng số phức.
Đọc dữ liệu từ file "input.txt" để đổ vào mảng
Dòng 1: Số lượng các số phức
Dòng 2 trở đi: Thông tin 1 số phức bao gồm 2 số nguyên dương để chỉ phần thực và phần ảo
Xuất dữ liệu file "output.txt" nội dung sau:
Dòng 1: Số phức lớn nhất
Dòng 2: Tổng các số phức
Dòng 3: Tích các số phức
Ví dụ:
input
5
2 3
-5 2
-11 -33
15 5
27 7
output
27 + 7*i
28 - 16*i
-224950 + 195250*i
*/