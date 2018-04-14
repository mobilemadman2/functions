#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int sum = 0, d = 1;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'D' || s[i] == 'd') { sum += d; d++; }
		else { d = 1; }
	}
	cout << sum;
	return 0;
}
/*
Ban tổ chức sẽ dùng máy tính để tính số điểm của đội đó. Điểm số được tính như sau:
Với mỗi câu trả lời sai, đội không được cộng điểm
Với mỗi câu trả lời đúng, đội đó sẽ nhận được điểm bằng số lần trả lời đúng liên tiếp từ câu trả lời này trở về trước.
Ví dụ: Với chuỗi kết quả thi của đội là: "DDSSDSSDDD" thì điểm số ở vòng thi này của đội là: 1+2+0+0+1+0+0+1+2+3 = 10

Yêu cầu: Bạn hãy tính thử xem với xâu kết quả độ dài không quá 1000 ký tự thì đội đó đạt bao nhiêu điểm.

Input:
Xâu kết quả của đội tham gia vòng thi Khởi Động
Output:
Số điểm của đội đó

Ví dụ:
Input
DDSSDSSDDD
Output
10
*/