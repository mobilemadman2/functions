#include <iostream>
using namespace std;

int main() {
	long long num, res = 1;
	cin >> num;

	for (long long i = 1; i <= num; i++) {
		res *= i;
		while (res % 10 == 0) { res /= 10; }
		res = res % 100000;
	}

	cout << res % 10 << endl;
	return 0;
}
/*
In mathematics, the factorial of a non-negative integer n, denoted by n!,
is the product of all positive integers less than or equal to n. Some examples of factorial:

n                      n!
2                      2
3                      6
4                     24
5                    120
6                    720

As you can see, it gets big quickly. So, we only want to find the first non-zero digit from right to left of n! .

Input
The input contains one positive number n (0< n<10000)

Output
Output a single line the first non-zero digit of n! from right to left.

Sample input                                      Sample output
3                                                     6
5                                                     2
26                                                    4
*/
/*
In mathematics, the factorial of a non-negative integer n, denoted by n!, 
is the product of all positive integers less than or equal to n. Some examples of factorial:

n                      n!
2                      2
3                      6
4                     24
5                    120
6                    720

As you can see, it gets big quickly. So, we only want to find the first non-zero digit from right to left of n! .

Input
The input contains one positive number n (0< n<10000)

Output
Output a single line the first non-zero digit of n! from right to left.

Sample input                                      Sample output
3                                                     6
5                                                     2
26                                                    4
*/