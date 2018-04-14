#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int num[100], nLen = 0, sum = 0, n;

	while (cin >> n){
		num[nLen++] = n;
		sum += n;
	}
	if (nLen >= 3){
		sort(num, num + nLen);
		cout << nLen << endl << sum << endl;
		for (int i = 0; i < nLen; i++){
			cout << num[i] << " ";
		}
	}
	else cout << "NO";
	//system("pause");
	return 0;
}
/*
Đọc một dãy số không cho trước số lượng phần tử, sau đó hãy xác định số lượng phần tử của dãy, 
tính tổng và sắp xếp từ bé đến lớn.
Nếu số lượng phần tử chưa tới 3 thì xuất ra "NO" (không có ngoặc kép)
Ví dụ:
Input:
5 4 3 2 1

Output:
5
15
1 2 3 4 5
*/