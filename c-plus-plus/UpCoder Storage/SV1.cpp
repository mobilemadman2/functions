#include <iostream>
#include <string>
using namespace std;
struct SV
{
	string hoten;
	int diem1, diem2, diem3;
};
istream& operator>>(istream& in, SV& sv){
	getline(cin, sv.hoten);
	in >> sv.diem1 >> sv.diem2 >> sv.diem3;
	return in;
}
ostream& operator<<(ostream& out, SV sv){
	out << sv.hoten << endl;
	return out;
}
bool operator<(SV a, SV b){
	//ko can thiet phai chia 3
	return (a.diem1 + a.diem2 + a.diem3) < (b.diem1 + b.diem2 + b.diem3);
}
int main() {
	SV sv, bestSV;
	int first = true;
	while (cin >> sv){
		cin.ignore();
		if (first){ bestSV = sv; first = false; }
		else if (bestSV < sv){ bestSV = sv; }
	}

	cout << bestSV;
	system("pause");
	return 0;
}
/*
Xây dựng 1 cấu trúc SV, gồm họtên và điểm của 3 môn học, yêu cầu viết các quá tải:

- Nhập >>, xuất << và bé hơn < (dựa vào điểm trung bình 3 môn).

- Viết chương trình nhập vào 1 danh sách gồm nhiều Sinh viên theo cấu trúc

Mỗi sinh viên nhập vào gồm: dòng đầu là họ và tên, dòng thứ 2 là điểm 3 môn (mỗi môn cách nhau 1 dấu cách).

Yêu cầu tìm sinh viên có điểm trung bình cao nhất và xuất ho tên sinh viên đó ra màn hình,
nếu có nhiều SV thì chỉ cần xuất SV có số thứ tự nhỏ nhất (gặp đầu tiên trong danh sách)

(Lưu ý: Họ tên là một chuỗi không có dấu)

Ví dụ:
Input:
Nguyen Van A
1 2 3
Tran Van Teo
4 5 6
Output:
Tran Van Teo
*/