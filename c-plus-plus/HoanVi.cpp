#include <iostream>
using namespace std;
void hoanVi(int a[], int n, int h = 1) {
	// xuat mang
	cout << "Hoan vi thu " << h << " la: ";
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
	hoanVi(a, n, h + 1);
}
int main() {
	int a[20], n = 5;
	for (int i = 1; i <= n; i++) {
		a[i] = i;
	}
	hoanVi(a, n);
	system("pause");
	return 0;
}