#include <iostream>
#include <string>
using namespace std;
//FIND >> tìm số chuỗi a trong chuỗi b (aba trong ababa => 2)
int countStringAinB(char a, string b) {
	int counter = 0, position = 0;
	while (true)
	{
		position = b.find(a, position);
		if (position != -1)
		{
			counter++;
			position++;
		}
		else break;
	}
	return counter;
}
string toLowerCase(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 65 && s[i] <= 90) {
			s[i] = s[i] + 32;
		}
	}
	return s;
}
int main() {
	string s; getline(cin, s); s = toLowerCase(s);
	int count; char kiTu = 'a';	// 97 - 122
	while (kiTu <= 122) {
		count = countStringAinB(kiTu, s);
		if (count > 0) { cout << kiTu << " : " << count << endl; }
		kiTu += 1;
	}
	system("pause");
	return 0;
}