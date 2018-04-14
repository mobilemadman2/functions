#include<iostream>
using namespace std;
//CHECK >> số nguyên tố cùng nhau
bool isSNTCungNhau(int a, int b) {
	while ((a != 0) && (b != 0)) {
		if (b>a) { b = b%a; }
		else { a = a%b; }
	}
	if (b == 0) { b = a; }
	if (b == 1) { return true; }
	else { return false; }
}
int main() {
	int a, b;
	cin >> a >> b;
	if (isSNTCungNhau(a, b)) { cout << "yes"; }
	else { cout << "no"; }
	return 0;
}
/*
Input:
- 2 số nguyên N, M.

Output:
- Nếu 2 số N,M nguyên tố cùng nhau xuất "yes", ngược lại xuất "no"

Ví dụ:

input
2 3
output
yes
*/