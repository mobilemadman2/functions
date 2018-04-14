#include <iostream>
#include <cmath>
#include <string.h>
#include <string>
#include <stdio.h>
#include <fstream>

using namespace std;

int tongUoc(int num){
	int tong = 0;
	for (int i = 1; i < num; i++){
		if (num%i == 0)
		{
			tong += i;
		}
	}
	return tong;
}

int TCS(int a){
	int kq = 0;
	while (a>0)
	{
		kq += a % 10;
		a /= 10;
	}
	return kq;
}

/*char numToChar(int num){
	char chu;
	string zeroToten[] = { "zero", "ichi", "ni", "san", "yon", "go", "roku", "nana", "hachi", "kyu", "jyu" };
	if (num < 11){
		chu = char(zeroToten[num]);
	}
	if (num >= 11 && num <= 19){
		char chuoi = 'jyu';
			chu = chuoi + zeroToten[num % 10];
	}
	return chu;
}*/

bool isChinhPhuong(int n){
	if (n>0)
	return sqrt(n) == int(sqrt(n));
	else return false;
}

int main(){
	
	int num;
	ifstream in;
	in.open("input.txt");
	in >> num;
	ofstream out("output.txt");
	if (isChinhPhuong(num)) out << "YES";
	else out << "NO";
	in.close();
	out.close();
	system("pause");
	return 0;
}