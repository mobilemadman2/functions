#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	int sl, str;
	string arr[102];

	ifstream in("NGOAC.INP");
	in >> sl;

	//vì đề cho vị trí ngoặc mở, nên số phần tử phải gấp đôi để chứa thêm ngoặc đóng
	for (int i = 0; i < sl * 2; i++){
		//nếu vị trí đó rỗng
		if (arr[i] != "(" && arr[i] != ")"){
			//lấy từ trong file số lượng phần tử mà ngoặc này chứa, gán vào str
			in >> str;
			//thêm dấu mở ngoặc tại vị trí trống
			arr[i] = "(";
			//dấu đóng sẽ nằm cách dấu mở một đoạn là str + 1
			arr[str + i + 1] = ")";
		}
	}
	in.close();

	ofstream out("NGOAC.OUT");
	for (int i = 0; i < sl * 2; i++){
		out << arr[i];
	}
	out.close();
	return 0;
}
/*
Một dãy dấu ngoặc hợp lệ là một dãy các ký tự "(" và ")" được định nghĩa như sau:
1. Dãy rỗng (không có ký tự nào) là một dãy dấu ngoặc hợp lệ
2. Nếu A là một dãy dấu ngoặc hợp lệ thì (A) là dãy dấu ngoặc hợp lệ.
Dấu ngoặc mở và dấu ngoặc đóng hai bên dãy A được gọi là tương ứng với nhau
3. Nếu A và B là hai dãy dấu ngoặc hợp lệ thì AB là dãy dấu ngoặc hợp lệ.

Ví dụ: ((()))(())()() là một dãy dấu ngoặc hợp lệ.
Các dấu mở ngoặc ở các vị trí: 1, 2, 3, 7, 8, 11, 13 tương ứng lần lượt với các dấu đóng ngoặc ở các vị trí: 6, 5, 4, 10, 9, 12, 14.

Ban đầu có một dãy dấu ngoặc hợp lệ, người ta viết vào dưới mỗi dấu ngoặc mở một số tự nhiên là số dấu ngoặc (cả đóng và mở)
nằm giữa dấu ngoặc mở đó và dấu ngoặc đóng tương ứng:
((()))(())()()
420   20  0 0

Sau đó xoá đi dãy ngoặc.

Yêu cầu: Cho biết dãy số còn lại, hãy khôi phục lại dãy ngoặc ban đầu
Dữ liệu: Vào từ file văn bản NGOAC.INP
·         Dòng 1: Ghi số n là số phần tử của dãy số còn lại (n £ 10000)
·         Dòng 2: Ghi lần lượt các số trong dãy

Kết quả: Ghi ra file văn bản NGOAC.OUT
Gồm 1 dòng ghi dãy dấu ngoặc khôi phục được

Ví dụ:
NGOAC.INP
7
4 2 0 2 0 0 0
0 1 2 3 4 5 6 7- i
6 7
NGOAC.OUT
i = "(";
i + str + 1 = ")";

((()))(())()()

0    56  9
1  4  78
23

NGOAC.INP
10
8 2 0 0 0 4 0 0 0 0

NGOAC.OUT
((())()())(()())()()
*/