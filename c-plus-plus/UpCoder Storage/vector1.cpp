#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	int n;
	while (cin >> n) {
		v.push_back(n);
	}
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++) {
		cout << *it;
	}
	for (vector<int>::reverse_iterator it = v.rbegin(); it < v.rend(); it++) {
		cout << *it;
	}
	return 0;
}
/*
Nhập vào một dãy số dùng vector.
yêu cầu dùng iterator để xuất ra màn hình
- Dòng 1 xuất theo chiều thuận (từ begin() đến end() )
- Dòng 2 xuất theo chiều ngược (từ rbegin() đến rend() )

ví dụ:
input:
1 2 3
output
1 2 3
3 2 1
*/