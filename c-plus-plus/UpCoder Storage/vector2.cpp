#include <iostream>
#include <vector>
#include <string>
using namespace std;
int toInt(string str) {
	int result = 0, i = 0, am = 1;
	if (str[0] == '-') { i = 1; am = -1; }
	for (; i < str.size(); i++) {
		result = result * 10 + str[i] - 48;
	}
	return result*am;
}
int main() {
	// nhập kiểu thao tác
	string s;
	getline(cin, s);
	// nhập vector
	vector<int> v;
	int n;
	while (cin >> n) {
		v.push_back(n);
	}
	// thực hiện
	int space = s.find(" ");
	if (s == "-1") { v.clear(); cout << "empty"; return 0; }
	else if (space > -1) {
		string a, b;
		a = s.substr(0, space);
		b = s.substr(space + 1, s.length());
		v.erase(v.begin() + toInt(a), v.begin() + toInt(a) + toInt(b) - 1);
	}
	else { v.erase(v.begin() + toInt(s)); }

	for (vector<int>::iterator it = v.begin(); it < v.end(); it++) {
		cout << *it;
	}
	system("pause");
	return 0;
}
/*
(yêu cầu dùng vector để làm bài này)

Nhập:

Dòng 1: nhập vị trí cần xóa hoặc đoạn cần xóa [a,b), hoặc nếu là -1 thì xóa hết dãy
Dòng 2: nhập vào 1 dãy số

Xuất:
mảng sau khi xóa, nếu dãy rỗng xuất ra chữ "empty"

ví dụ 1:
input:
2
1 2 3 4

output:
1 2 4

ví dụ 2:
input:
1 3
1 2 3 4

output:
1 4
*/