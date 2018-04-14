#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	//25 lũy thừa bất kì số nào đều có 2 số tận cùng là 25
	//tất nhiên là trừ số 0
	//https://www.misbbocconi.com/blog/knowledge/guest-article/cat-prep-series-how-to-find-out-last-two-digits-of-a-number/
	n > 0 ? cout << 25 : cout << 1;
	return 0;
}
/*
Câu hỏi là : “ Hãy tìm 2 chữ số tận cùng của 25^n với n là 1 số khá lớn “

Input :

1 dòng chứa số n ( 0<=n <=10^18)

Output:

1 dòng chứa 2 chữ số tận cùng của 25^n



Input
1
Output
25
*/