#include <iostream>
using namespace std;

int main(){
	char num[100];
	int pos;
	cin >> pos >> num;
	if ((int)num[pos] >= 48 && (int)num[pos] <= 57){
		cout << num[pos];
	}
	else{
		cout << -1;
	}
	system("pause");
	return 0;
}
/*
Nhập vào 1 số nguyên, yêu cầu xuất ra chữ số ở vị trí i của số đó, nếu không có thì xuất ra -1
(Lưu ý thứ tự đếm từ trái sang phải - bắt đầu là vị trí thứ 0)

input:
- Dòng 1: Nhập vào vị trí thứ i cần xuất
- Dòng 2: Nhập vào số cần xử lý

output:
- Xuất ra chữ số thứ i, nếu không có xuất -1

ví dụ:
input:
1
1234

output
2
*/