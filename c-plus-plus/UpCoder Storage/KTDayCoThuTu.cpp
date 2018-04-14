#include <iostream>
using namespace std;

int main(){
	int soLanNhap, num, flag = 1, max, min, soLanTang = 0, soLanGiam = 0;
	cin >> soLanNhap;
	for (int i = 0; i < soLanNhap; i++){
		cin >> num;
		if (flag == 1){ max = num; min = num; flag = 0; }
		if (num > max){ soLanTang++; max = num; }
		if (num < min){ soLanGiam++; min = num; }
	}
	//phai tru 1 vi num dau tien se = max = min
	soLanTang == soLanNhap - 1 ? cout << 1 :
	soLanGiam == soLanNhap - 1 ? cout << -1 : cout << 0;
	system("pause");
	return 0;
}
/*
Viết chương trình nhập vào dãy số nguyên N phần tử. Sau đó kiểm tra dãy có thứ tự tăng, 
giảm hay không có thứ tự.
Biết rằng,
Dãy có thứ tự tăng là dãy thỏa A[i] < A[j] với 0 <= i < j < N
Dãy có thứ tự giảm là dãy thỏa A[i] > A[j] với 0 <= i < j < N
Dãy không có thứ tự là dãy không thỏa 2 điều kiện trên.

Input:
- dòng đầu tiên là số nguyên n chỉ số lượng phần tử trong dãy
- dòng tiếp theo là n số nguyên chỉ từng giá trị phần tử trong dãy. Mỗi phần tử cách nhau khoảng trắng.

Output: giá trị quy ước cho biết kết quả: -1 (dãy giảm), 1 (dãy tăng), 0 (dãy không có thứ tự)

Vd:
Input:
5
12 3 15 2 8
Output:
0

Input:
5
1 2 3 5 8
Output:
1

Input:
5
12 11 10 2 -8
Output:
-1
*/