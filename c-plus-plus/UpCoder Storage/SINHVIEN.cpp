#include <iostream>
#include <string>
using namespace std;
struct SV
{
	string HoTen;
	int NamSinh;
	double DTB;
};
istream& operator >> (istream& is, SV &sv) {
	is >> sv.HoTen >> sv.NamSinh >> sv.DTB;
	return is;
}
ostream& operator << (ostream& os, SV sv) {
	os << sv.HoTen << " " << sv.NamSinh << " " << sv.DTB << endl;
	return os;
}
int main() {
	SV sv, max, min, listSV[100];
	int n = 0;
	while (cin >> sv) {
		if (n == 0) {
			max = sv;
			min = sv;
		}
		if (sv.DTB > max.DTB) { max = sv; }
		if (sv.DTB < min.DTB) { min = sv; }
		listSV[n] = sv;
		n++;
	}
	cout << "Diem cao nhat lop:" << endl;
	int stt = 1;
	for (int i = 0; i < n; i++) {
		if (listSV[i].DTB == max.DTB) {
			cout << "#" << stt << endl << listSV[i];
			stt++;
		}
	}
	cout << "Diem thap nhat lop:" << endl;
	stt = 1;
	for (int i = 0; i < n; i++) {
		if (listSV[i].DTB == min.DTB) {
			cout << "#" << stt << endl << listSV[i];
			stt++;
		}
	}
	system("pause");
	return 0;
}
/*
http://upcoder.xyz/index.php/scoreboards/view/175334/560915ff7d447c3ba618ef15d2c2c3ef/
*/