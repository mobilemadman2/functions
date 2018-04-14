#include <iostream>
#include <cmath>		//sqrt, pow
using namespace std;

struct DONTHUC{
	int a, n;
};

ostream& operator<<(ostream& os, DONTHUC don_thuc){
	if (don_thuc.a == 0){
		os << "";
	}
	else if (don_thuc.a == 1){
		if (don_thuc.n == 0){
			os << "";
		}
		else if (don_thuc.n == 1){
			//x
			os << "x";
		}
		else{
			//x^n
			os << "x^" << don_thuc.n;
		}
	}
	else{
		if (don_thuc.n == 0){
			//a
			os << don_thuc.a;
		}
		else if (don_thuc.n == 1){
			//ax
			os << don_thuc.a << "x";
		}
		else{
			//ax^n
			os << don_thuc.a << "x^" << don_thuc.n;
		}
	}
	return os;
}

void nhapDaThuc(DONTHUC mang_da_thuc[], int so_luong){
	DONTHUC don_thuc;
	for (int i = 0; i < so_luong; i++){
		do{
			cin >> don_thuc.a;
		} while (don_thuc.a < 0);

		mang_da_thuc[i].a = don_thuc.a;
	}
	for (int i = 0; i < so_luong; i++){
		cin >> don_thuc.n;
		mang_da_thuc[i].n = don_thuc.n;
	}
}

void xuatDaThuc(DONTHUC mang_da_thuc[], int so_luong){
	for (int i = 0; i < so_luong; i++){
		if (i == so_luong - 1 && mang_da_thuc[i].a != 0){
			cout << mang_da_thuc[i];
		}
		else if (mang_da_thuc[i].a == 0){
			cout << "";
		}
		else{
			cout << mang_da_thuc[i] << " + ";
		}
	}
	cout << endl;
}

int tinhDaThuc(DONTHUC mang_da_thuc[], int so_luong, int x){
	double result = 0;
	for (int i = 0; i < so_luong; i++){
		//a*x^n
		result += mang_da_thuc[i].a * pow(x, mang_da_thuc[i].n);
	}
	return (int)result;
}

void tinhDaoHam(DONTHUC mang_da_thuc[], int so_luong){
	for (int i = 0; i < so_luong; i++){
		mang_da_thuc[i].a = mang_da_thuc[i].a*mang_da_thuc[i].n;
		mang_da_thuc[i].n = mang_da_thuc[i].n - 1;
	}
	xuatDaThuc(mang_da_thuc, so_luong);
}

int main(){
	DONTHUC mang_da_thuc[100];
	int so_luong;
	cin >> so_luong;
	nhapDaThuc(mang_da_thuc, so_luong);

	int x;
	do{
		cin >> x;
	} while (x < 0);

	xuatDaThuc(mang_da_thuc, so_luong);
	cout << tinhDaThuc(mang_da_thuc, so_luong, x) << endl;
	tinhDaoHam(mang_da_thuc, so_luong);

	system("pause");
	return 0;
}
/*
Cho đa thức P(x) = a1xn1 + a2xn2 + a3xn3 + … + akxnk
với a1, a2, …, ak là giá trị số thực bất kỳ; n1, n2, …, nk là giá trị số nguyên bất kỳ
Xây dựng chương trình làm việc với danh sách các đa thức với các thao tác:
1. Nhập đa thức
2. Xuất đa thức
3. Tính đa thức khi biết giá trị x
4. Tính đạo hàm của đa thức

Dữ liệu đầu vào:
- Dòng đầu tiên chứa số nguyên k cho biết số lượng đơn thức trong đa thức
- Dòng thứ hai chứa k số thực không âm lần lượt là các giá trị từ a1 đến ak
- Dòng thứ ba chứa k số nguyên không âm lần lượt là các giá trị từ n1 đến nk
- Dòng thứ ba chứa giá trị của số thực x
Dữ liệu đầu ra:
- Dòng đầu tiên là đa thức vừa nhập được in ra theo cú pháp a1x^n1 + a2x^n2 + a3x^n3 + ... + akx^nk. Mỗi đơn thức và toán tử cách nhau 1 khoảng trắng.
- Dòng thứ hai là giá trị đa thức tương ứng với giá trị số thực x nhập vào
- Dòng thứ ba là đa thức đạo hàm của đa thức ban đầu. Mỗi đơn thức và toán tử cách nhau 1 khoảng trắng.

*Lưu ý: nếu đơn thức akx^nk có:
+ ak = 0 thì không cần xuất
+ ak = 1 thì xuất dưới dạng x^nk
+ nk = 0 thì xuất dưới dạng ak
+ nk = 1 thì xuất dưới dạng akx

Vd:
input:
5
5 4 3 2 1
0 1 2 3 4
2
output:
5 + 4x + 3x^2 + 2x^3 + x^4
57
4 + 6x + 6x^2 + 4x^3
*/