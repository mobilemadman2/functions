/*
Xây dựng mảng 1 chiều tên Vector. Viết hàm:
- >>, <<, []
- Thêm phần tử vào cuối (push_back)
- Hàm trả về kích thước của Vector (size)
- Hàm xóa (erase):
+ Truyền vị trí i: xóa phần tử tại vị trí i
+ Ko truyền tham số: xóa tất cả
+ Truyền 2 tham số a, b: xóa đoạn [a:b)
- Sắp xếp Vector (sort):
+ Truyền true hoặc ko truyền: sx tăng
+ False: sx giảm
- Hàm tìm kiếm (find): trả về vị trí có giá trị cần tìm, xuất -1 nếu ko tìm thấy.
*/
#include <iostream>
using namespace std;
template <class var>
struct Vector {
	int n = 0;
	var a[100];
	var& operator[](int i) { return a[i]; }
	void push_back(var x) {
		a[n] = x;
		n++;
	}
	int size() {
		return n;
	}
	void erase() {
		n = 0;
	}
	void erase(int i) {
		for (; i < n; i++) {
			a[i] = a[i + 1];
		}
		n--;
	}
	void erase(int i, int j) {
		while (i <= j && j < n) {
			j++;
			a[i] = a[j];
			i++;
		}
		n = i;
	}
	int find(int x) {
		for (int i = 0; i < n; i++) {
			if (a[i] == x) { return i; }
		}
		return -1;
	}
	void sort() {
		var min = a[0];

	}
};
template <class var>
istream& operator >> (istream& is, Vector<var>& v) {
	is >> v[v.n];
	v.n++;
	return is;
}
template <class var>
ostream& operator << (ostream& os, Vector<var> v) {
	for (int i = 0; i < v.n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	return os;
}
int main() {
	Vector<int> a;
	cin >> a >> a >> a;
	cout << a.find(2);
	system("pause");
	return 0;
}