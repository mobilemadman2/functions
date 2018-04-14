#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int val, le = 0, chan = 0, pchan, ple;
	for (int i = 1; i <= n; i++) {
		cin >> val;
		if (val % 2 == 0) { chan++; pchan = i; }
		else { le++; ple = i; }
	}
	if (le > chan) { cout << pchan; }
	else { cout << ple; }
	return 0;
}
/*
Trong giờ thực hành, Tí và Tèo làm bài thầy giao rất nhanh. Do không muốn để tốn thời gian rảnh, nên Tí và Tèo nghĩ ra một trò chơi thử thách sự nhạy bén của nhau. Trò chơi như sau:
Tí đưa ra một dãy có n số nguyên dương. Trong đó có 1 số duy nhất khác biệt với các số còn lại, tuy nhiên sự khác biệt đó là gì thì Tí không nói. Đây là câu hỏi thử thách Tèo.
Tèo rất thông minh, nên nhìn là biết ngay sự khác biệt đó và đưa ra vị trí của số khác biệt.

Bạn có thể tìm được số đó không?

Input:
Dòng 1: số nguyên dương n (3 <= n <= 100)
Dòng 2: n số nguyên dương, mỗi số cách nhau một khoảng trắng và không quá 100.
Dữ liệu đảm bảo chỉ có đúng 1 số duy nhất khác biệt với tất cả các số còn lại.
Output:
Vị trí của số khác biệt duy nhất đó.

Ví dụ:
Input
5
2 4 7 8 10
Output
3

Input
4
1 2 1 1
Output
2
*/