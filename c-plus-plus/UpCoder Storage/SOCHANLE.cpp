#include <iostream>
#include <string>
using namespace std;
//CONVERT >> chuỗi thành số
int stringToInt(string str) {
	int result = 0;
	for (size_t i = 0; i < str.size(); i++) {
		result = result * 10 + str[i] - 48;
	}
	return result;
}
//GET >> tổng chữ số: 123 = 1+2+3 = 6
int sumOfInt(int num) {
	int tong = 0;
	while (num > 0) {
		tong += num % 10;
		num /= 10;
	}
	return tong;
}
int main() {
	string a, b, n;
	cin >> a >> b >> n;

	string achan, ale, bchan, ble;

	for (int i = 0; i < a.size(); i++) {
		if (i % 2 == 0) { achan += a[i]; }
		else { ale += a[i]; }
	}

	for (int i = 0; i < b.size(); i++) {
		if (i % 2 == 0) { bchan += b[i]; }
		else { ble += b[i]; }
	}

	//Dòng 1: xuất số "CHỮ SỐ CHẴN" của số a
	cout << achan << endl;
	//Dòng 2: xuất số "CHỮ SỐ CHẴN" của số b
	cout << bchan << endl;
	//Dòng 3: ghi true nếu a < b, ngược lại ghi false
	stringToInt(a) < stringToInt(b) ? cout << "true" << endl : cout << "false" << endl;
	//Dòng 4: xuất tổng thành phần của a
	stringToInt(n) == 0 ? cout << sumOfInt(stringToInt(achan)) << endl : cout << sumOfInt(stringToInt(ale)) << endl;
	//Dòng 5: xuất tổng thành phần của b
	stringToInt(n) == 0 ? cout << sumOfInt(stringToInt(bchan)) << endl : cout << sumOfInt(stringToInt(ble)) << endl;

	return 0;
}
/*
Số "CHỮ SỐ CHẴN" của một số được định nghĩa là số
được tạo bởi các chữ số ở vị trí chẵn của một số nào đó (vị trí được đếm từ 0, tính từ trái sang phải)
(tương tự cho định nghĩa "CHỮ SỐ LẼ")

Ví dụ: số 1234, thì số "CHỮ SỐ CHẴN" của nó là 13.

Yêu cầu 1: viết các hàm sau:
1. quá tải toán tử >> (nhập vào 1 số nguyên)
2. quá tải toán tử << (xuất "CHỮ SỐ CHẴN" của số đó)
ví dụ: với số a=1234, cout << a; kết quả sẽ là: 13.
3. Quá tải toán tử so sánh < (dựa vào "CHỮ SỐ CHẴN" của nó)
ví dụ: 1434 < 1254 (vi 13<15)
4. viết hàm tính tổng thành phần (có sử dụng tham số mặc định)
+ Tham số mặc định có giá trị 0: là tổng các chữ số tại vị trí chẵn của số ban đầu
+ Tham số có giá trị 1 là tổng các chữ số tại vị trí lẽ của số ban đầu

ví dụ: với a=1234
cout << tongThanhPhan(a,0); // ket quả là: 4 (vì 1+3 = 4)
cout << tongThanhPhan(a); // ket quả là: 4 (vì 1+3 = 4)
cout << tongThanhPhan(a,1); // ket quả là: 6 (vì 2 + 4  = 6)

Yêu cầu 2: viết chương trình nhập theo thứ tự sau:
Dòng 1: nhập 2 số nguyên a và b (10 <= a,b <= 35000)
Dòng 2: nhập cách tính tổng thành phần

Yêu cầu xuất ra theo thứ tự sau:
- Dòng 1: xuất số "CHỮ SỐ CHẴN" của số a
- Dòng 2: xuất số "CHỮ SỐ CHẴN" của số b
- Dòng 3: ghi true nếu a < b, ngược lại ghi false (dựa vào phép so sánh < ở trên)
- Dòng 4: xuất tổng thành phần của a
- Dòng 5: xuất tổng thành phần của b

ví dụ:
input:
1234 5678
0
output:
13
57
true
4
12
*/