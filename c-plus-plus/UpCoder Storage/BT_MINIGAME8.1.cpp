#include <iostream>
using namespace std;

int main() {
	int sugar, milk, tea;
	cin >> sugar >> milk >> tea;

	int litre = 0;
	while (sugar > 0) {
		if (sugar * 2 <= milk && sugar * 4 <= tea) {
			litre = sugar * 7; break;
		}
		else { sugar--; }
	}
	cout << litre;
	system("pause");
	return 0;
}
/*
Input:
Dòng 1: số nguyên dương a (a <= 1000) - số lít đường.
Dòng 2: số nguyên dương b (b <= 1000) - số lít sữa.
Dòng 3: số nguyên dương c (c <= 1000) - số lít trà.
Output:
Số nguyên dương duy nhất - tổng số lít cả 3 loại nguyên liệu mà Tèo dùng. Nếu không pha được bình trà sữa nào với số nguyên liệu sẵn có thì xuất "0" (không xuất dấu ngoặc kép).
Ví dụ:
Input
2
5
7
Output
7
Giải thích: Tèo dùng 1 lít đường, 2 lít sữa, 4 lít trà. Tổng cộng là 7 lít.

Input
2
3
2
Output
0
Giải thích: Tèo không thể pha được bình trà sữa nào với số nguyên liệu hiện có.
*/