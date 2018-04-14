#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;
bool isPrimeNumber(int num) {
	if (num < 2) { return false; }
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num%i == 0) { return false; }
	}
	return true;
}
int filter(int n) {
	if (isPrimeNumber(n)) {
		int sum = 0;
		while (n > 0) {
			if (!isPrimeNumber(n % 10)) { sum += n % 10; }
			n /= 10;
		}
		return sum;
	}
	else { return -1; }
}
int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	vector<int> v;
	int n; in >> n;
	for (int i = 0; i < n; i++) {
		int val; in >> val;
		v.push_back(filter(val));
	}
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++) {
		out << *it;
	}
	system("pause");
	return 0;
}
/*
(sử dụng fstream và vector)

Viết chương trình hoàn chỉnh cho bài toán sau:

Nhập vào một dãy số nguyên dương gồm N phần tử từ tập tin “input.txt” theo cấu trúc:

- Dòng đầu ghi số nguyên dương N.

- N dòng tiếp theo, mỗi dòng ghi một số nguyên dương.

Yêu cầu: Xét mọi số nguyên trong dãy đã cho, nếu số đó là số nguyên tố
thì yêu cầu tính tổng các chữ số không phải là số nguyên tố của nó, ngược lại xuất -1.

Dữ liệu xuất ra được ghi vào tập tin “output.txt”.




Ví dụ
input
3

28

9817

23

output
-1

18

0
*/