#include <iostream>
using namespace std;

int main() {
	int n, l, r, max = false, min;
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++) {
		int val;
		cin >> val;
		if (i >= l && i <= r) {
			if (!max) { max = val; min = val; }
			if (val > max) { max = val; }
			if (val < min) { min = val; }
		}
	}
	cout << min << " " << max << endl;
	system("pause");
	return 0;
}
/*
Cho một dãy số có n số nguyên dương. Hãy tìm phần tử Min và phần tử Max trong đoạn [L;R] cho trước.
Ví dụ: Với dãy số 8 phần tử sau: 10 1 5 0 9 3 15 19
Phần tử Min trong đoạn [2;7] là: 0
Phần tử Max trong đoạn [2;7] là: 15
Input:
Dòng 1: 3 số nguyên n, L, R (1 <= L <= R <= n <= 10^6)
Dòng 2: n phần tử của dãy (giá trị các phần tử không vượt quá 10^6)
Output:
2 số nguyên cách nhau 1 khoảng trắng là giá trị Min và giá trị Max trong đoạn [L;R]

Ví dụ:
Input
8 2 7
10 1 5 0 9 3 15 19
Output
0 15

Input
8 2 3
10 1 5 0 9 3 15 19
Output
1 5
*/