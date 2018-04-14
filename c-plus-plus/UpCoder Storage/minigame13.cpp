#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int h, n, max, thuyen[100];
	cin >> h >> n;
	for (int i = 0; i < n; i++) {
		int s, v;
		cin >> s >> v;
		thuyen[i] = s / v;
		if (i == 0) { max = thuyen[i]; }
		if (thuyen[i] < max) { max = thuyen[i]; }
	}
	int thgianChamNuoc = sqrt(h * 2 / 10);
	int thgianChet = thgianChamNuoc + 60 * 5;
	if (max > thgianChet) { cout << "Khong cuu duoc"; }
	else {
		for (int i = 0; i < n; i++) {
			if (thuyen[i] == max) {
				cout << i;
			}
		}
		cout << endl << max << endl;
	}
	system("pause");
	return 0;
}
/*
Thắng và đám bạn cùng đi nhậu với sự khích lệ của bạn bè Thắng đã tỏ tình với người mình thích nhưng thất bại ê chề.
Thắng buồn bả và quyết định đi nhảy cầu (cây cầu có độ cao là h). 
Đồng thời lúc Thắng bắt đầu nhảy xuống nước thì có n chiếc thuyền (đánh dấu 0 tới n-1) 
đánh cá phát hiện và lập tức tiến về chỗ Thắng. Khoảng cách từ thuyền tới Thắng là s(m) và vận tốc của thuyền là v(m/s).

Theo ta biết công thức rơi tự do là  h=gt2/2, (g =10m/s2 ,t giây,h mét) và thuyền đánh cá đang chuyển động thẳng đều.

Hãy tìm chiếc thuyền đánh cá nhanh nhất tới cứu Thắng và thời gian 
chiếc thuyền ấy tới cứu Thắng là bao lâu? Biết thời gian trung bình người không biết bơi khi tiếp xúc với nước thì khoảng 5 phút thì sẽ không chịu nổi và ngạt nước.

Nếu không chiếc thuyền nào tới kịp thì xuất “Khong cuu duoc” (không có dấu ngoặc kép)

Lưu ý là ở công thức rơi tự do là thời gian được lấy  theo kiểu số nguyên (t=1,5s thì lấy t= 1s)



Input:

Dòng đầu tiên là độ cao h của cây cầu(h<=10000)

Dòng thứ 2 là số nguyên dương n (n<=100)

Các dòng tiếp theo tương ứng là khoảng cách và vận tốc của từng thuyền (s<=10^6,v<=100)
Output:

Dòng đầu là chỉ số đánh dấu của chiếc thuyền nhanh nhất (nếu có nhiều chiếc thuyền tới nhanh nhất cùng lúc thì xuất tất cả và cách nhau bởi khoảng trắng)

Dòng thứ hai là thời gian chiếc thuyền tới cứu Thắng


Ví dụ:

Input:
500
2
250 5
300 6
Output
0 1
50
*/