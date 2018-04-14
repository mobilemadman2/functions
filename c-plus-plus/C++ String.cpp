#include <iostream>
#include <algorithm>	
#include <string>		//replace
#include <fstream>

//FIND >> tìm số chuỗi a trong chuỗi b (aba trong ababa => 2)
int countStringAinB(string a, string b){
	int counter = 0, position = 0;
	while (true)
	{
		position = b.find(a, position);
		if (position != -1)
		{
			counter++;
			position++;
		}
		else break;
	}
	return counter;
}

//CONVERT >> số nguyên dương thành chuỗi có thể dùng như mảng: 1234 => "1234"
string tostr(int num){
	string rev;
	//số thành chuỗi đảo ngược
	while (num > 0)
	{
		rev = rev + char(num % 10 + 48);
		num /= 10;
	}
	//đảo ngược chuỗi
	string res;
	for (int i = rev.size() - 1; i >= 0; i--){
		res += rev[i];
	}
	return res;
}

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

// FILTER >> viết hoa kí tự đầu của từ (bui mINH PHUC => Bui Minh Phuc)
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

//CHECK >> chuỗi đối xứng?
bool isPalindrome(string str) {
	//#include <algorithm>
	string rev = str;
	reverse(rev.begin(), rev.end());
	if (str == rev) { return true; }
	else { return false; }
}
//GET >> tạo chuỗi palindrome từ chuỗi gốc
string makePalindrome1(string str) {
	if (isPalindrome(str)) {
		return str;
	}
	else {
		string tmp;
		for (int i = 0; i < str.size(); i++) {
			tmp = str[i] + tmp;
			if (isPalindrome(str + tmp)) {
				return str + tmp;
			}
		}
	}
}
//GET >> tạo chuỗi palindrome từ chuỗi gốc ----------- FASTERRRRRR
string makePalindrome(string str) {
	int k = 0;
	string p;
	for (int i = 1; i <= str.size(); i++)
	{
		//lấy chuỗi ngươc
		p = p + str[str.size() - i];
		//nếu đối xứng với chuỗi gốc thì lưu số kí tự
		if (p == str.substr(str.size() - i, i)) { k = i; }
	}
	for (int i = str.size() - k; i > 0; i--)
	{
		str += str[i - 1];
	}
	return str;
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

//REVERSE >> đảo ngược chuỗi
string reverseString(string str){
	string result = "";
	for (int i = str.size() - 1; i >= 0; i--){
		result += str[i];
	}
	return result;
}

// REVERSE >> -0012300 = -321
string reverse(string s) {
	int i = (s[0] == '-' ? 1 : 0);
	for (; i < s.length(); i++) {
		if (s[i] != '0') { break; }
	}
	int j;
	for (j = s.length() - 1; j > i; j--) {
		if (s[j] != '0') { break; }
	}
	string kq;
	while (j >= i) {
		kq += s[j]; j--;
	}
	return s[0] == '-' ? '-' + kq : kq;
}

//REPLACE >> thay một chuỗi con a bằng chuỗi con b trong chuỗi gốc
string thayTheKiTu(string chuoiGoc, string thay, string bang){
	int found;
	for (size_t i = 0; i < chuoiGoc.length(); i++){
		found = chuoiGoc.find(thay);
		if (found == -1)break;
		else chuoiGoc.replace(found, 1, bang);
	}
	return chuoiGoc;
}

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

//replace(bat dau, so ki tu bi thay the, chuoi thay the)
str.replace(9, 5, str2);          // "this is an example string." (1)
str.replace(8, 10, "just a");     // "this is just a phrase."     (3)

//erace(bat dau, ket thuc); neu ko co tham so ket thuc thi tu hieu la 1 ki tu

/*doan nay de nhap chuoi co khoang trang*/
cin.ignore();//them dong neu tren doan nay co nhap so
string str;
getline(cin, s);

// LẤY TỪNG PHẦN TỬ CỦA CHUỖI PHÂN CÁCH BỞI KHOẢNG TRẮNG
void stringFilter(string s) {
	string ptu[100], tmp = "";
	int n = 0;
	for (int i = 0; i <= s.length(); i++) {
		if (i == s.length() && tmp.length() > 0 || tmp.length() > 0 && s[i] == ' ') {
			ptu[n] = tmp; n++; tmp = "";
		}
		else if (s[i] != ' ') { tmp += s[i]; }
	}
	cout << n << endl;
}