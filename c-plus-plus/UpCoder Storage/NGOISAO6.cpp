#include <iostream>
using namespace std;

int main(){
	int h;
	cin >> h;
	int soSao = 1 + (2 * (h-2)) + (h*2 - 1);
	for (int i = 0; i < soSao; i++){
		cout << "*";
	}
	//system("pause");
	return 0;
}
/*
//bai dung
int i, j, h;
cin >> h;
for (i = 1; i <= h; ++i)
{
for (j = 1; j <= h + i - 1; ++j)
{
cout << ((j == h - i + 1 || j == h + i - 1 || i == h) ? "*" : " ");
}
cout << "\n";
}
*/
/*
Viết chương trình in ra màn hình tam giác sao rỗng với chiều cao h nhập vào từ bàn phím.

Ví dụ:
Input:
3

Output: --*--|-*-*-|***** -8
		--3--|-7-9-|11
		--h--|-(h*2+1)-(h*3)-|(h*h-1)
--*--
-*-*-
*****
r1=1;
rl=2*h-2
rh=h*2-1
8
Input:
4

Output: ---*---|--*-*--|-*---*-|******* -13 
		---4---|--10-12--|-16---20-|22
		---h---|--(h*2+2)-(h*3)--|-(h*4)---(h*5)-|(h*h-2)
---*---
--*-*--
-*---*-
*******

row=h;
rowLen=h*2-1;
sum=rowLen*3;
*/