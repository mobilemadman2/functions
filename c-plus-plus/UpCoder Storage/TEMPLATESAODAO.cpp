#include <iostream>
#include <cmath>
using namespace std;
struct SoDao {
	int abc;
	int reverseInt() {
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
template <class var>
struct khuonHinh {
	var a[100];
	int n = 0;
	var& operator[](int i) { return a[i]; }
	void sum() {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum = a[i] + sum;
		}
		n == 0 ?
			cout << "khong co" << endl :
			cout << sum << endl;
	}
	void max() {
		var max = a[0];
		for (int i = 1; i < n; i++) {
			if (a[i]>max) { max = a[i]; }
		}
		n == 0 ?
			cout << "khong co" << endl :
			cout << max << endl;
	}
};
template <class var>
istream& operator >> (istream& is, khuonHinh<var>& a) {
	is >> a[a.n]; a.n++;
	return is;
}
void cau2() {
	khuonHinh<int> a;
	khuonHinh<SoDao> b;
	char c;
	while (cin >> c) {
		if (c == 'T') { cin >> a; }
		if (c == 'D') { cin >> b; }
	}
	a.sum(); a.max(); b.sum(); b.max();
}
int main() {
	//cau1();
	cau2();
	return 0;
}
/*
Xây dựng chương trình có sử dụng khuôn hình, áp dụng cho bài sau:

Viết chương trình nhập vào 1 dãy số gồm nhiều loại số, yêu cầu xuất ra tổng của từng loại số ra màn hình.

Với các qui ước:

o   Kiểu T: là số nguyên

o   Kiểu D: là SoDao (đã được mô tả ở đây)

Dữ liệu đầu vào:

o   Gồm nhiều dòng còn lại, mỗi dòng chứa kiểu và 1 số thuộc kiểu đó

Dữ liệu đầu ra:

Ghi ra 3 dòng:

·         Dòng 1: tổng của loại số nguyên

·         Dong 2: số lớn nhất của loại số nguyên

·         Dòng 3: tổng của loại SoDao

·         Dòng 4: số lớn nhất của loại SoDao

Nếu không tìm thấy tổng, số lớn nhất của loại nào thì xuất kết quả “khong co” (chữ thường, không dấu) tại vị trí của loại đó

Ví dụ 1:

Input:

T 1

D 127

T 3

D  456

Output:

4

3

1375

[SoDao] 127

Ví dụ 2:

Input:

D 127

D  456





Output:

khong co

khong co

1375

[SoDao] 127
*/