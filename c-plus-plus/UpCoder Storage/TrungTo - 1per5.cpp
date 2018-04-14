#include <iostream>
#include <string>
#include <cmath>
#include <stack>
using namespace std;

//GET >> độ ưu tiên của các toán tử * / + -
int getPriority(char toan_tu) {
	return 0;
}

//CONVERT >> chuyển trung tố sang hậu tố
string trungToSangHauTo(string trungto) {
	string hau_to;
	stack <char> toan_tu;

	for (size_t i = 0; i < trungto.size(); i++) {
		if (int(trungto[i]) >= 48 && int(trungto[i]) <= 57) {
			hau_to += trungto[i];
		}
		else {
			if (trungto[i] == '*' || trungto[i] == '/' || trungto[i] == '+' || trungto[i] == '-' || trungto[i] == '^') {
				if (toan_tu.empty())
				{
					toan_tu.push(trungto[i]);
				}
				else {
					if (getPriority(toan_tu.top()) <= getPriority(trungto[i])) {
						toan_tu.push(trungto[i]);
					}
					if (getPriority(toan_tu.top()) > getPriority(trungto[i])) {
						hau_to += toan_tu.top();
						toan_tu.pop();
						toan_tu.push(trungto[i]);
					}
				}
			}
			else {
				if (trungto[i] == '(') {
					toan_tu.push(trungto[i]);

				}
				if (trungto[i] == ')') {
					while (toan_tu.top() != '(') {
						hau_to += toan_tu.top();
						toan_tu.pop();
					}
					toan_tu.pop();
				}
			}
		}
	}
	while (!toan_tu.empty()) {
		hau_to += toan_tu.top();
		toan_tu.pop();
	}
	string las;
	//them khoang trang giua moi ki tu
	for (int i = 0; i < hau_to.size(); i++) {
		las = las + hau_to[i] + ' ';
	}
	return las;
}

//CONVERT >> chuỗi thành số
int stringToInt(string str) {
	int result = 0;
	for (size_t i = 0; i < str.size(); i++) {
		result = result * 10 + str[i] - 48;
	}
	return result;
}

//CALCULATE >> tính biểu thức hậu tố
int tinhHauTo(string str) {
	stack <int> num;

	//a và b là 2 toán hạng
	int a, b;
	//lặp chuỗi
	for (int i = 0; i < str.size(); i++)
	{
		switch (str[i])
		{
		case '^':
			a = num.top();
			num.pop();
			b = num.top();
			num.pop();
			num.push(pow(b, a));
			break;
		case '+':
			a = num.top();
			num.pop();
			b = num.top();
			num.pop();
			num.push(a + b);
			break;
		case '-':
			a = num.top();
			num.pop();
			b = num.top();
			num.pop();
			num.push(b - a);
			break;
		case '*':
			a = num.top();
			num.pop();
			b = num.top();
			num.pop();
			num.push(a * b);
			break;
		case ' ':break;
		default:
			string nnum;
			//lặp đến khi gặp space
			while (str[i] != ' ')
			{
				nnum += str[i];
				i++;
			}
			num.push(stringToInt(nnum));
			nnum.clear();
			break;
		}
	}
	return num.top();
}

int main()
{
	string s = "(1+(2+3)-(1*3))";
	//cin >> s;
	cout << trungToSangHauTo(s);
	cout << tinhHauTo(trungToSangHauTo(s));
	system("pause");
	return 0;
}
/*
Cho một biểu thức trung tố gồm các số nguyên dương (<1000), các toán tử: +, -, *, ^ và các dấu ngoặc đơn biểu thị thứ tự ưu tiên thực hiện phép tính.
Hãy viết chương trình tính giá trị biểu thức này.

Dữ liệu đầu vào: Biểu thức trung tố
Dữ liệu đầu ra: một số nguyên duy nhất là giá trị biểu thức

Ví dụ:
Input: (1+(2+3))
(Lưu ý: Input không ghi là 1+2+3)

Output: 6
*/