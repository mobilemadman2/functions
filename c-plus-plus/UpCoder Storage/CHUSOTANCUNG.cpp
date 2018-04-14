#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int a, n, c = 1;
	cin >> a >> n;
	for (int i = 1; i <= n; i++){
		c *= a;
		if (c > 10)c %= 10;
	}
	cout << c;
	//system("pause");
	return 0;
}

/*
Cho 2 số nguyên dương a và n (a <= 100; n <=106)
Tìm chữ số tận cùng của an
+ input: 2 số a và n cách nhau 1 khoảng trắng.
+ output: 1 số duy nhất là kết quả tìm được

Ví dụ
Input
2 5
Output
2
Giải thích: 25 = 32, chữ số tận cùng của 32 là 2

Input
3 5
Output
3
Giải thích: 35 = 243, chữ số tận cùng của 243 là 3
*/