// BRUTE FORCE (much faster but cannot calculate the combination of 10)
#include <iostream>
#include <cmath>
using namespace std;
// num có tồn tại trong mảng? (kiểm tra số không lặp) 
bool isExist(int num, int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] == num) { return true; }
	}
	return false;
}
// num là 1 hoán vị không lăp từ 1 đến n?
bool isHoanViKoLap(int num, int n) {
	int a[10], i = 0, mod;
	while (num > 0) {
		mod = num % 10;
		if (mod > n || mod == 0 || isExist(mod, a, i)) {
			return false;
		}
		else { a[i] = mod; i++; }
		num /= 10;
	}
	return true;
}
void timHoanVi(int n) {
	// tìm hoán vị đầu tiên và cuối cùng dựa theo n
	int begin[10] = { 0,1,12,123,1234,12345,123456,1234567,12345678,123456789 };
	int end[10] = { 0,1,21,321,4321,54321,654321,7654321,87654321,987654321 };
	// tìm hoán vị
	for (int i = begin[n]; i <= end[n]; i++) {
		if (isHoanViKoLap(i, n)) {
			cout << i << endl;
		}
	}
}
int main() {
	int n; cin >> n;
	timHoanVi(n);
	system("pause");
	return 0;
}
// RECURSION
#include <iostream>
using namespace std;
void hoanVi(int a[], int n) {
	// xuat mang
	for (int i = 1; i <= n; i++) {
		cout << a[i];
	}
	cout << endl;
	// duyet tu phai sang tim vi tri a[j] < a[j+1]
	int j = n - 1;
	for (; j > 0; j--) {
		if (a[j] < a[j + 1]) { break; }
	}
	// kiem tra mang da la hoan vi cuoi cung chua
	if (j == 0) { return; }
	// tim trong doan [j+1;n] phan tu k nho nhat lon hon a[j] va swap(a[j],a[k])
	int min = j + 1;
	for (int m = j + 2; m <= n; m++) {
		if (a[m] > a[j] && a[m] < a[min]) {
			min = m;
		}
	}
	int tmp = a[j];
	a[j] = a[min];
	a[min] = tmp;
	// lat nguoc doan [j+1;n]
	int r = j + 1, s = n;
	while (r < s) {
		int tmp = a[r];
		a[r] = a[s];
		a[s] = tmp;
		r++; s--;
	}
	hoanVi(a, n);
}
//GET >> giai thừa cua 1 số
int factorial(int num) {
	int factorial = 1;
	for (int i = 0; i < num; i++) {
		factorial *= (num - i);
	}
	return factorial;
}
int main() {
	int a[20], n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		a[i] = i;
	}
	cout << factorial(n);
	hoanVi(a, n);
	system("pause");
	return 0;
}
/*
Liệt kê chuỗi hoán vị
Cho n chữ số 1, 2, 3, .., n (1 ≤ n ≤ 8), hãy liệt kê tất cả các hoán vị của n chữ số trên theo thứ tự từ điển.
Dữ liệu nhập:
- Là số nguyên n (1 ≤ n ≤ 8)
Dữ liệu xuất:
- Dòng thứ nhất là số nguyên m thể hiện số lượng hoán vị có được.
- Trong m dòng tiếp theo, mỗi dòng liệt kê một hoán vị theo thứ tự từ điển. Trong một hoán vị các chữ số đứng sát nhau (không dùng khoảng trắng để ngăn cách các chữ số)

Ví dụ
input
2
output
2
12
21

input
3
output
6
123
132
213
231
312
321
*/