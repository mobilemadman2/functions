#include <iostream>
using namespace std;

int main(){
	int n;

	while (cin >> n){
		cout << n / 10 + n % 10 <<" ";
	}

	//system("pause");
	return 0;
}
/*Nhập vào 1 dãy số, yêu cầu tính tổng các chữ số của dãy đó.

ví dụ:
input:
1
12
23
output:
1
3
5
*/