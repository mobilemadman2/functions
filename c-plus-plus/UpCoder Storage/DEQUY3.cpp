// BRUTE FORCE IMPROVE
#include <iostream>
#include <cmath>
using namespace std;
// num có tồn tại trong mảng?
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
int main() {
	// tìm hoán vị đầu tiên và cuối cùng dựa theo n, k
	int begin[10] = { 0,1,12,123,1234,12345,123456,1234567,12345678,123456789 };
	int lim[10] = { 0,1,21,321,4321,54321,654321,7654321,87654321,987654321 };
	int k, n, end;
	cin >> k >> n;
	end = lim[n] / pow(10, n - k);

	// tìm và lưu hoán vị
	int hv[1000], soHv = 0;
	for (int i = begin[k]; i <= end; i++) {
		if (isHoanViKoLap(i, n)) {
			hv[soHv] = i; soHv++;
		}
	}

	// xuất hoán vị tìm được
	for (int i = 0; i < soHv; i++) {
		cout << hv[i] << endl;
	}
	system("pause");
	return 0;
}
// USING RECURSION
#include <iostream>
#include <string>
using namespace std;
struct HoanVi {
	string s[1000];
	int n = 0;
	string& operator[](int i) {
		return s[i];
	}
};
void nhapHv(string s, HoanVi &hv) {
	for (int i = 0; i < hv.n; i++) {
		if (hv[i] == s) { return; }
	}
	hv[hv.n] = s; hv.n++;
}
void hoanVi(int a[], int n, HoanVi& hv, int k) {
	// luu hoan vi
	string stmp = "";
	for (int i = 1; i <= k; i++) {
		stmp += char(a[i] + 47);
	}
	nhapHv(stmp, hv);
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
	hoanVi(a, n, hv, k);
}
int main() {
	HoanVi hv;
	int k, n, a[10] = { 1,2,3,4,5,6,7,8,9 };
	cin >> k >> n;
	hoanVi(a, n, hv, k);
	for (int i = 0; i < hv.n; i++) {
		cout << hv[i] << endl;
	}
	system("pause");
	return 0;
}
/*
liệt kê chỉnh hợp không lặp chập k của tập n phần tử S = {1, 2, 3, 4, ..... , n }
Dữ liệu nhập:
- Gồm hai số nguyên k và n cách nhau 1 khoảng trắng (1 ≤ k ≤ n ≤ 9)
Dữ liệu xuất:
mỗi dòng là một chỉnh hợp chập k

input:
2 3
output:
12
13
21
23
31
32
*/