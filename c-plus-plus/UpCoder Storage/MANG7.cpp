#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;

	int count = n;
	for (int i = 0; i < n*n; i++) {
		int num; cin >> num;
		if (count == n) { cout << num << endl; count = 0; }
		else { count++; }
	}
	system("pause");
	return 0;
}
/*
Input: cho ma trận NxN được nhập như sau:
- Dòng 1: gồm 1 số nguyên N
- Dòng 2: gồm N dòng, mỗi dòng gồm N số nguyên (cách nhau 1 khoảng trắng)

Output: xuất các phần tử đường chéo chính của ma trận NxN

Ví dụ:

input
3
1 2 3	n*n-n*n
4 5 6	n*n/2
7 8 9	n*n
output
1 5 9
*/