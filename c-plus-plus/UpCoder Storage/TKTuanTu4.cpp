#include <iostream>
using namespace std;

void xuatMangSo(int mang[], int mLen){
	for (int i = 0; i < mLen; i++){
		cout << mang[i];
	}
}

int main()
{
	int x, num, numMax, flag = 1, ar[20], arLen = 0, posNumMax[20], posLen = 0;
	cin >> x;
	while (cin >> num)
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
		if (ar[i] == numMax) { posNumMax[posLen] = i; posLen++; }
	}
	//numMax = 0 nghia la ko co so nao <= x
	if (numMax == 0){ cout << -1; }
	else
	{
		xuatMangSo(posNumMax, posLen);
	}
	//system("pause");
	return 0;
}
/*
Bạn hãy dùng thuật toán tìm kiếm tuần tự để giải bài toán sau:

Input:
- Nhập vào 1 giá trị x
- Nhập vào 1 dãy số nguyên

Output:
- Xuất tất cả vị trí phần tử đạt giá trị lớn nhất không vượt quá x, nếu không tìm thấy xuất -1

Lưu ý: dãy số được đánh chỉ số từ 0

ví dụ
input
4
2 3 3 5

ouput
1 2
*/