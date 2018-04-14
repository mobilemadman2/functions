#include <iostream>
using namespace std;

int UCLN(long a, long b)
{
	return b == 0 ? a : UCLN(b, a%b);
}

struct PHANSO {	int tu, mau;};
PHANSO nhapPS(){
	PHANSO phanSo;
	cin >> phanSo.tu >> phanSo.mau;
	return phanSo;
}
void xuatPS(PHANSO ps){
	cout << ps.tu << "/" << ps.mau;
}

PHANSO rutGonPS(PHANSO ps){
	int mauChung = UCLN(ps.tu, ps.mau);
	ps.tu /= mauChung;
	ps.mau /= mauChung;
	return ps;
}
float PStoFloat(PHANSO ps){
	float f = ps.tu / (float)ps.mau;
	return f;
}
int main(){
	PHANSO arr[20], psMin;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		arr[i] = nhapPS();
		//gan phan so la phan so dau tien
		if (i == 0){ psMin = arr[i];}
		//neu ps < psMin thi gan psMin=ps, doi sang kieu float de so sanh
		if (PStoFloat(arr[i]) < PStoFloat(psMin)){ psMin = arr[i]; }
	}
	xuatPS(rutGonPS(psMin));
	system("pause");
	return 0;
}
/*
xây dựng 1 cấu trúc Phân Số (gồm tử và mẫu là số nguyên) với yêu cầu, xây dựng các hàm sau:
- Nhập, xuất phân số
- Hàm rút gọn.

Viết chương trình nhập vào N phân số, yêu cầu tìm xuất phân số nhỏ nhất (sau khi tối giản)

input:
- Dòng 1: số N
- N dòng tiếp theo, mỗi dòng gồm 2 số nguyên là tử và mẫu của 1 phân số

output:
Phân số nhỏ nhất (sau khi tối giản)

ví dụ:
input
2
1 2
2 4

output:
1/2

// setprecision example
#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision

int main () {
double f =3.14159;
std::cout << std::setprecision(5) << f << '\n';
std::cout << std::setprecision(9) << f << '\n';
std::cout << std::fixed;
std::cout << std::setprecision(5) << f << '\n';
std::cout << std::setprecision(9) << f << '\n';
return 0;
}
*/