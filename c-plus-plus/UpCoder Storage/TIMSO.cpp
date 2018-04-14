#include <iostream>
using namespace std;

int main(){
	int abcd, a, b, c, d;
	cin >> abcd;
	a = abcd / 1000;
	b = (abcd / 100) % 10;
	c = (abcd / 10) % 10;
	d = abcd % 10;
	a+b == c*d ? cout << "yes" : cout << "no";
	//system("pause");
	return 0;
}
/*Viết chương trình kiểm tra 1 số có 4 chữ số abcd có thỏa mãn tính chất sau không: a+b= c*d
Nếu thỏa xuất : "yes", ngược lại xuất "no"
ví dụ:

input:
1523

output:
yes
*/