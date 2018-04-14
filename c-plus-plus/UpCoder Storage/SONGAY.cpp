#include <iostream>
using namespace std;
int main(){
	int thang, nam;
	int arThang[13] =
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	cin >> thang >> nam;
	if (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0){ arThang[2] = 29; }
	cout << arThang[thang];
	system("pause");
	return 0;
}
/*
Nhập vào tháng và năm, yêu cầu xuất ra số ngày trong tháng đó.

ví dụ:
input
10 2016

output
31
*/