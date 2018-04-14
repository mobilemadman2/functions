#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;
bool isNgoacDung(string str) {
	stack <char> s;
	for (int i = 0; i < str.size(); i++) {
		s.push(str[i]);
		if (s.top() == ')') {
			s.pop();
			if (!s.empty() && s.top() == '(') { s.pop(); }
			else { s.push(')'); }
		}
		else if (s.top() == '}') {
			s.pop();
			if (!s.empty() && s.top() == '{') { s.pop(); }
			else { s.push('}'); }
		}
		else if (s.top() == ']') {
			s.pop();
			if (!s.empty() && s.top() == '[') { s.pop(); }
			else { s.push(']'); }
		}
	}
	if (s.empty()) { return true; }
	else { return false; }
}
int main() {
	ifstream in("ngoacdung.inp");
	ofstream out("ngoacdung.out");

	string str;
	in >> str; in.close();
	isNgoacDung(str) ? out << "yes" : out << "no";
	out.close();
	return 0;
}
/*
Xâu ngoặc đúng

Gọi xâu chỉ chứa các kí tự ngoặc tròn (, ), ngoặc vuông [, ] và ngoặc nhọn {, } là xâu ngoặc. Xâu ngoặc đúng được định nghĩa như sau:
- Xâu rỗng được coi là xâu ngoặc đúng
- Nếu a là xâu ngoặc đúng thì (a), {a}, [a] cũng là xâu ngoặc đúng
- Nếu a và b là các xâu ngoặc đúng thì ab cũng là xâu ngoặc đúng

Viết chương trình xác định xâu đầu vào có phải xâu ngoặc đúng hay không?

input: nằm trong file ngoacdung.inp

Chứa một xâu cần xác định
output: xuất ra file ngoacdung.out

Nếu xâu ngoặc đúng thì xuất  “yes” ngược lại xuất ra “no”

ví dụ:

input:

[()]
output:

yes
*/