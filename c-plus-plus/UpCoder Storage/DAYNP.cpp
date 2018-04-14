#include <iostream>
#include <iomanip>      // setprecision
using namespace std;
//CONVERT >> số nguyên dương thành chuỗi có thể dùng như mảng: 1234 => "1234"
string intToString(int num) {
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

//CHECK >> số chỉ chứa 0 hoặc 1
bool isBinaryNumber(int num) {
	string str = intToString(num);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != '0' && str[i] != '1') {
			return false;
		}
	}
	return true;
}

int main() {
	int n; cin >> n;
	int stop = 1;
	//sinh ra số nhị phân lớn nhất trong giới hạn n (3 -> 111; 4 -> 1111)
	for (int i = 1; i < n; i++) {
		stop = stop * 10 + 1;
	}
	//nếu là số nhị phân thì in ra màn hình theo đúng độ dài setw(n)
	//nếu thiếu thì fill vào số 0
	for (int i = 0; i <= stop; i++) {
		if (isBinaryNumber(i)) {
			cout << setfill('0') << setw(n) << i << endl;
		}
	}
	return 0;
}
/*
Xuất tất cả dãy nhị phân có độ dài là n.
input gồm 1 số tự nhiên n, n>=1
Ouput: xuất tất cả dãy số nhị phân có độ dài n, theo thứ tự tăng dần (mỗi dãy là 1 một dòng)

Ví dụ:
Input:
3
output:
000
001
010
011
100
101
110
111
*/