#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	string s;
	cin >> s;
	if (s == "1") cout << 1;
	else if (s == "2") cout << 2;
	else if (s == "6") cout << 3;
	else if (s == "24") cout << 4;
	else if (s == "120") cout << 5;
	else if (s == "720") cout << 6;
	else
	{
		double sum = 1, n = 0;
		while (sum < s.length()) {
			sum += log10(++n);
		}
		cout << n;
	}
	return 0;
}
/*
Cho n là một số tự nhiên dương, "n giai thừa", kí hiệu n! là tích của n số tự nhiên dương đầu tiên:
n! = n.(n-1).(n-2)....4.3.2.1
VD: 21! = 1 x 2 x 3 x · · · x 21 = 51 090 942 171 709 440 000
Với n, ta có thể tính n! một cách dễ dàng. Tuy nhiên, trong bài này, cho n!, nhiệm vụ của bạn là tìm ra số n.
Input:
Một dòng duy nhất chứa số n! của một số nguyên dương n. Số chữ số của n! không vượt quá 106.

Output:
Số nguyên dương n cần tìm.

Sample Input 1:
120
Sample Output 1:
5

Sample Input 2:
51090942171709440000
Sample Output 2:
21

Sample Input 3:
10888869450418352160768000000
Sample Output 3:
27
*/