#include <iostream>
using namespace std;
bool isPrimeNumber(int num) {
	if (num <= 10) { return false; }
	if (num < 2) { return false; }
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num%i == 0) { return false; }
	}
	return true;
}
bool isOK(int n) {
	if (n % 3 != 0 && n % 4 != 0 && n % 6 != 0 && n % 7 != 0 && n % 8 != 0 && n % 9 != 0) {
		return true;
	}
}
int main() {
	int n, count = 1, phase = 1;
	cin >> n;
	for (int i = 1; i <= n;) {
		if (isPrimeNumber(i)) { count++; }
		switch (phase)
		{
		case 1:i += 2; phase = 3; break;
		case 3:i += 4; phase = 7; break;
		case 7:i += 2; phase = 9; break;
		case 9:i += 2; phase = 1; break;
		}
	}
	cout << count;

	system("pause");
	return 0;
}
/*
Hãy tìm số lượng các số từ 1 đến n mà không chia hết cho bất kỳ số nào từ 2 đến 10
Input
1 dòng chứa 1 số n ( 1<=n<=10^18 )

Output:
Số lượng số không chia hết cho bất kỳ số nào từ 2 đến 10

Example
Input
12
Output
2
Giải thích : có 2 số thỏa mãn yêu cầu đề bài là 1 và 11 .*/