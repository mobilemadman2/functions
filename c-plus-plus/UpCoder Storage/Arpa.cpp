#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	//công thức áp dụng với lũy thừa n của mọi số tận cùng là 8
	switch (n % 4) {
	case 1: cout << 8; return 0;
	case 2: cout << 4; return 0;
	case 3: cout << 2; return 0;
	case 0: cout << 6; return 0;
	}
}
/*
Hòn đảo Arpa đưa ra một kì thi để tuyển chọn người thống trị. Đề thi chỉ có 1 câu hỏi duy nhất là : in ra chữ số cuối cùng của 1378 ^ n.
Mehrdad muốn thắng trong cuộc thi này nên nhớ sự trợ giúp của các bạn member Upcoder..
Input:
Nhập số n.
Output:
Xuất ra chữ số cuối cùng của 1378 ^ n.

Examples
input
1
output
8
input
2
output
4
*/