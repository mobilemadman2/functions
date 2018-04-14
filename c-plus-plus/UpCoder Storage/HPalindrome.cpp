#include <iostream>
#include <string>
#include <fstream>

using namespace std;
void xoaKhoangTrang(string &s){
	for (int i = 0; i < s.length(); i++){
		if (s[i] == ' '){
			s.erase(i, 1);
			i--;
		}
	}
}
bool doiXung(string s){
	int n = s.size();
	for (int i = 0; i < n / 2; i++){
		if (s[i] == s[n - 1 - i])
			continue;
		else
			return 0;
	}
	return 1;
}
void chuyenHoaThuong(string &s){
	int n = s.size();
	for (int i = 0; i < n; i++)
	if ('A' <= s[i] && s[i] <= 'Z')
		s[i] += 32;
}
int main(){
	ifstream in;
	string str;
	in.open("input.txt");
	ofstream out("output.txt");
	while (getline(in, str)){
		xoaKhoangTrang(str);
		chuyenHoaThuong(str);
		doiXung(str) ? out << 1 : out << 0;
	}
	in.close();
	out.close();
	//system("pause");
	return 0;
}
/*
Một chuỗi kí tự được gọi là Palindrome nếu ta đọc chuỗi đó từ bên trái cũng giống như ta đọc từ bên phải. 
Hãy viết chương trình kiểm tra chuỗi kí tự nhập từ tập tin “input.txt” theo cấu trúc:
-	Mỗi dòng là một chuỗi kí tự cần kiểm tra.
Xét các chuỗi kí tự đã cho, chuyển chuỗi sang chữ toàn thường, loại bỏ khoảng trắng (nếu có), 
sau đó xét nếu chuỗi đó là Palindrome thì xuất 1, ngược lại thì xuất 0. 
Dữ liệu xuất được ghi vào tập tin “output.txt”

Ví dụ:
input.txt
MADAM
Too bad I hid a boot
Tell ballet

output.txt
1
1
0
*/