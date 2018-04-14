#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isExistInArray(int data, int arr[], int len) {
	for (int i = 0; i < len; i++) {
		if (arr[i] == data) { return true; }
	}
	return false;
}
//FIND >> tìm số chuỗi a trong chuỗi b (aba trong ababa => 2)
int countStringAinB(char a, string b) {
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
void xuatMang(int mang[], int mLen, string str) {
	for (int i = 0; i < mLen; i++) {
		cout << char(mang[i]) << ":" << countStringAinB(char(mang[i]), str) << endl;
	}
}
int main() {
	string str;
	getline(cin, str);
	int cha[100], sl = 0;
	for (int i = 0; i < str.size(); i += 2) {
		if (!isExistInArray(int(str[i]), cha, sl)) {
			cha[sl] = int(str[i]);
			sl++;
		}
	}
	sort(cha, cha + sl);
	xuatMang(cha, sl, str);
	system("pause");
	return 0;
}
/*
Input:
- Gồm nhiều ký tự (mỗi ký tự cách nhau 1 khoảng trắng)
(chỉ tính các ký tự từ 'a' đến 'z', không tính khoảng trắng)

Output:
- Xuất số lượng các ký tự ra màn hình (xuất theo thứ tự từ nhỏ đến lớn - xem ví dụ để hiểu rõ hơn)

Ví dụ:

input
b a n a n a
output
a:3
b:1
n:2
Giải thích:
ký tự 'a' xuất hiện 3 lần
ký tự 'b' xuất hiện 1 lần
ký tự 'n' xuất hiện 2 lần
*/