#include <iostream>
using namespace std;
int UCLN(long a, long b)
{
	if (b == 0) return a;
	else return UCLN(b, a%b);
}
int main()
{
	long a, b;
	cin >> a >> b;
	cout << UCLN(a, b);
	return 0;
}

/*
Cho hai số nguyên dương a và b, hãy tìm ước số chung lớn nhất của a và b.

Dữ liệu nhập:
- Gồm 2 số a và b cách nhau một khoảng trắng (1 ≤ a, b ≤ 1018)

Dữ liệu xuất:
- Là ước số chung lớn nhất của a và b.

Ví dụ
input
6 9
output
3
input
1 10
output
1
*/