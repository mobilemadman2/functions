#include <iostream>
using namespace std;

int main(){
	int n;
	while (cin >> n){
		int sum = 0;
		while (n)
		{
			int soDu = n % 10;
			if (soDu == 2 || soDu == 3 || soDu == 5 || soDu == 7)
				sum += soDu;
			n = n / 10;
		}
		cout << sum << endl;
	}
	//system("pause");
	return 0;
}
/*Nhập vào 1 dãy số, yêu cầu tính tổng các chữ số nguyên tố của dãy đó.

ví dụ:
input:
1
12
23
output:
0
2
5
*/