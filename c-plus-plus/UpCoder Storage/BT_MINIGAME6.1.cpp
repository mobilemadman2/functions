#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n; cin >> n;
	int a[1000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int save[1000], s = 0;
	for (int i = 1; i < n - 1; i++) {
		if (a[i] == a[i - 1] * a[i + 1]) { save[s] = i + 1; s++; }
	}
	if (s == 0) { cout << -1; }
	else {
		cout << s << endl;
		sort(a, a + s);
		for (int i = 0; i < s; i++) {
			cout << save[i] << " ";
		}
	}
	system("pause");
	return 0;
}
/*
Cho một dãy các số nguyên, hãy tìm những vị trí trong dãy số đã cho thoả 2 điều kiện:
Có 2 giá trị lân cận
Giá trị tại vị trí đó bằng tích 2 giá trị lân cận
Nếu không tồn tại giá trị như vậy thì xuất ra "-1" (không có dấu ngoặc kép)

Dữ liệu vào:
Dòng 1: số nguyên dương n.
Dòng 2: n số nguyên của dãy số, mỗi số cách nhau một khoảng trắng.

Dữ liệu ra:
Dòng 1: số lượng giá trị thoả đề bài
Dòng 2: danh sách các vị trí mà các giá trị thoả điều kiện đề bài theo thứ tự tăng dần, mỗi phần tử cách nhau 1 khoảng trắng.
Lưu ý: Dữ liệu đảm bảo tất cả các giá trị không vượt quá 1000.

Ví dụ:
Input
6
1 2 8 4 20 5
Output
2
3 5
*/