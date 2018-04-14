#include <iostream>
#include <string>
using namespace std;

int process(string str) {
	int max = 0, tmp = 0, pre = false, res = 1, ok = false;
	for (int i = 0; i <= str.size(); i++) {
		if (i == str.size() || str[i] == ' ' && ok) {
			if (!pre) {
				pre = tmp;
			}
			if (tmp == pre) {
				max++;
				if (max > res) { res = max; }
			}
			else {
				pre = tmp;
				max = 1;
			}
			tmp = 0;
			ok = false;
		}
		if (str[i] != ' ') { tmp++; ok = true; }
	}
	return res;
}
int main() {
	int n; cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		cout << process(s) << endl;
	}
	system("pause");
	return 0;
}
/*
Nguyên đang viết một phần mềm đếm từ trong một xâu ký tự.
Cậu cảm thấy buồn chán sau khi viết xong phần mềm rất nhanh.
Bây giờ, cậu muốn tìm P là số lượng lớn nhất các từ có độ dài bằng nhau đứng liên tiếp trong xâu cho trước.

Cho một xâu chỉ chứa các ký tự từ a đến z và ký tự trống.
Mỗi từ là một chuỗi các ký tự liên tiếp khác ký tự trống và các từ phân tách nhau bởi ít nhất một ký tự trống.
Nhiệm vụ của bạn là viết chương trình giúp Nguyên tìm số P nói trên.

Dữ liệu vào

Dữ liệu vào gồm nhiều bộ dữ liệu tương ứng với nhiều test.
Dòng đầu tiên chứa một số nguyên dương không lớn hơn 20 là số lượng các bộ dữ liệu.
Các dòng tiếp theo chứa các bộ dữ liệu.
Trên mỗi dòng tiếp theo chứa xâu ký tự có không quá 1000 từ tương ứng với mỗi bộ dữ liệu,
mỗi từ có không quá 20 ký tự.

Dữ liệu ra
Với mỗi bộ dữ liệu, ghi ra trên một dòng số P mà Nguyên muốn tìm.

Ví dụ
Dữ liệu vào
2
a aa bb cc def ghi
a a a a a bb bb bb bb c c

Dữ liệu ra
3
5
*/