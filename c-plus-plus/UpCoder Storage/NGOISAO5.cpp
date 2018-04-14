#include <iostream>
using namespace std;
int main(){
	int num;
	cin >> num;
	for (int i = 0; i < num*num; i++){
		cout << "*";
	}
	//system("pause");
	return 0;
}
/*
//bai dung
int h;
cin>>h;
for (int i = h; i>0; i--){
for (int j = 1; j <= h - i; j++){
cout << " ";
}
for (int j = 2 * i - 1; j >= 1; j--){
cout << "*";
}
cout << endl;
}
return 0;

Viết chương trình in ra màn hình tam giác sao ngược với chiều cao h nhập vào từ bàn phím.

Ví dụ:
Input:
3

Output:
*****	h*2-1
***		h*2-3
*		h*2-5

Input:
5

Output:
*********	h*2-1
*******		h*2-3
*****		h*2-5
***			h*2-7
*			h*2-9

Input:
6

Output:
***********	h*2-1
*********	
*******
*****
***
*
*/