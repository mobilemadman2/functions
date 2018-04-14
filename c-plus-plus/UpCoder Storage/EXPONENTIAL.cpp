#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//CONVERT >> chuỗi thành số
int tonum(string str) {
	int result = 0;
	for (size_t i = 0; i < str.size(); i++) {
		result = result * 10 + str[i] - 48;
	}
	return result;
}
//CONVERT >> số nguyên dương thành chuỗi có thể dùng như mảng: 1234 => "1234"
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
void baseEndIn1(string a, string n) {
	cout << (a[a.size() - 2] - 48) * (n[n.size() - 1] - 48) % 10 << 1 << endl;
}
int main() {
	string a, n;
	cin >> a >> n;
	if (a[a.size() - 1] == '1') {
		baseEndIn1(a, n);
	}
	if (a[a.size() - 1] == '5') {
		if ((a[a.size() - 2] - 48) % 2 == 0) {
			cout << 25;
		}
		else {
			if ((n[n.size() - 1] - 48) % 2 == 0) {
				cout << 25;
			}
			else { cout << 75; }
		}
	}
	system("pause");
	return 0;
}
/*
Cho hai số nguyên không âm a và n, hãy xuất ra hai chữ số cuối cùng của phép tính a^n.

Dữ liệu đầu vào: hai số a và n (0<=a,n<10^18).
Dữ liệu đầu ra: hai chữ số cuối cùng của a^n.

Ví dụ:
Input: 3 2
Output: 09

Input: 32 4
Ouput: 76
http://totalgadha.com/mod/forum/discuss.php?d=4405
https://www.misbbocconi.com/blog/knowledge/guest-article/cat-prep-series-how-to-find-out-last-two-digits-of-a-number/
http://gmatclub.com/forum/how-to-find-last-two-digits-of-a-number-145162.html
*/