#include <iostream>
#include <cmath>
using namespace std;

struct DIEM{ int x, y; };
istream& operator>>(istream& is, DIEM & diem){
	is >> diem.x >> diem.y;
	return is;
}
ostream& operator<<(ostream& os, DIEM  diem){
	os << "(" << diem.x << "," << diem.y << ")";
	return os;
}
float khoangCachDiem(DIEM a, DIEM b){
	return (float)sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
bool operator == (DIEM a, DIEM b){
	return khoangCachDiem(a, b) == 0;
}

struct TAMGIAC{ DIEM a, b, c; };
istream& operator>>(istream& is, TAMGIAC & tg){
	is >> tg.a >> tg.b >> tg.c;
	return is;
}
ostream& operator<<(ostream& os, TAMGIAC  tg){
	os << tg.a << tg.b << tg.c;
	return os;
}
float chuViTamGiac(TAMGIAC tg){
	float ab, bc, ac;
	ab = khoangCachDiem(tg.a, tg.b);
	bc = khoangCachDiem(tg.b, tg.c);
	ac = khoangCachDiem(tg.a, tg.c);
	return ab + bc + ac;
}
float operator+(TAMGIAC a, TAMGIAC b){
	return chuViTamGiac(a) + chuViTamGiac(b);
}
bool operator<(TAMGIAC a, TAMGIAC b){
	return chuViTamGiac(a) < chuViTamGiac(b);
}
bool operator == (TAMGIAC tg1, TAMGIAC tg2){
	if (tg1.a == tg2.a || tg1.a == tg2.b || tg1.a == tg2.c){
		if (tg1.b == tg2.a || tg1.b == tg2.b || tg1.b == tg2.c){
			if (tg1.c == tg2.a || tg1.c == tg2.b || tg1.c == tg2.c){
				return true;
			}
		}
	}

	return false;
}
int main() {
	TAMGIAC a, b;
	cin >> a >> b;
	cout << a << endl << b << endl;
	a < b ? cout << "TRUE" : cout << "FALSE";
	cout << endl;
	a == b ? cout << "TRUE" : cout << "FALSE";
	//system("pause");
	return 0;
}
/*
Yêu cầu 1:  Xây dựng cấu trúc ĐIỂM gồm tung độ và hoành độ (số nguyên)
-      Viết quá tải hàm nhập,xuất điểm

-      Viết hàm tính khoảng cách giữa 2 điểm

-      Viết quá tải so sánh bằng giữa 2 điểm: kiểm tra 2 điểm có trùng nhau không?

Yêu cầu 2: Xây dựng cấu trúc TAMGIAC gồm 3 điểm (PHẢI dựa vào cấu trúc ĐIỂM ở trên)

-      Viết quá tải hàm nhập,xuất (không cần kiểm tra điều kiện của tam giác, giả sư với 3 điểm bất kỳ đều là tam giác)

-      Viết hàm tính chu vi tam giác

-      Quá tải toán tử + hai tam giác (HD: cộng chu vi tam giác)

-      Quá tải toán tử <  dùng để so sánh 2 tam giác (HD: so sánh dựa vào chu vi)

-      Quá tải toán tử so sánh bằng dùng kiểm tra 2 TAM GIÁC có trùng nhau hay không?

Yêu cầu 3: nhập dữ liệu tọa độ của 2 tam giác theo cấu trúc

-      Dòng 1: 3 điểm của tam giác 1

-      Dòng 2: 3 điểm của tam giác 2
Xuất kết quả theo cấu trúc sau:

-      Dòng 1: xuất các tọa độ của tam giác 1

-      Dòng 2: xuất các tọa độ của tam giác 2

-      Dòng 1: ghi TRUE, nếu tam giác 1 < tam giác 2, ngược lại ghi FALSE

-      Dòng 2: ghi TRUE, nếu 2 tam giác trùng nhau, ngược lại ghi FALSE


Ví dụ:
Input:
1 2 3 4 5 6
7 8 9 0 1 2

Output:
(1,2)(3,4)(5,6)
(7,8)(9,0)(1,2)
TRUE
FALSE.
*/