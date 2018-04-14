#include <iostream>
#include <string>
using namespace std;
struct GateWay {
	string maso[100], sdt[100], nhamang[100];
	int n = 0;
	void print(string s) {
		string mang = "Mobi";
		if (s.find("098") == 0) {
			mang = "Viettel";
		}
		else if (s.find("091") == 0) {
			mang = "Vinaphone";
		}
		for (int i = 0; i < n; i++) {
			if (nhamang[i] == mang) {
				cout << maso[i] << ":" << sdt[i] << ":" << nhamang[i] << endl;
			}
		}
	}
};
istream& operator >> (istream& is, GateWay& gw) {
	is >> gw.maso[gw.n] >> gw.sdt[gw.n] >> gw.nhamang[gw.n];
	gw.n++;
	return is;
}
int main() {
	GateWay a;
	int n; cin >> n; cin.ignore();
	for (int i = 0; i < n; i++) {
		cin >> a;
	}
	string sdt; cin >> sdt;
	a.print(sdt);
	system("pause");
	return 0;
}
/*
SMG Gateway là một thiết bị để quản lý hàng loạt SIM điện thoại.
Mỗi thiết bị có thể chứa N slot để gắn SIM. Mỗi slot như vậy sẽ có các thông tin như:
mã số (kiểu chuỗi, tối đa 10 kí tự), số điện thoại của SIM (kiểu chuỗi, tối đa 11 kí tự i),
nhà mạng cung cấp (kiểu chuỗi, tối đa 20 kí tự).
Hãy xây dựng chương trình để quản lý SMG Gateway với các chức năng sau:
Hàm nhập thông tin cho N slot
Hàm xuất thông tin cho N slot
Hàm nhập vào số điện thoại (tối đa 11 chữ số),
sau đó tìm và in ra thông tin của các slot có cùng nhà mạng cung cấp với số điện thoại nhập vào
(dựa theo đầu số là 3 kí tự đầu của số điện thoại)
Yêu cầu:
- Sử dụng con trỏ và kĩ thuật cấp phát động để quản lý mảng
- Sử dụng phép nạp chồng toán tử nhập (>>) và xuất (<<) để nhập, xuất dữ liệu

Input:
- Dòng đầu tiên là số nguyên N cho biết số lượng slot
- N dòng tiếp theo, mỗi dòng là thông tin của từng slot, bao gồm: mã số, số điện thoại, nhà mạng.
Mỗi thông tin cách nhau 1 khoảng trắng
- Dòng cuối cùng chứa số điện thoại để tìm slot có cùng nhà mạng
Output:
- Lần lượt in ra thông tin của các slot tìm được, mỗi slot là một dòng có các thông tin:
mã số, số điện thoại, nhà mạng cung cấp. Mỗi thông tin cách nhau 1 dấu hai chấm “:”

Ví dụ:
Input:
3
S01 0903334455 Mobi
S02 0981234567 Viettel
S03 0919999999 Vinaphone
0907773177

Output:
S01:0903334455:Mobi
*/