#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	int n = a;
	while (n >= a && n <= b){
		if ((long)sqrt(n)*(long)sqrt(n) == n) cout << n << endl;
		n++;
	}
	//system("pause");
	return 0;
}
/*Hãy tìm tất cả các số chính phương trong đoạn [A,B] .

Input
Gồm 2 số nguyên A và B cách nhau bởi 1 dấu cách ( 1 ≤ A ≤ B ≤ 200000).

Output
Ghi ra tất cả các số chính phương trong khoảng [A,B]. Mỗi số trên 1 dòng.

Ví dụ
Input:
1 100

Output:
1
4
9
16
25
36
49
64
81
100
*/