#include <iostream>
#include <string>
using namespace std;
void mailFilter() {
	string s;
	while (cin >> s) {
		if (s.find("@gmail.com") != -1) {
			cout << s << endl;
		}
	}
}
int main() {
	mailFilter();
	return 0;
}
/*
Hiện nay , facebook là mạng xã hội khá đình là đình đám .Có một thầy giáo dạy toán online khá là nổi tiếng đã viết ra một cuốn sách dành cho học sinh cấp 3 ôn thi đại học .Thầy giáo sẽ gửi miễn phí bản pdf của cuốn sách cho những ai để lại mail dưới phần comment status của thầy. Tuy nhiên khi thầy giáo đăng bài trên facebook đã nảy sinh một vấn đề là có quá nhiều mail dưới phần comment .Hãy viết chương trình lọc mail từ comment ở trên facebook để giúp thầy giáo có thể gửi sách cho các bạn học sinh .

ví dụ:
input
namxuanbui29@gmail.com
Thích · Trả lời · 23 Tháng 3 lúc 19:21
Trang Thùy
Trang Thùy thuytrangg579@gmail.com
Thích · Trả lời · 24 Tháng 3 lúc 17:43
Hải yến
Hải yến khuatthiyen11@gmail.com
Thích · Trả lời · 24 Tháng 3 lúc 21:26
Nguyễn Thanh Hiệp
Nguyễn Thanh Hiệp daichizan1998@gmail.com
Thích · Trả lời · 24 Tháng 3 lúc 21:50
Vân Nguyễn
Vân Nguyễn nguyenvan16061999@gmail.com
Thích · Trả lời · 24 Tháng 3 lúc 22:39
Hồng My-A
Hồng My-A hongmya6789@gmail.com
output
namxuanbui29@gmail.com
thuytrangg579@gmail.com
khuatthiyen11@gmail.com
daichizan1998@gmail.com
nguyenvan16061999@gmail.com
hongmya6789@gmail.com
*/