#include <iostream>
#include <string>
using namespace std;
bool isExist(string a[], int n, string s) {
	for (int i = 0; i < n; i++) {
		if (a[i] == s) { return true; }
	}
	return false;
}
string tostr(int num) {
	string rev;
	//số thành chuỗi đảo ngược
	while (num > 0)
	{
		rev = rev + char(num % 10 + 48);
		num /= 10;
	}
	//đảo ngược chuỗi
	string res;
	for (int i = rev.size() - 1; i >= 0; i--) {
		res += rev[i];
	}
	return res;
}
int main() {
	int n = 0, t; cin >> t; cin.ignore();
	string a[100];
	for (int i = 0; i < t; i++) {
		string s; cin >> s;
		if (!isExist(a, n, s)) {
			cout << "OK" << endl;
		}
		else {
			int c = 1;
			string tmp = s;
			while (isExist(a, n, tmp)) {
				tmp = s + tostr(c);
				c++;
			}
			s = tmp;
			cout << s << endl;
		}
		a[n] = s; n++;
	}
	return 0;
}
/*
Vào đầu năm học mới, thầy giáo giới thiệu cho các sinh viên trang UPCoder - Hệ thống chấm bài tự động để làm bài tập. Thầy yêu cầu các sinh viên vào đăng ký tài khoản.
Khi đăng ký tài khoản, sinh viên sẽ chọn một tên (username) dùng để đăng nhập. Do rất nhiều sinh viên đăng ký nên việc lựa chọn username cho riêng mình đương nhiên có thể trùng nhau. Tuy nhiên điều này là không thể, vì hệ thống không cho phép tồn tại 2 username giống nhau. Do đó, hệ thống tự động nhắc sinh viên biết tình trạng username đó đã tồn tại hay chưa. Cụ thể như sau:
Khi nhập username, nếu username đó chưa được chọn trước đó, thì hệ thống sẽ phản hồi với câu thông báo "OK".
Khi nhập username mà đã tồn tại trước đó trong cơ sở dữ liệu thì hệ thống sẽ đưa ra gợi ý để lựa chọn username khác (đương nhiên sẽ cố gắng giữ lại một phần tên username của sinh viên muốn chọn). Bằng cách nối thêm số (bắt đầu từ 1) vào phía sau username bị trùng đó. (ví dụ: name1, name2, vv...)
Yêu cầu: Với n sinh viên (1<= n <=100) vào đăng ký tài khoản, hãy xác định xem những phản hồi của hệ thống với từng trường hợp

Input:
Dòng 1: Chứa số nguyên dương n
n dòng tiếp theo, mỗi dòng là một chuỗi (không có khoảng trắng, độ dài mỗi chuỗi tối đa 32 ký tự) - là username mà mỗi sinh viên dự định sẽ chọn để đăng ký.
Output:
n dòng, mỗi dòng là phản hồi của hệ thống với từng trường hợp. Nếu username đó được chấp nhận thành công thì xuất "OK" (không xuất dấu ngoặc kép). Ngược lại, hãy xuất ra tên username mới được hệ thống gợi ý.

Ví dụ:
Input
5
teonv
upcoder
teonq
upcoder
abc
Output
OK
OK
OK
upcoder1
OK
*/