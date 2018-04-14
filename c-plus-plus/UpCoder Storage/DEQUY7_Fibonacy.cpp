#include <iostream>
#include <fstream>
using namespace std;
void fibonacy(int n) {
	int a[40] = { 1,1,1 }, i = 3;
	ofstream out("FIBO.out");
	out << 1 << 1;
	for (; i <= n; i++) {
		a[i] = a[i - 1] + a[i - 2];
		out << a[i] << " ";
	}
}
int main() {
	ifstream in("FIBO.inp");
	int n; in >> n;
	fibonacy(n);
	system("pause");
	return 0;
}
/*
Dãy số fibonacy được định nghĩa như sau:
f1 = f2 = 1
fn = fn-1 + fn-2  (với n >= 3)
Bạn hãy viết chương trình sử dụng đệ quy in ra n số đầu tiên của dãy số fibonacy.

Dữ liệu nhập từ file "FIBO.inp":
là số nguyên n (1<= n <= 40)

Dữ liệu xuất ra file "FIBO.out":
Là n số fibonacy đầu tiên trên cùng một dòng, mỗi số cách nhau một khoảng trắng.

input:
5
output:
1 1 2 3 5
*/