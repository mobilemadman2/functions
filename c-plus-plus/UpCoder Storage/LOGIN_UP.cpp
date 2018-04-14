#include <iostream>
#include <string>
using namespace std;
//CHECK >> có xóa 1 số kí tự trong chuỗi b để thành chuỗi a đc hay ko
bool isAinB(string astr, string bstr) {
	int c = 0;
	//tìm từ đầu đến cuối chuỗi nhập
	for (int i = 0; i < bstr.size(); i++) {
		//nếu có từ cần tìm thì tìm chữ tiếp theo
		if (bstr[i] == astr[c]) { c++; }
	}
	if (c == astr.size()) { return true; }
	else { return false; }
}
int main() {
	string str;
	cin >> str;
	if (isAinB("upcoder", str)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
/*
Ví dụ Tèo muốn vào trang upcoder.xyz để làm bài. Sau khi gõ địa chỉ trang web,
hệ thống thông báo Tèo nhập vào một xâu ký tự.
Tèo gõ: "ahihiupcccccodeeeerrr", hệ thống sẽ xem xét xâu này và tự động loại bỏ
các chữ cái để trở thành từ "upcoder". Như vậy Tèo vào được hệ thống để làm bài.

Nhưng khi Tèo gõ: "uppdcoer", hệ thống không thể làm cách nào để xóa bớt
chữ cái để trở thành từ "upcoder" được. Như vậy Tèo không vào được hệ thống.

Nhiệm vụ của bạn là xác định xem, khi Tèo gõ một xâu, xâu đó có được chấp nhận để Tèo vào hệ thống làm bài hay không?

Input:
Một dòng chứa xâu chữ cái mà Tèo định gõ, với chiều dài từ 1 đến 100 ký tự.
Output:
Nếu Tèo được đồng ý vào hệ thống, xuất "YES", ngược lại xuất "NO" (không xuất dấu ngoặc kép).

Ví dụ:
Input:
ahihiupcccccodeeeerrr
Output:
YES
Input:
uppdcoer
Output:
NO
Input:
upxyzcccccteoder
Output:
YES
*/