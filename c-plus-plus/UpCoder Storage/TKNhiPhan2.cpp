#include <iostream>
using namespace std;
int main()
{
	int so_luong, gia_tri, num, flag = true;
	cin >> so_luong >> gia_tri;

	for (int i = 0; i < so_luong; i++)
	{
		cin >> num;
		if (num == gia_tri) {
			flag = false;
			cout << i;
		}
	}
	if (flag) { cout << -1; }
	return 0;
}
/*
Viết chương trình tìm kiếm nhị phân

Input:
- Dòng 1: số n và số x cần tìm trong dãy số
- Dòng 2: Nhập vào một dãy số nguyên (đã được sắp xếp tăng dần)

Output:
- Nếu tìm thấy xuất ra tất cả vị trí tìm thấy phần tử x
- Ngược lại nếu không tìm thấy xuất -1

(lưu ý: chỉ số của dãy số được tính từ 0)

ví dụ:
input:
5 3
1 2 3 3 4

output:
2 3

input:
5 10
1 2 3 4 5
output:
-1
*/