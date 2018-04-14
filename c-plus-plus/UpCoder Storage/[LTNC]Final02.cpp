//http://upcoder.xyz/index.php/scoreboards/view/173123/e000a21343d05e7dca314085ae5fe573
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, subs[10], tmp; char c; int sl = 0;
	cin >> s >> c;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != c) { tmp += s[i]; }
		else {
			if (tmp.size() > 0) {
				subs[sl] = tmp; tmp = ""; sl++;
			}

		}
	}
	if (tmp.size() > 0) { cout << sl + 1 << endl; }
	else { cout << sl << endl; }
	for (int i = 0; i < sl; i++) {
		cout << subs[i] << endl;
	}
	cout << tmp;
	return 0;
}
/*
Hãy viết hàm để tách một chuỗi ban đầu thành một mảng các chuỗi con dựa vào một kí tự phân tách được chỉ định.
Lưu ý: trước khi tách chuỗi, phải kiểm tra nếu trong chuỗi có nhiều kí tự phân tách đứng liền nhau,
hoặc có kí tự phân tách đứng ở đầu chuỗi, hoặc cuối chuỗi, thì phải loại bỏ các kí tự thừa sao cho chỉ còn 1 kí tự phân tách giữa các từ, đầu chuỗi và cuối chuỗi không có kí tự phân tách
Vd:
Chuỗi ban đầu: ",abc,,xyz,,,123,456,,"
Kí tự phân tách: ,
Chuỗi sau khi loại bỏ kí tự thừa: "abc,xyz,123,456"
Input:
Dòng đầu tiên: chuỗi ban đầu
Dòng thứ hai: kí tự phân tách
Output:
Số lượng chuỗi con sau khi tách
Các dòng tiếp theo lần lượt là các chuỗi con tách được

Vd:
Input:
one,two,three,four,five
,
Output:
5
one
two
three
four
five
*/