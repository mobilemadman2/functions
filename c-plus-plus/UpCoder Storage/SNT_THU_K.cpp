#include <iostream>
#define max 5000000
using namespace std;
bool mark[max];
void eratosthenes(int pos);
void markI(int x, int n);
int main() {
	int k; cin >> k;
	eratosthenes(k);
	system("pause");
	return 0;
}
void eratosthenes(int pos) {
	int n = max;
	// i bắt đầu từ số nguyên tố đầu tiên
	for (int i = 2; i <= n; i++) {
		// false là snt
		if (!mark[i]) {
			if (pos == 1) {
				cout << i << endl; return;
			}
			else { pos--; }
			// đánh dấu các bội của i
			markI(i, n);
		}
	}
}
void markI(int x, int n) {
	int i = 2, num;
	// bội của x => x * i với i bắt đầu từ 2
	// n là phạm vi cần sàng
	// nếu bội lớn hơn n thì dừng lại
	while ((num = i*x) <= n) {
		mark[num] = true;
		// cập nhật bội số
		i++;
	}
}
/*
Viết chương trình tìm số nguyên tố thứ k.

INPUT
Số nguyên dương k (k <= 105)

OUTPUT
Số nguyên tố thứ k

VÍ DỤ:
Input		Output
2			3
100000		1299709
25			97

Tham khảo code
https://lhchuong.wordpress.com/2015/04/13/thuat-toan-eratosthenes-toi-uu-thuat-toan-sang-so-nguyen-to/
*/