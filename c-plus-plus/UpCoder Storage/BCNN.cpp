#include <iostream>
#include <cmath>
using namespace std;

int UCLN(int a, int b){
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

int BCNN(int a, int b){
	int kq;
	a = abs(a);
	b = abs(b);
	return kq=(a/UCLN(a,b))*b;
}

int main(){
	int a, b;
	cin >> a >> b;
	cout << BCNN(a, b);
	system("pause");
	return 0;
}