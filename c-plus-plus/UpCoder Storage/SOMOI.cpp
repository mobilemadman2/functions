#include <iostream>
using namespace std;
struct SoMoi {
	int a;
	int sumOfInt() {
		int tong = 0;
		while (a > 0) {
			tong += a % 10;
			a /= 10;
		}
		return tong;
	}
};
istream& operator >> (istream& is, SoMoi& sm) {
	is >> sm.a;
	return is;
}
ostream& operator << (ostream& os, SoMoi sm) {
	os << "[SoMoi]" << sm.a << endl;
	return os;
}
bool operator > (SoMoi a, SoMoi b) {
	return a.sumOfInt() > b.sumOfInt();
}
int operator + (SoMoi a, SoMoi b) {
	return a.sumOfInt() + b.sumOfInt();
}
void cau1() {
	SoMoi a, b;
	cin >> a >> b;
	cout << a << b;
	cout << (a > b ? "true" : "false");
	cout << a + b;
}
int main() {
	cau1();
	system("pause");
	return 0;
}
/*
Yêu cầu 1:
Xây dựng cấu trúc SoMoi (Số Mới) biểu diễn một cấu trúc mới gồm 1 thành phần:
- Một số nguyên A (0<= A <= 1.000.000).
Yêu cầu xây dựng các hàm sau:

1. Quá tải nhập và xuất SoMoi (xem ví dụ để hiểu rõ hơn cách xuất 1 SoMoi)

2. Tính tổng các chữ số của SoMoi (tổng các chữ số của A).

3. Quá tải so sánh > hai SoMoi: dựa vào tổng các chữ số (tổng các chữ số SoMoi nào lớn hơn thì sẽ xác định số đó là số lớn hơn)

4. Quá tải cộng + với tham số là cộng 2 SoMoi, nội dung của hàm: tổng các chữ số của 2 SoMoi cộng lại với nhau , hàm trả về là 1 SoMoi.
Yêu cầu 2:
Sử dụng cấu trúc ở trên, giải bài tập với các yêu cầu sau:

Input:
Gồm 2 dòng, mỗi dòng chứa 1 nguyên đại diện cho 2 SoMoi.
Output:
-          Dòng 1: Xuất thông tin của SoMoi 1
-          Dòng 2: Xuất thông tin của SoMoi 2

-          Dòng 3: xuất chữ “true” (không có dấu “ ) nếu SoMoi 1 > SoMoi 2, ngược lại xuất “false” (không có dẫu “ )

-          Dòng 4: Xuất tổng SoMoi 1 và SoMoi 2


Ví dụ:

Input

Output

21
34

[SoMoi] 21

[SoMoi] 34

false
10
*/