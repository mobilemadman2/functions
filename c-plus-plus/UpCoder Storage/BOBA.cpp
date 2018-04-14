#include<iostream>
#include<string>
using namespace std;

int tongChuSo(int num){
	int tong = 0;
	while (num > 0){
		tong += num % 10;
		num /= 10;
	}
	return tong;
}

int main()
{
	int n, k;
	string m;
	cin >> n;
	cin >> m;
	cin >> k;
	if (tongChuSo(n) + (int(m[0]) - 48) == k){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
	system("pause");
	return 0;
}
/*
Viết chương trình nhập vào 3 số nguyên dương N,M,K;

Yêu cầu kiểm tra tổng các chữ số của N cộng với chữ số đầu tiên của M có bằng K hay không? Nếu có xuất Yes ngược lại xuất No

Dữ liệu nhập:

- Là 3 số nguyên N, M, K cách nhau một khoảng trắng (1 ≤ N, M,K ≤ 105)

Dữ liệu xuất:

- In ra Yes nếu N, M là thỏa điều kiện trên. In ra No nếu không phải.

Ví dụ
Input
23 123 6

Output
Yes
*/