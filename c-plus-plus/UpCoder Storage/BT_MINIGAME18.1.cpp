#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, a[1000];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 1; i<n; i++) {
		if (a[i] > a[0]) { cout << a[i]; return 0; }
	}
	cout << "NO";
	return 0;
}