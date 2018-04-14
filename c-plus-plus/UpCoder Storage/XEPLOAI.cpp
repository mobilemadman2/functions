#include <iostream>
using namespace std;

int main(){
	float num, stt = 0, sum = 0;
	while (cin >> num)
	{
		if (num == -1){ break; }
		else{
			sum += num;
			stt++;
		}
	}
	if (sum / stt >= 0 && sum / stt < 4){
		cout << "F";
	}
	else if (sum / stt >= 4 && sum / stt < 5.5){
		cout << "D";
	}
	else if (sum / stt >= 5.5 && sum / stt < 7){
		cout << "C";
	}
	else if (sum / stt >= 7 && sum / stt < 8.5){
		cout << "B";
	}
	else if (sum / stt >= 8.5 && sum / stt <= 10){
		cout << "A";
	}
	system("pause");
	return 0;
}
/*
Nhập vào điểm các môn học của một sinh viên (là các số nguyên từ 0 đến 10), yêu cầu xuất ra xếp loại của sinh viên đó.

Cách xếp loại dựa vào điểm trung bình (ĐTB) của sinh viên được xếp như sau.

- Nếu ĐTB <4 xếp loại F
- Nếu 4 <= ĐTB  <5.5 xếp loại D
- Nếu 5.5 <= ĐTB < 7.0 xếp loại C
- Nếu 7.0 <= ĐTB < 8.5 xếp loại B
- Nếu 8.5 <= ĐTB xếp loại A

Input:
Gồm nhiều dòng, mỗi dòng là 1 điểm kết thúc là số -1

(lưu ý -1 chỉ là ký hiệu kết thúc, không tính vào điểm số của sinh viên)

Output:
Xuất ra xếp loại của sinh viên

Ví dụ:

Input:		output:
10			B
9
5
-1
*/