#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int x = 1, i = 1;
	//x là bội số của n khi x chia hết cho n
	while (x%n != 0) {
		//đảm bảo giá trị x chỉ có số 1
		x = x * 10 + 1;
		x %= n;
		//đếm mỗi lần tăng x
		i++;
	}
	cout << i;
	return 0;
}
/*
Cho một số 0<=N<=100000 không chia hết cho 2 và 5. X là bội số của N và X là một dãy số chỉ chứa các kí tự 1. Đếm xem dãy số X chứa bao nhiêu kí tự 1?

Ví dụ:
Input:
3
Output
3
Note: N=3 => X=111 X có chứa 3 kí tự 1.

Input:
7
Output
6
Note: N=7 => X=111111 X có chứa 6 kí tự 1.
*/