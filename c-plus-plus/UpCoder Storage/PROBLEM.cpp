#include <iostream>
using namespace std;
int main()
{
	int t;
	int n, a, b, i = 1;
	cin >> t;
	while (i <= t) {
		cin >> n >> a >> b;
		if (n - a >= b) {
			if (a>b) { cout << a - b << a; }
			else { cout << 0 << a; }
		}
		else {
			if (a>b) { cout << a - b << n - b; }
			else { cout << 0 << n - b; }
		}
		i++;
	}
	return 0;
}
/*
Có n người được mời tham gia giải quyết 1 vấn đề mang tính toàn cầu.
Trong n người này, có a người biết cách giải quyết vấn đề và b người từ chối tham gia.
Hỏi có tối thiểu và tối đa bao nhiêu người sẽ bắt tay vào giải quyết vấn đề.

Dữ liệu:
Dòng đầu tiên chứa số nguyên t (1<= t < = 10.000) là số lượng test. Sau đó là t test.
Mỗi test gồm 1 dòng duy nhất chứa ba số nguyên n, a và b (1<= n <=1000; 0<= a,b <=n).

Kết quả:
Với mỗi test ghi ra 1 dòng chứa 2 số nguyên là số lượng người tối thiểu và tối đa tham gia giải quyết vấn đề

Ví dụ:
input
output
3
3 2 1
5 5 0
4 3 3
1 2
5 5
0 1
*/