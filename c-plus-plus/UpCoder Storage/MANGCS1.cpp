#include <iostream>

using namespace std;

int main(){
	int viTri, giaTri, phanTu, mang[100], mLen = 0;
	cin >> viTri >> giaTri;
	while (cin >> phanTu){
		mang[mLen++] = phanTu;
	}
	for (int i = mLen; i > viTri; i--){
		mang[i] = mang[i-1];
	}
	mang[viTri] = giaTri;
	mLen++;
	for (int i = 0; i < mLen; i++){
		cout << mang[i] << " ";
	}
	//system("pause");
	return 0;
}
/*Nhập:
Dòng 1: nhập vị trí cần thêm và giá trị thêm
Dòng 2: nhập vào 1 dãy số

Xuất: Mảng sau khi thêm

ví dụ
input:
2 5
1 2 3 4

output:
1 2 5 3 4 
*/