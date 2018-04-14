#include <iostream>
#include <string>
using namespace std;

string doc(int n){
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
	default:return "watashiha fukudesu.";
	}
}

int main(){
	int n;
	cin >> n;
	cout << doc(n);
	system("pause");
	return 0;
}
/*
Nhập vào 1 số gồm 1 chữ số, yêu cầu xuất ra cách đọc chữ đó ra màn hình (gõ không dấu, chữ thường)

ví dụ
input:
1

output
mot
*/