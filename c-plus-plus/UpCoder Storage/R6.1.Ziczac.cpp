#include <iostream>
using namespace std;

int main() {
	int x, y, n;
	cin >> x >> y >> n;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			x--;
		}
		else { x++; y++; }
	}
	cout << x << y;
	system("pause");
	return 0;
}
/*
Một chú thỏ xuất phát ở tọa độ (x,y) có thói quen di chuyển n bước theo kiểu Ziczac như sau :

+ Ở bước có giá trị lẻ thỏ sẽ di chuyển (x+1,y+1) .

+ Ở bước có giá trị chẵn thỏ sẽ di chuyển (x-1,y) .

Hỏi sau n bước thỏ đang tọa độ bao nhiêu .



Input :

Dòng 1 chứa 2 số x y là tọa độ hiện tại của thỏ ( -10^7 <= x , y <=10^7 )

Dòng 2 chứa số n là số bước của thỏ ( 0 <=n<=10^7 )



Output:

2 số x y là tọa độ của thỏ sau n bước

Ví dụ :

Input
0 0
3
Output
1 2
*/