#include <iostream>
#include <string>
using namespace std;
void process(int n) {
	if (n == 3) { cout << "3 = 1 + 2"; return; }
	for (int i = 2; i <= n / 2; i++) {
		//nếu i lẽ và n/i là số nguyên
		if (i % 2 != 0 && n / i == n / double(i)) {
			int num = i / 2;
			cout << n << " = ";
			string p = " + ";
			for (int x = 0; x < i; x++) {
				if (x == i - 1) { p = ""; }
				cout << n / i - num << p;
				num--;
			}kh	
			return;
		}
		//nếu i chẵn và n/i dư 0.5
		if (i % 2 == 0  && n / i == n / double(i) - 0.5) {
			int num = i / 2 - 1;
			cout << n << " = ";
			string p = " + ";
			for (int x = 0; x < i; x++) {
				if (x == i - 1) { p = ""; }
				cout << n / i - num << p; 
				num--;
			}
			return;
		}
	}
	cout << "IMPOSSIBLE" << endl;
}
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		process(a);
	}
	system("pause");
	return 0;
}
/*
Cho 1 số N. Thể hiện N như là tổng của ít nhất 2 số nguyên dương liên tiếp. Ví dụ
10 = 1 + 2 + 3 + 4
24 = 7 + 8 + 9
Nếu có nhiều đáp án thì in ra đáp án có số lượng phần tử ít nhất. Nếu không có đáp án in "IMPOSSIBLE"
INPUT
Dòng đầu thể hiện T số lượng bộ test
M dòng sau mỗi dòng chứa 1 số nguyên N ( N<=10^9 )
OUTPUT
Với mỗi test xuất ra 1 dòng chứa:
N= a+(a+1)+...+b như yêu cầu đề bài.
Nếu không có đáp án in 1 dòng chứa "IMPOSSIBLE"

Ví dụ
INPUT
3
8
10
24
OUTPUT
IMPOSSIBLE
10 = 1 + 2 + 3 + 4
24 = 7 + 8 + 9
*/