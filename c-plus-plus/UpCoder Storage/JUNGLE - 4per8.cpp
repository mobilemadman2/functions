#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
//CHECK >> số nguyên tố?
bool isPrimeNumber(int num) {
	if (num < 2) { return false; }
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num%i == 0) { return false; }
	}
	return true;
}
int main() {
	int vitri, tainguyen;
	cin >> vitri >> tainguyen;

	stack <int> map; int x = 0, snt = 2;
	while (true) {
		if (isPrimeNumber(snt)) {
			if (x % 2 == tainguyen % 2) {
				map.push(snt);
				if (snt >= vitri) { break; }
			}
			x++;
		}
		snt++;
	}

	int top1 = map.top(); map.pop();
	if (abs(top1 - vitri) < abs(map.top() - vitri)) { cout << top1; }
	else { cout << map.top(); }
	system("pause");
	return 0;
}
/*
Một người nông dân lạc vào khu rừng ,ông ta đang ở tọa độ n và ông ta cần nước hoặc thức ăn .
Trên tay ông ta cầm 1 tấm bản đồ , tấm bản đồ đánh dấu nguồn thức ăn và
nước bằng 1 số nguyên tố xen kẽ nhau . Vị trí đầu tiên trên bản đồ là nước .
Hãy tìm ra điểm gần nhất nguồn thức ăn hoặc nước mà ông ta cần .

Input  :
1 dòng chứa 2 số n và m với n là vị trí của ông ta , m là tài nguyên ông ta cần với 0 là nước và 1 là thức ăn ( 0 <= n , m <=10^6 )

Output :
1 số là tọa độ điểm thức ăn hoặc nước gần ông ta nhất .

Example

Input
6 0
Output
5
Giải thích : 2 , 5 lần lượt là nguồn nước . 3 , 7 lần lượt là nơi chứa thức ăn . Vậy kết quả là 5
*/