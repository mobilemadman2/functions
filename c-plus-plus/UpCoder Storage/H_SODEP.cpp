#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int tong = 0;
	while (n>0)
	{
		tong += n % 10;
		n /= 10;
	}
	if (tong%10==9) cout << "TRUE";else cout << "FALSE";
	system("pause");
	return 0;
}

/*
Số tự nhiên N được gọi là số đẹp nếu tổng các chữ số của N tận cùng bằng 9. Ví dụ một số số đẹp là 18 (1+8=9), 234 (2+3+4=9), 658 (6+5+8=19). Cho một số N, hãy kiểm tra xem N có phải là số đẹp hay không.
Dữ liệu nhập:
- Là số nguyên N (0 ≤ n ≤ 109)
Dữ liệu xuất:
- Nếu N là số đẹp, in ra "TRUE", nếu không in ra "FALSE"
Ví dụ
input: 27 --> output: TRUE
input: 2727 --> output: FALSE
input: 888333777 --> output: FALSE
*/