#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>	/*setwidth*/
using namespace std;
int toInt(string str) {
	size_t result = 0, i = 0, am = 1;
	if (str[0] == '-') { i = 1; am = -1; }
	for (; i < str.size(); i++) {
		result = result * 10 + str[i] - 48;
	}
	return result*am;
}
struct TIME {
	int h, m, s;
};
istream& operator >> (istream& is, TIME& t) {
	string s; cin >> s;
	t.h = toInt(s.substr(0, 2));
	t.m = toInt(s.substr(3, 2));
	t.s = toInt(s.substr(6, 2));
	return is;
}
bool operator>(TIME a, TIME b) {
	if (a.h > b.h) { return true; }
	else if (a.h == b.h) {
		if (a.m > b.m) { return true; }
		else if (a.m == b.m) {
			if (a.s > b.s) { return true; }
		}
	}
	return false;
}
int diffTime(TIME a, TIME b) {
	time_t now;
	struct tm begin; struct tm end;
	int seconds;

	time(&now);  /* get current time; same as: now = time(NULL)  */

	begin = *localtime(&now); end = *localtime(&now);

	begin.tm_hour = a.h; begin.tm_min = a.m; begin.tm_sec = a.s;
	end.tm_hour = b.h; end.tm_min = b.m; end.tm_sec = b.s;
	if (a>b) {
		end.tm_mday += 1;
	}
	seconds = difftime(mktime(&end), mktime(&begin));
	return seconds;
}
int main() {
	TIME a, b;
	int n, tLamBai; cin >> n;
	while (n != 0) {
		cin >> a >> b >> tLamBai; tLamBai *= 60;
		int lim = diffTime(a, b); if (lim == 0) { lim = 86400; }
		if (tLamBai <= lim) { cout << "Perfect" << endl; }
		else if (tLamBai <= lim + 3600) { cout << "Extra" << endl; }
		else { cout << "Fail" << endl; }
		n--;
	}
	system("pause");
	return 0;
}