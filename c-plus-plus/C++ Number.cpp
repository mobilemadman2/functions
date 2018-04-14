#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // setprecision
#include <cmath>		//sqrt, pow

int main() {
	
	system("pause");
	return 0;
}
//lấy phần thực
#include <iomanip>
double f = 3.14159;
int x = 15;
cout << setfill('0') << setw(5) << x;//output: 00015
cout << setprecision(5) << f << '\n';//output: 3.1415
cout << setprecision(9) << f << '\n';//output: 3.14159
cout << fixed;
cout << setprecision(5) << f << '\n';//output: 3.14159
cout << setprecision(9) << f << '\n';//output: 3.141590000

//ROUND >> làm tròn số
#include <math.h>
double val = 1.23456789;
cout << ceilf(val * 1000) / 1000 << endl; /* 1.235 - lam tron len*/
cout << roundf(va l * 10000) / 10000 << endl; /* 1.2346 - lam tron gan nhat*/
cout << floorf(val * 100) / 100 << endl; /* 1.23 - lam tron xuong*/

//SORT >> sắp xếp mảng
#include <algorithm>
reverse(mangChan, mangChan + mCLen);
sort(mangLe, mangLe + mLLen);		//sắp tăng dần

//CONVERT >> binary to decimal
int binToDec(int bin) {
	int i = 0, remainder;
	double dec = 0;
	while (bin != 0) {
		remainder = bin % 10;
		bin /= 10;
		dec += remainder*pow(2, i);
		++i;
	}
	return int(dec);
}

//CONVERT >> đổi số thập phân sang nhị phân (binary: mode = 2) hoặc bát phân (octal: mode = 8)
int decimalTo(int num, int mode){
	//mảng lưu phần dư và chỉ số
	int mod = -1, amod[100];
	//vòng lặp chia lấy nguyên lưu dư
	while (num > 0)
	{
		mod++;
		amod[mod] = num % mode;
		num /= mode;
	}
	//lặp mảng ngược
	int res = 0;
	while (mod >= 0)
	{
		res = res + amod[mod] * (int)pow(10, mod);
		mod--;
	}
	return res;
}

//CONVERT >> đổi số thập phân sang thập lục phân (hexadecimal)
string hexaDecimal(int num){
	//mảng lưu phần dư và chỉ số
	int mod = -1, amod[100];
	//vòng lặp chia lấy nguyên lưu dư
	while (num > 0)
	{
		mod++;
		amod[mod] = num % 16;
		num /= 16;
	}
	//lặp mảng ngược
	string res, thaplucphan = "0123456789ABCDEF";
	while (mod >= 0)
	{
		res = res + thaplucphan[amod[mod]];
		mod--;
	}
	return res;
}

//CONVERT >> chuỗi thành số ("-123" -> -123)
int toInt(string str) {
	int result = 0, i = 0, am = 1;
	if (str[0] == '-') { i = 1; am = -1; }
	for (; i < str.size(); i++) {
		result = result * 10 + str[i] - 48;
	}
	return result*am;
}

//CHECK >> số nguyên tố?
bool isPrimeNumber(int num) {
	if (num < 2) { return false; }
	int sqrtNum = sqrt(num);
	for (int i = 2; i <= sqrtNum; i++)
	{
		if (num%i == 0) { return false; }
	}
	return true;
}

//CHECK >> số nguyên tố cùng nhau
bool isSNTCungNhau(int a, int b) {
	while ((a != 0) && (b != 0)) {
		if (b>a) { b = b%a; }
		else { a = a%b; }
	}
	if (b == 0) { b = a; }
	if (b == 1) { return true; }
	else { return false; }
}

// TÌM CÁC ƯỚC NGUYÊN TỐ CỦA n
void uocNT(int n)
{
	for (int i = 2, last = 0; i <= abs(n); i++)
	{
		if (n%i == 0)
		{
			if (i != last) {
				cout << i; last = i;
			}
			n /= i--;
		}
	}
}

// TÌM ƯỚC NGUYÊN TỐ LỚN NHẤT CỦA n
int uocNTMax(int n) {
	int i, last;
	for (i = 2, last = 0; i <= abs(n); i++) {
		if (n%i == 0) {
			if (i != last) { last = i; }
			n /= i--;
		}
	}
	return i;
}

//CHECK >> số đẹp? (223 là số đẹp vì 2 + 2 + 3 = 7, số cuối cùng là số 7)
bool isSoDep(int num){
	int tong = 0;
	while (num > 0){
		tong += num % 10;
		num /= 10;
	}
	return tong % 10 == 7;
}

//CHECK >> số chính phương? (là số có căn bậc 2 là một số nguyên)
bool isSquareNumber(int num){
	if (sqrt(num) == floor(sqrt(num))){
		return true;
	}
	return false;
}

//GET >> chiều dài kí tự của một số
int lengthOfInt(int num){
	int length = 1;
	while (num /= 10){ length++; }
	return length;
}

//REVERSE >> đảo ngược số: 1234 => 4321
int reverseInt(int abc) {
	bool check = false;
	if (abc < 0) { abc = abc*-1; check = true; }
	//lấy chiều dài số
	int len = 1;
	int tmp = abc;
	while (tmp /= 10) { len++; }
	//tính toán
	int rev = 0;
	while (abc > 0)
	{
		rev = rev + (abc % 10)*(int)pow(10, len - 1);
		len--;
		abc /= 10;
	}
	if (check) { rev = rev*-1; }
	return rev;
}

//GET >> tổng chữ số: 123 = 1+2+3 = 6
int sum(int n, int s = 0) {
	if (n == 0) { return s; }
	return sum(n / 10, s + n % 10);
}

//GET >> giai thừa cua 1 số
long long factorial(int num){
	long long factorial = 1;
	for (int i = 0; i < num; i++){
		factorial *= (num - i);
	}
	return factorial;
}
long factorial(int n) {
	if (n == 0) return 1;
	return n * factorial(n - 1);
}

//GET >> ước chung lớn nhất của 2 số
int UCLN(long a, long b)
{
	return b == 0 ? a : UCLN(b, a%b);
}

//soChan(1235)=13
int soChan(int num){
	int dem = 0, soChan = 0, dv;
	for (int l = 0; l<lengthOfInt(num); l++){
		dv = (num / (int)pow(10, l)) % 10;
		if (dv % 2 != 0){
			soChan += dv*(int)pow(10, dem); dem++;
		}
	}
	return soChan;
}

//GET >> tổng các ước của một số: num = 6; tong uoc = 2+3
int tongUoc(int num)
{
	int sum = 0;
	for (int i = 1; i <= num; i++){
		if (num%i == 0){
			sum += i;
		}
	}
	return sum;
}

//phuong trinh bac 1
void giaiPTB1(double a, double b){
	if (a == 0){
		if (b == 0){ cout << "VSN"; }
		else{ cout << "VN"; }
	}
	else{ cout << fixed << setprecision(2) << -b / a; }
	/*
	a == 0 ?
	b == 0 ? cout << "VSN" : cout << "VN" :
	cout << fixed << setprecision(2) << -b / a;
	*/
}

//dem so khong tu ben trai: 8050 -> 1
int countZeroFromRight(int num){
	int soMu = 1;
	int mod = 0;
	while (mod == 0){
		mod = num % (int)pow(10, soMu);
		if (mod == 0){
			soMu++;
		}
		else{
			soMu--;
			break;
		}
	}
	return soMu;
}

//số bạn bè (là b khi a chia hết cho b)
bool isDevisorOf(int devidend, int devisor){
	//chia cho float sẽ lấy phần thập phân, chia cho int thì ngc lại
	//nếu a chia hết cho b nghĩa là a/b sẽ ko bị dư phần thập phân nào
	if (devidend / (float)devisor == devidend / devisor){
		return true;
	}
	return false;
}
int sumOfDevisor(int num){
	int sum = 0;
	for (int i = 1; i < num; i++){
		if (isDevisorOf(num, i)){
			sum += i;
		}
	}
	return sum;
}

struct MINMAX {
	int Min, Max;
};

MINMAX findMinMax2xFaster(int arr[], int start, int end) {
	MINMAX  min_max;
	int index;
	int n = end - start + 1;//n: the number of elements to be sorted, assuming n>0
	if (n % 2 != 0) {// if n is odd

		min_max.Min = arr[start];
		min_max.Max = arr[start];

		index = start + 1;
	}
	else {// n is even
		if (arr[start] < arr[start + 1]) {
			min_max.Min = arr[start];
			min_max.Max = arr[start + 1];

			index = start + 2;
		}
	}
	int big, small;
	for (int i = index; i < n - 1; i = i + 2) {
		if (arr[i] < arr[i + 1]) { //one comparison
			small = arr[i];
			big = arr[i + 1];
		}
		else {
			small = arr[i + 1];
			big = arr[i];
		}
		if (min_max.Min > small) { //one comparison
			min_max.Min = small;
		}
		if (min_max.Max < big) { //one comparison
			min_max.Max = big;
		}
	}
	return min_max;
}

//DATE >> trả về số serial của date theo lịch julian, tham khảo http://www.c-jump.com/CIS60/hw3.htm
int serial_julian_date(int Month, int Day, int Year) {
	int a = (14 - Month) / 12;
	int m = Month + 12 * a - 3;
	int y = Year + 4800 - a;
	return Day + (153 * m + 2) / 5 + 365 * y + (y / 4) - (y / 100) + (y / 400) - 32045;
}

//CỘNG SỐ LỚM
int stringToNum(char c)     // chuyen char sang so
{
	return c - '0';
}

char numToString(int n)     // chuyen so sang char
{
	return (char)(n + 48);
}

void chuanHoa(string &a, string &b) // lam 2 xau co do dai bang nhau
{
	int l1 = a.length(), l2 = b.length();
	if (l1 >= l2)
	{
		b.insert(0, l1 - l2, '0');    // chen vao dau cua b cac ky tu '0'
	}
	else
	{
		a.insert(0, l2 - l1, '0');    // chen vao dau cua a cac ky tu '0'
	}
}

string sum(string a, string b)  // tong 2 so
{
	string s = "";
	chuanHoa(a, b);      // chuan hoa
	int l = a.length();

	int temp = 0;
	for (int i = l - 1; i >= 0; i--)   // duyet va cong
	{
		temp = stringToNum(a[i]) + stringToNum(b[i]) + temp;    // tinh tong tung doi mot
		s.insert(0, 1, numToString(temp % 10));         // gan phan don vi vao
		temp = temp / 10;     // lay lai phan hang chuc
	}
	if (temp>0)  // neu hang chuc > 0 thi them vao KQ
	{
		s.insert(0, 1, numToString(temp));
	}
	return s;
}

//NHÂN SỐ LỚN
// nhan so co 1 chu so voi so co nhieu chu so (VD 4 va 7826), lam tuong tu nhu phep cong
string nhanNho(char a, string b)
{
	string s = "";
	int temp = 0;
	for (int i = b.length() - 1; i >= 0; i--)
	{
		temp = stringToNum(a) * stringToNum(b[i]) + temp;
		s.insert(0, 1, numToString(temp % 10));
		temp = temp / 10;
	}

	if (temp>0)
	{
		s.insert(0, 1, numToString(temp));
	}
	return s;
}

string nhan(string a, string b)     // nhan 2 so lon
{
	string s = "";
	int l = a.length();
	string s1[1000];

	for (int i = l - 1; i >= 0; i--)   // nhan tung chu so cua a voi b sau do cong don vao
	{
		s1[i] = nhanNho(a[i], b);   // nhan tung so cua a voi b
		s1[i].insert(s1[i].length(), l - i - 1, '0');
		s = sum(s, s1[i]);  // cong don theo cach cong so lon
	}
	return s;
}

//IS INTEGER
if (x == (int)x)
{
	// Number is integer
}

// QUICK SORT
template <class var>
int partition(var a[], int l, int r) {
	var key = a[r];
	int i = l - 1, j;
	for (j = l; j<r; j++)
		if (a[j] <= key) {
			i++;
			var tmp = a[i]; a[i] = a[j]; a[j] = tmp;
		}
	var tmp = a[i + 1]; a[i + 1] = a[r]; a[r] = tmp;
	return i + 1;
}
template <class var>
void TailRecursiveQuicksort(var a[], int r, int l = 0) {
	r--;
	while (l<r)
	{
		int q = partition(a, l, r);
		if (q < (l + (r - l) / 2)) {
			TailRecursiveQuicksort(a, q - 1, l);
			l = q + 1;
		}
		else {
			TailRecursiveQuicksort(a, r, q + 1);
			r = q - 1;
		}
	}
}