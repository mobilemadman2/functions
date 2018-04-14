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
	int num; cin >> num;
	cin.ignore();

	int howmany = -1, stt[100];
	for (int i = 0; i < num; i++) {
		string str;
		cin >> str;
		if (isAinB("upcoder", str)) {
			howmany++;
			stt[howmany] = i;
		}
	}
	cout << howmany + 1 << endl;
	for (int i = 0; i <= howmany; i++) {
		cout << stt[i] + 1 << " ";
	}
	system("pause");
	return 0;
}
/*
Ví dụ Tèo muốn vào trang upcoder.xyz. Sau khi gõ địa chỉ trang web,
hệ thống thông báo nhập Tèo nhập vào một xâu ký tự. Tèo gõ: "ahihiupcccccodeeeerrr",
hệ thống sẽ xem xét xâu này và tự động loại bỏ các chữ cái để trở thành từ "upcoder". Như vậy Tèo vào được hệ thống.

Tý cũng muốn vào hệ thống, nhưng Tý gõ: "uppdcoer", hệ thống không thể làm cách nào để xóa bớt
chữ cái để trở thành từ "upcoder" được. Như vậy Tý không vào được hệ thống.

Nhiệm vụ của bạn là xác định xem, trong một đợt kiểm tra có n sinh viên muốn vào hệ thống để thi,
mỗi sinh viên phải nhập một xâu, hỏi bao nhiêu sinh viên được chấp nhận để vào hệ thống làm bài.

Input:
Dòng đầu tiên là số nguyên dương n (1<= n <=500) - là số sinh viên muốn đăng nhập hệ thống.
n dòng tiếp theo, mỗi dòng là 1 xâu mà từng sinh viên sẽ nhập (độ dài mỗi xâu không quá 100 ký tự)
Output:
Dòng 1: số m là số lượng sinh viên được cho phép vào hệ thống.
Dòng 2: m số nguyên dương (mỗi số cách nhau một khoảng trắng).
Là số thứ tự các sinh viên được cho phép vào hệ thống theo thứ tự tăng dần.

Ví dụ:
Input:
5
ahihiupcccccodeeeerrr
uppdcoer
upxyzcccccteoder
abcxyz
luxubu

Output:
2
1 3

Giải thích:
Có 2 sinh viên được cho phép vào hệ thống là sinh viên thứ 1 và thứ 3.
Vì xâu của 2 sinh viên này nhập vào thỏa yêu cầu mà hệ thống xử lý.
*/