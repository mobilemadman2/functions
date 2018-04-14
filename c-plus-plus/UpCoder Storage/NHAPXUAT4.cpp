#include <iostream>
using namespace std;

int main(){
	int num;
	cin >> num;
	if (int(num % 1000 / 100) > 0){
		cout << int(num % 1000 / 100);
	}
	else{
		cout << -1;
	}
	system("pause");
	return 0;
}
/*
Nhập vào 1 số nguyên, yêu cầu xuất ra chữ số hàng trăm của số đó, nếu không có thì xuất ra -1

ví dụ:
input:
1234

output
2
*/