#include<iostream>
#include <cmath>		//sqrt, pow
using namespace std;

//so Chinh Phuong
bool isSquareNumber(int num){
	if (sqrt(num) == floor(sqrt(num))){
		return true;
	}
	return false;
}
bool isSNT(int num){
	if (num < 2) return false;
	for (int i = 2; i < num; i++){
		if (num%i == 0) return false;
	}
	return true;
}
int main()
{
	int sl, n, arr[100];
	cin >> sl;
	for (int i = 0; i < sl; i++){
		cin >> n;
		arr[i] = n;
	}
	for (int i = 0; i < sl; i++){
		if (isSquareNumber(arr[i])){
			cout << arr[i];
		}
	}
	for (int i = 0; i < sl; i++){
		if (isSNT(arr[i])){
			cout << arr[i];
		}
	}
	return 0;
}
/*
Input:
- Dòng 1: Nhập vào N là số lượng phần tử của mảng
- Dòng 2: N số nguyên (mỗi số cách 1 khoảng trắng)

Ouput:
- Dòng 1: xuất các số chính phương của dãy
- Dòng 2: xuất các số nguyên tố của dãy

Ví dụ:
input
4
1 2 3 4
output
1 4
2 3
*/