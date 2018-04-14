#include <iostream>
#include <string>
using namespace std;
//FIND >> tìm số chuỗi a trong chuỗi b (aba trong ababa => 2)
int countStringAinB(string a, string b) {
	int counter = 0, position = 0;
	while (true)
	{
		position = b.find(a, position);
		if (position != -1)
		{
			counter++;
			position++;
		}
		else break;
	}
	return counter;
}
int main() {
	int n; cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		cout << countStringAinB("Happy new year 2017", s);
	}
	system("pause");
	return 0;
}
/*
Để chào mừng năm mới 2017, UPCoder sẽ tặng điểm thưởng cho tất cả các tài khoản.
Mỗi tài khoản tùy theo sự siêng năng giải bài của mình mà được tặng số điểm tương ứng.
Tuy nhiên admin không cho biết trước số điểm sẽ tặng mà mã hóa nó trong một chuỗi ký tự dưới dạng tin nhắn.
Số lượng chuỗi "Happy new year 2017" trong tin nhắn sẽ là số điểm thưởng cho tài khoản nhận được.

Cho chuỗi ký tự, bạn hãy tính toán xem số điểm thưởng là bao nhiêu nhé.

Dữ liệu đầu vào:
- Số nguyên n là số lượng tài khoản nhận được tin nhắn (1<=n<=100000)
- n dòng tiếp theo là các chuỗi ký tự (có khoảng trắng) mà các tài khoản nhận được.

Dữ liệu đầu ra: gồm n dòng ghi lại số điểm thưởng của các tài khoản theo thứ tự đầu vào.

Ví dụ:
Input: 2016 Happy new year 2017 Happy new year 2017 Happy
Output: 1
*/