#include <iostream>
using namespace std;
int d = 0;
int n;
int x[100], a[100], b[100], c[100];
int cou = 0;
void start() {
	cin >> n;
	for (int i = 1; i <= n; i++) a[i] = 1;
	for (int i = 2; i <= 2 * n; i++) b[i] = 1;
	for (int i = 1 - n; i <= n - 1; i++) c[i] = 1;
}
void prin() {
	cout << d + 1;
	for (int i = 1; i <= n; i++)
		cout << i << " " << x[i];
	cout << "n" << endl;
	d++;
}
void Try(int i) {
	int  j;
	for (j = 1; j <= n; j++) {
		if (a[j] == 1 && b[i + j] == 1 && c[i - j] == 1) {
			x[i] = j;
			if (i != n) {
				a[j] = 0;
				b[i + j] = 0;
				c[i - j] = 0;
				Try(i + 1);
				a[j] = 1;
				b[i + j] = 1;
				c[i - j] = 1;
			}
			else {
				//prin();
				cou++;
			}
		}
	}
}
int main() {
	start();
	Try(1);
	cout << cou;
	system("pause");
	return 0;
}
/*
http://thienduongit.com/threads/thuat-toan-de-quy-bai-toan-xep-hau-trong-c.751/
https://vi.wikipedia.org/wiki/B%C3%A0i_to%C3%A1n_t%C3%A1m_qu%C3%A2n_h%E1%BA%ADu
*/