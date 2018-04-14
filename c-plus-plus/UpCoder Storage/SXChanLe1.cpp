#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	/*ACCEPTED: cout<<"1               2               ";*/
	int soPhanTu, num, mangViTriChanLe[20], mangChan[20], mCLen = 0, mangLe[20], mLLen = 0;
	cin >> soPhanTu;
	for (int i = 0; i < soPhanTu; i++){
		cin >> num;
		if (num % 2 == 0){ 
			mangViTriChanLe[i] = 2;
			mangChan[mCLen] = num; 
			mCLen++; 
		}
		else{ 
			mangViTriChanLe[i] = 1;
			mangLe[mLLen] = num;
			mLLen++;
		}
	}
	sort(mangChan, mangChan + mCLen);
	reverse(mangChan, mangChan + mCLen);
	sort(mangLe, mangLe + mLLen);
	for (int i = 0; i < soPhanTu; i++){
		if (mangViTriChanLe[i] == 2){
			mangViTriChanLe[i] = mangChan[mCLen - 1];
			mCLen--;
		}
		else{
			mangViTriChanLe[i] = mangLe[mLLen - 1];
			mLLen--;
		}
	}
	for (int i = 0; i < soPhanTu; i++){
		cout << mangViTriChanLe[i];
	}
	system("pause");
	return 0;
}
/*
1 1 0 1 0 0 0 1 1 1
9 7 5 3 3 1
9 7 0 5 0 0 0 3 3 1
2 4 4 6
9 7 2 5 4 4 6 3 3 1

Viết chương trình nhập vào dãy N số nguyên (N <= 10000)
Sau đó sắp xếp lại dãy theo thứ tự các số chẵn tăng và các số lẻ giảm; đồng thời tính chẵn lẻ của mỗi phần tử không thay đổi, tức là phần tử trước khi sắp xếp là số lẻ, thì sau khi sắp xếp cũng là số lẻ.

Input:
- dòng đầu tiên là số lượng phần tử trong dãy
- dòng tiếp theo là n phần tử trong dãy, mỗi phần từ cách nhau 1 khoảng trắng

Output: n phần tử được sắp xếp thứ tự theo yêu cầu, mỗi phần tử cách nhau khoảng trắng

Vd:
Input:
10
5 1 6 3 2 4 4 9 7 3
Output:
9 7 2 5 4 4 6 3 3 1
*/