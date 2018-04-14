#include <iostream>
#include <cmath>
#include <string>
using namespace std;
//DIEM
struct Diem { int x, y; };
istream& operator >> (istream& is, Diem& d) {
	is >> d.x >> d.y;
	return is;
}
ostream& operator << (ostream& os, Diem d) {
	os << "(" << d.x << "," << d.y << ")";
	return os;
}
double operator - (Diem a, Diem b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)); //sqrt((x1-x2)^2+(y1-y2)^2)
}
//DUONG TRON
struct DuongTron { Diem tam; int banKinh; };
istream& operator >> (istream& is, DuongTron& dt) {
	is >> dt.tam.x >> dt.tam.y >> dt.banKinh;
	return is;
}
ostream& operator << (ostream& os, DuongTron dt) {
	os << "(x-" << dt.tam.x << ")^2+(y-" << dt.tam.y << ")^2=" << dt.banKinh*dt.banKinh;//(x-a)^2+(y-b)^2=R^2
	return os;
}
bool operator == (DuongTron a, DuongTron b) {
	return a.banKinh == b.banKinh && a.tam.x == b.tam.x && a.tam.y == b.tam.y;
}
bool operator < (DuongTron a, DuongTron b) {
	return a.banKinh < b.banKinh;
}
Diem toaDoTam(DuongTron c) { return c.tam; }
int banKinh(DuongTron c) { return c.banKinh; }
int main() {
	//1. Nhập vào tọa độ điểm A
	Diem a; cin >> a;
	//2. Nhập vào các thành phần của đường tròn C1
	//3. Nhập vào các thành phần của đường tròn C2
	DuongTron c1, c2; cin >> c1 >> c2;
	//4. Nhập vào phương trình đường tròn C3. (Định dạng của phương trình như trên, đảm bảo tọa độ tâm là số nguyên dương)
	string s; cin >> s;
	//5. Xuất ra màn hình tọa độ điểm A, phương trình đường tròn C1, phương trình đường tròn C2
	cout << a << endl << c1 << endl << c2 << endl;
	//6. Kiểm tra 2 đường tròn có trùng nhau hay không
	cout << (c1 == c2 ? "YES" : "NO") << endl;
	//7. So sánh 2 hình tròn C1 < C2, C1 > C2, C1 = C2
	cout << (c1.banKinh == c2.banKinh ? "C1 = C2" : c1 < c2 ? "C1 < C2" : "C1 > C2") << endl;

	//8. Kiểm tra điểm A có nằm trong, nằm ngoài, hay nằm trên đường tròn C1 và C2
	string viTri = "trong";
	if (c1.tam - a == c1.banKinh) { viTri = "tren"; }
	else if (c1.tam - a > c1.banKinh) { viTri = "ngoai"; }
	cout << "A nam " << viTri << " C1" << endl;
	viTri = "trong";
	if (c2.tam - a == c2.banKinh) { viTri = "tren"; }
	else if (c2.tam - a > c2.banKinh) { viTri = "ngoai"; }
	cout << "A nam " << viTri << " C2" << endl;

	//9. Xuất ra màn hình tọa độ tâm của đường tròn C3 và bán kính của đường tròn C3
	//(x-12)^2+(y-5)^2=16 => Tam (12,5) Ban kinh 4
	string tam = "Tam ("; int bKinh = 0;
	int i = 3;
	for (; s[i + 1] - '0' <= 9; i++) {
		tam += s[i];
	}
	tam += ",";
	for (i = tam.length() + 4; s[i + 1] - '0' <= 9; i++) {
		tam += s[i];
	}
	tam += ") Ban kinh ";
	int j = 0;
	for (i = s.length() - 1; s[i] - '0' <= 9; i--) {
		bKinh += (s[i] - '0') * pow(10, j);
		j++;
	}
	cout << tam << sqrt(bKinh) << endl;
	system("pause");
	return 0;
}
/*
Yêu cầu 1:

Xây dựng cấu trúc Diem gồm hoành độ và tung độ là 2 số nguyên dương, yêu cầu viết các quá tải sau:

quá tải nhập (>>) để nhập điểm (nhập hoành độ và tung độ)
quá tải xuất (<<) để xuất tọa độ điểm – cách xuất theo dạng (x,y)
quá tải toán tử trừ (-) để tính khoảng cách giữa 2 điểm.
Ví dụ: kc = A - B là khoảng cách giữa 2 điểm AB


Yêu cầu 2:

Xây dựng cấu trúc DuongTron gồm tâm và bán kính (tâm là 1 điểm và bán kính là số nguyên dương)
1. Viết quá tải sau:
quá tải nhập (>>) để nhập các thành phần của đường tròn (gồm tọa độ tâm và bán kính)
quá tải xuất (<<) để xuất phương trình đường tròn (xem ví dụ để hiểu rõ)

Biết rằng: phương trình đường tròn có tâm I(a,b) và bán kính R có dạng:
(x-a)^2+(y-b)^2=R^2

quá tải so sánh bằng (==) kiểm tra 2 đường tròn trùng nhau. Biết rằng, 2 đường tròn trùng nhau khi có bán kính bằng nhau và trùng tâm.
quá tải so sánh bé hơn (<) để so sánh 2 hình tròn.
2. Viết các hàm sau:
Hàm toaDoTam(DuongTron C) trả về điểm là tâm của đường tròn C
Hàm banKinh(DuongTron C) trả về bán kính của đường tròn C

Yêu cầu 3:
Viết chương trình thực hiện các yêu cầu sau:
1. Nhập vào tọa độ điểm A
2. Nhập vào các thành phần của đường tròn C1
3. Nhập vào các thành phần của đường tròn C2
4. Nhập vào phương trình đường tròn C3. (Định dạng của phương trình như trên, đảm bảo tọa độ tâm là số nguyên dương)
5. Xuất ra màn hình tọa độ điểm A, phương trình đường tròn C1, phương trình đường tròn C2
6. Kiểm tra 2 đường tròn có trùng nhau hay không
7. So sánh 2 hình tròn C1 < C2, C1 > C2, C1 = C2
8. Kiểm tra điểm A có nằm trong, nằm ngoài, hay nằm trên đường tròn C1 và C2
9. Xuất ra màn hình tọa độ tâm của đường tròn C3 và bán kính của đường tròn C3

Input:
Dòng 1: 2 số nguyên dương cách nhau một khoảng trắng là tọa độ điểm A
Dòng 2: 3 số nguyên dương là các thành phần của đường tròn C1
Dòng 3: 3 số nguyên dương là các thành phần của đường tròn C2
Dòng 4: chuỗi s biểu diễn phương trình đường tròn C3
Output:
Dòng 1: Tọa độ điểm A
Dòng 2: Phương trình đường tròn C1
Dòng 3: Phương trình đường tròn C2
Dòng 4: Nếu C1 trùng C2 thì xuất "YES" ngược lại xuất "NO". Không xuất dấu ngoặc kép
Dòng 5: Xuất C1 < C2 hoặc C1 > C2 hoặc C1 = C2 (có ý nghĩa là so sánh 2 hình tròn)
Dòng 6: Xuất "A nam trong C1" hoặc "A nam ngoai C1" hoặc "A nam tren C1" tương ứng từng trường hợp của yêu cầu số 8
Dòng 7: Xuất "A nam trong C2" hoặc "A nam ngoai C2" hoặc "A nam tren C2" tương ứng từng trường hợp của yêu cầu số 8
Dòng 8: Xuất ra tọa độ tâm I của đường tròn C3 và bán kính của đường tròn C3. Định dạng theo mẫu: "Tam (x,y) Ban kinh R"

Ví dụ:
Input
4 3
2 3 2
6 4 3
(x-12)^2+(y-5)^2=16
Output
(4,3)
(x-2)^2+(y-3)^2=4
(x-6)^2+(y-4)^2=9
NO
C1 < C2
A nam tren C1
A nam trong C2
Tam (12,5) Ban kinh 4
*/