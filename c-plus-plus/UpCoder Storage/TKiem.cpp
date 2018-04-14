#include <iostream>
using namespace std;

int main() {
	int num, x;
	cin >> num >> x;

	int data;
	for (int i = 0; i < num; i++) {
		cin >> data;
		if (data == x) {
			cout << i;
			data = false;
			break;
		}
	}
	if (data != false)cout < -1;
	return 0;
}
/*
Viết chương trình tìm kiếm phần tử trong mảng

Input:
- Dòng 1: số n và số x cần tìm trong dãy số
- Dòng 2: Nhập vào một dãy số nguyên (đã được sắp xếp tăng dần)

Output:
- Nếu tìm thấy xuất ra vị trí tìm thấy đầu tiên
- Ngược lại nếu không tìm thấy xuất -1

(lưu ý: chỉ số của dãy số được tính từ 0)

ví dụ:
input:
5 3
1 2 3 4 5

output:
2

input:
5 10
1 2 3 4 5
output:
-1
*/