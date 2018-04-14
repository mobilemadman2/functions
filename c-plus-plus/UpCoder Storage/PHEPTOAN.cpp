#include <iostream>
#include <string>

using namespace std;

int main(){
	int a, b;
	string phepTinh;
	cin >> a >> b >> phepTinh;
	if (phepTinh == "+"){ cout << a << "+" << b << "=" << a + b; }
	if (phepTinh == "-"){ cout << a << "-" << b << "=" << a - b; }
	if (phepTinh == "*"){ cout << a << "*" << b << "=" << a * b; }
	if (phepTinh == "%"){ cout << a << "%" << b << "=" << a % b; }
	//system("pause");
	return 0;
}
/*nhập vào 2 số nguyên và 1 phép toán. Yêu cầu thực hiện phép toán (là 1 trong 4 phép toán: +,-,*,%)

Input:
- Dòng 1: nhập vào 2 số nguyên A, B
- Dòng 2: Nhập vào 1 phép toán

Output:
-Biểu thức thực hiện phép toán.

Ví dụ:
Input:
1 2
+

Output:
1+2=3
*/