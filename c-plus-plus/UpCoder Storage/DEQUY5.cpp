#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
//GET >> giai thừa cua 1 số
long long factorial(int num) {
	long long factorial = 1;
	for (int i = 0; i < num; i++) {
		factorial *= (num - i);
	}
	return factorial;
}
double sumPow(int n, int x, double sum = 0, int p = 1) {
	if (p > 2 * n + 1) { return sum + 1; }
	else { sum += (pow(x, p)) / factorial(p); }
	cout << sum << endl;
	return sumPow(n, x, sum, p + 2);
}
int main() {
	int n, x;
	ifstream in("TONG.inp");
	in >> n >> x;
	ofstream out("TONG.out");
	out << roundf(sumPow(n, x) * 1000) / 1000;
	system("pause");
	return 0;
}
/*
Tính tổng 2
sử dụng phương pháp ĐỆ QUY tính tổng sau :

S(n) = 1 + x + x3/3! + x5/5! + .... + x2n+1/(2n+1)!

Dữ liệu nhập từ file văn bản "TONG.inp": chứa n và x (0

Dữ liệu ra file văn bản "TONG.out" : Tổng S (làm tròn tới 3 chữ số thập phân)

Lưu ý : dùng hàm roundf(n * 1000) / 1000 để làm tròn n tới 3 chữ số thập phân

input :
5 2
output:
4.627
*/