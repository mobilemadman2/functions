#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

struct DIEM { int x, y; };
istream& operator >> (istream& is, DIEM &d)
{
	is >> d.x >> d.y;
	return is;
}
ostream& operator << (ostream& os, DIEM d)
{
	os << "(" << d.x << "," << d.y << ")";
	return os;
}
int khoangCach(DIEM a, DIEM b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
bool operator == (DIEM a, DIEM b)
{
	return a.x == b.x && a.y == b.y;
}

struct TRIANGLE { DIEM a, b, c; };
istream& operator >> (istream& is, TRIANGLE &t)
{
	is >> t.a >> t.b >> t.c;
	return is;
}
ostream& operator <<(ostream& os, TRIANGLE t)
{
	os << t.a << "," << t.b << "," << t.c;
	return os;
}
int chuVi(TRIANGLE t)
{
	return khoangCach(t.a, t.b) + khoangCach(t.a, t.c) + khoangCach(t.b, t.c);
}
int operator + (TRIANGLE a, TRIANGLE b)
{
	return chuVi(a) + chuVi(b);
}
bool operator > (TRIANGLE a, TRIANGLE b)
{
	return chuVi(a) > chuVi(b);
}
bool operator == (TRIANGLE a, TRIANGLE b)
{
	return a.a == b.a&&a.b == b.b&&a.c == b.c;
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	TRIANGLE tri[100];
	int i = 0;
	while (in >> tri[i]) { i++; }
	int sum = chuVi(tri[0]);
	int max = sum, pos = 0;
	for (int j = 1; j < i; j++)
	{
		sum += chuVi(tri[j]);
		if (max < chuVi(tri[j]))
		{
			max = chuVi(tri[j]);
			pos = j;
		}
	}
	out << sum << endl;
	out << tri[pos] << endl;
	return 0;
}
/*
Xây dựng cấu trúc DIEM gồm tung độ và hoành độ (số nguyên)
- Viết quá tải hàm nhập, xuất điểm
- Viết hàm tính khoảng cách giữa 2 điểm
- Viết quá tải so sánh bằng giữa 2 điểm: kiểm tra 2 điểm có trùng nhau không?

Xây dựng cấu trúc TAMGIAC gồm 3 điểm (dựa vào cấu trúc DIEM ở trên)
- Viết quá tải hàm nhập, xuất
- Viết hàm tính chu vi tam giác
- Quá tải toán tử + hai tam giác (HD: cộng chu vi tam giác)
- Quá tải toán tử > : so sánh 2 tam giác dựa vào chu vi
- Quá tải toán tử so sánh bằng : kiểm tra 2 TAM GIÁC có trùng nhau hay không?
- Khai báo 1 mảng TAM GIÁC

- Nhập mảng tam giác trên từ file văn bản input.txt theo cấu trúc: mỗi dòng gồm tọa độ của 3 điểm của 1 tam giác
input.txt
0 3 4 0 4 3
0 5 12 0 12 5

- Xuất ra file văn bản output.txt
+ Dòng 1: tổng các TAM GIÁC vừa nhập
+ Dòng 2: thông tin tam giác có chu vi lớn nhất
output.txt
42
(0, 5),(12, 0),(12, 5)
*/