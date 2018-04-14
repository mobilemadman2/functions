#include <iostream>
using namespace std;
int sumOfInt(int num) {
	int tong = 0;
	while (num > 0) {
		tong += num % 10;
		num /= 10;
	}
	return tong;
}
void lastNumber() {
	int n;
	cin >> n;
	while (n>10) {
		n = sumOfInt(n);
	}
	cout << n;
}
int main() {
	lastNumber();
	return 0;
}
/*
Một LASTNUM được xác định là tổng các chữ số của số đó, sau đó lại tiếp tục tính tổng các chữ số của số mới tạo ra cho đến khi chỉ còn 1 chữ số duy nhất.
Nhờ bạn hãy giúp tìm ra số cuối cùng đó nhé!
Yêu cầu: Cho số N, bạn hãy tìm LASTNUM của số đó.
Dữ liệu nhập:
Gồm 1 số nguyên N duy nhất (1 ≤ N ≤ 101000000).
Dữ liệu xuất:
Gồm 1 số nguyên duy nhất là LASTNUM tìm được.
Ví dụ
input
79
output
7
Các số được tạo ra lần lượt là 79 ➔ 16 ➔  7

Lưu ý: Bài này sự dụng nhập xuất chuẩn (từ bàn phím).
*/