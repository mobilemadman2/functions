#include<iostream>
using namespace std;
int main()
{
	int sl, n, arr[100];
	cin >> sl;
	for (int i = 0; i < sl; i++){
		cin >> n;
		arr[i] = n;
	}
	for (int i = 0; i < sl; i++){
		if (arr[i] < 0){
			cout << arr[i];
		}
	}
	for (int i = 0; i < sl; i++){
		if (arr[i] > 0){
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
- Dòng 1: xuất các số âm của dãy
- Dòng 2: xuất các số dương của dãy

Ví dụ:
input
4
1 -2 3 -4
output
-2 -4
1 3
*/