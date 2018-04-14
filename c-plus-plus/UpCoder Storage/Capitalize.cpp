#include <iostream>
#include <string>
using namespace std;
string Capitalize(string s) {
	bool firstCha = true;
	for (int i = 0; i < s.length(); i++) {
		if (firstCha) {
			if (s[i] > 90) { s[i] -= 32; }
			firstCha = false;
		}
		else if (s[i] == ' ') {
			firstCha = true;
		}
		else if (s[i] < 97) {
			s[i] += 32;
		}
	}
	return s;
}
int main() {
	string s;
	getline(cin, s);
	cout << Capitalize(s);
	system("pause");
	return 0;
}
/*
Viết chương trình chuyển đổi chuỗi nhập sang định dạng Capitalize, tức là đổi các chữ cái đầu của mỗi từ trong chuỗi thành chữ in HOA, các chữ cái còn lại thành chữ in thường.
Input:
- Chuỗi nhập
Output:
- Chuỗi xuất đã chuyển sang định dạng Capitalize

Ví dụ:
Input:
tran minh anh
Output:
Tran Minh Anh*/