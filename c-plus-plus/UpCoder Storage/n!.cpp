#include <iostream>
using namespace std;

int factorial(int num){
	int factorial = 1;
	for (int i = 0; i < num; i++){
		factorial *= (num - i);
	}
	return factorial;
}

int main(){
	int num;
	cin >> num;
	cout << factorial(num);
	system("pause");
	return 0;
}
/*
Nhập vào 1 số nguyên n, xuất ra n!

ví dụ:

input:
3

output:
6
*/