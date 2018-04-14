#include <iostream>
using namespace std;

bool isSNT(int num){
	if (num < 2) return false;
	for (int i = 2; i < num; i++){
		if (num%i == 0) return false;
	}
	return true;
}

int main(){
	int num, flag = true;
	cin >> num;
	for (int i = 1; i <= num; i++){
		if (isSNT(i)){
			cout << i << " ";
			flag = false;
		}
	}
	if (flag){
		cout << -1;
	}
	system("pause");
	return 0;
}
/*
Nhập vào 1 số nguyên n, yêu cầu xuất tất cả số nguyên tố từ 1 đến n (mỗi số cách 1 khoảng trắng) - nếu không có số nào, xuất -1


ví dụ:

input:
5

output
2 3 5
*/