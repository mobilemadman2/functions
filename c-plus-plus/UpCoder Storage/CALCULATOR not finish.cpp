#include <iostream>
#include <string>
#include <stack>
using namespace std;

//GET >> độ ưu tiên của các toán tử * / + -
int getPriority(string toan_tu) {
	switch (toan_tu[0]) {
	case '*': return 4;
	case '/': return 3;
	case '+': return 2;
	case '-': return 1;
	default: return 0;
	}
}
//CONVERT >> chuỗi thành số ("123" -> 123)
int toInt(string str) {
	int result = 0;
	for (size_t i = 0; i < str.size(); i++) {
		result = result * 10 + str[i] - 48;
	}
	return result;
}
//CONVERT >> chuyển trung tố sang hậu tố
string trungToSangHauTo(string trungto[], int n) {
	stack <string> hau_to;
	stack <string> toan_tu;
	for (int i = 0; i < n; i++) {
		if (int(trungto[i][0]) >= 48 && int(trungto[i][0]) <= 57) {
			string tmp = "";
			tmp += trungto[i];
			hau_to.push(tmp);
		}
		else {
			if (trungto[i] == "*" || trungto[i] == "/" || trungto[i] == "+" || trungto[i] == "-") {
				if (toan_tu.empty()) {
					toan_tu.push(trungto[i]);
				}
				else {
					if (getPriority(toan_tu.top()) <= getPriority(trungto[i])) {
						toan_tu.push(trungto[i]);
					}
					if (getPriority(toan_tu.top()) > getPriority(trungto[i])) {
						hau_to.push(toan_tu.top());
						toan_tu.pop();
						toan_tu.push(trungto[i]);
					}
				}
			}
			else {
				if (trungto[i] == "(") {
					toan_tu.push(trungto[i]);
				}
				if (trungto[i] == ")") {
					while (toan_tu.top() != "(") {
						hau_to.push(toan_tu.top());
						toan_tu.pop();
					}
					toan_tu.pop();
				}
			}
		}
	}
	while (!toan_tu.empty()) {
		hau_to.push(toan_tu.top());
		toan_tu.pop();
	}
	string kq = "";
	while (!hau_to.empty()) {
		kq = hau_to.top() + " " + kq;
		hau_to.pop();
	}
	return kq;
}

//CALCULATE >> tính biểu thức hậu tố
int tinhHauTo(string str) {
	stack <int> toan_tu;
	//a và b là 2 toán hạng
	int a, b;
	//lặp chuỗi
	for (size_t i = 0; i < str.size(); i++)
	{
		switch (str[i]) {
		case '+':
			a = toan_tu.top(); toan_tu.pop();
			b = toan_tu.top(); toan_tu.pop();
			toan_tu.push(a + b); break;
		case '-':
			a = toan_tu.top(); toan_tu.pop();
			b = toan_tu.top(); toan_tu.pop();
			toan_tu.push(b - a); break;
		case '*':
			a = toan_tu.top(); toan_tu.pop();
			b = toan_tu.top(); toan_tu.pop();
			toan_tu.push(a * b); break;
		case '/':
			a = toan_tu.top(); toan_tu.pop();
			b = toan_tu.top(); toan_tu.pop();
			toan_tu.push(b / a); break;
		case ' ':break;
		default:
			string num;
			//lặp đến khi gặp space
			while (str[i] != ' ') {
				num += str[i]; i++;
			}
			toan_tu.push(toInt(num));
			num.clear(); break;
		}
	}
	return toan_tu.top();
}

int main()
{
	//nhập chuỗi và lấy phần tử vào mảng
	string s = "( 2 + 5 ) * ( 9 - 3 ) * 6 - 1";
	string toan_tu[100], tmp = "";
	int n = 0;
	for (int i = 0; i <= s.length(); i++) {
		if (i == s.length() && tmp.length() > 0 || tmp.length() > 0 && s[i] == ' ') {
			toan_tu[n] = tmp; n++; tmp = "";
		}
		else if (s[i] != ' ') { tmp += s[i]; }
	}
	//chuyển sang hậu tố
	cout << trungToSangHauTo(toan_tu, n) << endl;
	cout << tinhHauTo(trungToSangHauTo(toan_tu, n));

	system("pause");
	return 0;
}