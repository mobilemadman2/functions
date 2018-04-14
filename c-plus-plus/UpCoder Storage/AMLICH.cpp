#include <iostream>
#include <string>
using namespace std;

int main() {
	string can[10] = { "Canh","Tan","Nham","Quy","Giap","At","Binh","Dinh","Mau","Ky" };
	string chi[12] = { "Than","Dau","Tuat","Hoi","Ti","Suu","Dan","Meo","Thin","Ty","Ngo","Mui" };
	int nam; cin >> nam;
	cout << can[nam % 10] << " " << chi[nam % 12] << endl;
	system("pause");
	return 0;
}
/*
Theo quan niệm phương Đông, mỗi năm được gọi theo một tên ghép từ 10 can và 12 chi.
Cụ thể theo thứ tự như sau:
4
8
- 10 can: Giáp, Ất, Bính, Đinh, Mậu, Kỷ, Canh, Tân, Nhâm, Quý
- 12 chi: Tí, Sửu, Dần, Mẹo, Thìn, Tỵ, Ngọ, Mùi, Thân, Dậu, Tuất, Hợi
Ghép một can và một chi, ta được tên của một năm (ví dụ: Ất Mẹo, Quý Mùi,...).
Mỗi năm trôi qua lại lấy can và chi kế tiếp theo thứ tự trên để ghép với nhau.

Biết năm 2017 là năm Đinh Dậu, hãy tính toán các năm khác có tên âm lịch là gì.

Dữ liệu đầu vào: số nguyên n ghi lại năm cần biết tên (1800<=n<=3000)
Dữ liệu ra: tên âm lịch của năm tương ứng (viết không dấu).


Ví dụ
input
2018
output
Mau Tuat
*/