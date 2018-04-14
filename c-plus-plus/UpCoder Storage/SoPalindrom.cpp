#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//CHECK >> chuỗi đối xứng?
bool isPalindrome(string s) {
	int n = s.size();
	for (int i = 0; i < n / 2; i++)
		if (s[i] == s[n - 1 - i])
			continue;
		else {
			return false;
			break;
		}
		return true;
}

int main()
{
	ifstream in("dayso.in");
	int n;
	in >> n;
	while (n--) {
		string s;
		in >> s;
		if (isPalindrome(s)) {
			cout << s << " ";
		}
	}
	return 0;
}
/*
Một số nguyên gọi là palindrom nếu nó đọc từ trái sang cũng bằng đọc từ phải sang. Ví dụ 121 là số palindrom.
Yêu cầu:
-         Hãy xây dựng hàm kiểm tra một số có phải là palindrom hay không?
-         Viết chương trình sử dụng hàm đã viết để in ra các số palindrom.

Dữ liệu vào trong file dayso.in gồm n + 1 dòng:
-         dòng đầu ghi số n ( 0 < n < 1000 )
-         n dòng còn lại mỗi dòng ghi một số nguyên dương m (0< m <106)
Kết quả in ra mà hình các số Palindrom

Ví dụ: Tập tin dayso.in là:
4
102
121
250
9889

Kết quả xuất ra màn hình các số Palindrom là:
121   9889
*/