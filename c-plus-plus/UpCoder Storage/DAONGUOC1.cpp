#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int lengthOfInt(int num){
	int length = 1;
	while (num /= 10)
		length++;
	return length;
}
int reverseInt(int num){
	int dem = 0, soNguoc = 0, dv;
	int coSo = lengthOfInt(num) - 1;
	for (; coSo >= 0; coSo--){
		dv = (num / (int)pow(10, coSo)) % 10;
		soNguoc += dv*(int)pow(10, dem); dem++;
	}
	return soNguoc;
}

int main(){
	ifstream in;
	in.open("inDaoNguoc1.txt");
	ofstream out("outDaoNguoc1.txt");
	int num, soMax, flag = 1;
	while (in >> num){
		if (flag == 1){ soMax = num; flag = 0; }
		if (reverseInt(num) > reverseInt(soMax))soMax = num;
	}
	in.close();
	out << soMax;
	out.close();
	/*int num, soMax, flag = 1;
	while (cin >> num){
		if (flag == 1){ soMax = num; flag = 0; }
		if (reverseInt(num) > reverseInt(soMax))soMax = num;
	}
	cout << soMax;*/
	//system("pause");
	return 0;
}
/*
Nhập vào 1 dãy số, tìm số có số đảo ngược của nó là lớn nhất
+ Dữ liệu vào từ file: inDaoNguoc1.txt
+ Dữ liệu ra file: outDaoNguoc1.txt

Ví dụ 1:
Input:
123
12
1
341

Output:
123
*/