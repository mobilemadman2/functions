#include <iostream>
#include <string>
using namespace std;
//GET >> giai thừa cua 1 số
int factorial(int num) {
	int factorial = 1;
	for (int i = 0; i < num; i++) {
		factorial *= (num - i);
	}
	return factorial;
}

void hoanVi(string chuoi) {
	int len = chuoi.size() - 1;
	int loop = factorial(chuoi.size()) / chuoi.size();
	cout << loop << " " << len << endl;
	for (int i = 1; i <= loop; i++) {
		if (i == 1) { cout << chuoi << endl; continue; }
		if (i % 2 != 0) {
			swap(chuoi[len - 1], chuoi[len - 2]);
			cout << chuoi << endl;
		}
		if (i % 2 == 0 || i == loop) {
			swap(chuoi[len - 0], chuoi[len - 1]);
			cout << chuoi << endl;
		}
	}
}
int main() {
	string chuoi = "12345";
	hoanVi(chuoi);
	system("pause");
	return 0;
}
/*
Cho một tập hợp gồm n phần tử có giá trị từ 1 đến n. Yêu cầu xuất ra các hoán vị của tập hợp này theo thứ tự tăng dần.

Dữ liệu đầu vào: số nguyên dương n (n<10)
Dữ liệu đầu ra: gồm n! dòng ghi các hoán vị theo thứ tự tăng dần, mỗi phần tử của tập hợp ngăn cách nhau bởi khoảng trắng.

Ví dụ:
Input: 3
Output:
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/