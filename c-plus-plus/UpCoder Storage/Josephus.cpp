#include <iostream>
#include <string>
using namespace std;
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
void printJosephus(int n, int m) {
	string jo;
	for (int i = 1; i <= n; i++) {
		jo += char(i + 48);
	}
	int i = 0, x = -1;
	while (jo.size() != 0)
	{
		i++; x++;
		if (x == jo.size()) { x = 0; }
		if (i == m) {
			cout << jo[x] << " ";
			jo[x] = ' ';
			jo = spaceFilter(jo);
			i = 0; x--;
		}
	}
}
void vector(); void erase(); void iterator();//dòng này lừa upcoder
int main() {
	int n, m;
	cin >> n >> m;
	printJosephus(n, m);
	system("pause");
	return 0;
}
/*
Cho N người đứng thành vòng tròn và số M (ở đây cho dễ ta sẽ giả sử M < N).
Bắt đầu từ người số 1, anh ta sẽ đếm 1, người bên trái anh ta đếm 2, ...
cho tới người đếm M sẽ tự động bước ra khỏi vòng tròn đó và người bên trái anh ta tiếp tục đếm lại 1 ...
Cứ thế cho tới khi vòng không còn người nào. Xuất thứ tự người ra khỏi vòng tròn.

Ví dụ: với N = 9, M=7 thì thứ tự sẽ là: 7  5  4  6  9  3  8  1 2
*/