#include <iostream>
#include <string>
using namespace std;

int main() {
	int n; cin >> n;
	string boo = "bo", str = "";

	for (int i = 0; i < n; i++) {
		int pos; cin >> pos;
		while (str.length() < pos) {
			boo = boo + "o";
			str = str + boo + str;
		}
		cout << str[pos - 1] << endl;
	}
	system("pause");
	return 0;
}
/*
Dãy kí tự trên được diễn tả như sau:
Gọi S(0) là dãy ba kí tự “b o o”.
Sau đó dãy kí tự S(k) sẽ bằng dãy S(k-1) và thêm vào “b o … o” với k+2 chữ o, và sau đó cộng thêm một lần nữa dãy S(k-1).
Ví dụ:
S(0) = "b o o"
S(1) = "b o o b o o o b o o"
S(2) = "b o o b o o o b o o b o o o o b o o b o o o b o o"
Với cách này sẽ tạo được dãy kí tự rất dài, và dãy này sẽ dùng cho game "Boo".

Tèo là 1 trong số các sinh viên tham gia trò chơi "Boo". Tèo rất thông minh nên sẽ tính trước
được kí tự thứ N của dãy này là chữ “b” hay chữ “o”. Tèo đố bạn đáp số là gì?

Input:
Dòng 1: số nguyên dương T - số lượng test (T <= 10)
T dòng tiếp theo, mỗi dòng gồm một số nguyên N (1 <= N <= 10^9).
Output:
T dòng, mỗi dòng chứa duy nhất kí tự “b” hoặc “o” (đáp số của từng câu hỏi mà Tèo đưa ra)

Ví dụ:
Input
2
11
24
Output:
b
o
Giải thích: Ký tự thứ 11 trong dãy trên là b và ký tự thứ 24 trong dãy là o
*/