#include <iostream>
#include <iomanip>      // setprecision
#include <cmath>		//sqrt, pow
using namespace std;

int main(){
	int num;
	double sum = 0;
	cin >> num;
	for (int i = 0; i < num; i++){
		sum += 1 / (pow(num - i, 3));
	}
	std::cout << std::fixed << std::setprecision(3) << sum;
	system("pause");
	return 0;
}
/*
Input:
1 số nguyên n
ouput:
kết quả của phép toán: 1+1/23+1/33+...+1/n3
(kết quả lấy 3 chữ số thập phân)

ví dụ:
input:
3

output:
1.162
*/