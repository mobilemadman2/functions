#include <iostream>
using namespace std;

int main(){
	int soMin, soMax, num, flag = 1;
	while (cin >> num){
		if (flag == 1){
			soMax = num;
			soMin = num;
			flag = 0;
		}
		if (num > soMax)soMax = num;
		if (num < soMin)soMin = num;
	}
	cout << soMin << endl << soMax << endl << soMax + soMin;
	//system("pause");
	return 0;
}
/*
Bạn hãy nhập vào 1 dãy số, yêu cầu tìm số nhỏ nhất và số lớn nhất, sau đó tính tổng 2 số đó ra màn hình.
input:
Nhập vào 1 dãy số, mỗi số cách nhau 1 khoảng trắng

output:
- dòng 1: xuất số nhỏ nhất
- dòng 2: xuất số lớn nhất
- dòng 3: xuất tổng số nhỏ và số lớn nhất
ví dụ:
input:
1 2 3 4 5

output
1
5
6
*/