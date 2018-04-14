#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
	ifstream in("SEQUENCE.INP");
	ofstream out("SEQUENCE.OUT");
	long long num, a[100000];
	in >> num;
	for (long long i = 0; i < num; i++) {
		long long data; in >> data;
		a[i] = data;
	}
	sort(a, a + num - 1);
	out << a[num - 3] + 2 * a[num - 2] + 3 * a[num - 1] << endl;
	return 0;
}
/*
Cho dãy số gồm n số nguyên a1, a2, …, an.

Tìm giá trị lớn nhất của hàm f (i,j,k)= ai +2 × aj +3 × ak với 1 ≤ i < j < k ≤ n.

Ví dụ: với dãy gồm 5 số -1, 2, -2, -3, 5 thì f (1,2,5)= -1 + 2 × 2 + 3 × 5 = 18 là lớn nhất.

Dữ liệu: Vào từ file văn bản SEQUENCE.INP:
• Dòng đầu tiên chứa số nguyên n (3 ≤ n ≤ 105),
• Dòng thứ i trong n dòng tiếp theo chứa số nguyên ai (|ai| ≤ 109).

Kết quả: Đưa ra file văn bản SEQUENCE.OUT một số nguyên – giá trị lớn nhất của hàm f (i,j,k) tìm được.

Ví dụ:

SEQUENCE.INP
5
-1
2
-2
-3
5

SEQUENCE.OUT
18
*/