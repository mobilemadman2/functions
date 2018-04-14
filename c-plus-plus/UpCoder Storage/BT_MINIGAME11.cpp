#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct TIME { int h, m, s; };
TIME getTime(string s) {
	TIME kq;
	kq.h = (s[0] - '0') * 10 + s[1] - '0';
	kq.m = (s[3] - '0') * 10 + s[4] - '0';
	kq.s = (s[6] - '0') * 10 + s[7] - '0';
	return kq;
}
ostream& operator<<(ostream& os, TIME t) {
	os << setfill('0') << setw(2) << t.h << ":";
	os << setfill('0') << setw(2) << t.m << ":";
	os << setfill('0') << setw(2) << t.s << endl;
	return os;
}
TIME operator+(TIME t, int n) {
	int sec = t.h * 3600 + t.m * 60 + t.s + n;
	if (sec > 86400) { sec %= 86400; }
	t.h = sec / 3600;
	if (t.h == 24) { t.h = 0; }
	t.m = (sec % 3600) / 60;
	t.s = sec % 60;
	return t;
}
int main() {
	string s; cin >> s;
	TIME t = getTime(s);
	int n; cin >> n;
	cout << t + n;
	system("pause");
	return 0;
}
/*
Viết chương trình nhập vào số chỉ đồng hồ hiện tại và cho biết sau t giây, đồng hồ sẽ chỉ bao nhiêu.

Dữ liệu đầu vào:
- Dòng đầu tiên chứa một chuỗi biểu diễn số chỉ đồng hồ (loại hiển thị 24 giờ) hiện tại theo mẫu hh:mm:ss
- Dòng tiếp theo chứa số nguyên t (0 <= t <= 86400)

Dữ liệu đầu ra: ghi lại số chỉ đồng hồ sau t giây theo định dạng hh:mm:ss

Ví dụ
input
00:00:00
20
output
00:00:20
*/