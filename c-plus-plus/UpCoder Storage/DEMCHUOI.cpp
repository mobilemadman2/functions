#include<iostream>
#include <string>
using namespace std;

//FIND >> tìm chuỗi a trong chuỗi b (aba trong ababa => 2)
int countStringAinB(string a, string b){
	int counter = 0, position = 0;
	while (true)
	{
		position = b.find(a, position);
		if (position != -1)
		{
			counter++;
			position++;
		}
		else break;
	}
	return counter;
}

int main()
{
	int sl;
	cin >> sl;

	string a, b;
	cin >> a;

	int arr[10];
	for (int i = 0; i < sl; i++){
		cin >> b;
		arr[i] = countStringAinB(a, b);
	}

	for (int i = 0; i < sl; i++){
		cout << arr[i] << endl;
	}
	system("pause");
	return 0;
}
/*
Dữ liệu đầu vào:
- Dòng 1 là số nguyên N
- Dòng 2 chứa 1 chuỗi A
- N dòng tiếp theo, mỗi dòng là 1 chuỗi.

Dữ liệu đầu ra :Đếm số lần xuất hiện chuỗi A có trong N chuỗi còn lại.

ví dụ:
2
ab
aabab
cdfaf

output
2
0
*/