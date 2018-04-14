#include <iostream>
#include <iomanip>      // setprecision
using namespace std;

void giaiPTB1(double a, double b){
	if (a == 0){
		if (b == 0){ cout << "VSN"; }
		else{ cout << "VN"; }
	}
	else{ cout << fixed << setprecision(2) << -b / a; }
	/*
	a == 0 ?
	b == 0 ? cout << "VSN" : cout << "VN" :
	cout << fixed << setprecision(2) << -b / a;
	*/
}
int main(){
	double a, b;
	cin >> a >> b;
	giaiPTB1(a, b);
	system("pause");
	return 0;
}
/*
Giải phương trình Ax + B = 0. Với A, B là hai he sô được nhập vào từ bàn phím

- Nếu phương trình vô nghiệm xuất kết quả: VN
- Nếu phương trình VSN xuất ra : VSN
- Nếu phương có nghiệm, xuất ra nghiệm (Lưu ý: kết quả xuất ra là số thực (lấy 2 chữ số thập phân)

ví dụ 1:

input
2
-4

output:
2.00

ví dụ 2:

input
2
3

output:
-1.50
*/