#include <iostream>
#include <string>
using namespace std;
string tachMail(string mail){
	int at = mail.find('@');
	string dinhDanh = mail.substr(0, at);
	string tenMien = mail.substr(at, mail.length());
	if (dinhDanh.length()>2){
		for (int i = 1; i < dinhDanh.length() - 1; i++){
			dinhDanh[i] = '*';
		}
	}
	return dinhDanh+tenMien;
}
int main(){
	string mail;
	cin >> mail;
	cout << tachMail(mail) << endl;
	system("pause");
	return 0;
}
/*
Một email hợp lệ bao gồm phần định danh, dấu @ và tên miền cấp email. 
Ví dụ: UPCoder@hcmup.edu.vn thì UPCoder là phần định danh, hcmup.edu.vn là tên miền của email.

Phần định danh (trừ kí tự đầu và cuối) sẽ được công ty ẩn đi bằng các dấu *, 
nếu phần định danh chỉ có 2 kí tự thì giữ nguyên.

Dữ liệu vào: email đầy đủ của khách hàng 
(gồm kí tự in hoa, kí tự thường, chữ số, dấu chấm, dấu @ và gạch nối dưới)
Dữ liệu ra: email sau khi đã ẩn

Ví dụ:
Input: UPCoder@hcmup.edu.vn
Output: U*****r@hcmup.edu.vn
*/