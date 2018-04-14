#include <iostream>
#include <string>
using namespace std;
string giaiMa(string s) {
	string kq = "", a, b;
	for (int i = s.length() - 1; i >= 0; i--) {
		int len = kq.length();
		if (len == 0) { kq = s[i]; }
		else if (len == 1) { kq = s[i] + kq; }
		else {
			a = kq.substr(0, len / 2);
			b = kq.substr(len / 2, len);
			kq = a + s[i] + b;
		}
		s = s.substr(0, s.length() - 1);
	}
	return kq;
}
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		cout << giaiMa(s);
	}
	system("pause");
	return 0;
}
/*
Tèo đang tìm hiểu về mã hóa mật thư. Trước tiên Tèo tìm hiểu về khái niệm "Ký tự trung bình của một từ". Ký tự trung bình của 1 từ là ký tự đứng giữa của từ đó, nếu chiều dài của từ là số chẵn thì ký tự trung bình là ký tự bên trái của hai ký tự đứng giữa. Ví dụ các ký tự trung bình của từ là: upcoder , pedagogy

Mật thư được mã hóa như sau: Với mỗi từ, Tèo viết ra ký tự trung bình của từ đó, rồi xóa ký tự đó đi trong từ gốc, rồi lặp lại công việc đó cho đến khi từ gốc không còn ký tự nào.
Ví dụ: Từ upcoder được Tèo mã hóa thành: ocdpeur.

Giải thích:
Bước
Kết quả
Từ gốc
0

upcoder
1
o
upcder
2
oc
upder
3
ocd
uper
4
ocdp
uer
5
ocdpe
ur
6
ocdpeu
r
7
ocdpeur


Tèo đưa cho bạn một mật thư đã được mã hóa. Nhiệm vụ của bạn là hãy giải mã nó.

Input:
Dòng thứ nhất: Số nguyên dương n - số lượng từ trong bức mật thư (1 <= n <=100)
n dòng tiếp theo, mỗi dòng là một chuỗi ký tự s (bao gồm các ký tự 'a'..'z' , không có khoảng trắng). Chiều dài mỗi chuỗi không vượt quá 2000 ký tự.

Output:
n dòng, mỗi dòng là một chuỗi mà bạn giải mã được.

Ví dụ:

Input:
3
i
ovle
ocdpeur
Output:
i
love
upcoder

Input:
2
senyo
abba
Output:
yesno
baba
*/