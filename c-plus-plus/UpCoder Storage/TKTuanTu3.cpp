#include <iostream>
using namespace std;

int main()
{
	int x, num, numMax, flag = 1, ar[20], arLen = 0, posNumMax;
	cin >> x;
	while (cin>>num)
	{
		//chi luu so nao <= x, lon hon se gan = 0
		num <= x ? num = num : num = 0;
		ar[arLen] = num;
		arLen++;
		//luu lai so lon nhat ma <= num
		if (flag == 1){ numMax = num; flag = 0; }
		if (num >= numMax){ numMax = num; }
	}
	//tim vi tri cua numMax
	for (int i = 0; i < arLen; i++){
		if (ar[i] == numMax) { posNumMax = i; break; }
	}
	//numMax = 0 nghia la ko co so nao <= x
	numMax == 0 ? cout << -1 : cout << posNumMax;
	//system("pause");
	return 0;
}
/*
Bạn hãy dùng thuật toán tìm kiếm tuần tự để giải bài toán sau:

Input:
- Nhập vào 1 giá trị x
- Nhập vào 1 dãy số nguyên

Output:
- Vị trí phần tử đầu tiên có giá trị lớn nhất không vượt quá x, nếu không tìm thấy xuất -1

Lưu ý: dãy số được đánh chỉ số từ 0

ví dụ
input
4
2 1 3 5

ouput
2
*/