// BRUTE FORCE >< NOT USE RECURSION
#include <iostream>
using namespace std;
//CONVERT >> chuỗi thành số ("123" -> 123)
int toInt(string str) {
	int result = 0;
	for (size_t i = 0; i < str.size(); i++) {
		result = result * 10 + str[i] - 48;
	}
	return result;
}
// là hoán vị? (có lặp)
bool isHoanVi(int num, int hv) {
	while (num > 0) {
		if (num % 10 > hv || num % 10 == 0) {
			return false;
		}
		num /= 10;
	}
	return true;
}
int main() {
	// xác định 2 hoán vị đầu tiên và cuối cùng
	int begin[6] = { 0,1,11,111,1111,11111 };
	int k, n, end;
	cin >> k >> n;
	string e = "";
	for (int i = 0; i < n; i++) {
		e += char(k + 48);
	}
	end = toInt(e);

	// tìm và lưu hoán vị
	int hv[10000], soHv = 0;
	for (int i = begin[n]; i <= end; i++) {
		if (isHoanVi(i, k)) {
			hv[soHv] = i; soHv++;
		}
	}

	// xuất các hoán vị tìm được
	cout << soHv << endl;
	for (int i = 0; i < soHv; i++) {
		cout << hv[i] << endl;
	}
	system("pause");
	return 0;
}
/*
Cho k chữ số 1, 2, 3, ..., k (1 ≤ k ≤ 9), hãy liệt kê các chuỗi k-phân có chiều dài n 
theo thứ tự từ điển (xem ví dụ để hiểu rõ hơn chuỗi k-phân).
Dữ liệu nhập:
- Gồm hai số nguyên k và n cách nhau 1 khoảng trắng (1 ≤ k ≤ 9, 1 ≤ n ≤ 5)
Dữ liệu xuất:
- Dòng đầu tiên là một số nguyên m - số lượng chuỗi k-phân tính được.
- Trong m dòng tiếp theo, mỗi dòng là một chuỗi k-phân, các dòng sắp theo thứ tự từ điển.
*/