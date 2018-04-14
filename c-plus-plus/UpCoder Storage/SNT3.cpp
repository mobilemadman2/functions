#include <iostream>
#define max 200001
using namespace std;
bool mark[max];
void eratosthenes(int a, int b);
void markI(int x, int n);
int main() {
	int a, b;
	cin >> a >> b;
	eratosthenes(a, b);
	system("pause");
	return 0;
}
void eratosthenes(int a, int b) {
	int n = max;
	// i bắt đầu từ số nguyên tố đầu tiên
	for (int i = 2; i <= n; i++) {
		// false là snt
		if (!mark[i]) {
			if (i >= a && i <= b) {
				cout << i << " ";
			}
			if (i > b) { return; }
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
Hãy tìm tất cả các số nguyên tố trong đoạn [A,B] .
Input:
Gồm 2 số nguyên A và B cách nhau bởi 1 dấu cách ( 1 ≤ A ≤ B ≤ 200000 ) .
Output:
Ghi ra tất cả các số nguyên tố trong đoạn [A,B]. Mỗi số trên 1 dòng .
Ví dụ
Input:
1 10
Output:
2
3
5
7
*/