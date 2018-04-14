#include <iostream>
using namespace std;
int s(int n, int i = 0, int sum = 0) {
	if (sum == 0) { i = n; }
	if (i == 0) { return sum; }
	if (n == 0) { i--; n = i; }
	return s(n - 1, i, sum + n);
}
// USING LOOP
long p(int n) {
	long i = n, pum = 1, sum = 0;
	while (i > 0) {
		pum *= n; n--;
		if (n == 0) { i--; n = i; sum += pum; pum = 1; }
	}
	return sum;
}
// USING RECURSION
/*int p(int n, int pum=1, int sum=0, int i=0) {
if (sum == 0) { i = n; }
if (i == 0) { return sum; }
if (n == 0) { i--; n = i; sum += pum; pum = 1; }
return p(n - 1, pum*n, sum, i);
}*/
int main() {
	int n;
	cin >> n;
	cout << "S(" << n << ") = " << s(n) << endl;
	cout << "P(" << n << ") = " << p(n);
	system("pause");
	return 0;
}
/*
Cho tổng S(n) = 1 + (1+2) + (1+2+3) + (1+2+3+4) + .... + (1+2+3+4+...+n)
và tổng P(n) = 1 + 1.2 + 1.2.3 + 1.2.3.4 + .... + 1.2.3.4....n

với n là số nguyên dương.

Hãy viết hàm đệ quy để tính 2 tổng trên với số n nhập từ bàn phím (n<=20)

Ví dụ:
input
3
output
S(3) = 10    (Lưu ý: có khoảng trắng phía trước và sau dấu "=")
P(3) = 9

input
5
output
S(5) = 35
P(5) = 153

Lưu ý: PHẢI sử dụng ĐỆ QUY để làm bài này.
*/