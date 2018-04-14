#include <iostream>
#include <cmath>		//sqrt
using namespace std;

bool isSquareNumber(int num){
	if (sqrt(num) == floor(sqrt(num))){
		return true;
	}
	return false;
}
int main(){
	int num, soLuong, sum = 0;
	cin >> soLuong;
	for (int i = 0; i < soLuong; i++){
		cin >> num;
		if (isSquareNumber(num)){
			sum += num;
		}
	}
	cout << sum;
	system("pause");
	return 0;
}

/*
Số chính phương (Square number) là số mà căn bậc hai của nó là một số nguyên.
Input:
- Dòng 1: Nhập vào N là số lượng phần tử của mảng
- Dòng 2: N số nguyên (mỗi số cách 1 khoảng trắng)

Ouput:
Yêu cầu xuất tổng các số chính phương ra màn hình

ví dụ:
input:
4
1 2 3 4

output
5
*/