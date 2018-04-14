#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	cout << a % 10 + b % 10;
	system("pause");
	return 0;
}

/*
Nhập vào 2 số nguyên N và M, yêu cầu tính tổng chữ số cuối cùng của  N và của M.

ví dụ:
input:
123
456

output
9
*/