#include <iostream>
#include <cmath>
using namespace std;
//CHECK >> số nguyên tố?
bool isPrimeNumber(int num) {
	if (num < 2) { return false; }
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num%i == 0) { return false; }
	}
	return true;
}

//REVERSE >> đảo ngược số: 1234 => 4321
int reverseInt(int num) {
	//lấy chiều dài số
	int len = 1;
	int tmp = num;
	while (tmp /= 10) { len++; }
	//tính toán
	int rev = 0;
	while (num > 0)
	{
		rev = rev + (num % 10)*(int)pow(10, len - 1);
		len--;
		num /= 10;
	}
	return rev;
}

int main() {
	int a, b;
	cin >> a >> b;

	int count = 0;
	for (int i = a; i <= b; i++) {
		if (isPrimeNumber(i) && i == reverseInt(i)) {
			count++;
		}
	}
	cout << count;
	system("pause");
	return 0;
}
/*
Sở giao thông Hà Nội quyết định bán đấu giá các biển số xe đẹp để lấy tiền ủng hộ đồng bào lũ lụt miền Trung.
Một biển số xe được gọi là đẹp nếu nó là số nguyên dương T thỏa mãn các điều kiện sau:
- A ≤ T ≤ B trong đó A, B là hai số nguyên dương cho trước;
- T là một số nguyên tố;
- T là một số đối xứng (đọc T từ trái qua phải thu được kết quả giống như đọc T từ phải qua trái). Ví dụ 12321 là một số đối xứng.

Yêu cầu: Cho hai số nguyên dương A và B, hãy tìm số lượng các biển số xe đẹp.

Dữ liệu nhập:

- Là hai số nguyên A và B cách nhau một khoảng trắng (104 ≤ A < B< 105)

Dữ liệu xuất:

- Là số nguyên xác định số lượng biển số xe đẹp.

Ví dụ
input
11111 22222
output
23
*/