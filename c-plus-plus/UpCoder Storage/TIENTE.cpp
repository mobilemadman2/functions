#include <iostream>
using namespace std;
bool mirror[100];
int n, num[100];
void xuat(bool a[]) {
	for (int i = 0; i < n; i++) {
		cout << (a[i] ? 1 : 0) << " ";
	}
	cout << endl;
}
bool allTrue(bool a[]) {
	for (int i = 0; i < n; i++) {
		if (!a[i]) { return false; }
	}
	return true;
}
void tiente(int begin = 0) {
	if (begin == n) { cout << "return" << endl; return; }
	int m = 0; bool out = true;
	while (out) {
		for (int i = begin; i < n - m && out; i++) {
			// copy
			bool tmp[100];
			for (int copy = 0; copy < n; copy++) {
				tmp[copy] = mirror[copy];
			}
			// xu li
			for (int j = 0; j <= m; j++) {
				tmp[i + j] = true;
				if (allTrue(tmp)) { out = false; break; }
			}
			// xuat
			if (out) xuat(tmp);
		}
		cout << endl;
		m++;
	}
	mirror[begin] = true;
	tiente(begin + 1);
}
int main() {
	cin >> n;
	tiente();
	system("pause");
	return 0;
}