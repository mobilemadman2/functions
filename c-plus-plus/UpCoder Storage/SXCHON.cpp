#include <iostream>
#include <cstdlib>
using namespace std;

//hieu chinh
void Shift(int num_arr[], int left, int right)
{
	int  x, curr, joint;
	curr = left; joint = 2 * curr + 1;
	x = num_arr[curr];
	while (joint <= right)
	{
		if (joint < right) //neu co du 2 thanh phan lien doi
		{
			if (num_arr[joint] < num_arr[joint + 1]) {
				joint = joint + 1;
			}
		}
		if (num_arr[joint] < x) //thoa quan he lien doi
		{
			break;
		}
		num_arr[curr] = num_arr[joint];
		curr = joint;
		joint = 2 * curr + 1;
	}
	num_arr[curr] = x;
}

//tao heap
void CreateHeap(int num_arr[], int right)
{
	int left;
	for (left = (right - 1) / 2; left >= 0; left--)
		Shift(num_arr, left, right - 1);
}

//sap xep tang dan
void HeapSort(int a[], int N)
{
	int right;
	CreateHeap(a, N);
	right = N - 1;
	while (right > 0)
	{
		int tmp = a[0];
		a[0] = a[right];
		a[right] = tmp;
		right--;
		Shift(a, 0, right);
	}
}

//xuat mang
void xuat(int num[], int len){
	for (int i = 0; i < len; i++){
		cout << num[i] << " ";
	}
	cout << endl;
}
int main(){
	int num[70], len = 0, numm;
	while (cin >> numm){
		num[len] = numm;
		len++;
	}
	Shift(num, 1, len);
	HeapSort(num, len);
	xuat(num, len);
	system("pause");
	return 0;
}
/*
Viết chương trình sắp xếp bằng thuật toán chọn trực tiếp/chèn trực tiếp/sắp xếp nhanh/v.v..

Input:
- 1 dãy số nguyên

Output:
- dãy số đã được sắp xếp tăng dần

ví dụ:
input
2 1 3 0

output
0 1 2 3
*/