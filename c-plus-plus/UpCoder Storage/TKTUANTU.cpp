#include <iostream>
using namespace std;
int main(){
	int n, x, m;
	cin >> n >> x;
	for (int i = 0; i < n; i++){
		cin >> m;
		if (m == x){ m = i; break; }
		else m = -1;
	}
	cout << m;
	//system("pause");
	return 0;
}
/*
Input:
- Dòng 1: số n và số x cần tìm trong dãy số
- Dòng 2: Nhập vào một dãy n số nguyên

Output:
- Nếu tìm thấy xuất ra vị trí tìm thấy đầu tiên
- Ngược lại nếu không tìm thấy xuất -1

ví dụ:
input:
5 3
2 1 3 5 7

output:2

input:
5 10
2 1 3 5 7

output:-1
*/