#include <iostream>
using namespace std;
bool isSNT(int num){
	if (num < 2) return false;
	for (int i = 2; i < num; i++){
		if (num%i == 0) return false;
	}
	return true;
}
int main()
{
	int k, num, max = 0;
	cin >> k;
	while (cin >> num){
		if (isSNT(num) && num > max && num <= k){
			max = num;
		}
	}
	max == 0 ? cout << -1 : cout << max;
	system("pause");
	return 0;
}
/*
Cho 1 dãy các số nguyên ,Hãy tìm số nguyên tố lớn nhất nhỏ hơn hoặc bằng K

Input
dòng 1: số nguyên K
dòng 2 : dãy số nguyên

output:
dòng 2 : số nguyên tố lớn nhất mà không lớn hơn K, nếu không có in ra -1

ví dụ:
input:
9
5 4 7 11 10 13

output:
7
*/