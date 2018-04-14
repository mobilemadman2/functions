#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	int maxcv = 0, num, arr[100], sl = 0;
	while (cin >> num){
		arr[sl] = num;
		sl++;
	}
	if (s == "HCN"){
		for (int i = 0; i < sl - 1; i += 2){
			int cv = (arr[i] + arr[i + 1]) * 2;
			if (cv>maxcv){
				maxcv = cv;
			}
		}
	}
	else if (s == "HV"){
		for (int i = 0; i < sl; i++){
			int cv = arr[i] * 4;
			if (cv>maxcv){
				maxcv = cv;
			}
		}
	}
	cout << maxcv << endl;
	system("pause");
	return 0;
}
/*
Xây dựng lớp HìnhChữNhật có thuộc tính: chiều dài, chiều rộng và phương thức tínhChuVi, tínhDiệnTích.
Xây dựng lớp HìnhVuông kế thừa từ lớp HìnhChữNhật.

input:
- Dòng 1 là loại hình (Nếu HCN là hình chữ nhật, HV: là hình vuông)
- Gồm nhiều dòng, mỗi dòng gồm 2 số (nếu dòng 1 là HCN), hoặc 1 số (nếu dòng 1 là HV) là chiều dài và chiều rộng của HCN (hoặc cành của hình vuông)
Output:
- Xuất chu vi lớn nhất tìm thấy

ví dụ:
HCN
1 2
3 4

output:
24
*/