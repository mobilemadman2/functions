#include <iostream>
#include <string>
using namespace std;
struct BaiCao {
	int diem[6], n = 6;
	string player[6] = { "Dau","Su","Lu","Bu","Ti","Teo" };
	int money[6] = { 100000,100000,100000,100000,100000,100000 };
	int& operator[](int i) { return diem[i]; }
	void printResult() {
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				if (money[i] < 100000) {
					cout << player[i] << " : Thua" << 100000 - money[i] << endl;
				}
				else if (money[i] > 100000) {
					cout << player[i] << " : Thang" << 100000 - money[i] << endl;
				}
				else cout << player[i] << " : Hoa" << endl;
			}

			else { cout << player[i] << " : " << money[i] << endl; }
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
	for (int i = 0; i < 6; i++) {
		is >> a >> b >> c;
		int score = (diem(a) + diem(b) + diem(c));
		if (score == 30) { score = 10; }
		else { score %= 10; }
		bc[i] = score;
		if (i > 0) {
			if (bc[i] > bc[0]) { bc.money[i] += 10000; bc.money[0] -= 10000; }
			if (bc[i] < bc[0]) { bc.money[i] -= 10000; bc.money[0] += 10000; }
		}
	}
	return is;
}
int main() {
	BaiCao a;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
	}
	a.printResult();
	system("pause");
	return 0;
}
/*
Năm mới, nhóm bạn gồm Su, Lu, Bu, Tí, Tèo tới nhà Dậu chúc Tết. Để cho có không khí ngày Tết,
6 bạn chơi trò bài cào (luật chơi các bạn xem tại bài tập BAICAO (Bài cào) để hiểu rõ)

Khi chơi thì Dậu là chủ nhà nên làm cái.

Vì chơi vui nên mỗi ván mọi người đặt cược cố định là 10.000 vnđ. Su, Lu, Bu, Tí, Tèo mỗi người ban đầu có 100.000 vnđ

Bạn hãy xác định xem, sau một loạt ván bài, mỗi người sẽ có bao nhiêu tiền.



Dữ liệu nhập:

Dòng 1: số nguyên dương n - số lượng ván chơi (n <= 10)
Mỗi ván chơi gồm 1 bộ dữ liệu gồm 6 dòng, mỗi dòng gồm 3 giá trị lá bài của người tương ứng (theo thứ tự là Dậu, Su, Lu, Bu, Tí, Tèo).
Mỗi bộ dữ liệu của 1 ván chơi cách nhau bởi 1 dòng trắng.

Dữ liệu xuất:

Dòng đầu tiên: Bạn hãy xác định xem Dậu Thang, Thua hay Hoa. Trong trường hợp Thang hoặc Thua thì số tiền Thang (Thua) là bao nhiêu.
5 dòng tiếp theo: Tên của từng người và số tiền của người đó khi kết thúc trò chơi.
Xem ví dụ mẫu để hiểu rõ định dạng output.


Dữ liệu mẫu:

Input
2
J J J
J Q K
K K K
5 6 7
6 7 8
A 2 3

10 J Q
A 2 3
Q 3 6
3 6 9
2 5 7
2 2 2

Output
Dau : Thua 20000
Su : 110000
Lu : 110000
Bu : 100000
Ti : 100000
Teo : 100000
Giải thích:

Ở ván đầu tiên, Dậu lên bài được 3 lá J và thắng ván đó (thắng 3 bạn Bu, Tí, Tèo và hòa với Su, Lu)
Ở ván thứ hai, Dậu lên bài được 10, J, Q. Số điểm của Dậu là 0 điểm và thua cả 5 bạn còn lại.
*/