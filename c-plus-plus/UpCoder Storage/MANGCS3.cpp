#include <iostream>
using namespace std;

int main(){
	int viTri, phanTu, mang[100], mLen = 0;
	cin >> viTri;

	//nhap day so
	while (cin >> phanTu){
		mang[mLen++] = phanTu;
	}

	//doi cac phan tu bat dau tu vi tri da nhap
	for (int i = viTri; i < mLen - 1; i++){
		mang[i] = mang[i + 1];
	}

	for (int i = 0; i < mLen - 1; i++){
		cout << mang[i] << " ";
	}
	//system("pause");
	return 0;
}
/*
Nhập:

Dòng 1: nhập vị trí cần xóa
Dòng 2: nhập vào 1 dãy số

Xuất:
mảng sau khi xóa

ví dụ:
input:
2
1 2 3 4 5

output:
1 2 4 5
*/