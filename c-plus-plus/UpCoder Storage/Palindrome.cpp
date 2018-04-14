#include<iostream>
#include<string>
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

//CHECK >> chuỗi a có trong mảng b hay ko?
bool isStringAinArrayB(string a, string b[], int blen) {
	for (int i = 0; i < blen; i++) {
		if (a == b[i]) {
			return true;
		}
	}
	return false;
}
//COUNT >> số chuỗi palindrome trong 1 chuỗi
int countPalindrome(string str) {
	//lưu các chuỗi palindrome
	string palin[100];
	//đếm số chuỗi palindrome
	int count = 0;
	//số kí tự sẽ lấy để so sánh
	int chara = 1;
	//lưu số kí tự vào biến tạm
	string tmp;
	//tăng số kí tự đến khi bằng tối đa thì dừng
	while (chara <= str.size())
	{
		//lặp đến hết chuỗi
		for (size_t i = 0; i < str.size(); i++) {
			//lặp lấy số kí tự từ vị trí i
			tmp = str.substr(i, chara);
			//nếu là palindrome và chưa có trong chuỗi palin thì add vào palin
			if (isPalindrome(tmp) && !isStringAinArrayB(tmp, palin, count)) {
				palin[count] = tmp;
				count++;
			}
			//clear tmp để chút nữa lưu chuỗi mới
			tmp.clear();
		}
		chara++;
	}
	return count;
}
int main()
{
	string str;
	cin >> str;
	cout << countPalindrome(str) << endl;
	system("pause");
	return 0;
}
/*
Một chuỗi được gọi là Palindrome khi nó đều giống nhau nếu đọc xuôi hay đọc ngược.

Ví dụ:
Những chuỗi sau là palindrome: "racecar", "abba", "x"
Những chuỗi sau không là palindrome: "abc", "racecars", "xy".
Cho trước một chuỗi S, nhiệm vụ của bạn là tìm số lượng chuỗi con palindrome riêng biệt của S.

Dữ liệu vào:

- Chuỗi không rỗng, không quá 100 kí tự
Dữ liệu ra:

Số lượng chuỗi con palindrome riêng biệt của S
Ví dụ:

input
banana		anana a n ana nan
output
6
Giải thích: các palindrome riêng biệt của S:  a, b, n, ana, nan, anana.
*/