#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, k, len[100], shorter = 0, longer = 0;
	cin >> n >> k;
	for (int i = 0; i <= n; i++) {
		cin.ignore();
		string s; cin >> s;
		if (i == n) {
			for (int j = 0; j < n; j++) {
				if (len[j] < s.length()) {
					shorter++;
				}
				else if (len[j] > s.length()) {
					longer++;
				}
			}
		}
		len[i] = s.length();
	}
	cout << shorter / k * 5 + shorter / k*k + shorter%k << " ";
	longer = n - longer;
	cout << longer / k * 5 + longer / k*k + longer%k;
	system("pause");
	return 0;
}
/*
Tèo tham gia rất nhiều diễn đàn, websites học tập. Mỗi nơi Tèo đều tạo tài khoản cá nhân.
Trong một lần Tèo đăng nhập vào hệ thống Upcoder để làm bài tập.
Không may rằng Tèo không nhớ rõ mật khẩu chính xác là gì.
Khi đó Tèo nhập ngẫu nhiên mật khẩu theo trí nhớ mà mình từng đặt.Tèo sẽ nhập các mật khẩu
theo thứ tự độ dài ngắn nhập trước, đến khi mật khẩu chính xác thì Tèo sẽ login thành công.
Một mật khẩu Tèo sẽ không nhập 2 lần.
Biết rằng, để nhập một mật khẩu Tèo mất 1s, tuy nhiên nếu nhập sai k lần,
Tèo sẽ phải đợi 5s sau mới được nhập tiếp.
Bạn hãy xác định xem, thời gian tối thiểu và thời gian tối đa để Tèo có thể login thành công.

Input:
Dòng thứ nhất: 2 số nguyên dương n, k (1 <= n,k <= 100). Trong đó: n là số mật khẩu Tèo dự định sẽ nhập,
k là số lần nhập sai mật khẩu liên tiếp cho phép. Nếu nhập sai k lần thì Tèo phải đợi 5s mới được nhập tiếp.
n dòng tiếp theo, mỗi dòng là một chuỗi ký tự từ 'a'...'z'; '0'...'9'.
Không bao gồm ký tự đặc biệt và khoảng trắng. Độ dài mỗi chuỗi không vượt quá 100.
Dòng cuối cùng: mật khẩu chính xác mà Tèo sẽ login thành công nếu nhập đúng mật khẩu này.

Output:
Dòng duy nhất gồm 2 số nguyên dương a, b cách nhau một khoảng trắng.
Là thời gian tối thiểu và thời gian tối đa để Tèo login hệ thống thành công.

Ví dụ:
Input:
5 2
cba
abc
aa1
ABC
Abc
abc

Output:
1 15
Giải thích:
Trường hợp tốt nhất: Tèo nhập đúng mật khẩu "abc" ở ngay lần thứ nhất.
Nên Tèo chỉ mất 1s để nhập mật khẩu này và login thành công.
Trường hợp xấu nhất: Tèo sẽ nhập mật khẩu đúng ở lần cuối cùng.
Tức là Tèo sẽ nhập 4 mật khẩu sai trước. Tèo mất 2s để nhập 2 mật khẩu sai đầu tiên, sau đó phải đợi 5s.
Tiếp tục nhập 2 mật khẩu nữa, rồi lại đợi 5s. Cuối cùng là 1s để nhập mật khẩu đúng. Tổng cộng Tèo mất 15s.

Input:
4 10
ab
ca
a
b
ab

Output:
3 4
Giải thích:
Trường hợp tốt nhất: Do Tèo nhập các mật khẩu ngắn hơn trước, nên mất 2s để nhập chúng.
Và mật khẩu tiếp theo Tèo nhập đúng nên mất tổng cộng 3s.
Trường hợp xấu nhất: Tèo nhập mật khẩu đúng ở lần cuối cùng. Mất tất cả 4s để login.
*/