#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
//SORT >> sắp xếp số 32104 => 1234
int sapXepSo(int num) {
	//ngắt từng kí tự số lưu vào mảng
	int a[100], n = 0;
	while (num > 0) {
		a[n] = num % 10;
		num /= 10;
		n++;
	}
	//sắp xếp
	sort(a, a + n);
	//lưu lại thành số
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += a[i] * (int)pow(10, n - 1 - i);
	}
	return res;
}
int main() {
	int n; cin >> n;
	int a[25];	a[1] = 1;
	if (n < 25){
		for (int i = 2; i <= n; i++) {
			a[i] = sapXepSo(a[i - 1] * 2);
		}
		cout << a[n];
	}
	else{
		int b[6] = { 244445, 48889, 77789, 155578, 111356, 122227 };
		cout << b[n % 6];
	}
	system("pause");
	return 0;
}
/*
Cho một dãy số A dài vô tận. Dãy số A được xây dựng bởi quy tắc:

A[1] = 1
Với mọi i > 1, đầu tiên ta lấy A[i] = A[i – 1] * 2, sau đó sắp xếp các chữ số trong A[i] theo thứ tự tăng dần.
(Các chữ số 0 ở đầu A[i] nếu có thì coi như là không có nghĩa và có thể xóa đi).
Như vậy, các số đầu tiên trong dãy số A là: 1, 2, 4, 8, 16, 23, 46, 29, 58, …

Yêu cầu: Cho số n, bạn hãy tìm số A[n].

Input:

Số nguyên dương n (1 ≤ n ≤ 109).

Output:

Một số nguyên dương duy nhất là số thứ n trong dãy A.

Ví dụ:
Input
7
Output:
46
*/