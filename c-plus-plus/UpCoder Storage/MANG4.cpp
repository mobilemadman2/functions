#include <iostream>
using namespace std;

bool isSNT(int num){
	if (num < 2) return false;
	for (int i = 2; i < num; i++){
		if (num%i == 0) return false;
	}
	return true;
}

int main(){
	int soLuong, num, sum = 0;
	cin >> soLuong;
	for (int i = 0; i < soLuong; i++){
		cin >> num;
		if (isSNT(num)){
			sum += num;
		}
	}
	cout << sum;
	system("pause");
	return 0;
}

/*
Input:
- Dòng 1: Nhập vào N là số lượng phần tử của mảng
- Dòng 2: N số nguyên (mỗi số cách 1 khoảng trắng)

Ouput:
Yêu cầu xuất tổng các số nguyên tố ra màn hình

ví dụ:
input:
3
1 2 3

output
5
*/