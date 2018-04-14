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
mangMotChieu operator+(mangMotChieu m1, mangMotChieu m2)
{
	mangMotChieu m;
	if (m1.n < m2.n)
	{
		m.n = m2.n;
		for (int i = 0; i < m1.n; i++)
			m.a[i] = m1.a[i] + m2.a[i];
		for (int i = m1.n; i < m2.n; i++)
			m.a[i] = m2.a[i];
	}
	else
	{
		m.n = m1.n;
		for (int i = 0; i < m2.n; i++)
			m.a[i] = m1.a[i] + m2.a[i];
		for (int i = m2.n; i < m1.n; i++)
			m.a[i] = m1.a[i];
	}
	return m;
}
int main()
{
	mangMotChieu a, b;
	cin >> a >> b;
	cout << a + b;
	//system("pause");
	return 0;
}
/*
Cho cấu trúc mảng 1 chiều.
yêu cầu xây dựng các hàm quá tải sau:
Nhập
Xuất.
Cộng
Viết một chương trình nhập vào 2 mảng 1 chiều, xuất tổng của 2 mảng ra màn hình

Hướng dẫn nhập:

Dòng 1: nhập số lượng phần tử mảng thứ 1
Dòng 2: Nhập các phần tử của mảng thứ 1
Dòng 3: nhập số lượng phần tử mảng thứ 2
Dòng 4: nhập số lượng phần tử mảng thứ 2

Hướng dẫn xuất: xuất ra  các phần tử của mảng mỗi phần tử cách nhau 1 khoảng trắng.
ví dụ:
input:
3
1 2 3
4
1 2 5 7

output:
2 4 8 7
*/