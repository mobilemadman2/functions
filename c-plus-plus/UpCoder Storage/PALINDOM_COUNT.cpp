#include <iostream>
using namespace std;
//REVERSE >> đảo ngược số: 1234 => 4321
int reverseInt(int abc) {
	bool check = false;
	if (abc < 0) { abc = abc*-1; check = true; }
	//lấy chiều dài số
	int len = 1;
	int tmp = abc;
	while (tmp /= 10) { len++; }
	//tính toán
	int rev = 0;
	while (abc > 0)
	{
		rev = rev + (abc % 10)*(int)pow(10, len - 1);
		len--;
		abc /= 10;
	}
	if (check) { rev = rev*-1; }
	return rev;
}
int main() {
	int n; cin >> n;
	while (n != 0) {
		int a, b, c = 0; cin >> a >> b;
		if (a>b) { swap(a, b); }
		while (a <= b) {
			if (a == reverseInt(a)) {
				c++;
			}
			a++;
		}
		cout << c << endl;
		n--;
	}
	system("pause");
	return 0;
}
/*
Số nguyên Palindrome là số mà đọc từ trái qua phải hay từ phải qua trái đều giống nhau, ví dụ các số Palindrome: 11, 101, 121, 222.
Cho hai số nguyên L, R. Hãy đếm số lượng số Palindrome trong đoạn L, R.
Input:
- Dòng đầu là T (T <= 50000), số lượng cặp số L, R.
- T dòng sau, mỗi dòng gồm hai số nguyên L, R (0 <= L, R <= 1017 ).
Output:
- Gồm T dòng tương ứng là số lượng số Palindrome trong đoạn L, R.
Ví dụ
input
4
1 10
100 1
1 1000
1 10000
output
9
18
108
198
*/