#include <iostream>
using namespace std;
int main() {
	int n, k, a[100000], max = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i <= n - k; i++) {
		for (int j = i; j < k + i; j++) {
			if (max >= i && max < k + i) {
				if (j<max) { j = max; }
				else if (a[j]>a[max]) { max = j; }
			}
			else { max = i; }
		}
		cout << a[max] << endl;
	}
	return 0;
}
/*
Cho một dãy gồm N (1<= N <= 10^5) số nguyên, và số nguyên dương K (1 <= K <= N).
Hãy tìm phần tử lớn nhất trong mỗi đoạn con gồm K phần tử liên tiếp nhau của dãy ban đầu.

Input:
Dòng 1: 2 số nguyên dương N, K
Dòng 2: N số nguyên A[i] là phần tử thứ i của dãy (1 <= A[i] <= 10^4)
Output:
Trên một dòng gồm nhiều phần tử, mỗi phần tử cách nhau một khoảng trắng là giá trị lớn nhất của mỗi đoạn con liên tiếp gồm K phần tử.

Ví dụ:
Input
5 2
3 4 6 3 4
Output
4 6 6 4

Giải thích:
Những đoạn con liên tiếp gồm 2 phần tử của dãy là: {3,4}, {4,6}, {6,3}, {3,4}
Và giá trị lớn nhất của từng đoạn lần lượt là: 4, 6, 6, 4

Input
7 4
3 4 5 8 1 4 10
Output
8 8 8 10

Giải thích:
Những đoạn con liên tiếp gồm 4 phần tử của dãy là: {3,4,5,8}, {4,5,8,1}, {5,8,1,4}, {8,1,4,10}
Giá trị lớn nhất của từng đoạn lần lượt là: 8, 8, 8, 10
*/