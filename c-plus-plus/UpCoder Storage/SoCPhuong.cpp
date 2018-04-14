#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin >> n;
	sqrt(n)*sqrt(n) == n ? cout << "yes" : cout << "no";
	system("pause");
	return 0;
}
/*Nhập vào 1 số.

Kiểm tra số đó có phải là số chính phương không?
Xuất: yes, nếu đó là số chính phương, ngược lại xuất no

ví dụ:
input: 4

output: yes

P/S: Số chính phương hay còn gọi là số hình vuông là số tự nhiên có căn bậc 2 là một số tự nhiên, 
hay nói cách khác, số chính phương là bình phương (lũy thừa bậc 2) của một số tự nhiên khác.
*/