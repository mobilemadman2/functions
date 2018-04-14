#include<iostream>
using namespace std;
bool isSNT(int n){
	int dem = 1;
	if (n < 2) return false;
	if (n == 2) return true;
	else{
		for (int i = 2; i < n; i++){
			if (n % i == 0) dem = 0;
		}
	}
	if (dem == 1) return true;
	else return false;
}
int main()
{
	int n;
	cin >> n;
	isSNT(n) ? cout << "true" : cout << "false";
	system("pause");
	return 0;
}
/*
Nhập vào 1 số.

Kiểm tra số đó có phải là số nguyên tố không?
Xuất: true, nếu đó là số nguyên tố, ngược lại xuất false

ví dụ:
input: 4

output: false
*/
/*
Hãy tìm số nguyên dương Q nhỏ nhất sao cho tích các chữ số của Q phải bằng N cho trước
Input
Số N duy nhất với 0 <= N <= 10^9

Output
In ra duy nhất số Q. Nếu không tìm được thì in ra -1

input 10
output 25
*/