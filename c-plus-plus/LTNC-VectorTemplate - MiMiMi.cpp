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

#include<iostream>
using namespace std;

template <typename T>
struct Vector {
	T a[1000];
	int n;
	T& operator [](int i) {
		return a[i];
	}
};

template <typename T>
istream& operator >> (istream & is, Vector <T> & v) {
	is >> v.n;
	for (int i = 0; i < v.n; i++) {
		is >> v.a[i];
	}
	return is;
}

template <typename T>
ostream& operator << (ostream& os, Vector <T> v) {
	for (int i = 0; i < v.n; i++) {
		os << v.a[i];
	}
	return os;
}

template <typename T>
T push_back(Vector <T> v) {
	is >> v.a[v.n + 1];
}

template <typename T>


int main() {


	system("pause");
	return 0;
}