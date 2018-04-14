#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
ofstream out("snt.out");
void dsSNT(int num){
	int dem = 0;
	for (int i = 2; i <= sqrt(num); i++){
		if (num%i == 0){ dem++; break; }
	}
	if (dem == 0 && num != 1) out << num << endl;
}
int main(){
	int a, b;
	ifstream in("snt.inp");
	in >> a >> b;
	in.close();
	for (; a <= b; a++)	dsSNT(a);
	out.close();
	return 0;
}
/*
Hãy tìm tất cả các số nguyên tố trong đoạn [A,B] .

Input từ tập tin snt.inp
Gồm 2 số nguyên A và B cách nhau bởi 1 dấu cách ( 1 ≤ A ≤ B ≤ 200000 ) .

Output ra tập tin snt.out
Ghi ra tất cả các số nguyên tố trong đoạn [A,B]. Mỗi số trên 1 dòng .

Ví dụ
Input:
1 10

Output:
2
3
5
7
*/