//STRING
bool operator==(string str1, string str2){
	if (str1.compare(str2) == 0)return true;
	return false;
}
bool operator!=(string str1, string str2){
	if (str1.compare(str2) != 0)return true;
	return false;
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
	/*
	b > a		true
	c > abc		true
	abc > ab	true
	ab > ab		false
	*/
}

//PHAN SO
struct PHANSO{ int tu, mau; };
istream& operator>>(istream& is, PHANSO & ps){
	is >> ps.tu >> ps.mau;
	return is;
}
ostream& operator<<(ostream& os, PHANSO  ps){
	os << ps.tu << "/" << ps.mau;
	return os;
}
bool operator==(PHANSO ps1, PHANSO ps2){
	return ps1.tu*ps2.mau == ps1.mau*ps2.tu;
}
bool operator!=(PHANSO ps1, PHANSO ps2){
	//return ps1.tu*ps2.mau != ps1.mau*ps2.tu;
	return !(ps1 == ps2);
}
bool operator>(PHANSO ps1, PHANSO ps2){
	return double(ps1.tu / (double)ps1.mau) > double(ps2.tu / (double)ps2.mau);
}
bool operator<(PHANSO ps1, PHANSO ps2){
	return double(ps1.tu / (double)ps1.mau) < double(ps2.tu / (double)ps2.mau);
}


int UCLN(long a, long b)
{
	return b == 0 ? a : UCLN(b, a%b);
}
PHANSO rutGonPS(PHANSO ps){
	int mauChung = UCLN(ps.tu, ps.mau);
	ps.tu /= mauChung;
	ps.mau /= mauChung;
	return ps;
}
PHANSO operator+(PHANSO ps1, PHANSO ps2){
	PHANSO kq;
	kq.tu = ps1.tu*ps2.mau + ps1.mau*ps2.tu;
	kq.mau = ps1.mau * ps2.mau;
	return kq;
}
PHANSO operator*(PHANSO ps1, PHANSO ps2) {
	ps1.tu *= ps2.tu;
	ps1.mau *= ps2.mau;
	return ps1;
}
//hieu chinh
void Shift(PHANSO num_arr[], int left, int right)
{
	PHANSO  x;
	int curr, joint;
	curr = left; joint = 2 * curr + 1;
	x = num_arr[curr];
	while (joint <= right)
	{
		if (joint < right) //neu co du 2 thanh phan lien doi
		{
			if (num_arr[joint] < num_arr[joint + 1]) {
				joint = joint + 1;
			}
		}
		if (num_arr[joint] < x) //thoa quan he lien doi
		{
			break;
		}
		num_arr[curr] = num_arr[joint];
		curr = joint;
		joint = 2 * curr + 1;
	}
	num_arr[curr] = x;
}
//tao heap
void CreateHeap(PHANSO num_arr[], int right)
{
	int left;
	for (left = (right - 1) / 2; left >= 0; left--)
		Shift(num_arr, left, right - 1);
}
//sap xep tang dan
void HeapSort(PHANSO a[], int N)
{
	int right;
	CreateHeap(a, N);
	right = N - 1;
	while (right > 0)
	{
		PHANSO tmp = a[0];
		a[0] = a[right];
		a[right] = tmp;
		right--;
		Shift(a, 0, right);
	}
}
void xuatMangSo(PHANSO mang[], int mLen){
	for (int i = 0; i < mLen; i++){
		cout << mang[i];
	}
}

//FRACTION ARRAY
struct mangPS{
	int n;
	PHANSO a[50];
	//Phuong thuc khoi tao - Kien thuc mo^n: huong doi tuong
	//Phuong thuc duoc goi tu dong - khi doi tuong duoc tao ra
	mangPS(){ n = 0; }
	PHANSO& operator[](int i){ return a[i]; }
};
istream& operator>>(istream &is, mangPS& m){
	PHANSO ps;

	//m.n=0;
	while (cin >> ps){
		//m.a[m.n++] = ps;
		m[m.n++] = ps;  //Chua co qua tai toan tu gan = ???
	}

	return is;
}
ostream& operator<<(ostream &os, mangPS m){
	for (int i = 0; i < m.n; ++i)
		os << m[i] << endl;
	return os;
}

//SINGLE DIMENSION ARRAY
struct mangMotChieu
{
	int n;
	int a[50];
	int&  operator[](int i)
	{
		return a[i];
	}
};
istream& operator>>(istream& is, mangMotChieu& m)
{
	is >> m.n;
	for (int i = 0; i < m.n; i++)
		is >> m.a[i];
	return is;
}
ostream& operator<<(ostream& os, mangMotChieu m)
{
	for (int i = 0; i < m.n; i++)
		os << m.a[i];
	return os;
}
bool operator ==(mangMotChieu m1, mangMotChieu m2)
{
	if (m1.n != m2.n)
		return false;
	else
	{
		for (int i = 0; i < m1.n; i++)
		{
			if (m1.a[i] != m2.a[i])
				return false;
		}
		return true;
	}
}
bool operator !=(mangMotChieu m1, mangMotChieu m2)
{
	return !(m1 == m2);
}
/*Cong tat ca cac phan tu*/
mangMotChieu operator+(mangMotChieu m1, mangMotChieu m2)
{
	mangMotChieu tongMang;
	if (m1.n > m2.n)
	for (int i = m2.n; i < m1.n; i++)
		m2.a[i] = 0;
	else
	if (m1.n<m2.n)
	for (int i = m1.n; i < m2.n; i++)
		m1.a[i] = 0;
	for (int i = 0; i < m1.n; i++)
		tongMang.a[i] = m1.a[i] + m2.a[i];
	return tongMang;
}
/*cong tu phan tu*/
mangMotChieu operator+(mangMotChieu m1, mangMotChieu m2)
{
	mangMotChieu m;
	if (m1.n < m2.n)
	{
		m.n = m2.n;
		for (int i = 0; i < m1.n; i++)
			m.a[i] = m1.a[i] + m2.a[i];
		for (int i = m1.n; i < m2.n; i++)
			m.a[i] = m2.a[i];
	}
	else
	{
		m.n = m1.n;
		for (int i = 0; i < m2.n; i++)
			m.a[i] = m1.a[i] + m2.a[i];
		for (int i = m2.n; i < m1.n; i++)
			m.a[i] = m1.a[i];
	}
	return m;
}

//HON SO
struct HONSO { int honso;	PHANSO ps; };
istream& operator>>(istream& is, HONSO & hs){
	is >> hs.honso >> hs.ps;
	return is;
}
ostream& operator<<(ostream& os, HONSO hs){
	os << hs.honso << " " << hs.ps.tu << "/" << hs.ps.mau;
	return os;
}
HONSO rutGonHS(HONSO hs){
	//giu nguyen hon so, rut gon phan so
	hs.ps = rutGonPS(hs.ps);
	return hs;
}
HONSO rutGonHS2(HONSO hs){
	HONSO hs_toi_gian;
	hs_toi_gian.honso = hs.honso + hs.ps.tu / hs.ps.mau;
	hs_toi_gian.ps.tu = hs.ps.tu % hs.ps.mau;
	hs_toi_gian.ps.mau = hs.ps.mau;
	hs_toi_gian.ps = rutGonPS(hs_toi_gian.ps);
	return hs_toi_gian;
}
bool operator!=(HONSO hs1, HONSO hs2){
	//theo yeu cau: 2 hỗn số khác nhau khi có thành phần tương ứng của chúng khác nhau
	return hs1.honso != hs2.honso && hs1.ps != hs2.ps;
}
int tongThanhPhan(HONSO hs){
	return hs.honso + hs.ps.tu + hs.ps.mau;
}
bool operator>(HONSO hs1, HONSO hs2){
	return tongThanhPhan(hs1) > tongThanhPhan(hs2);
}