#include <iostream>
using namespace std;
int main(){
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < b * 2 + (a - 2) * 2; i++){
		cout << "*";
	}
	//system("pause");
	return 0;
}
/*

Viết chương trình in ra màn hình hình chữ nhật sao rỗng với độ dài 2 cạnh nhập vào từ bàn phím.

Input: 2 số nguyên dương a, b.
Output: hình chữ nhật ngôi sao rỗng giữa tương ứng độ dài 2 cạnh.

Ví dụ:

Input:
3 5

Output:b*2+(a-2)*2
*****
*   *
*****

Input:
5 8

Output:
********
*      *
*      *
*      *
********


Dữ liệu nhập đảm bảo vẽ được hình chữ nhật rỗng.

--bai dung--
#include <iostream>
using namespace std;

int main(){
int a,b;
cin>>a>>b;
for(int i=0;i<a;i++){
if(i==0 || i== a-1){
for(int j=0;j<b;j++){
cout<<"*";
}
}
else{
for(int j=0;j<b;j++){
if(j==0 || j==b-1)
cout<<"*";
else cout<<" ";
}
}
cout<<endl;
}
return 0;
}
-----
*/