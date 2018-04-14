#include <iostream>
#include <string>
using namespace std;
struct BaiCao {
	int diem[5], n = 0;
	int& operator[](int i) {
		return diem[i];
	}
	int maxDiem() {
		int max = diem[0];
		for (int i = 1; i < n; i++) {
			if (diem[i] > max) { max = diem[i]; }
		}
		return max;
	}
	void printWinner() {
		string player[5] = { "Su","Lu","Bu","Ti","Teo" };
		for (int i = 0; i < n; i++) {
			if (diem[i] == maxDiem()) {
				cout << player[i] << " ";
			}
		}
	}
	void printSCore() {
		string player[5] = { "Su","Lu","Bu","Ti","Teo" };
		for (int i = 0; i < n; i++) {
			cout << player[i] << " " << diem[i] << " ";
		}
	}
};
int diem(string c) {
	if (c == "10") { return 0; }
	switch (c[0]) {
	case 'J':
	case 'Q':
	case 'K':return 10; break;
	case 'A':return 1; break;
	default: return int(c[0]) - 48;
	}
}
istream& operator >> (istream& is, BaiCao& bc) {
	string a, b, c;
	for (int i = 0; i < 5; i++) {
		is >> a >> b >> c;
		int score = (diem(a) + diem(b) + diem(c));
		if (score == 30) { score = 10; }
		else { score %= 10; }
		bc[bc.n] = score;
		bc.n++;
	}
	return is;
}
int main() {
	BaiCao a;
	cin >> a;
	a.printWinner();
	system("pause");
	return 0;
}
/*
Bài cào hay còn gọi là bài ba cào là một kiểu chơi bài khá phổ biến. Mỗi người chơi được phát 3 lá bài, ai có số điểm cao nhất là người chiến thắng.

Cách tính điểm như sau: Các lá: A(1), 2, 3, 4, 5, 6, 7, 8, 9, 10 mỗi lá có số điểm tương ứng con số đó.Các lá: J, Q, K mỗi lá tính 10 điểm. Điểm của người chơi trong mỗi ván là số lẻ của tổng điểm ba lá bài.

Ví dụ, tổng ba lá là 27 điểm thì được 7 điểm, 10 điểm thì được 0 điểm (thường được gọi là bù).

Trường hợp đặc biệt là ai sở hữu được cả ba lá bài J, Q, K bất kỳ thì thắng ngay ván đó mà không cần tính điểm.

Nhân dịp năm mới, Su chơi bài cào cùng các bạn Lu, Bu, Ti, Teo. Hãy giúp Su xác định ai là người chiến thắng của mỗi ván chơi.

Dữ liệu nhập: Gồm 5 dòng, mỗi dòng gồm 3 giá trị lá bài của người tương ứng (theo thứ tự Su, Lu, Bu, Ti, Teo).

Dữ liệu ra: Tên của người chiến thắng, nếu có nhiều hơn 1 người chiến thắng thì tên mỗi người ngăn cách nhau bởi một khoảng trắng.

Dữ liệu mẫu:

Input

Output

J J J

J Q K

K K K

5 6 7

A 2 3

Su Lu Bu



Input

Output

10 J Q

A 2 3

Q 3 6

3 6 9

2 5 7

Bu
*/