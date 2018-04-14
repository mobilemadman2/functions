#include <iostream>
#include <string>
using namespace std;
//CONVERT >> số nguyên dương thành chuỗi có thể dùng như mảng: 1234 => "1234"
string intToString(int num) {
	string rev;
	//số thành chuỗi đảo ngược
	while (num > 0)
	{
		rev = rev + char(num % 10 + 48);
		num /= 10;
	}
	//đảo ngược chuỗi
	string res;
	for (int i = rev.size() - 1; i >= 0; i--) {
		res += rev[i];
	}
	return res;
}


int main()
{
	string res;
	int n; cin >> n;
	for (int i = 1; i < 100000; i++) {
		res += intToString(i);
	}
	cout << res[n - 1];
	system("pause");
	return 0;
}
/*
Viết các số thập phân 1,2, ... liên tiếp thu được dãy số như sau :
12345678910111213141516171819202122 ...

Viết chương trình tìm chữ số ở vị trí N.

Input
Gồm duy nhất 1 số N, 1 ≤ N ≤ 100,000.

Output
Số duy nhất là chữ số ở vị trí N trong dãy.

Sample

Input
10
15
Output
1
2
*/