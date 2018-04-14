#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
int sumPow(int n, int x, int sum = 0, int p = 0) {
	if (p > n) { return sum; }
	else { sum = sum + pow(x, p); }
	return sumPow(n, x, sum, p + 1);
}
int main() {
	int n, x;
	ifstream in("DEQUY.inp");
	in >> n >> x;
	ofstream out("DEQUY.out");
	out << sumPow(n, x);
	system("pause");
	return 0;
}
/*
Tính tổng
tính tổng theo công thức sau bằng phương pháp ĐỆ QUY:

S(n) = 1 + x + x2 + x3 + ..... + x^n

dữ liệu nhập từ file văn bản "DEQUY.inp": số n và x

dữ liệu ra file văn bản "DEQUY.out" : tổng S

input:
5 2
output
63
*/