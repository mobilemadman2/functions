#include<iostream>
using namespace std;

int main()
{
	int dong, cot, arr[100][100], num = 1;
	cin >> dong >> cot;
	for (int i = 0; i < dong; i++){
		for (int j = 0; j < cot; j++){
			arr[i][j] = num;
			num++;
		}
	}

	for (int i = 0; i < dong; i++){
		//dong chan: 0 2 4 thi xuat tu 0 den cot
		if (i % 2 == 0){
			for (int j = 0; j < cot; j++){
				cout << arr[i][j];
			}
		}
		//dong le: 1 3 5 thi xuat nguoc lai
		else{
			for (int j = cot - 1; j >= 0; j--){
				cout << arr[i][j];
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
/*
Input:
- Nhập vào 2 số nguyên N, M là số dòng và số cột của mảng 2 chiều NxM

Ouput:
Xuất mảng Xoắn Ốc, các giá trị được đi từ 1 đến N.M (xem ví dụ để hiểu thêm)

Ví dụ:
input
3 3
output
1 2 3	0 1 2	i+j		i+j		i+j
8 9 4	7 8 3	n*2+1	n*2+2	n
7 6 5	6 5 4	n*m+1	n*m		n*m-1
*/