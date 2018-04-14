#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	double a, b, c, delta, x1, x2, tmp;
	cin >> a >> b >> c;
	delta = b*b - 4 * a*c;
	if (a == 0) {
		if (b == 0) { c != 0 ? cout << 0 : cout << -1; }
		else {
			x1 = (-1 * c) / b;
			x1 == 0 ? cout << 1 << endl << "0.0000000000"
				: cout << 1 << fixed << setprecision(10) << x1;
		}
	}
	if (a != 0) {
		if (delta < 0) { cout << 0; }
		else if (delta == 0) {
			x1 = -1 * b / (2 * a);
			x1 == 0 ? cout << 1 << endl << "0.0000000000"
				: cout << 1 << fixed << setprecision(10) << x1;
		}
		else {
			x1 = (-1 * b - sqrt(delta)) / (2 * a);
			x2 = (-1 * b + sqrt(delta)) / (2 * a);
			if (x1 > x2) { swap(x1, x2); }
			if (x1 == 0 && x2 > 0) {
				cout << 2 << endl << "0.0000000000";
				cout << fixed << setprecision(10) << x2;
			}
			else if (x1<0 && x2 == 0) {
				cout << 2 << fixed << setprecision(10) << x1;
				cout << endl << "0.0000000000";
			}
			else { cout << 2 << fixed << setprecision(10) << x1 << x2; }
		}
	}
	return 0;
}
/*
Cho phương trình bậc hai: Ax2 + Bx + C = 0

Yêu cầu: Xác định xem phương trình trên có bao nhiêu nghiệm và xuất các nghiệm đó theo thứ tự tăng dần.

Input:
3 số nguyên A, B, C (-105 <= A, B, C <= 105). Lưu ý: Các hệ số có thể bằng 0
Output:
Dòng đầu tiên:
Nếu phương trình có vô số nghiệm thì xuất -1
Nếu phương trình vô nghiệm thì xuất 0
Ngược lại: Xuất số nghiệm của phương trình. Các dòng tiếp theo xuất các nghiệm của phương trình theo thứ tự tăng dần.
Lưu ý: Xuất "chính xác" nghiệm của phương trình với 10 chữ số thập phân sau dấu phẩy.
Bài này hệ thống có "cờ" chấm theo định dạng chính xác của output. Thiếu một số "0" cũng là sai kết quả.

Ví dụ:
Input
1 -5 6
Output
2
2.0000000000
3.0000000000

Input
0 -2 0
Output
1
0.0000000000
*/