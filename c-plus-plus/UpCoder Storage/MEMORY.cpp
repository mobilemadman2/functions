//http://upcoder.xyz/index.php/scoreboards/view/175319/d5f01003d16b7633530cd55461f4cfb3/phucbm
#include <iostream>
using namespace std;

int main()
{
	//input
	int n, k, a[1000001];
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	//process
	int count = 1;
	while (k > count)
	{
		k = k - count++;
	}
	//output
	cout << a[k] << endl;
	return 0;
}
/*
Trong 1 lớp học để tập luyện trí nhớ , thầy giáo ra một trò chơi .
Bạn thứ nhất nghĩ ra 1 con số x1 và đọc nó .
Bạn thứ hai nghĩ ra 1 con số x2 và phải đọc con số x1 x2 . Cứ như vậy cho đến bạn thứ n .
Hỏi con số đếm thứ k là con số mấy
Input :
- Dòng đầu 2 con số n và k ( 1<=n<=10^6)
- Dòng thứ hai chứa x1 , x2 , …. ,xn là con số mà bạn thứ i chọn ( 1<=i<=n)

Output:
- In số thứ k

Input
2 2
1 2
Output
1

Input
4 5
10 4 18 3
Output
4

10 15
0 1 2 3 4 5 6 7 8 9
0 0 1 0 1 2 0 1 2 3 0 1 2 3 4 0 1 2 3 4 5 0 1 2 3 4 5 6
Giải thích :
Test case 1 : Trình tự đọc sẽ là : 1 , 1 , 2 . Nếu k = 2 thì kết quả sẽ là 1
Test case 2 : Trình tự đọc sẽ là : 10, 10 , 4 , 10, 4 , 18 , 10 , 4 , 18 , 3 . Nếu k = 5 thì kết quả sẽ là 4
*/