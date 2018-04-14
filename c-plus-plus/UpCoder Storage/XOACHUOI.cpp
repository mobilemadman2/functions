#include <iostream>
#include <string>
using namespace std;

bool isItOk(string x, string y){
	bool check = false;
	for (int i = 0; i < x.size(); i++){
		for (int j = i; j < y.size(); j++){
			if (x[i] == y[j]){ check = true; break; }
			else check = false;
		}
	}
	return check;
}

int main(){
	string x, y;
	getline(cin, x);
	getline(cin, y);
	if (isItOk(x, y)){ cout << "YES" << endl << y.size() - x.size(); }
	else cout << "NO";
	system("pause");
	return 0;
}

/*
Nhập vào 2 chuỗi X, Y từ bàn phím. Hãy kiểm tra có thể xóa một số ký tự của Y để Y biến thành X được hay không?

Dữ liệu xuất ra màn hình:

-         Dòng 1: Nếu cách làm miêu tả ở trên thực hiện được, xuất ra màn hình chữ: YES, ngược lại xuất: NO.

-         Dòng 2: nếu dòng 1 là YES, thì dòng 2 xuất số lượng kí tự xóa của Y, để Y biến thành X.

Ví dụ:
Input |  Output | Lý giải
abc   |   YES   |   Xóa 2 ký tự ‘d’ và ‘e’ thì dabec sẽ trở thành abc
dabec |    2    |
*/