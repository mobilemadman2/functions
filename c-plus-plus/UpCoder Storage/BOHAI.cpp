#include<iostream>
using namespace std;

int tongUoc(int num)
{
	int sum = 0;
	for (int i = 1; i <= num; i++){
		if (num%i == 0){
			sum += i;
		}
	}
	return sum;
}
int tichChuSo(int num)
{
	int tich = 1;
	while (num != 0)
	{
		tich *= num % 10;
		num /= 10;
	}
	return tich;
}
int main()
{
	int n, m;
	cin >> n >> m;
	tongUoc(m) == tichChuSo(n) ? cout << "YES" : cout << "NO";
	return 0;
}
/*
Viết chương trình nhập vào 2 số nguyên dương N,M;  trong đó N có số chữ số lớn hơn một.
Yêu cầu kiểm tra tích các chữ số của N có bằng tổng các ước của M hay không? Nếu có xuất YES ngược lại xuất NO

Dữ liệu nhập:

- Là hai số nguyên N, M cách nhau một khoảng trắng (1 ≤ N, M ≤ 105)

Dữ liệu xuất:

- In ra YES nếu N, M là thỏa điều kiện trên. In ra NO nếu không phải.

Ví dụ
Input
23 6

Output
NO
*/