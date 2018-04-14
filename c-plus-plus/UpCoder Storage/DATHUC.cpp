#include <iostream>
using namespace std;
struct BACNHAT{ int a, b; };
istream& operator>>(istream& in, BACNHAT& dt){
	in >> dt.a >> dt.b;
	return in;
}
ostream& operator<<(ostream& out, BACNHAT dt){
	out << dt.a << "x+" << dt.b;
	return out;
}
int tinhFx(BACNHAT dt, int x){
	return dt.a*x + dt.b;
}
BACNHAT operator+(BACNHAT a, BACNHAT b){
	BACNHAT sum;
	sum.a = a.a + b.a;
	sum.b = a.b + b.b;
	return sum;
}
bool operator ==(BACNHAT bn1, BACNHAT bn2)
{
	return bn1.a + bn1.b == bn2.a + bn2.b;
}

int main() {
	BACNHAT f1, f2;
	cin >> f1 >> f2;

	int x;
	cin >> x;

	//2x+3
	cout << f1 << endl;
	cout << f2 << endl;
	//2x+3+5x+6=7x+9
	cout << f1 << "+" << f2 << "=" << f1 + f2 << endl;
	cout << tinhFx(f1, x) << endl << tinhFx(f2, x) << endl;
	f1 == f2 ? cout << "TRUE" : cout << "FALSE";
	system("pause");
	return 0;
}
/*
Xây dựng cấu trúc BACNHAT biểu diễn một đa thức bậc 1 có dạng ax+b, trong đó a,b là số nguyên
Yêu cầu 1:
a) Xây dựng cấu trúc trên.
b) Viết quả tải toán tử nhập và xuất cho cấu trúc trên (nhập hệ số a,b)
c) Viết hàm tính giá trị của BACNHAT với giá trị x cụ thể
ví dụ: với F(x) =  2x + 3 và x = 2;
F(2) =   2*2 + 3 =  4 +3 =7
d) Hãy cài đặt hàm quá tải toán tử cộng 2 BACNHAT bằng cách cộng từng hệ số với nhau,
kết quả trả về 1 BACNHAT.
ví dụ:
F1(x) = 2x + 3
F2(x) = 5x + 6
=> Tong(x) = 7x + 9
e) hãy cài đặt quá tải toán tử so sánh bằng, so sánh 2 BACNHAT bằng xét tổng 2 hệ số a+b
ví dụ:
F1(x) = 2x + 3
F2(x) = 5x + 6
F1 không bằng F2, vì 2 + 3 != 5+6

Yêu cầu 2:
Viết chương trình nhập vào theo cấu trúc sau
- Dòng 1 là 2 hệ số của 1 BACNHAT F1
- Dòng 2 là 2 hệ số của 1 BACNHAT F2
- Dòng 3 là 1 số nguyên x0

Xuất kết quả theo cấu trúc sau:
- Dòng 1: xuất F1 (dạng đầy đủ ax+b)
- Dòng 2: xuất F2 (dạng đầy đủ ax+b)
- Dòng 3: xuất tổng F1 và F2 (xem cách xuất ở ví dụ bên dưới)
- Dòng 4: giá trị F1(x0)
- Dòng 5: giá trị F2(x0)
- Dòng 6: xuất TRUE nếu 2 BACNHAT bằng nhau, ngược lại xuất FALSE

Ví dụ:

Input
2 3
5 6
2

Output
2x+3
5x+6
2x+3+5x+6=7x+9
7
16
FALSE
*/