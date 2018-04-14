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
	string res, fin;
	cin >> fin;
	for (int i = 1; i < 100000; i++) {
		res += intToString(i);
	}
	cout << res.find(fin, 0) + 1;
	system("pause");
	return 0;
}
/*
Viết các số thập phân 1,2, ... liên tiếp thu được dãy số như sau :

12345678910111213141516171819202122 ...

Viết chương trình tìm vị trí xuất hiện đầu tiên của số N trong dãy trên.

Input

Gồm duy nhất 1 số N, 1 ≤ N ≤ 100,000.

Output

Số duy nhất là vị trí xuất hiện đầu tiên của số N trong dãy.

Sample

Input
15
34
Output
20
3
*/