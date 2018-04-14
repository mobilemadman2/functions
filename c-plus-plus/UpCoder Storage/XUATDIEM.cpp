#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct DIEM{ int x, y; };
istream& operator>>(istream& is, DIEM & diem){
	is >> diem.x >> diem.y;
	return is;
}
ostream& operator<<(ostream& os, DIEM  diem){
	os << "(" << diem.x << "," << diem.y << ")";
	return os;
}
bool operator == (DIEM a, DIEM b){
	return a.x==b.x&&a.y==b.y;
}
string soThanhChuoi(int n){
	string s, kq;
	if (n<0)kq += '-';
	if (n == 0)	kq = "0";
	n = abs(n);
	while (n>0){
		s += (char)(n % 10 + 48);n /= 10;
	}
	for (int i = s.size() - 1; i >= 0; i--){kq += s[i];}
	return kq;
}
bool operator < (DIEM A, DIEM B){
	string s1, s2;
	s1 = soThanhChuoi(A.x);
	s2 = soThanhChuoi(B.x);
	if (s1.compare(s2)<0)
		return true;
	if (s1.compare(s2) == 0){
		string s3, s4;
		s3 = soThanhChuoi(A.y);
		s4 = soThanhChuoi(B.y);
		if (s3.compare(s4)<0)
			return true;
	}
	return false;
}
DIEM operator+(DIEM a, DIEM b){
	DIEM s;
	s.x = a.x + b.x;
	s.y = a.y + b.y;
	return s;
}

struct mangDiem{
	int n;
	DIEM a[50];
	//Phuong thuc khoi tao - Kien thuc mo^n: huong doi tuong
	//Phuong thuc duoc goi tu dong - khi doi tuong duoc tao ra
	mangDiem(){ n = 0; }
	DIEM& operator[](int i){ return a[i]; }
};
istream& operator>>(istream &is, mangDiem& m){
	DIEM ps;

	//m.n=0;
	while (cin >> ps){
		//m.a[m.n++] = ps;
		m[m.n++] = ps;  //Chua co qua tai toan tu gan = ???
	}

	return is;
}
ostream& operator<<(ostream &os, mangDiem m){
	for (int i = 0; i < m.n; ++i)
		os << m[i] << endl;
	return os;
}

int main() {
	DIEM a, max, sum;
	int flag = 1;
	ifstream in;
	in.open("input.txt");
	while (in >> a){
		if (flag == 1){ max = a; sum = a; flag = 0; }
		else sum = sum + a;
		if (max < a){ max = a; }
		
	}
	in.close();// dong file
	ofstream out("output.txt");
	out << max << sum;
	out.close();
	//system("pause");
	return 0;
}
/*
Yêu cầu 1:
Xây dựng cấu trúc Điểm gồm hoành độ và tung độ là 2 số nguyên,yêu cầu viết các quá tải
· >>  nhập điểm
· << xuất điểm – cách xuất theo dạng (x,y)
· Viết quá tải == (kiểm tra 2 điểm có trùng nhau không? )
· Viết quá tải < (so sánh theo kiểu “từ điển”)
· Quá tải toán tử + cộng 2 điểm trả về 1 Điểm có tung độ bằng tổng 2 tung độ và 
hoành độ bằng tổng 2 hoành độ.
Xây dựng cấu trúc Mảng 1 chiều dùng để lưu 1 dãy Điểm thuộc cấu trúc trên, 
yêu cầu viết các quá tải: >>, <<, +

Yêu cầu 2:
Viết chương trình nhập vào 1 dãy điểm, yêu cầu tìm điểm “lớn nhất” và xuất tổng điểm ra màn hình.
+ Dữ liệu vào từ file: input.txt
+ Dữ liệu ra file: output.txt

Ví dụ:
Input:
1 2
3 4
5 6

Output:
(5,6)
(9,12)
*/