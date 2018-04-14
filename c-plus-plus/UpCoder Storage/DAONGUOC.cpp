#include <iostream>
using namespace std;
int main(){
	int num;
	cin >> num;
	cout << num % 10 << num / 10 % 10 << (num / 100) % 10;
	//system("pause");
	return 0;
}
/*
Nhập vào 1 số gồm 3 chữ số, yêu cầu xuất số đó theo thứ tự ngược lại

ví dụ
input
123

output
321
*/