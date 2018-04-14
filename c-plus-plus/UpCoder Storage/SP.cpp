#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream in("SP.INP");
	ofstream out("SP.OUT");
	long m, n, t;
	in >> m >> n >> t;

	//nếu điều kiện tặng > số cần mua thì ko cần tính nữa
	if (m >= n) { out << n*t; }
	//nếu nhỏ hơn thì tính xem mua bao nhiêu thì vừa đủ
	if (m<n) {
		//s là số cần mua, tang là số đc tặng
		int s = m, tang = 1, dem = 0;
		//khi mà số đã mua + tặng chưa bằng với yêu cầu thì tiếp tục mua
		while (s + tang<n) {
			s++;
			dem++;
			//nếu mua đủ đk tặng thì đc tặng
			if (dem == m) { tang++; dem = 0; }
		}
		out << s*t;
	}
	return 0;
}
/*
Nhân dịp tổ chức OLP2012, siêu thị Big C tổ chức bán bút với chương trình  khuyến mãi như sau: Giá một chiếc bút là t đồng, khi mua m chiếc khách hàng được tặng thêm 1 chiếc. Để phục vụ kỳ thi, Ban tổ chức cần phải chuẩn bị ít nhất n bút phát cho các thí sinh dự thi.
Yêu cầu: Cho biết m, n và t. Tính số tiền S (đơn vị đồng) ít nhất cần có để mua bút.

Dữ  liệu nhập: từ tập tin SP.INP
- Gồm một dòng chứa ba số nguyên dương m, n và t (1 ≤ m ≤ 106, 0 ≤ n, t ≤ 106), mỗi số cách nhau một khoảng trắng.

Dữ liệu xuất: xuất ra tập tin SP.OUT

- Là một số nguyên xác định số tiền cần thiết.

Ví dụ
input
2 3 100
output
200
*/