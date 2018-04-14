#include <iostream>
using namespace std;
long n, a[1000000], b[1000000], sum = 0;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		sum += a[i];
		b[i] = sum / (i + 1);
	}
	for (int i = 0; i < n; i++) {
		cout << b[i] << " ";
	}
	system("pause");
	return 0;
}
/*
Cho trước một dãy số nguyên A có n phần tử (n <= 10^6)
Dãy số nguyên B gọi là dãy trung bình cộng của dãy số A khi phần tử B[i] là
trung bình cộng của các phần tử từ A[0] đến A[i]. (Chỉ lấy phần nguyên của phép chia trung bình cộng).

Hãy tính và xuất ra các phần tử của dãy B

Input:
Dòng 1: số nguyên dương n (n<=10^6)
Dòng 2: gồm n phần tử của dãy A. Giá trị tuyệt đối của mỗi phần tử không vượt quá 10^9
Output:
Dãy số B. Mỗi số cách nhau một khoảng trắng.

Ví dụ:
Input
5
1 3 6 8 7
Output
1 2 3 4 5
*/