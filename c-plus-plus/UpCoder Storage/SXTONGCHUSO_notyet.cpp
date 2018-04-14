#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int tongChuSo(string s) {
	int tong = 0;
	for (int i = 0; i < s.length(); i++) {
		tong += s[i] - 48;
	}
	return tong;
}
bool operator < (string a, string b) {
	return
		tongChuSo(a) == tongChuSo(b) ?
		a.length() < b.length() :
		tongChuSo(a) < tongChuSo(b);

}
// QUICK SORT
template <class var>
int partition(var *a, int l, int r) {
	var key = a[r];
	int i = l - 1, j;
	for (j = l; j<r; j++)
		if (a[j] < key) {
			i++;
			var tmp = a[i]; a[i] = a[j]; a[j] = tmp;
		}
	var tmp = a[i + 1]; a[i + 1] = a[r]; a[r] = tmp;
	return i + 1;
}
template <class var>
void TailRecursiveQuicksort(var *a, int r, int l = 0) {
	r--;
	while (l<r)
	{
		int q = partition(a, l, r);
		if (q < (l + (r - l) / 2)) {
			TailRecursiveQuicksort(a, q - 1, l);
			l = q + 1;
		}
		else {
			TailRecursiveQuicksort(a, r, q + 1);
			r = q - 1;
		}
	}
}
struct ARR {
	string a[100];
	int tcs[100];	// tong chu so
	int n = 0;
	string& operator[](int i) { return a[i]; }
	bool isPrimeNumber(int num) {
		if (num < 2) { return false; }
		for (int i = 2; i <= sqrt(num); i++)
		{
			if (num%i == 0) { return false; }
		}
		return true;
	}
	void printSumPrimeList() {
		for (int i = 0; i < n; i++) {
			if (isPrimeNumber(tcs[i])) {
				cout << a[i] << " ";
			}
		}
		cout << endl;
	}
	void sortGiam() {
		TailRecursiveQuicksort(a, n);
		for (int i = n - 1; i >= 0; i--) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
};
istream& operator >> (istream& is, ARR& a) {
	is >> a[a.n];
	a.tcs[a.n] = tongChuSo(a[a.n]);
	a.n++;
	return is;
}
int main() {
	if ("15" > "123")cout << "yes";
	ARR a;
	int n; cin >> n;
	cin.ignore();
	while (cin >> a);
	a.printSumPrimeList();
	a.sortGiam();
	system("pause");
	return 0;
}
/*
Cho dãy số nguyên dương A. Hãy viết thực hiện các yêu cầu sau:
1.     Tìm và in ra các số có tổng các chữ số là giá trị nguyên tố.
2.     Sắp xếp dãy A giảm dần theo giá trị tổng các chữ số, nếu 2 số có giá trị tổng bằng nhau thì số nào có nhiều chữ số hơn sẽ xếp sau.
Ví dụ: giữa 2 số 123 và 55 thì số 55 sẽ đứng trước 123 vì tổng các chữ số trong số 55 là 10, còn tổng các chữ số trong số 123 là 6.

Ví dụ:
-       dãy A ban đầu: 12 2 15 3 13 8 5 20 43 123
-       các số thỏa điều kiện câu 1: 12 2 3 5 43
-       dãy A sau khi sắp xếp: 8 43 15 123 5 13 3 12 2 20

Input:
-       Dòng đầu tiên là số n cho biết số lượng giá trị trong dãy A
-       Dòng tiếp theo là n giá trị số nguyên dương trong dãy A, mỗi số cách nhau 1 khoảng trắng
Output:
-       Dòng đầu tiên là các số thỏa điều kiện câu 1, mỗi số cách nhau 1 khoảng trắng.
-       Dòng tiếp theo là dãy A sau khi sắp xếp theo điều kiện câu 2.
*/