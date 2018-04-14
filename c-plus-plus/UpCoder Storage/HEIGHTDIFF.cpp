#include <iostream>
using namespace std;
struct MINMAX {
	int Min, Max;
};

MINMAX findMinMax2xFaster(int arr[], int start, int end) {
	MINMAX  min_max;
	int index;
	int n = end - start + 1;//n: the number of elements to be sorted, assuming n>0
	if (n % 2 != 0) {// if n is odd

		min_max.Min = arr[start];
		min_max.Max = arr[start];

		index = start + 1;
	}
	else {// n is even
		min_max.Min = arr[start];
		min_max.Max = arr[start + 1];

		index = start + 2;
	}
	int big, small;
	for (int i = index; i < n - 1; i = i + 2) {
		if (arr[i] < arr[i + 1]) { //one comparison
			small = arr[i];
			big = arr[i + 1];
		}
		else {
			small = arr[i + 1];
			big = arr[i];
		}
		if (min_max.Min > small) { //one comparison
			min_max.Min = small;
		}
		if (min_max.Max < big) { //one comparison
			min_max.Max = big;
		}
	}
	return min_max;
}
int main() {
	int n, m;
	cin >> n >> m;
	//lưu danh sách học sinh với chiều cao theo số lượng n
	int dshs[100], slhs = -1;
	while (slhs < n - 1) {
		int chieucao;
		cin >> chieucao;
		dshs[++slhs] = chieucao;
	}
	//nhập từng đoạn theo số lượng m và xử lý yêu cầu
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		//nếu đoạn nhập vào không phù hợp A>B thì xuất ra -1000001
		if (a > b) { cout << -1000001 << endl; }
		//nếu a=b nghĩa là cùng một chỗ nên chênh lệch sẽ = 0
		else if (a == b) { cout << 0 << endl; }
		//tìm max min và xuất kết quả
		else {
			/*int max, min = false;
			//do m đếm từ 1 nên hạ 1 đơn vị để giống trong mảng
			a--; b--;
			for (int j = a; j <= b && j <= slhs; j++) {
			if (!min) { min = dshs[j]; max = min; }
			if (dshs[j] > max) { max = dshs[j]; }
			if (dshs[j] < min) { min = dshs[j]; }
			}*/
			if (b >= slhs + 1) { b = slhs + 1; }
			MINMAX z = findMinMax2xFaster(dshs, a - 1, b - 1);
			cout << z.Max - z.Min << endl;
		}
	}
	system("pause");
	return 0;
}
/*
Ban tuyển chọn đã chuẩn bị một danh sách gồm N học sinh, chia thành M đoạn.
Hãy giúp các thầy cô xác định chênh lệch chiều cao giữa học sinh thấp nhất và cao nhất trong M đoạn này.

Dữ liệu đầu vào:
- Dòng đầu tiên chứa 2 số nguyên N và M.
- Dòng thứ i trong số N dòng sau chứa 1 số nguyên duy nhất, là độ cao của học sinh thứ i.
- Dòng thứ i trong số M dòng tiếp theo chứa 2 số nguyên A, B (dữ liệu đúng sẽ có 1 ≤ A ≤ B ≤ N), cho biết đoạn các học sinh từ A đến B.

Dữ liệu đầu ra: Gồm M dòng, mỗi dòng chứa 1 số nguyên,
là chênh lệch chiều cao giữa học sinh thấp nhất và cao nhất thuộc đoạn tương ứng
(nếu đoạn nhập vào không phù hợp A>B thì xuất ra -1000001).

Ví dụ:
Input:
6 3
1
7
3
4
2
5
1 5
4 6
2 2

Output:
6
3
0
*/