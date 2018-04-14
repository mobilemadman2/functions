#include <iostream>
#include <cmath>
using namespace std;
int UCLN(int a, int b){
	a = abs(a);
	b = abs(b);
	if (a == 0 || b == 0)
		return a + b;
	while (a != b)
	{
		if (a>b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

int main(){
	int a, b;
	cin >> a >> b;
	cout << UCLN(a, b);
	system("pause");
	return 0;
}

/*
Nhập vào 2 số nguyên a và b.
Yêu cầu tìm UCLN của 2 số đó.

ví dụ
input:
10 8

output
2
*/