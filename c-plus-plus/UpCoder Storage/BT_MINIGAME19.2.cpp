#include <iostream>
#include <string>
using namespace std;
int main() {
	string ten[100];
	int n = 0;
	while (cin >> ten[n]) {
		n++;
	}
	cout << "Ho: " << ten[0];
	if (n>2) {
		cout << "Lot: ";
		for (int i = 1; i<n - 1; i++) {
			cout << ten[i];
		}
	}
	cout << "Ten: " << ten[n - 1];
	return 0;
}
/*
Trong giờ học Lập trình về xử lý chuỗi. Thầy giáo có cho một bài tập như sau: Thầy sẽ đọc họ và tên của một bạn sinh viên bất kỳ trong lớp. Công việc của chúng ta là hãy viết một chương trình để tách Họ, Tên Lót (tên đệm), và Tên của bạn đó ra.

Input:
Một chuỗi duy nhất là họ tên của bạn sinh viên mà thầy đọc.
Lưu ý: Họ tên có thể chỉ gồm họ và tên (không có tên lót), hoặc đầy đủ họ, lót, tên.
Output:
Dòng 1: Xuất ra họ
Dòng 2: Xuất ra tên lót (nếu có).
Dòng 3: Xuất ra tên.
Lưu ý: Xuất theo đúng định dạng ví dụ mẫu:

Ví dụ:
Input
Cong Ton Sach
Output
Ho: Cong
Lot: Ton
Ten: Sach

Input
Nguyen Trai
Output
Ho: Nguyen
Ten: Trai

Input
Vo Sy Quyen Nang
Output
Ho: Vo
Lot: Sy Quyen
Ten: Nang
*/