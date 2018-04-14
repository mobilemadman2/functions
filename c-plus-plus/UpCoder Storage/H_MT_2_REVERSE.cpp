#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int lengthOfInt(int num) {
	int length = 1;
	while (num /= 10)
		length++;
	return length;
}
int reverseInt(int num) {
	int dem = 0, soNguoc = 0, dv;
	int coSo = lengthOfInt(num) - 1;
	for (; coSo >= 0; coSo--) {
		dv = (num / (int)pow(10, coSo)) % 10;
		soNguoc += dv*(int)pow(10, dem); dem++;
	}
	return soNguoc;
}

int main() {
	ifstream in;
	in.open("input.txt");
	ofstream out("output.txt");
	int num, soMax, flag = 1;
	while (in >> num) {
		if (flag == 1) { soMax = num; flag = 0; }
		if (reverseInt(num) > reverseInt(soMax))soMax = num;
	}
	in.close();
	out << reverseInt(soMax);
	out.close();
	return 0;
}
/*
Nhập vào 1 dãy số nguyên dương, in ra số đảo ngược lớn nhất

+ Dữ liệu vào từ file: input.txt
+ Dữ liệu ra file: output.txt


Ví dụ 1:

input.txt:
123
12
1
341
output.txt:
321
*/