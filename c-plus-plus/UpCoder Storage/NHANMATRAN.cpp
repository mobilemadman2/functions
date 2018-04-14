#include <iostream>
using namespace std;

struct matrix {
	int m, n;
	double val[50][50];
};

istream& operator >> (istream& is, matrix & mat) {
	cin >> mat.m >> mat.n;
	for (int i = 0; i < mat.m; i++) {
		for (int j = 0; j < mat.n; j++) {
			is >> mat.val[i][j];
		}
	}
	return is;
}

ostream& operator << (ostream& os, matrix  mat) {
	for (int i = 0; i < mat.m; i++) {
		for (int j = 0; j < mat.n; j++) {
			os << mat.val[i][j] << " ";
		}
		os << endl;
	}
	return os;
}

matrix operator * (matrix a, matrix b) {
	matrix c;
	c.m = a.m;
	c.n = b.n;
	for (int i = 0; i < c.m; i++) {
		for (int j = 0; j < c.n; j++) {
			c.val[i][j] = 0;
			for (int z = 0; z < a.n; z++) {
				c.val[i][j] += a.val[i][z] * b.val[z][j];
			}
		}
	}
	return c;
}
int main() {
	matrix a, b;
	cin >> a >> b;
	cout << a*b;
	system("pause");
	return 0;
}
/*
Cho 2 ma trận: A kích thước M∗N và B kích thước N∗P (Đề đảm bảo rằng cột của ma trận A bằng với số hàng của ma trận B).

Yêu cầu xuất kết quả phép nhân ma trận A và B.

Input:
Dòng đầu: 2 số nguyên dương M, N cách nhau một khoảng trắng (số hàng và số cột của ma trận A)
M dòng tiếp theo, mỗi dòng là N số nguyên. Mỗi số cách nhau một khoảng trắng.
Dòng tiếp theo: 2 số nguyên dương N, P cách nhau một khoảng trắng (số hàng và số cột của ma trận B)
N dòng tiếp theo, mỗi dòng là P số nguyên. Mỗi số cách nhau một khoảng trắng.

Giới hạn: M, N, P <= 50; các phần tử của mảng đảm bảo <= 100.

Output:
Ma trận C là tích của ma trận A và ma trận B.
Ví dụ:

input
3 3
1 0 0
0 1 0
0 0 1
3 3
1 0 0
0 1 0
0 0 1
output
1 0 0
0 1 0
0 0 1
*/