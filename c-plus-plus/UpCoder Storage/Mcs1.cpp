#include <iostream>
#include <string>
using namespace std;
//CONVERT >> chuỗi thành số
int stringToInt(string str) {
	int result = 0;
	for (size_t i = 0; i < str.size(); i++) {
		result = result * 10 + str[i] - 48;
	}
	return result;
}
int main() {
	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string val; cin >> val;
		if ((val[0] - 48) % 2 == 0) {
			sum += stringToInt(val);
		}
	}
	cout << sum;
	system("pause");
	return 0;
}
/*
Cho một dãy các số nguyên có n phần tử.
Hãy tính tổng các phần tử a[i]....a[n] sao cho phần tử đó có chữ số đầu tiên từ trái sang phải là số chẵn.

input
5
2 3 45 67 97

output

114
*/