#include <iostream>
#include <string>
using namespace std;

//FILTER >> xóa khoảng trắng
string spaceFilter(string s) {
	string new_s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ' ') {
			new_s += s[i];
		}
	}
	return new_s;
}

//CHECK >> chuỗi đối xứng?
bool isPalindrome(string s) {
	int foot = s.size() - 1;
	int head = 0;
	while (head <= foot) {
		if (s[head] != s[foot]) { return false; }
		head++;
		foot--;
	}
	return true;
}

//CONVERT >> chuyển sang chữ thường
string toLowerCase(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 65 && s[i] <= 90) {
			s[i] = s[i] + 32;
		}
	}
	return s;
}

int main() {
	int num;
	cin >> num;
	cin.ignore();
	for (int i = 1; i <= num; i++) {
		string str;
		getline(cin, str);
		if (isPalindrome(spaceFilter(toLowerCase(str)))) {
			cout << 1;
		}
		else { cout << 0; }
	}
	return 0;
}
/*
Xuất nội dung của queue sau mỗi thao tác trong dãy.
Một chữ cái tượng trưng cho thao tác thêm chữ cái đó vào trong queue,
dấu * tượng trưng cho thao tác lấy nội dung một phần tử trong queue in lên màn hình.
Cho biết kết quả xuất ra màn hình sau khi hoàn tất chuỗi input.

input từ file queue.inp
dữ liệu ra file queue.out

Ví dụ:
input:
AB*

ouput:
A
*/