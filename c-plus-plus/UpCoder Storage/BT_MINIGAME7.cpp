#include <iostream>
using namespace std;

int main() {
	int a[8], vn;
	for (int i = 1; i < 8; i++) { cin >> a[i]; }
	if (a[7] == 1) {
		if (a[1] + a[2] + a[3] > a[4] + a[5] + a[6]) { cout << "VN"; }
		else if (a[1] + a[2] + a[3] == a[4] + a[5] + a[6]) { cout << "TIE"; }
		else { cout << "TL"; }
	}
	else {
		if (a[1] > a[4] || a[2] > a[5] || a[3] > a[6]) { cout << "VN"; }
		else if (a[1] == a[4] && a[2] == a[5] && a[3] == a[6]) { cout << "TIE"; }
		else { cout << "TL"; }
	}
	system("pause");
	return 0;
}
/*
Các giải đấu thể thao quốc tế luôn dành một phần thưởng lớn cho các đoàn có thứ hạng cao. Có hai cách để xếp hạng các đoàn:

Cách 1: đoàn nào có tổng số huy chương lớn hơn thì xếp trên
Cách 2: đoàn nào có nhiều huy chương vàng hơn thì xếp trên, nếu bằng nhau thì xét đến huy chương bạc, nếu bằng sẽ xét đến huy chương đồng.

Việt Nam và Thái Lan là hai cường quốc thể thao ở Đông Nam Á. Cho biết số lượng các huy chương của hai đoàn này cùng cách xếp hạng của ban tổ chức, hãy cho biết đội nào xếp trên.

Dữ liệu đầu vào:
- Dòng đầu tiên chứa 6 số nguyên không âm (không vượt quá 200) ghi lại số huy chương vàng, bạc, đồng của Việt Nam và số huy chương vàng,
bạc, đồng của Thái Lan
- Dòng tiếp theo chứa một số nguyên duy nhất 1 hoặc 2 ghi lại cách xếp hạng của ban tổ chức.

Dữ liệu đầu ra:
- Nếu Việt Nam xếp trên thì xuất ra "VN".
- Nếu Thái Lan xếp trên thì xuất ra "TL".
- Nếu không phân định được thì xuất ra "TIE".

Ví dụ
input
20 15 30 12 24 35
1
output
TL

Ví dụ
input
20 15 30 12 24 35
2
output
VN
*/