#include <iostream>
using namespace std;
int catalan(int n) {
	int c[1000];
	c[0] = 1; c[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		c[i] = 0;
		for (int j = 0; j<i; j++)
		{
			c[i] += c[j] * c[i - j - 1];
		}
	}
	return c[n];
}
int main() {
	int n;
	while (cin >> n) {
		cout << catalan(n);
	}
	system("pause");
	return 0;
}
/*
Ta gọi dãy Catalan là dãy Cn được định nghĩa bởi công thức sau:


Hãy tính giá trị của dãy Catalan ứng với mỗi số nguyên dương n nhập từ bàn phím.

Dữ liệu vào: gồm nhiều dòng, mỗi dòng là một số nguyên dương.
Dữ liệu ra:giá trị của dãy Catalan ứng với từng input.

Ví dụ:
Input:
2
3
4

Output:
2
5
14
*/