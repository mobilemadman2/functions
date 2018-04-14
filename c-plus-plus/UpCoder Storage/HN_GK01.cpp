#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
bool isSoDep(int num){
	int tong = 0;
	while (num > 0){
		tong += num % 10;
		num /= 10;
	}
	return tong % 10 == 7;
}
long tichChuSo(long n){
	long tich = 1;
	while (n > 0){
		tich *= n % 10;
		n /= 10;
	}
	return tich;
}
bool isSNT(int num){
	if (num < 2) return false;
	for (int i = 2; i < num; i++){
		if (num%i == 0) return false;
	}
	return true;
}
long tongCSNT(long n){
	long kq = 0;
	while (n > 0){
		int xet = n % 10;
		if (isSNT(xet))
			kq += xet;
		n /= 10;
	}
	return kq;
}
int main(){
	ifstream ifile("input.txt");
	ofstream ofile("output.txt");
	long n;
	while (!ifile.eof()){
		ifile >> n;
		isSoDep(n) ? ofile << tichChuSo(n) : ofile << tongCSNT(n);
	}
	ifile.close();
	ofile.close();
	return 0;
}
/*
Số tự nhiên N được gọi là số đẹp nếu tổng các chữ số của N tận cùng bằng 7.
Ví dụ một số số đẹp là 16 (1+6=7), 232 (2+3+2=7), 656 (6+5+6=17). 
Cho một dãy các số nguyên, hãy kiểm tra xem N có phải là số đẹp hay không và thực hiện theo yêu cầu.

Dữ liệu nhập:
- N số nguyên, mỗi số trong đoạn từ 0 ≤ n ≤ 10^9.

Dữ liệu xuất:
- N số nguyên,
•	mỗi số kiểm tra nếu A[i] là số đẹp, in ra tích các chữ số;
•	nếu A[i] không là số đẹp thì in ra tổng các chữ số là nguyên tố của A[i],
nếu không có chữ số nào nguyên tố thì in ra giá trị 0.

Ví dụ :
input.txt
6
13
223
8108
6317
7913

output.txt:
0
3
12
0
126
10
*/