#include <iostream>
#include <string>
#include <fstream>
#include <cmath>		//abs
using namespace std;

//DATE
struct DATE{ int dd, mm, yyyy; };
istream& operator>>(istream& is, DATE & dat){
	is >> dat.dd >> dat.mm >> dat.yyyy;
	return is;
}
ostream& operator<<(ostream& os, DATE  dat){
	string d = "", m = "";
	if (dat.dd < 10){ d = "0"; }
	if (dat.mm < 10){ m = "0"; }
	os << d << dat.dd << "/" << m << dat.mm << "/" << dat.yyyy;
	return os;
}
bool operator==(DATE dat1, DATE dat2){
	return dat1.dd == dat2.dd && dat1.mm == dat2.mm && dat1.yyyy == dat2.yyyy;
}

//CHECK >> kiem tra nam nhuan
bool isLeapYear(DATE dat){
	return dat.yyyy % 4 == 0 && dat.yyyy % 100 != 0 || dat.yyyy % 400 == 0;
}
//GET >> thu cua 7 ngay trong tuan
string getWeekday(DATE dat){
	int d = dat.dd, m = dat.mm, y = dat.yyyy;
	if (m < 3){
		m += 12;
		y--;
	}
	//thu = (ngày+2*tháng+(3*(tháng+1)) / 5 + năm + (năm / 4)) % 7
	switch ((d + 2 * m + (3 * (m + 1)) / 5 + y + (y / 4)) % 7)
	{
	case 1:return "Monday";
	case 2:return "Tuesday";
	case 3:return "Wednesday";
	case 4:return "Thursday";
	case 5:return "Friday";
	case 6:return "Saturday";
	default:return "Sunday";
	}
}
//GET >> ngay thu may trong nam
int getSTT(DATE dat){
	int day[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int res = 0;
	if (isLeapYear(dat)) day[2] = 29;
	for (int i = 1; i < dat.mm; i++) {
		res += day[i];
	}
	res += dat.dd;
	return res;
}
//GET >> ngay tiep theo------------------------------------chua xong 
DATE getNextDate(DATE dat){
	DATE nex = dat;
	if ((dat.dd == 31 && (dat.mm == 1 || dat.mm == 3 || dat.mm == 5 || dat.mm == 7 || dat.mm == 8 || dat.mm == 10))
		|| (dat.dd == 30 && (dat.mm == 4 || dat.mm == 6 || dat.mm == 9 || dat.mm == 11))
		|| (dat.mm == 2 && isLeapYear(dat) && dat.dd == 29)
		|| (dat.mm == 2 && !isLeapYear(dat) && dat.dd == 28))
	{
		nex.dd = 1; nex.mm++;
	}
	else if (dat.mm == 12 && dat.dd == 31){
		nex.yyyy++; nex.dd = 1; nex.mm = 1;
	}
	else{
		nex.dd++;
	}
	return nex;
}
//CHECK >> cung thu
bool isSameWeekday(DATE dat1, DATE dat2){
	return getWeekday(dat1) == getWeekday(dat2);
}
//lay so ngay tu nam 1 SCN
int getSTTfromCN(DATE dat){
	int sum = 0;
	for (int i = 1; i < dat.yyyy; i++){
		DATE dat_temp;
		dat_temp.yyyy = i;
		isLeapYear(dat_temp) ? sum += 366 : sum += 365;
	}
	return sum + getSTT(dat);
}
bool operator<(DATE dat1, DATE dat2){
	return getSTTfromCN(dat1) < getSTTfromCN(dat2);
}
int operator-(DATE dat1, DATE dat2){
	return getSTTfromCN(dat1) - getSTTfromCN(dat2);
}
int main() {
	ifstream in("DATE.inp");
	ofstream out("DATE.out");
	DATE d1, d2;
	in >> d1 >> d2;
	in.close();

	//17/05/2016 Tuesday 138 18/05/2016 TRUE
	out << d1 << " " << getWeekday(d1) << " " << getSTT(d1) << " " << getNextDate(d1) << " ";
	isLeapYear(d1) ? out << "TRUE" << endl : out << "FALSE" << endl;
	out << d2 << " " << getWeekday(d2) << " " << getSTT(d2) << " " << getNextDate(d2) << " ";
	isLeapYear(d2) ? out << "TRUE" << endl : out << "FALSE" << endl;

	//same weekday
	isSameWeekday(d1, d2) ? out << "TRUE" << endl : out << "FALSE" << endl;

	//< > =
	if (d1 < d2){
		out << "1 < 2" << endl;
	}
	else if (d1 == d2){
		out << "1 = 2" << endl;
	}
	else{
		out << "1 > 2" << endl;
	}

	//khoang cach giua d1 va d2
	out << abs(d1 - d2) << endl;

	out.close();
	return 0;
}

/*
Xây dựng cấu trúc để biểu diễn ngày ,tháng, năm (kiểu số nguyên và phải hợp lệ)

Viết quá tải toán tử nhập ( >> ) ,xuất ( << ) (có kiểm tra tính hợp lệ hiện thị ra màn hình dạng dd/mm/yyyy)
Viết hàm kiểm tra năm nhuận khi biết ngày tháng năm (ngày 15/01/2016 thuộc năm nhuận )
viết hàm tìm ngày thứ mấy trong năm khi biết ngày tháng năm (VD: ngày 15/01/2016 là ngày thứ 15 trong năm 2016)
viết hàm xác định thứ trong tuần khi biết ngày tháng năm (16/05/2016 là thứ 2 )
viết hàm tìm ngày kế tiếp khi biết ngày tháng năm (VD: 15/05/2016 ngày kế tiếp là 16/05/2016)
viết quá tải toán tử so sánh bằng ( == )  để so sánh 2 ngày trùng nhau (VD: 17/05/2011 == 17/05/2011 )
viết hàm kiểm tra xem 2 ngày có trùng thứ trong tuần không (VD : 16/05/2016 trùng thứ với 09/05/2016 vì cùng là thứ 2)
viết quá tải so sánh nhỏ hơn ( < ) để so sánh ngày nào nhỏ hơn (VD: 15/05/2013 < 02/07/2013)
viết quá tải so sánh trừ ( - ) để tính số ngày giữa 2 ngày (VD: 15/05/2015 đến ngày 20/05/2015 cách nhau 5 ngày )
gợi ý : cách tính thứ của ngày trong năm :
nếu tháng của ngày đó nhỏ hơn 3 thì biến đổi tháng = tháng + 12 , năm  = năm - 1 ,nếu tháng của ngày đó lớn hơn 2 thì giữ nguyên ,sau đó thế vào CT :
n = (ngày+2*tháng+(3*(tháng+1)) / 5 + năm + (năm / 4)) % 7
với n = 0 là Chủ Nhật, n = 1 là thứ 2 , n = 3 là thứ 3,.....

dữ liệu nhập từ file "DATE.inp":
dòng 1: ngày thứ 1, có dạng DD MM YYYY
dòng 2: ngày thứ 2, có dạng DD MM YYYY

dữ liệu xuất ra file "DATE.out":
dòng 1: xuất ra ngày 1 ,thuộc  thứ mấy trong trong tuần, ngày thứ mấy trong năm, ngày kế tiếp,  nếu ngày 1 là năm nhuân in ra "TRUE", ngược lại in ra "FALSE",
dòng 2: xuất ra ngày 2 ,thuộc  thứ mấy trong trong tuần, ngày thứ mấy trong năm, ngày kế tiếp, nếu ngày 2 là năm nhuân in ra "TRUE", ngược lại in ra "FALSE",
dòng 3: nếu ngày 1 và 2 có thứ trong tuần trùng nhau thì in ra "TRUE" ,ngược lại in ra "FALSE"
dòng 4: nếu ngày 1 nhỏ hơn ngày 2 thì in ra "1 < 2", nếu ngày 1 trùng ngày 2 in ra "1 = 2", nếu ngày 1 lớn hơn ngày 2 in ra "1 > 2"
dòng 5: số ngày giữa ngày 1 và ngày 2
lưu ý :
Chủ Nhật - xuất ra "Sunday"
Thứ 2 - xuất ra "Monday"
Thứ 3 - xuất ra "Tuesday"
Thứ 4 - xuất ra "Wednesday"
Thứ 5 - xuất ra "Thursday"
Thứ 6 - xuất ra "Friday"
Thứ 7 - xuất ra "Saturday"

input:
17 05 2016
05 05 2015

output:
17/05/2016 Tuesday 138 18/05/2016 TRUE
05/05/2015 Tuesday 125 06/05/2015 FALSE
TRUE
1 > 2
378
*/