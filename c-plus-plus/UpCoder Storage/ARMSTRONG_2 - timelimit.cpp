#include <iostream>
#include <cmath>
using namespace std;
int size(int num) {
	int length = 1;
	while (num /= 10) { length++; }
	return length;
}
bool isAmrstrong(int num) {
	int sum_pow = 0, len = size(num), tmp = num;
	while (tmp > 0) {
		sum_pow += pow(tmp % 10, len);
		tmp /= 10;
	}
	if (sum_pow == num) { return true; }
	else { return false; }
}
int main() {
	int a, b;
	cin >> a >> b;
	bool iidesuka = false;
	for (int i = a; i <= b; i++) {
		if (isAmrstrong(i)) { cout << i << endl; iidesuka = true; }
	}
	if (!iidesuka) { cout << -1; }
	system("pause");
	return 0;
}
/*
Một số nguyên dương có n chữ số được gọi là số Armstrong khi tổng các lũy thừa bậc n của các chữ số của nó bằng chính nó.
Ví dụ:
371 là số Armstrong vì: 3^3 + 7^3 + 1^3 = 371
8208 là số Armstrong vì: 8^4 + 2^4 + 8^4 = 8208
Hãy tìm tất cả các số Armstrong trong đoạn [A; B].

Input:
Gồm 2 số nguyên dương A, B cách nhau bởi 1 khoảng trắng (1 <= A <= B <= 10^7)
Output:
In ra tất cả các số Armstrong trong đoạn [A;B].
Xuất theo thứ tự từ nhỏ đến lớn, mỗi số cách nhau một khoảng trắng.
Nếu trong đoạn [A; B] không có số Armstrong nào thì xuất -1

Ví dụ:
Input:
30 40
Output:
-1

Input:
300 400
Output:
370 371

Input:
8000 9000
Output:
8208
*/