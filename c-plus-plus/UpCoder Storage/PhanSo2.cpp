#include <iostream>
using namespace std;

struct PHANSO{	int tu, mau;};

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

struct mangPS{
	int n;
	PHANSO a[50];
	//Phuong thuc khoi tao - Kien thuc mo^n: huong doi tuong
	//Phuong thuc duoc goi tu dong - khi doi tuong duoc tao ra
	mangPS(){ n = 0; }
	PHANSO& operator[](int i){return a[i];}
};

istream& operator>>(istream &is, mangPS& m){
	PHANSO ps;

	//m.n=0;
	while (cin >> ps){
		//m.a[m.n++] = ps;
		m[m.n++] = ps;  //Chua co qua tai toan tu gan = ???
	}

	return is;
}

ostream& operator<<(ostream &os, mangPS m){
	for (int i = 0; i < m.n; ++i)
		os << m[i] << endl;

	return os;
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
int main()
{
	mangPS arPs;
	cin >> arPs;
	//tao phan so sum =0
	PHANSO sum;
	sum.tu = 0;
	sum.mau = 1;
	//cong cac phan tu trong mang ps va gan vao sum
	for (int i = 0; i<arPs.n; ++i)
		sum = sum + arPs[i];
	cout << rutGonPS(sum);
	return 0;
}
/*
+Xây dựng cấu trúc PhanSo:
Viết quá tải toán tử: >>, <<, ==,!=,+

+ xây dựng cấu trúc mảng Phân số
viết quá tải toán tử: >>,<<,[].

viết ct nhập vào dãy phân số, yêu cầu xuất tổng phân số sau khi rút gọn
ví dụ:
1 2
2 3
3 4

output:
23/12
*/