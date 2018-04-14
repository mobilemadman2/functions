#include <iostream>
#include <string>
using namespace std;
//CỘNG SỐ LỚM
int stringToNum(char c)     // chuyen char sang so
{
	return c - '0';
}
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
char numToString(int n)     // chuyen so sang char
{
	return (char)(n + 48);
}

void chuanHoa(string &a, string &b) // lam 2 xau co do dai bang nhau
{
	int l1 = a.length(), l2 = b.length();
	if (l1 >= l2)
	{
		b.insert(0, l1 - l2, '0');    // chen vao dau cua b cac ky tu '0'
	}
	else
	{
		a.insert(0, l2 - l1, '0');    // chen vao dau cua a cac ky tu '0'
	}
}

string sum(string a, string b)  // tong 2 so
{
	string s = "";
	chuanHoa(a, b);      // chuan hoa
	int l = a.length();

	int temp = 0;
	for (int i = l - 1; i >= 0; i--)   // duyet va cong
	{
		temp = stringToNum(a[i]) + stringToNum(b[i]) + temp;    // tinh tong tung doi mot
		s.insert(0, 1, numToString(temp % 10));         // gan phan don vi vao
		temp = temp / 10;     // lay lai phan hang chuc
	}
	if (temp>0)  // neu hang chuc > 0 thi them vao KQ
	{
		s.insert(0, 1, numToString(temp));
	}
	return s;
}

//NHÂN SỐ LỚN
// nhan so co 1 chu so voi so co nhieu chu so (VD 4 va 7826), lam tuong tu nhu phep cong
string nhanNho(char a, string b)
{
	string s = "";
	int temp = 0;
	for (int i = b.length() - 1; i >= 0; i--)
	{
		temp = stringToNum(a) * stringToNum(b[i]) + temp;
		s.insert(0, 1, numToString(temp % 10));
		temp = temp / 10;
	}

	if (temp>0)
	{
		s.insert(0, 1, numToString(temp));
	}
	return s;
}

string nhan(string a, string b)     // nhan 2 so lon
{
	string s = "";
	int l = a.length();
	string s1[1000];

	for (int i = l - 1; i >= 0; i--)   // nhan tung chu so cua a voi b sau do cong don vao
	{
		s1[i] = nhanNho(a[i], b);   // nhan tung so cua a voi b
		s1[i].insert(s1[i].length(), l - i - 1, '0');
		s = sum(s, s1[i]);  // cong don theo cach cong so lon
	}
	return s;
}
//GET >> giai thừa cua 1 số
string factorial(int num) {
	string factorial = "1";
	for (int i = 0; i < num; i++) {
		factorial = nhan(factorial, intToString(num - i));
	}
	return factorial;
}
// COUNT >> đếm số từ khác nhau trong chuỗi
int countWord(string s) {
	string word[100], tmp = "";
	int n = 0;
	for (int i = 0; i <= s.length(); i++) {
		if (i == s.length() && tmp.length() > 0 || tmp.length() > 0 && s[i] == ' ') {
			cout << tmp << " "; word[n] = tmp; n++; tmp = "";
		}
		else { tmp += s[i]; }
	}
	int j = 1;
	for (; j < n; j++) {
		if (s[j] != s[0]) { return n; }
	}
	return 1;
}
int main() {
	string s;
	getline(cin, s);
	cout << factorial(countWord(s));
	system("pause");
	return 0;
}