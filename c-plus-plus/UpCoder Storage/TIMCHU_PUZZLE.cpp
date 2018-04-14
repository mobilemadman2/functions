#include <iostream>
#include <string>
using namespace std;
struct PUZZLE {
	int row, col, n;
	char puz[101][101];
};
istream& operator >> (istream& is, PUZZLE& pz) {
	is >> pz.row >> pz.col >> pz.n;
	for (int i = 1; i <= pz.row; i++) {
		for (int j = 1; j <= pz.col; j++) {
			cin >> pz.puz[i][j];
		}
	}
	return is;
}
ostream& operator << (ostream& os, PUZZLE pz) {
	cout << "Puzzle la:" << endl;
	for (int i = 1; i <= pz.row; i++) {
		for (int j = 1; j <= pz.col; j++) {
			cout << pz.puz[i][j] << " ";
		}
		cout << endl;
	}
	return os;
}
// DUONG THANG
bool goUp(PUZZLE pz, string word, int x, int y) {
	if (x - word.length() >= 0) {
		for (int i = 0; i < word.length(); i++) {
			if (word[i] != pz.puz[x][y]) {
				return false;
			}
			x--;
		}
		return true;
	}
	return false;
}
void goUp(PUZZLE pz, int x, int y, int len) {
	cout << "YES" << endl;
	while (len >= 1) {
		cout << "(" << x << "," << y << ")" << " ";
		len--; x--;
	}
	cout << endl;
}
bool goDown(PUZZLE pz, string word, int x, int y) {
	if (x + word.length() - 1 <= pz.row) {
		for (int i = 0; i < word.length(); i++) {
			if (word[i] != pz.puz[x][y]) {
				return false;
			}
			x++;
		}
		return true;
	}
	return false;
}
void goDown(PUZZLE pz, int x, int y, int len) {
	cout << "YES" << endl;
	while (len >= 1) {
		cout << "(" << x << "," << y << ")" << " ";
		len--; x++;
	}
	cout << endl;
}
bool goLeft(PUZZLE pz, string word, int x, int y) {
	if (y - word.length() >= 0) {
		for (int i = 0; i < word.length(); i++) {
			if (word[i] != pz.puz[x][y]) {
				return false;
			}
			y--;
		}
		return true;
	}
	return false;
}
void goLeft(PUZZLE pz, int x, int y, int len) {
	cout << "YES" << endl;
	while (len >= 1) {
		cout << "(" << x << "," << y << ")" << " ";
		len--; y--;
	}
	cout << endl;
}
bool goRight(PUZZLE pz, string word, int x, int y) {
	if (y + word.length() - 1 <= pz.col) {
		for (int i = 0; i < word.length(); i++) {
			if (word[i] != pz.puz[x][y]) {
				return false;
			}
			y++;
		}
		return true;
	}
	return false;
}
void goRight(PUZZLE pz, int x, int y, int len) {
	cout << "YES" << endl;
	while (len >= 1) {
		cout << "(" << x << "," << y << ")" << " ";
		len--; y++;
	}
	cout << endl;
}
// DUONG CHEO
bool goUpLeft(PUZZLE pz, string word, int x, int y) {
	if (x - word.length() >= 0 && y - word.length() >= 0) {
		for (int i = 0; i < word.length(); i++) {
			if (word[i] != pz.puz[x][y]) {
				return false;
			}
			x--; y--;
		}
		return true;
	}
	return false;
}
void goUpLeft(PUZZLE pz, int x, int y, int len) {
	cout << "YES" << endl;
	while (len >= 1) {
		cout << "(" << x << "," << y << ")" << " ";
		len--; x--; y--;
	}
	cout << endl;
}
bool goDownLeft(PUZZLE pz, string word, int x, int y) {
	if (x + word.length() - 1 <= pz.row && y - word.length() >= 0) {
		for (int i = 0; i < word.length(); i++) {
			if (word[i] != pz.puz[x][y]) {
				return false;
			}
			x++; y--;
		}
		return true;
	}
	return false;
}
void goDownLeft(PUZZLE pz, int x, int y, int len) {
	cout << "YES" << endl;
	while (len >= 1) {
		cout << "(" << x << "," << y << ")" << " ";
		len--; x++; y--;
	}
	cout << endl;
}
bool goUpRight(PUZZLE pz, string word, int x, int y) {
	if (y + word.length() - 1 <= pz.col && x - word.length() >= 0) {
		for (int i = 0; i < word.length(); i++) {
			if (word[i] != pz.puz[x][y]) {
				return false;
			}
			x--; y++;
		}
		return true;
	}
	return false;
}
void goUpRight(PUZZLE pz, int x, int y, int len) {
	cout << "YES" << endl;
	while (len >= 1) {
		cout << "(" << x << "," << y << ")" << " ";
		len--; x--; y++;
	}
	cout << endl;
}
bool goDownRight(PUZZLE pz, string word, int x, int y) {
	if (x + word.length() - 1 <= pz.row && y + word.length() - 1 <= pz.col) {
		for (int i = 0; i < word.length(); i++) {
			if (word[i] != pz.puz[x][y]) {
				return false;
			}
			x++; y++;
		}
		return true;
	}
	return false;
}
void goDownRight(PUZZLE pz, int x, int y, int len) {
	cout << "YES" << endl;
	while (len >= 1) {
		cout << "(" << x << "," << y << ")" << " ";
		len--; x++; y++;
	}
	cout << endl;
}
void findWord(PUZZLE pz, string word) {
	char firstChar = word[0];
	bool check = false;
	for (int i = 1; i <= pz.row; i++) {
		for (int j = 1; j <= pz.col; j++) {
			if (pz.puz[i][j] == firstChar) {
				if (goUp(pz, word, i, j)) {
					goUp(pz, i, j, word.length()); check = true;
				}
				else if (goDown(pz, word, i, j)) {
					goDown(pz, i, j, word.length()); check = true;
				}
				else if (goLeft(pz, word, i, j)) {
					goLeft(pz, i, j, word.length()); check = true;
				}
				else if (goRight(pz, word, i, j)) {
					goRight(pz, i, j, word.length()); check = true;
				}
				else if (goUpLeft(pz, word, i, j)) {
					goUpLeft(pz, i, j, word.length()); check = true;
				}
				else if (goUpRight(pz, word, i, j)) {
					goUpRight(pz, i, j, word.length()); check = true;
				}
				else if (goDownLeft(pz, word, i, j)) {
					goDownLeft(pz, i, j, word.length()); check = true;
				}
				else if (goDownRight(pz, word, i, j)) {
					goDownRight(pz, i, j, word.length()); check = true;
				}
			}
		}
	}
	if (!check)cout << "NO";
}
int main() {
	PUZZLE a;
	cin >> a;
	for (int i = 0; i < a.n; i++) {
		string word; cin >> word;
		findWord(a, word);
	}
	system("pause");
	return 0;
}
/*
a m c l
k z u l
o p h q
c d p e
Tèo rất thích học Tiếng Anh. Thời gian rảnh Tèo thường cố gắng rèn luyện và trau dồi vốn từ vựng.
Một trong những phương pháp Tèo chọn là chơi trò chơi tìm chữ có tên là Puzzle. Vừa luyện nhanh mắt, vừa học được từ mới.

Trò chơi được mô tả như sau:
Cho 1 bảng chữ gồm n dòng, mỗi dòng là m chữ cái từ 'A' .. 'Z', mỗi chữ cách nhau một khoảng trắng.
Kế tiếp là một danh sách các từ vựng mà Tèo cần tìm. Công việc của Tèo đơn giản chỉ là dùng bút highlight lên từ đó ở trên bảng. Tuy nhiên các từ này không nằm theo thứ tự thông thường, mà chúng có thể nằm ngang, dọc, chéo, vv...

Sau khi giải xong bảng đó, Tèo lại tìm bảng chữ mới và tiếp tục công việc.
Vốn đam mê lập trình, Tèo chợt nghĩ ra cách viết một chương trình có thể tìm được vị trí của các từ đó một cách nhanh nhất ^..^

Bạn hãy cùng Tèo viết chương trình này nhé!

Input:
Dòng 1: 3 số nguyên dương n, m, t với n, m theo mô tả ở trên, t là số từ cần tìm (n, m <= 50, t <= 100)
n dòng tiếp theo, mỗi dòng là m chữ cái 'A' .. 'Z'. Mỗi chữ cách nhau 1 khoảng trắng
Tiếp đó là t dòng, mỗi dòng là 1 từ cần tìm (độ dài mỗi từ không quá 50 ký tự)
Output:
Ứng với mỗi từ trong t từ ở input, nếu từ này có tồn tại trên bảng chữ thì xuất "YES", ngược lại xuất "NO" (không xuất dấu ngoặc kép)
Nếu dòng trên là "YES" thì sẽ xuất tọa độ của lần lượt từng chữ cái theo đúng thứ tự xuất hiện trong từ đó (xem ví dụ để hiểu rõ cách xuất)
Ví dụ:
Input
6 6 3
S U N D P R
A U K S M E
E P P O O H
H H Q H Q S
K C A K A O
R E H T O M
SUPHAM
MOTHER
PHUC

Output
YES
(1,1) (2,2) (3,3) (4,4) (5,5) (6,6)
YES
(6,6) (6,5) (6,4) (6,3) (6,2) (6,1)
NO
*/