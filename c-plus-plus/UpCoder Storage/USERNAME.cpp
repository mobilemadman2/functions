#include <iostream>
#include <string>
using namespace std;
bool isExistInArray(string data, string arr[], int len) {
	for (int i = 0; i < len; i++) {
		if (arr[i] == data) { return true; }
	}
	return false;
}
int main() {
	int num, flag = false; cin >> num;
	cin.ignore();
	string user[100];

	for (int i = 0; i < num; i++) {
		string in;
		getline(cin, in);
		user[i] = in;
		if (isExistInArray(in, user, i)) { cout << i + 1; flag = true; }
	}
	if (!flag) { cout << -1; }
	system("pause");
	return 0;
}
/*
Dữ liệu đầu vào:
- Số nguyên dương N (N<100)
- N dòng tiếp theo là các chuỗi Si (không có khoảng trắng) cho biết username mà sinh viên thứ i muốn đăng kí.

Dữ liệu đầu ra:
- Số thứ tự của sinh viên không đăng kí được tài khoản theo thứ tự tăng dần, ngăn cách bởi khoảng trắng. Nếu tất cả đều đăng kí được thì xuất ra -1.

Ví dụ:
Input:
5
abcd
ab
abcd
acd
ab
Ouput:
3 5
(Giải thích: người thứ 3 khai báo username trùng với người thứ 1 nên không đăng kí được, tương tự người thứ 5 trùng username với người thứ 2)

Input:
6
Messi
Ronaldo
Ronaldinho
messi
ronaldo
ronaldinho
Output:
-1
*/