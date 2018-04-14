#include <iostream>
#include <cmath>
using namespace std;
bool isPrimeNumber(int num) {
	if (num < 2) { return false; }
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num%i == 0) { return false; }
	}
	return true;
}
bool isNearPrime(int n) {
	int c = 0;
	for (int i = 2; i<n; i++) {
		if (n%i == 0 && isPrimeNumber(i)) { c++; }
		if (c>2) { return false; }
	}
	return c == 2 ? true : false;
}
void soGanNT() {
	int n; cin >> n;
	int c = 0, a[10000];
	for (int i = 1; i <= n; i++) {
		if (isNearPrime(i)) {
			a[c] = i; c++;
		}
	}
	cout << c << endl;
	for (int i = 0; i<c; i++) {
		cout << a[i] << " ";
	}
}
int main() {
	soGanNT();
	return 0;
}
/*
Số gần nguyên tố
Như ta đã biết, một số nguyên dương được gọi là số nguyên tố khi nó chỉ có hai nghiệm là 1 và chính nó.
Vậy còn số gần nguyên tố? Một số được gọi là số gần nguyên tố nếu như nó có đúng 2 ước số nguyên tố phân biệt.
Ví dụ: 6, 18, 24 là những số gần nguyên tố. Còn 9, 23 thì không phải.

Yêu cầu: Hãy đếm xem có bao nhiêu số "gần nguyên tố" trong đoạn [1;n]

Input:
Số nguyên dương n (1 <= n <= 3000)
Output:
Số nguyên x - đáp số bài toán
Dòng tiếp theo, xuất x số "gần nguyên tố" tìm được. Mỗi số cách nhau một khoảng trắng.
(Yêu cầu này đã được bổ sung so với bài tập trong Minigame#19)

Ví dụ:
Input
10
Output
2
6 10

Input
21
Output
8
6 10 12 14 15 18 20 21
*/