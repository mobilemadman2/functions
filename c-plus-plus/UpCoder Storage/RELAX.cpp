#include <iostream>
using namespace std;
int main() {
	int n; cin >> n;
	int min, max;
	if (n % 7 == 0) { min = max = n / 7 * 2; }
	else {
		//nếu dư 6 ngày thì có thể sẽ có 1 ngày nghỉ, ít hơn thì 0 có
		int dumin = 0;
		if (n % 7 == 6) { dumin = 1; }
		min = (n / 7 * 2) + dumin;
		//nếu dư 1 ngày thì vẫn có thể có 1 ngày nghỉ, hơn thì có thể có 2 ngày
		int dumax = 2;
		if (n % 7 < 2) { dumax = 1; }
		max = (n / 7 * 2) + dumax;
	}
	cout << min << " " << max << endl;
	system("pause");
	return 0;
}
/*
Ở một hành tinh 1 năm có n ngày . 
Nhưng những người dân vẫn làm việc như là ở trái đất với 
1 tuần làm việc bắt đầu từ thứ 2 kết thúc vào thứ 6 và được nghỉ 2 ngày thứ 7 và chủ nhật
Hãy đếm số ngày nghỉ tối thiếu và tối đa trong năm của hành tinh đó

Input :
1 số n ( 1 <= n <= 10^6 )

Output:
2 số là số ngày nghỉ thấp nhất và số ngày nghỉ cao nhất có thể trong n ngày . 2 số cách nhau khoảng trắng

Example
Input
14
Output
4 4

Input
5
Output
0 2

Giải thích :
Test case 1 : nếu bắt đầu ở bất kể thứ nào thì kết quả vẫn được 2 ngày thứ 7 và 2 ngày chủ nhật
Test case 2 : nếu bắt đầu ở thứ 2 thì không có ngày nghỉ nào nếu bắt đầu thứ 7 sẽ có được 2 ngày nghỉ
*/