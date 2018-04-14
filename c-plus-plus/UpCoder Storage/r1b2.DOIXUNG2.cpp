#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string str;
bool isPalindrome(int head, int foot) {
	while (head <= foot) {
		if (str[head] != str[foot]) { return false; }
		head++;	foot--;
	}
	return true;
}

int main() {
	ifstream in("chuoi.inp");
	in >> str;
	in.close();

	int max = 1;
	int len = str.size();
	for (int head = 0; head < len - 1; head++) {
		for (int foot = head + 1; foot < len; foot++) {
			if (str[head] == str[foot]) {
				if (isPalindrome(head, foot) && foot - head + 1 > max) {
					max = foot - head + 1;
				}
			}
		}
	}

	ofstream out("chuoi.out");
	if (str.empty()) { out << 0; }
	else { out << max; }
	out.close();

	return 0;
}
/*
Một chuỗi được gọi là đối xứng nếu nó không có ít hơn một ký tự và nếu ta đọc từ trái sang phải hay từ phải sang trái đều giống nhau.

Ví dụ :       ‘A’ ; ‘TET’ ; ‘CAOOAC’ là chuỗi đối xứng

‘BHABHCD’ là chuỗi không đối xứng

Viết chương trình nhập vào chuỗi ký tự cho trước S có chiều dài n (1<=n<=20000) và cho biết chiều dài chuỗi con đối xứng dài nhất.
Chuỗi con của S là chuỗi gồm 1 số ký tự liên tiếp nhau trong S có độ dài nhỏ hơn hoặc bằng n.

Dữ liệu vào  được cho trong tập tin văn bản chuoi.inp gồm 1 dòng  :

-          Dòng sau gồm các ký tự liên tiếp gồm các chữ cái in hoa (A → Z)

Dữ liệu ra : Ghi vào tập tin văn bản  chuoi.out gồm 1 số duy nhất là độ dài của chuỗi con đối xứng dài nhất.

Ví dụ 1 :

chuoi.inp				chuoi.out
IKACOBEGIGEBOCAHTM		13
*/