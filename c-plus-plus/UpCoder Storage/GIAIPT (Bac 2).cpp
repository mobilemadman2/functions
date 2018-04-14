#include <iostream>
#include <iomanip>      // setprecision
#include <cmath>		//sqrt, pow
using namespace std;

void giaiPTB1(double a, double b){
	if (a == 0){
		if (b == 0){ cout << "VSN"; }
		else{ cout << "VN"; }
	}
	else{ cout << fixed << setprecision(4) << -b / a; }
}
void giaiPTB2(int a, int b, int c){
	if (a == 0){
		giaiPTB1(b, c);
	}
	else{
		int delta = b*b - 4 * a*c;
		if (delta < 0){
			cout << "VN";
		}
		else if (delta == 0){
			//cout << fixed << setprecision(4) << -b / (2 * a);
			cout << "VSN";
		}
		else if (delta>0){
			cout << fixed << setprecision(4) << (-b + sqrt(delta)) / (2 * a) << endl;
			cout << (-b - sqrt(delta)) / (2 * a);
		}
	}

}

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	giaiPTB2(a, b, c);
	system("pause");
	return 0;
}
/*
Giải phương trình ax2+bx+c=0
Input:
- Gồm 3 dòng, mỗi dòng là 1 số nguyên, tương ứng với 3 hệ số a,b,c

Output:
- Nếu phương trình có nghiệm, xuất nghiệm lấy 4 chữ số thập (nếu có 2 nghiệm xuất mỗi nghiệm ở một hàng riêng biệt)
- Nếu phương trình vô nghiệm, xuất VN
- Nếu phương trình vô số nghiệm, xuát VSN.

Lưu ý: nếu a=0, thì phương trình trở thành phương trình bậc 1

ví dụ:
input		output
3			2.0000

-10			1.3333

8
*/