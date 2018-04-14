#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

//GET >> tổng chữ số: 123 = 1+2+3 = 6
long long sumOfInt(long long num) {
	long long tong = 0;
	while (num > 0) {
		tong += num % 10;
		num /= 10;
	}
	return tong;
}
//GET >> chiều dài kí tự của một số
long long lengthOfInt(long long num) {
	long long length = 1;
	while (num /= 10) { length++; }
	return length;
}
int main() {
	ifstream in("DIGITSUM.INP");
	ofstream out("DIGITSUM.OUT");

	long long num, ka, pos, res[1000000], ri = 0;
	in >> num >> ka >> pos;
	in.close();

	for (long long i = ka; i <= pow(10, num); i += 9) {
		if (sumOfInt(i) == ka) {
			res[ri++] = i;
		}
	}
	out << ri << endl << res[pos - 1] << endl;
	out.close();
	return 0;
}
/*
Cho trước hai số nguyên dương n và k (n <= 10, k <= 50).

Yêu cầu 1: Hãy cho biết có bao nhiêu số có <= n chữ số mà tổng các chữ số đúng bằng k
Yêu cầu 2: Cho số nguyên dương p, hỏi nếu đem các số tìm được sắp xếp theo thứ tự tăng dần thì số thứ p là số nào.
(p không lớn hơn số lượng các số tìm được)

Dữ liệu: Vào từ file văn bản DIGITSUM.INP gồm 1 dòng chứa ba số n, k, p theo đúng thứ tự cách nhau 1 dấu cách.

Kết quả: Ghi ra file văn bản DIGITSUM.OUT gồm 2 dòng
· Dòng 1: Ghi số lượng các số tìm được trong yêu cầu 1
· Dòng 2: Ghi số thứ p trong yêu cầu 2 tìm được

Ví dụ:
DIGITSUM.INP		DIGITSUM.OUT
2 7 4				8	34


Giải thích:
+ Với n = 2 và k = 7 thì ta có các số thỏa yêu cầu đề bài là: 7 16 25 34 43 52 61 70

DIGITSUM.INP		DIGITSUM.OUT
3 8 10				45	107
*/