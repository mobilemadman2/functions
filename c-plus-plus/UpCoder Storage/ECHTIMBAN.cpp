#include <iostream>
#include <string>
using namespace std;
//REVERSE >> đảo ngược chuỗi
string reverseString(string str) {
	string result = "";
	for (int i = str.size() - 1; i >= 0; i--) {
		result += str[i];
	}
	return result;
}
bool canHeFoundHer(int k, string s) {
	//nếu x sau v thì đảo chuỗi
	if (s.find("X") > s.find("V")) { s = reverseString(s); }
	//tìm
	for (int i = s.find("X") + k; i <= s.find("V"); i += k) {
		if (s[i] == '#') { return false; }
		if (s[i] == 'V') { return true; }
	}
	return false;
}
int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n, k; string s;
		cin >> n >> k;
		cin.ignore();
		cin >> s;
		if (canHeFoundHer(k, s)) { cout << "YES" << endl; }
		else { cout << "NO" << endl; }
	}
	system("pause");
	return 0;
}
/*
Input:
Dòng đầu tiên: số nguyên dương T là số lượng test.
Với mỗi bộ test, dữ liệu vào gồm 2 dòng:
Dòng thứ nhất chứa hai số nguyên dương n và k (2 <= n <= 100, 1 <= k <= n-1). Với n là số lượng cọc gỗ, k là chiều dài mỗi bước nhảy của chú ếch.
Dòng thứ hai là một chuỗi n ký tự bao gồm ‘.’, ‘#’, ‘X’, ‘V’.
Ký tự ‘.’ có nghĩa là cọc đó đang trống và chú ếch có thể nhảy tới cọc đó.
Ký tự ‘#’ nghĩa là cọc đó đang có chướng ngại vật, và chú ếch không thể nhảy tới đây.
Ký tự ‘X’ là vị trí hiện tại của chú ếch xanh.
Ký tự ‘V’ là vị trí hiện tại của chú ếch vàng.

Output:
Với từng test, nếu tồn tại một chuỗi các bước nhảy sao cho chú ếch xanh có thể nhảy tới cọc mà chú ếch vàng đang đứng thì in “YES”. Ngược lại in “NO” (không xuất dấu ngoặc kép).

Ví dụ:
Input:
4
5 2
#X#V#
6 1
V....X
7 3
V..#..X
6 2
..XV..

Output:
YES
YES
NO
NO

Giải thích:
Ở test 1: Chú ếch có thể nhảy 1 bước duy nhất từ cọc số 2 đến cọc số 4.
Ở test 2: Chú ếch có thể nhảy qua từng chiếc cọc để đến được cọc số 1.
Ở test 3: Chú ếch xanh không thể nhảy được bước nào. Vì cọc số 4 có chướng ngại vật.
Ở test 4: Chú ếch xanh chỉ có thể nhảy tới các cọc số 1 và cọc số 5, rồi lại quay về cọc 3. Không thể nhảy tới cọc có chú ếch vàng.
*/