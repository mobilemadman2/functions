#include <iostream>
#include <string>
using namespace std;

string docMotChuSo(int n){
	switch (n){
	case 0:return "khong"; break;
	case 1:return "mot"; break;
	case 2:return "hai"; break;
	case 3:return "ba"; break;
	case 4:return "bon"; break;
	case 5:return "nam"; break;
	case 6:return "sau"; break;
	case 7:return "bay"; break;
	case 8:return "tam"; break;
	case 9:return "chin"; break;
	case 10:return "muoi"; break;
	case -5:return "lam"; break;
	case -10:return ""; break;
	default:return "watashiha fukudesu.";
	}
}

string docHaiChuSo(int n){
	int hangChuc = n / 10, hangDv = n % 10;

	//tu so 10 tro len, dang don vi =5 doc la "lam" | -5 = "lam"
	if (n > 10 && hangDv == 5){ hangDv = -5; }

	//tu so 20, hang don vi = 0 bien thanh rong | -10 = ""
	if (n >= 20 && hangDv == 0){ hangDv = -10; }

	//tu so 20 tro len, giua hang chuc va hang don vi them chu "muoi"
	string bonus = " ";
	if (n >= 20){ bonus = " muoi "; }

	//neu so < 10 doc luon
	if (n <= 10) return docMotChuSo(n);

	//case: so trong khoang 11-19 doc la "muoi" + hang don vi
	if (n > 10 && n < 20) return docMotChuSo(10) + bonus + docMotChuSo(hangDv);

	//case: so >=20 doc hang chuc + "muoi" + hang don vi
	if (n >= 20) return docMotChuSo(hangChuc) + bonus + docMotChuSo(hangDv);
}
int main(){
	int n;
	cin >> n;
	cout << docHaiChuSo(n);
	system("pause");
	return 0;
}
/*
Nhập vào 1 số gồm 2 chữ số, yêu cầu xuất ra cách đọc chữ đó ra màn hình (gõ không dấu, chữ thường)

ví dụ
input:
12

output
muoi hai
*/