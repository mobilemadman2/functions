#include <iostream>
#include <string>
using namespace std;

//PHAN SO
struct PHANSO{ int tu, mau; };
istream& operator>>(istream& is, PHANSO & ps){
	is >> ps.tu >> ps.mau;
	return is;
}
ostream& operator<<(ostream& os, PHANSO  ps){
	os << ps.tu << "/" << ps.mau;
	return os;
}
bool operator!=(PHANSO ps1, PHANSO ps2){
	//theo yeu cau: 2 phân số khác nhau khi có thành phần tương ứng khác nhau
	return ps1.mau != ps2.mau && ps1.tu != ps2.tu;
}
int UCLN(long a, long b)
{
	return b == 0 ? a : UCLN(b, a%b);
}
PHANSO rutGonPS(PHANSO ps){
	int mauChung = UCLN(ps.tu, ps.mau);
	ps.tu /= mauChung;
	ps.mau /= mauChung;
	return ps;
}

//HON SO
struct HONSO { int honso;	PHANSO ps; };
istream& operator>>(istream& is, HONSO & hs){
	is >> hs.honso >> hs.ps;
	return is;
}
ostream& operator<<(ostream& os, HONSO hs){
	os << hs.honso << " " << hs.ps.tu << "/" << hs.ps.mau;
	return os;
}
HONSO rutGonHS(HONSO hs){
	//giu nguyen hon so, rut gon phan so
	hs.ps = rutGonPS(hs.ps);
	return hs;
}
HONSO rutGonHS2(HONSO hs){
	HONSO hs_toi_gian;
	hs_toi_gian.honso = hs.honso + hs.ps.tu / hs.ps.mau;
	hs_toi_gian.ps.tu = hs.ps.tu % hs.ps.mau;
	hs_toi_gian.ps.mau = hs.ps.mau;
	hs_toi_gian.ps = rutGonPS(hs_toi_gian.ps);
	return hs_toi_gian;
}
bool operator!=(HONSO hs1, HONSO hs2){
	//theo yeu cau: 2 hỗn số khác nhau khi có thành phần tương ứng của chúng khác nhau
	return hs1.honso != hs2.honso && hs1.ps != hs2.ps;
}
int tongThanhPhan(HONSO hs){
	return hs.honso + hs.ps.tu + hs.ps.mau;
}
bool operator>(HONSO hs1, HONSO hs2){
	return tongThanhPhan(hs1) > tongThanhPhan(hs2);
}

int main(){
	HONSO hs1, hs2;
	cin >> hs1 >> hs2;

	string mode;
	cin >> mode;

	hs1 != hs2 ? cout << "TRUE" : cout << "FALSE";
	hs1>hs2 ? cout << "TRUE" : cout << "FALSE";

	if (mode == "true"){
		//hon so rut gon
		cout << rutGonHS2(hs1) << endl << rutGonHS2(hs2) << endl;
	}
	else if (mode == "false"){
		//phan so rut gon
		PHANSO ps1, ps2;
		ps1.tu = hs1.honso*hs1.ps.mau + hs1.ps.tu;
		ps1.mau = hs1.ps.mau;
		ps2.tu = hs2.honso*hs2.ps.mau + hs2.ps.tu;
		ps2.mau = hs2.ps.mau;
		cout << rutGonPS(ps1) << endl << rutGonPS(ps2) << endl;
	}
	system("pause");
	return 0;
}
/*
Xây dựng Cấu trúc PhanSo gồm tử và mẫu.
Viết các hàm toán tử:
- Nhập và xuất cho PhanSo
- So sánh != khi so sánh 2 phân số (HD: 2 phân số khác nhau khi có thành phần tương ứng khác nhau)

Yêu cầu 2: Xây dựng cấu trúc hỗn số gồm  một phần nguyên a và một phân số b/c
, trong đó a, b,c ∈ Z (interger)
(yêu cầu PHẢI sử dụng lại cấu trúc PhanSo ở trên)

a)   Viết quá tải nhập và xuất cho cấu trúc trên

b)   Sử dụng tham số mặc định, yêu cầu viết hàm chuyển đổi hỗn số sang hỗn số tối giản hoặc chuyển sang phân số tối giản.
(tham số mặc định áp dụng để chuyển sang hỗn số tối giản)
ví dụ: với hỗn số 4 8/6 , rút gọn thành 5 1/3, chuyển sang phân số thành

c)    Hãy cài đặt quá tải tóan tử khác != khi so sánh 2 Hỗn Số. (HD: 2 hỗn số khác nhau khi có thành phần tương ứng của chúng khác nhau)

d)   Viết hàm tongCacThanhPhan dùng để tính tổng các thành phần của hổn số
ví dụ: hỗn số 1 2/3 , kết quả trả về của hàm tongCacThanhPhan là: 6 (=1+2+3)

e)    Dựa vào hàm của câu d), hãy viết quá tải toán tử lớn hơn > để so sánh tổng các thành phần của 2 Hỗn Số.
Ví dụ:   >    (do: 4+ 5 + 6 = 15  > 1 + 2 +3)

Yêu cầu 3:
Viết chương trình nhập vào theo cấu trúc sau:
Input
- Dòng 1: gồm 3 số của hỗn số 1
- Dòng 2: gồm 3 số của hỗn số 2.
- Dòng 3: nếu là chữ “true” yêu cầu rút gọn 2 hỗn số đó thành hỗn số rút gọn, nếu là false yêu cầu thành phân số rút gọn.
Dữ liệu xuất:

Output
- Dòng 1: xuất TRUE nếu 2 hỗn số khác nhau, ngược lại xuất FALSE.
- Dòng 2: xuất TRUE nếu hỗn số 1 “lớn hơn” hỗn số 2, ngược lại xuất FALSE (dựa vào câu e )
- Dòng 3: xuất dạng rút gọn của hỗn số 1
- Dòng 4: xuất dạng rút gọn của hỗn số 2.
(lưu ý: dòng 1 và dòng 2 áp dụng cho hỗn số ban đầu chưa rút gọn)

Input
2 8 6
1 2 3
true

output
TRUE
TRUE
3 1/3
1 2/3
*/