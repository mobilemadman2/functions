#include<iostream>
using namespace std;
struct mangMotChieu
{
	int n;
	int a[50];
	int&  operator[](int i)
	{
		return a[i];
	}
};

istream& operator>>(istream& is, mangMotChieu& m)
{
	is >> m.n;
	for (int i = 0; i < m.n; i++)
		is >> m.a[i];
	return is;
}

ostream& operator<<(ostream& os, mangMotChieu m)
{
	for (int i = 0; i < m.n; i++)
		os << m.a[i];
	return os;
}

bool operator ==(mangMotChieu m1, mangMotChieu m2)
{
	if (m1.n != m2.n)
		return false;
	else
	{
		for (int i = 0; i < m1.n; i++)
		{
			if (m1.a[i] != m2.a[i])
				return false;
		}
		return true;
	}
}

bool operator !=(mangMotChieu m1, mangMotChieu m2)
{
	return !(m1 == m2);
}

mangMotChieu operator+(mangMotChieu m1, mangMotChieu m2)
{
	mangMotChieu tongMang;
	if (m1.n > m2.n)
		for (int i = m2.n; i < m1.n; i++)
			m2.a[i] = 0;
	else
		if (m1.n<m2.n)
		for (int i = m1.n; i < m2.n; i++)
			m1.a[i] = 0;
			for (int i = 0; i < m1.n; i++)
				tongMang.a[i] = m1.a[i] + m2.a[i];
			return tongMang;
}
int main()
{
	mangMotChieu m1, m2;
	cin >> m1;
	cin >> m2;
	m1 == m2 ? cout << "yes" : cout << "no";
	return 0;
}
/*
Cho cấu trúc mảng 1 chiều, yêu cầu xây dựng các hàm quá tải sau:
Nhập
Xuất.
Gán
Cộng
So sánh bằng
So sánh khác

Viết một chương trình nhập vào 2 mảng 1 chiều, xuất "yes" nếu 2 mảng giống nhau, 
ngược lại xuất "no" nếu 2 mảng khác nhau.

Hướng dẫn nhập:

Dòng 1: nhập số lượng phần tử mảng thứ 1
Dòng 2: Nhập các phần tử của mảng thứ 1
Dòng 3: nhập số lượng phần tử mảng thứ 2

ví dụ:
input:
3
1 2 3
4
1 2 5 7

output:
no
*/