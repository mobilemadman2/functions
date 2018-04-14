#include <iostream>
#include <string>
using namespace std;
string toLowerCase(string s);
int count(string s, string mode);
bool operator > (string a, string b);
string lexi(string s, string mode);
int main() {
	// INPUT
	string s, line;
	bool check = false;
	while (true)
	{
		getline(cin, line);
		if (check)break;
		// find the last line
		if (line != ".......") {
			// find dash and erase
			if (line[line.size() - 1] == '-') {
				line.erase(line.find("-"));
			}
			else { line += ' '; }

			// to lower case
			line = toLowerCase(line);

			s += line;
		}
		else { check = true; }
	}

	// OUTPUT
	cout << s << endl;

	cout << count(s, "digit") << " " << count(s, "vowel") << " " << count(s, "consonant") << endl;

	cout << lexi(s, "min") << " " << lexi(s, "max") << endl;

	if (s.find("cs3233") > s.size()) { cout << 0 << endl; }
	else { cout << 1 << endl; }

	cout << count(line, "s") << " " << count(line, "h") << " " << count(line, "7") << endl;

	system("pause");
	return 0;
}
//CONVERT >> chuyển sang chữ thường
string toLowerCase(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 65 && s[i] <= 90) {
			s[i] = s[i] + 32;
		}
	}
	return s;
}
//COUNT >> đếm số các con số (digit), nguyên âm (vowel) và phụ âm (consonant)
int count(string s, string mode) {
	int c = 0;
	if (mode == "digit") {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 48 && s[i] <= 57) { c++; }
		}
	}
	else if (mode == "vowel") {
		for (int i = 0; i < s.size(); i++) {
			//vowel: a-97, e-101, i-105, o-111, u-117
			if (s[i] == 97 || s[i] == 101 || s[i] == 105 || s[i] == 111 || s[i] == 117) {
				c++;
			}
		}
	}
	else if (mode == "consonant") {
		for (int i = 0; i < s.size(); i++) {
			//consonant: bcd:98-100, fgh:102-104, jklmn:106-110, pqrst:112-116, vwxyz:118-122
			if ((s[i] >= 98 && s[i] <= 100) ||
				(s[i] >= 102 && s[i] <= 104) ||
				(s[i] >= 106 && s[i] <= 110) ||
				(s[i] >= 112 && s[i] <= 116) ||
				(s[i] >= 118 && s[i] <= 122)) {
				c++;
			}
		}
	}
	else {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == mode[0]) { c++; }
		}
	}
	return c;
}
//COMPARE >> so sánh 2 chuỗi theo kiểu từ điển
bool operator > (string a, string b) {
	//lấy độ dài ngắn hơn làm đk dừng loop
	int len = a.size();
	if (a.size() > b.size()) { len = b.size(); }
	//nếu có bất cứ kí tự nào của a so với b
	for (int i = 0; i < len; i++) {
		if (a[i] > b[i]) { return true; }	//lớn hơn => true;
		if (a[i] < b[i]) { return false; }	//bé hơn => false;
											//bằng thì tiếp tục vòng lặp
	}
	//hết vòng lặp thì chuỗi nào dài hơn sẽ lớn hơn
	return a.size() > b.size();
}
//STRING >> lấy từ lớn nhất hoặc nhỏ nhất theo thứ tự từ điển
string lexi(string s, string mode) {
	string min = "", max = "", word = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ' && word != "") {
			if (min == "") { min = word; }
			else if (min > word) { min = word; }
			if (word > max) { max = word; }
			word = "";
		}
		else {
			if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57)) {
				word += s[i];
			}
		}
	}
	if (mode == "min") { return min; }
	if (mode == "max") { return max; }
}
/*
Input and Output
Input contains several lines that contain only alphabet characters [A-Za-z], digits [0-9], space, dash ('-'), and period ('.').
The first input block ends with a line containing seven periods (".......").
The dash character, if appears, will only appear at the end of a line.
If there is a dash character at the end of a line, it means that the last word of that line is actually continued in the next line.
The dash character will not appear in the line before (".......").
There can be up to 30 characters per line and no more than 10 lines for this input block.

For this input block, output the input again but now in one line and in lowercase form.
Then output three integers in one line to denote the number of digits, vowels, and consonants found in this input block.
Then output two words (separated by a single space) in this input block that is lexicographically smallest and largest.
Here, word is defined by consecutive alphabet(s) and/or digit(s) separated by either space(s), dot(s), or a newline.
Finally, output either "0" or "1" in one line: "1" if the first input block contains substring "cs3233" (case insensitive); "0" otherwise.

After the line with seven periods ("......."), there will be one more line appearing in the input.
This last line can be of any length.

For this last line, output three integers in one line to denote the number of character 's' (lower case), 'h' (lower case), and '7' in the last line.

This problem can be frustrating one if you keep getting WA...
Thus, we have included the actual input/output data with very trivial modification.

The Actual Input (with very very few trivial modification so that you cannot just print the output)
I love CS3233 Competitive Pro-
gramming and AlGoRiThM. Of
course I love my wife Grace
Suryani very much too. Test
that there are thirty chars
m12345678901234567890123456789
......
hehehe the line above only
contains six . cannot stop...
....... after the first input block... there will be one last line can be very long... I am going to type 77777777777777777777777777777777777777777777777777777777777777777777777777777 then a longgggggggggggggggggggggggggggggggggggggggggggg ssssssssssssssssssssssssssstrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrringgggggggggggggggggggggggg ssssssssssssssssssssssssssstrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrringgggggggggggggggggggggggg ssssssssssssssssssssssssssstrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrringgggggggggggggggggggggggg ssssssssssssssssssssssssssstrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrringgggggggggggggggggggggggg ssssssssssssssssssssssssssstrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrringgggggggggggggggggggggggg ssssssssssssssssssssssssssstrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrringgggggggggggggggggggggggg ssssssssssssssssssssssssssstrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrringgggggggggggggggggggggggg ssssssssssssssssssssssssssstrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrringggggggggggggggggggggggggssssssssssssssssssssssssssstrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrringggggggggggggggggggggggggssssssssssssssssssssssssssstrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrringggggggggggggggggggggggggssssssssssssssssssssssssssstrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrringggggggggggggggggggggggggssssssssssssssssssssssssssstrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrringggggggggggggggggggggggggssssssssssssssssssssssssssstrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrringggggggggggggggggggggggggssssssssssssssssssssssssssstrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrringggggggggggggggggggggggggssssssssssssssssssssssssssstrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrringggggggggggggggggggggggggssssssssssssssssssssssssssstrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrringggggggggggggggggggggggggssssssssssssssssssssssssssstrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrringggggggggggggggggggggggggssssssssssssssssssssssssssstrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrringggggggggggggggggggggggggssssssssssssssssssssssssssstrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrringggggggggggggggggggggggggssssssssssssssssssssssssssstrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrringggggggggggggggggggggggggssssssssssssssssssssssssssstrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrringgggggggggggggggggggggggg

The Actual Output (you will get WA if you just print these output)
i love cs3233 competitive programming and algorithm. of course i love my wife grace suryani very much too.
test that there are thirty chars m12345678901234567890123456789 ...... hehehe the line above only contains six . cannot stop...
33 58 96
above wife
1
569 3 77
*/