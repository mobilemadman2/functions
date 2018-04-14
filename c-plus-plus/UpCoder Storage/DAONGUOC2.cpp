#include <iostream>
#include <fstream>
using namespace std;
//REVERSE >> đảo ngược số: 1234 => 4321
int reverseInt(int num) {
	//lấy chiều dài số
	int len = 1;
	int tmp = num;
	while (tmp /= 10) { len++; }
	//tính toán
	int rev = 0;
	while (num > 0)
	{
		rev = rev + (num % 10)*(int)pow(10, len - 1);
		len--;
		num /= 10;
	}
	return rev;
}

int main() {
	ifstream in("inDaoNguoc2.txt");
	ofstream out("outDaoNguoc2.txt");

	//mảng lưu số đảo ngược, chỉ số mảng, num, số max, số lượng số max (nếu có số bằng nhau)
	int a[100], ai = 0, num, max = 0, sl = 0;
	//nhập số
	while (in >> num)
	{
		//đảo ngược và gán vào mảng
		a[ai] = reverseInt(num); ai++;
		//lấy max
		if (reverseInt(num) > max) { max = reverseInt(num); }
	}
	in.close();

	//xuất max đảo lại số ban đầu
	out << reverseInt(max) << endl;

	//đếm max
	for (int i = 0; i < ai; i++) {
		if (a[i] == max) { sl++; }
	}
	//có nhiều max thì xuất vị trí
	if (sl > 1) {
		for (int i = 0; i < ai; i++) {
			if (a[i] == max) { out << i << " "; }
		}
	}
	out.close();
	return 0;
}
/*
Nhập vào 1 dãy số, tìm số có số đảo ngược của nó là lớn nhất,
nếu có nhiều hơn 2 số như vậy hãy xuất tất cả vị trí tìm thấy số đó ở dòng thứ 2

+ Dữ liệu vào từ file: inDaoNguoc2.txt
+ Dữ liệu ra file: outDaoNguoc2.txt

Ví dụ 1:

Input:
12
123
341

Output:
123

Ví dụ 2:

Input:
123
12
123
341

Output:
123
0  2
*/