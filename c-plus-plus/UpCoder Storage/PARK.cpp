#include <iostream>
using namespace std;
int isExist(int num, int a[], int len) {
	for (int i = 0; i < len; i++) {
		if (num == a[i]) { return i; }
	}
	return -1;
}
int main() {
	int num, soxe[100], lan_gui[100], index = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int gui; cin >> gui;
		if (isExist(gui, soxe, index) == -1) {
			//chưa có trong sổ thì thêm vào
			soxe[index] = gui;
			lan_gui[index] = 1;
			index++;
		}
		else {
			//có rồi thì tăng lần gửi
			lan_gui[isExist(gui, soxe, index)]++;
		}
	}

	//đếm số lần gửi và tính phí
	int fee = 0;
	for (int i = 0; i < index; i++) {
		if (lan_gui[i] > 5) { fee += 100 + lan_gui[i] - 5; }
		else { fee += 100; }
	}
	cout << fee;
	system("pause");
	return 0;
}
/*
Một  bãi đỗ  xe  nhận  trông xe  trong  vòng một  tháng.
Mỗi  xe  sẽ được  gắn một  số  hiệu  là một  số nguyên dương T (10102010 ≤ T ≤ 10109999).
Hai xe khác nhau sẽ được gắn hai số hiệu khác nhau. Một xe có thể ra vào bãi đỗ xe nhiều lần,
mỗi lần vào bãi đỗ xe, người trông xe sẽ ghi vào sổ sách số hiệu của chiếc xe đó.
Cuối tháng dựa vào sổ ghi chép, người trông xe làm thống kê về số lần vào bãi đỗ xe của từng chiếc xe để tiến hành thu phí.
Nếu một chiếc xe vào bãi đỗ xe p lần, cuối tháng chủ xe phải trả một lượng phí được tính như sau:
- Nếu p ≤ 5, chi phí là: 100.
- Nếu p > 5, chi phí là: 100 + (p-5)
Yêu cầu: Tính tổng số phí người trông xe thu được vào cuối tháng.
Dữ liệu nhập:
- Dòng đầu chứa một số nguyên dương K (0 < K ≤ 106)
- K dòng tiếp theo, mỗi dòng chứa số hiệu một chiếc xe.
Dữ liệu xuất:
-  Là tổng số phí thu được.
Lưu ý: dùng scanf("%lld", &x) để đọc số nguyên 64 bít.
Ví dụ
input
7
10102010
10108888
10102010
10102010
10102010
10102010
10102010
output
201
*/