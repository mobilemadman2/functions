#include <iostream>
#include <cmath>
#define epsilon 0.0001	// sai số, nếu số hạng bé hơn epsilon thì dừng
using namespace std;

// TÍNH GIAI THỪA
long factorial(int n) {
	if (n == 0) return 1;
	return n * factorial(n - 1);
}

// TÍNH SIN: sin(x) = x – x3/3! + x5/5! + … + (-1)n(x2n+1/(2n+1)!)
double sinn(double x, int n = 0, double result = 0) {
	double soHang = pow(-1, n)*(pow(x, 2 * n + 1) / factorial(2 * n + 1));
	if (abs(soHang) < epsilon) { return roundf(result * 100) / 100; }
	return sinn(x, n + 1, result + soHang);
}

// TÍNH COS
double coss(double x, int n = 1, double result = 0) {
	double soHang = pow(-1, n)*(pow(x, 2 * n) / factorial(2 * n));
	if (abs(soHang) < epsilon) { return roundf((result+1) * 100) / 100; }
	return coss(x, n + 1, result + soHang);
}

int main() {
	double x; cin >> x;
	cout << sinn(x) << endl << coss(x);
	system("pause");
	return 0;
}