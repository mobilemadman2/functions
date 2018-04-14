#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
	string name, year, que, khoa;
	getline(cin, name);
	getline(cin, year);
	getline(cin, que);
	getline(cin, khoa);
	int so_mon = 0, diem, tong_diem = 0, bang_diem[100];
	while (cin >> diem)
	{
		bang_diem[so_mon] = diem;
		so_mon++;
		tong_diem += diem;
	}
	cout << "Ho Ten: " << name << endl;
	cout << "Nam Sinh: " << year << endl;
	cout << "Que quan: " << que << endl;
	cout << "Khoa: " << khoa << endl;
	cout << "Diem cac mon: ";
	for (int i = 0; i < so_mon; i++) { cout << bang_diem[i] << " "; }
	cout << endl;
	cout << "Diem trung binh: " << fixed << setprecision(2) << tong_diem / double(so_mon) << endl;
	return 0;
}
/*
Viết chương trình nhập vào thông tin 1 sinh viên, yêu cầu xuất thông tin ra màn hình

Ví dụ:

input
Nguyen Van A
1983
Ca Mau
CNTT
10 8 1

output
Ho Ten: Nguyen Van A
Nam Sinh: 1983
Que quan: Ca Mau
Khoa: CNTT
Diem cac mon: 10 8 1
Diem trung binh: 6.33
*/