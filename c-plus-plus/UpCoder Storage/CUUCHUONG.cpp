#include <iostream>
using namespace std;

int main(){
	int num;
	cin >> num;
	for (int i = 1; i <= 10; i++){
		cout << num << "x" << i << "=" << num*i << endl;
	}
	system("pause");
	return 0;
}
/*
Nhập vào số i, yêu cầu xuất ra bảng cửu chương thứ i (lưu ý xuất theo định dạng giống ví dụ mẫu)

ví dụ:
input:
2

output:
2x1=2
2x2=4
2x3=6
2x4=8
2x5=10
2x6=12
2x7=14
2x8=16
2x9=18
2x10=20
*/