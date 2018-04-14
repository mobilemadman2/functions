#include <iostream>
#include <cmath>
using namespace std;
struct SoDao {
	int abc;
	int reverseInt() {
		bool check = false;
		if (abc < 0) { abc = abc*-1; check = true; }
		//lấy chiều dài số
		int len = 1;
		int tmp = abc;
		while (tmp /= 10) { len++; }
		//tính toán
		int rev = 0;
		while (abc > 0)
		{
			rev = rev + (abc % 10)*(int)pow(10, len - 1);
			len--;
			abc /= 10;
		}
		if (check) { rev = rev*-1; }
		return rev;
	}
};
istream& operator >> (istream& is, SoDao& sd) {
	is >> sd.abc;
	return is;
}
ostream& operator<<(ostream& os, SoDao sd) {
	os << "[SoDao]" << sd.abc;
	return os;
}
bool operator > (SoDao a, SoDao b) {
	return a.reverseInt() > b.reverseInt();
}
int operator + (SoDao sd, int n) {
	return sd.reverseInt() + n;
}
void cau1() {
	SoDao a, b;
	cin >> a >> b;
	cout << a << b;
	cout << (a > b ? "YES" : "NO") << endl;
	cout << b + (a + 0) << endl;
}
int main() {
	cau1();
	return 0;
}
/*
Yêu cầu 1:
Xây dựng cấu trúc SoDao (Số Đảo) biểu diễn một cấu trúc mới gồm 1 thành phần:
-  Một số tự nhiên có 3 chữ số.
Yêu cầu xây dựng các hàm sau:
1. Quá tải nhập và xuất SoDao (xem ví dụ để hiểu rõ hơn cách xuất 1 SoDao)
2. Viết hàm trả về số đảo ngược của SoDao (bằng cách trả về số ngược ).
3. Quá tải so sánh > hai SoDao: giá trị đảo ngược (giá trị đảo ngược của SoDao nào lớn hơn thì sẽ xác định số đó là số lớn hơn)
4. Quá tải cộng + với tham số là 1 SoDao và 1 số nguyên, nội dung hàm là lấy giá trị đảo ngược của SoDao cộng với số nguyên đó, kết trả về của hàm là 1 số nguyên.
Yêu cầu 2:
Sử dụng cấu trúc ở trên, giải bài tập với các yêu cầu sau:

Input:
Gồm 2 dòng, mỗi dòng chứa 1 số tự nhiên có 3 chữ số đại diện cho số SoDao (Dữ liệu đầu vào đảm bảo mỗi dòng chứa 1 số tự nhiên có 3 chữ số).
Output:
-   Dòng 1: Xuất thông tin của SoDao 1
-   Dòng 2: Xuất thông tin của SoDao 2
-   Dòng 3: xuất chữ “YES” (không có dấu “ ) nếu SoDao 1 > SoDao 2, ngược lại xuất “NO” (không có dấu “ )
-   Dòng 4: Xuất tổng SoDao 1 và SoDao 2
(Sử dụng toán tử + được mô tả ở trên, HD: lấy SoDao 1 cộng với số 0, sau đó lấy kết quả cộng với SoDao 2)

Ví dụ:

Input

Output

127
456

[SoDao] 127

[SoDao] 456

YES
1375


Lưu ý: mỗi yêu cầu bị thiếu sẽ bị trừ 1 điểm
*/