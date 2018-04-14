#include <iostream>
using namespace std;

int main()
{
	int nmax, xfind, ifound = false;
	cin >> nmax >> xfind;
	for (int i = 0; i < nmax; i++) {
		int num;
		cin >> num;
		if (num == xfind) {
			cout << i;
			ifound++;
		}
	}
	if (ifound == false) {
		cout << -1;
	}

	system("pause");
	return 0;
}
/*
Input:
- Dòng 1: số n và số x cần tìm trong dãy số
- Dòng 2: Nhập vào một dãy số nguyên

Output:
- Nếu tìm thấy xuất ra tất cả vị trí tìm thấy
- Ngược lại nếu không tìm thấy xuất -1

(lưu ý: chỉ số của dãy số được tính từ 0)

ví dụ:
input:
5 3
2 1 3 5 3

output:
2 4

input:
5 10
2 1 3 5 7

output:
-1
*/