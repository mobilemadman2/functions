#include <iostream>
#include <fstream>
using namespace std;
int combination(int n, int k) {
	if (n == k) { return 1; }
	if (k == 1) { return n; }
	return combination(n - 1, k) + combination(n - 1, k - 1);
}
int main() {
	ifstream in("DEQUY.inp");
	ofstream out("DEQUY.out");
	int n, k;
	in >> n >> k;
	out << combination(n, k);
	system("pause");
	return 0;
}
/*
Tổ Hợp Chập K

Nhập vào số nguyên dương n và số nguyên k (1 <= k <= n)
và sử dụng phương pháp đệ quy in ra giá trị C(n,k)
của tổ hợp chập k của n bằng cách dựa vào công thức:
C(n, k) = C(n-1, k) + C(n-1, k-1),
biết C(n, n) = 1, C(n, 1) = n

dữ liệu vào từ file văn bản "DEQUY.inp": gồm 2 số n và k

dữ liệu ra file văn bản "DEQUY.out" : Giá trị C(n, k)

input :
5 3
ouput:
10
*/