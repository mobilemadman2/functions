#include <iostream>
using namespace std;
int main() {
	int num, c = 0;
	while (cin >> num) {
		if (cin.get() == '\n') {
			cout << c; c = 0;
		}
		c++;
	}
	cout << c;
	system("pause");
	return 0;
}