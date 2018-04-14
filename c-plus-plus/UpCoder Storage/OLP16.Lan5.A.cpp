#include <iostream>
using namespace std;

int tribonacci(int num) {
	//create tribonacci array
	int a[100] = { 0,0,1 };
	for (int i = 3; i < 97; i++) {
		a[i] = a[i - 1] + a[i - 2] + a[i - 3];
	}
	//find tribonacci >= num
	for (int i = 0; i < 100; i++) {
		if (a[i] >= num) { return a[i]; }
	}
}
int main()
{
	int num;
	while (cin >> num)
	{
		cout << tribonacci(num) << endl;
	}
	system("pause");
	return 0;
}
/*
Dãy số tribonacci được định nghĩa như sau:
• a0=0, a1=0, a2=1;
• an = an-1 + an-2 + an-3, n ≥ 3.

Các phần tử ban đầu của dãy là:
0, 0, 1, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504, 927, 1705,
3136, 5768, 10609, 19513, 35890, 66012, 121415, 223317, 410744,
755476, 1389537, 2555757, 4700770, 8646064, …
Cho số n, tìm số tribonacci đầu tiên lớn hơn hoặc bằng n.

Input
• Input gồm nhiều test, số lượng test không quá 100.
• Mỗi test gồm một dòng chứa số nguyên n (0 ≤ n ≤ 109).

Output
• Với mỗi test, in ra số tribonacci tìm được.

ví dụ:
input
1
2
3
4
5

output
1
2
4
4
7
*/