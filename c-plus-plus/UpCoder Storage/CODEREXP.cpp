#include <iostream>
#include <string>
using namespace std;
string level(int n) {
	int exp[12] = { 0,49,99,499,999,1499,1999,2499,3499,4199,5499,6999 };
	string lev[13] = { "So Sinh","Lop Mam","Lop Choi","Lop La","Tieu Hoc",
		"THCS","THPT","Trung Cap","Cao Dang","Dai Hoc","Thac Si","Tien Si","Giao Su" };
	for (int i = 0; i < 12; i++) {
		if (exp[i] - n >= 0) { return "Coder " + lev[i]; }
	}
	return "Coder " + lev[12];
}
int main() {
	// INPUT
	int exp = 0;
	for (int i = 10; i <= 40; i += 10) {
		int val; cin >> val;
		exp = exp + i*val;
	}
	// OUTPUT
	cout << exp << endl;
	cout << level(exp) << endl;
	system("pause");
	return 0;
}
/*
http://upcoder.xyz/index.php/problems/submit/528/f806510f17b829c40d2fcf2a9891c243/Kinh_nghi%E1%BB%87m_coder
Theo cách tính mới, mỗi bài tập sẽ có các cấp độ: cơ bản, trung bình, nâng cao, khó;
tương ứng với các số điểm 10, 20, 30, 40. Coder sẽ được cộng điểm kinh nghiệm tương ứng khi giải đúng 100% số test của bài đó.

Danh hiệu coder sẽ được đặt tùy theo kinh nghiệm mà coder đó đạt được. Cụ thể:

Cho trước số bài giải được của coder theo từng cấp độ. Hãy tính toán điểm kinh nghiệm và xem coder đó đang đạt danh hiệu nào.

Dữ liệu đầu vào: gồm 4 số nguyên dương (không lớn hơn 500) lần lượt là số bài giải được theo cấp độ cơ bản, trung bình, nâng cao, khó.

Dữ liệu đầu ra: gồm 2 dòng
- Dòng đầu tiên ghi lại điểm kinh nghiệm của coder.
- Dòng thứ hai ghi danh hiệu của coder đó (không dấu).

Ví dụ
input
20 10 2 1
output
500
Coder Tieu Hoc
*/