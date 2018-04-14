#include <iostream>
using namespace std;

//PHAN SO
struct PHANSO{ int tu, mau; };
istream& operator>>(istream& is, PHANSO & ps){
	is >> ps.tu >> ps.mau;
	return is;
}
ostream& operator<<(ostream& os, PHANSO  ps){
	os << ps.tu << "/" << ps.mau;
	return os;
}
bool operator==(PHANSO ps1, PHANSO ps2){
	return ps1.tu*ps2.mau == ps1.mau*ps2.tu;
}
bool operator!=(PHANSO ps1, PHANSO ps2){
	//return ps1.tu*ps2.mau != ps1.mau*ps2.tu;
	return !(ps1 == ps2);
}
bool operator>(PHANSO ps1, PHANSO ps2){
	return double(ps1.tu / (double)ps1.mau) > double(ps2.tu / (double)ps2.mau);
}
bool operator<(PHANSO ps1, PHANSO ps2){
	return double(ps1.tu / (double)ps1.mau) < double(ps2.tu / (double)ps2.mau);
}
int UCLN(long a, long b)
{
	return b == 0 ? a : UCLN(b, a%b);
}
PHANSO rutGonPS(PHANSO ps){
	int mauChung = UCLN(ps.tu, ps.mau);
	ps.tu /= mauChung;
	ps.mau /= mauChung;
	return ps;
}
PHANSO operator+(PHANSO ps1, PHANSO ps2){
	PHANSO kq;
	kq.tu = ps1.tu*ps2.mau + ps1.mau*ps2.tu;
	kq.mau = ps1.mau * ps2.mau;
	return kq;
}

//hieu chinh
void Shift(PHANSO num_arr[], int left, int right)
{
	PHANSO  x;
	int curr, joint;
	curr = left; joint = 2 * curr + 1;
	x = num_arr[curr];
	while (joint <= right)
	{
		if (joint < right) //neu co du 2 thanh phan lien doi
		{
			if (num_arr[joint] < num_arr[joint + 1]) {
				joint = joint + 1;
			}
		}
		if (num_arr[joint] < x) //thoa quan he lien doi
		{
			break;
		}
		num_arr[curr] = num_arr[joint];
		curr = joint;
		joint = 2 * curr + 1;
	}
	num_arr[curr] = x;
}
//tao heap
void CreateHeap(PHANSO num_arr[], int right)
{
	int left;
	for (left = (right - 1) / 2; left >= 0; left--)
		Shift(num_arr, left, right - 1);
}
//sap xep tang dan
void HeapSort(PHANSO a[], int N)
{
	int right;
	CreateHeap(a, N);
	right = N - 1;
	while (right > 0)
	{
		PHANSO tmp = a[0];
		a[0] = a[right];
		a[right] = tmp;
		right--;
		Shift(a, 0, right);
	}
}

void xuatMangSo(PHANSO mang[], int mLen){
	for (int i = 0; i < mLen; i++){
		cout << mang[i];
	}
}
int main(){
	int so_luong;
	PHANSO ps, arr[10];
	cin >> so_luong;
	for (int i = 0; i < so_luong; i++){
		cin >> ps;
		arr[i] = rutGonPS(ps);
	}
	Shift(arr, 1, so_luong);
	HeapSort(arr, so_luong);
	xuatMangSo(arr, so_luong);
	system("pause");
	return 0;
}
/*
Cho cấu trúc lưu trữ Phân số, bao gồm 2 số nguyên cho biết tử số và mẫu số
Viết chương trình nhập vào một mảng Phân số và xuất ra mảng các Phân số được sắp xếp tăng dần theo gía trị.
Yêu cầu:
- Sử dụng kĩ thuật nạp chồng toán tử so sánh lớn, bé để so sánh 2 phân số, phục vụ cho thuật toán sắp xếp.

Dữ liệu đầu vào:
- Dòng đầu tiên chứa số nguyên N (0
- N dòng tiếp theo, mỗi dòng chứa một Phân số, bao gồm 2 số nguyên cho biết tử số và mẫu số.
Mỗi số nguyên cách nhau bởi 1 khoảng trắng.
Dữ liệu đầu ra:
- Dãy phân số được sắp xếp tăng dần theo giá trị.
Mỗi phân số bao gồm tử và mẫu đã được tối giản và được xuất theo định dạng tử/mẫu.
Mỗi phân số cách nhau bởi 1 khoảng trắng.

Vd:
input:
5
4 2
6 8
18 15
7 8
2 6
output:
1/3 3/4 7/8 6/5 2/1
*/