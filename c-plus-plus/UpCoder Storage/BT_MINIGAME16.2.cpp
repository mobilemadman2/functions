#include <iostream>
using namespace std;

int main() {
	int soBe, soQua, sttBatDau, n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> soBe >> soQua >> sttBatDau;
		int x = (sttBatDau + soQua) % soBe - 1;
		cout << (x != 0 ? x : soBe);
	}
	return 0;
}
/*
Một lớp học mẫu giáo có N bé, mỗi bé có mã số X khác nhau được đánh số từ 1 đến N. Cô giáo có M món quà dự định tặng các bé.
Cô giáo quyết định cho cả lớp xếp thành một vòng tròn (theo thứ tự tăng dần), và sau đó bắt đầu từ 1 bé ngẫu nhiên có mã số X. Cô giáo bắt đầu phát quà cho mỗi bé lần lượt đến khi hết M món quà.

Ví dụ: Bắt đầu với bé có mã số X = 5. Thì cô sẽ phát quà theo thứ tự: (5, 6, 7, 8, ..., N-1, N, 1, 2, 3, 4, 5, ...) cho đến khi món quà thứ M được phát.
Hỏi rằng, món quà cuối cùng được phát cho bé có mã số bao nhiêu?

Input:
Dòng 1: số nguyên dương T - số lượng test (1 <= T <= 100)
T dòng tiếp theo ứng với mỗi test gồm 3 số nguyên dương N, M, X. Mỗi số cách nhau một khoảng trắng. (1 <= N, M, X <= 10^9)
Output:
T dòng, mỗi dòng là 1 số nguyên chỉ mã số của bé được nhận món quà cuối cùng ở từng bộ test

Ví dụ:
Input
2
5 2 1
5 3 4
Output
2
1

Giải thích:
Ở test 1: Với 5 bé, 2 món quà. Cô giáo bắt đầu phát từ bé mã số 1 món quà đầu tiên, bé số 2 món quà thứ hai (món quà cuối cùng). Vậy đáp số là 2
Ở test 2: Với 5 bé, 3 món quà. Thứ tự mã số của các bé mà cô giáo phát quà sẽ là: 4,5,1
*/