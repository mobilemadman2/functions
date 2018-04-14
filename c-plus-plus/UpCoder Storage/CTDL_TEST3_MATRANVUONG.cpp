#include<stdio.h>
#include <iostream>
#include<math.h>
#define MAX 7

using namespace std;

/*ham nhap vao ma tran*/
void nhap(int a[MAX][MAX], int n)
{
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			//cout << "Nhap phan tu cho ma tran " << n << "x" << n << " vi tri hang " << i << " cot " << j << endl;
			cin >> a[i][j];
		}
	}
}
/*ham xuat ma tran*/
void xuat(int a[MAX][MAX], int n)
{
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
int ktraDoiXung(int a[MAX][MAX], int n){
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (a[i][j] != a[j][i]){
				return 0;
				break;
			}
		}
	}
	return 1;
}
int main(){
	int n;
	int a[MAX][MAX];
	cout << "Nhap n cua ma tran: ";
	cin >> n;
	nhap(a, n);
	cout << ktraDoiXung(a, n);
	//xuat(a,n);
	system("pause");
	return 0;
}
/*
Nhập vào một ma trận vuông cấp N. Hãy cho biết ma trận vuông có đối xứng hay không?
Biết rằng: ma trận vuông là ma trận thỏa A[i,j] = A[j,i]

Input:
- Dòng đầu tiên cho biết cấp của ma trận
- N dòng tiếp theo cho biết giá trị của từng phần tử,
mỗi phần tử là một giá trị số nguyên cách nhau một khoảng trắng.

1 2 3
2 3 1
3 1 2
Output:
Kết quả kiểm tra, quy ước 1 là ma trận đối xứng, 0 là ma trận không đối xứng hoặc không hợp lệ
*/