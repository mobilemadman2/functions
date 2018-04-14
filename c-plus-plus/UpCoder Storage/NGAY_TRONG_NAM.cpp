#include <iostream>
#include <string>
using namespace std;
//GET >> thu cua 7 ngay trong tuan
string getWeekday(int d, int m, int y) {
	if (m < 3) {
		m += 12;
		y--;
	}
	//thu = (ngày+2*tháng+(3*(tháng+1)) / 5 + năm + (năm / 4)) % 7
	switch ((d + 2 * m + (3 * (m + 1)) / 5 + y + (y / 4)) % 7)
	{
	case 1:return "Thu Hai";
	case 2:return "Thu Ba";
	case 3:return "Thu Tu";
	case 4:return "Thu Nam";
	case 5:return "Thu Sau";
	case 6:return "Thu Bay";
	default:return "Chu Nhat";
	}
}
int main() {
	int d, m, y;
	cin >> d >> m >> y;
	cout << getWeekday(d, m, y);
	system("pause");
	return 0;
}
/*
Yêu cầu của bài toán là khi cô thư ký nhập vào ngày tháng năm bất kỳ thì sẽ biết ngay đó là thứ mấy?

Dữ liệu đầu vào:
- Dòng đầu tiên: giá trị ngày.
- Dòng thứ hai: giá trị tháng.
- Dòng thứ ba: giá trị năm.

Dữ liệu đầu ra:
- Một dòng duy nhất là kết quả của bài toán.

Chú ý:
- Kết quả xuất ra là không dấu và viết hoa ký tự đầu tiên:

Ví dụ 1
input
13
1
2017
output
Thu Sau

Ví dụ 2
input
15
1
2017
output
Chu Nhat
*/