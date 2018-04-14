#include <iostream>
#include <fstream>
#include <queue>
#include <string>
using namespace std;

int main() {
	queue <char> qu;
	ifstream in("queue.inp");
	ofstream out("queue.out");

	string chuoi;
	cin >> chuoi;
	for (int i = 0; i < chuoi.size(); i++) {
		if (chuoi[i] != '*') {
			qu.push(chuoi[i]);
		}
		else {
			cout << qu.front();
			qu.pop();
		}
	}
	system("pause");
	return 0;
}
/*
Xuất nội dung của queue sau mỗi thao tác trong dãy.
Một chữ cái tượng trưng cho thao tác thêm chữ cái đó vào trong queue,
dấu * tượng trưng cho thao tác lấy nội dung một phần tử trong queue in lên màn hình.
Cho biết kết quả xuất ra màn hình sau khi hoàn tất chuỗi input.

input từ file queue.inp
dữ liệu ra file queue.out

Ví dụ:
input:
AB*

ouput:
A
*/