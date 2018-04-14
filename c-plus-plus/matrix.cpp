/*
ham rank co van de (sample: c3b9b)
PROGRAM: M.A.T.R.I.X
Coder: BMP
Version: beta-6
Log: thêm "độc lập & phụ thuộc tuyến tính", "bộ phận đltt tối đại"
Main function:
1. Các phép toán trên ma trận.
2. Tính định thức ma trận vuông cấp n.
3. Tính hạng (liệt kê từng bước rút gọn theo dòng từng bậc).
4. Ma trận đảo.
5. Giải hệ phương trình.
6. Độc lập & phụ thuộc tuyến tính.
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* ------------------------------------------------------------------------- KHAI BAO ----------------------------------- */
struct matrix {
	int m, n;
	double val[20][20];
};
// CIN >> nhập số dòng m cột n và m*n phần tử
istream& operator >> (istream& is, matrix & mat) {
	cout << "Nhap so dong va so cot: ";
	cin >> mat.m >> mat.n;
	cout << "Nhap " << mat.n << " phan tu tren " << mat.m << " dong." << endl;
	for (int i = 1; i <= mat.m; i++) {
		for (int j = 1; j <= mat.n; j++) {
			is >> mat.val[i][j];
		}
	}
	cout << endl;
	return is;
}
// COUT << xuất m dòng n cột của ma trận
ostream& operator << (ostream& os, matrix  mat) {
	for (int i = 1; i <= mat.m; i++) {
		for (int j = 1; j <= mat.n; j++) {
			os << mat.val[i][j] << " ";
		}
		os << endl;
	}
	cout << endl;
	return os;
}

/* ---------------------------------------------------------------------- PHEP TINH CO BAN ------------------------------ */
// CAL >> cộng 2 ma trận
matrix operator + (matrix a, matrix b) {
	matrix c;
	c.m = a.m;
	c.n = a.n;
	for (int i = 1; i <= a.m; i++) {
		for (int j = 1; j <= a.n; j++) {
			c.val[i][j] = a.val[i][j] + b.val[i][j];
		}
	}
	return c;
}
// CAL >> nhân 1 số nguyên với ma trận
matrix operator * (double num, matrix a) {
	for (int i = 1; i <= a.m; i++) {
		for (int j = 1; j <= a.n; j++) {
			a.val[i][j] *= num;
		}
	}
	return a;
}
// CAL >> nhân 2 ma trận
matrix operator * (matrix a, matrix b) {
	matrix c;
	c.m = 1; c.n = 1; c.val[0][0] = 0;
	if (a.n == b.m) {
		c.m = a.m;
		c.n = b.n;
		for (int i = 1; i <= c.m; i++) {
			for (int j = 1; j <= c.n; j++) {
				c.val[i][j] = 0;
				for (int z = 1; z <= a.n; z++) {
					c.val[i][j] += a.val[i][z] * b.val[z][j];
				}
			}
		}
		return c;
	}
	else { cout << "2 Ma tran khong thoa dieu kien de nhan!" << endl; }
	return c;
}

/* ---------------------------------------------------------------------------- DINH THUC -------------------------------- */
// CAL >> định thức của ma trận vuông cấp 3
double det3(matrix a) {
	double kq = 0;
	if (a.m == a.n) {
		kq = a.val[1][1] * a.val[2][2] * a.val[3][3]
			+ a.val[1][2] * a.val[2][3] * a.val[3][1]
			+ a.val[1][3] * a.val[2][1] * a.val[3][2]
			- a.val[1][1] * a.val[2][3] * a.val[3][2]
			- a.val[1][3] * a.val[2][2] * a.val[3][1]
			- a.val[1][2] * a.val[2][1] * a.val[3][3];
	}
	else { cout << "Ma tran vuong moi tinh duoc dinh thuc!" << endl; }
	return kq;
}
// FILTER >> biến ma trận A thành ma trận Aij (bỏ dòng i cột j)
matrix matrixFilter(matrix a, int dong, int cot) {
	matrix b; b.m = a.m - 1; b.n = b.m;
	int am = 1, an;
	for (int bm = 1; bm <= b.m; bm++) {
		if (am == dong) { am++; }
		an = 1;
		for (int bn = 1; bn <= b.n; bn++) {
			if (an == cot) { an++; }
			b.val[bm][bn] = a.val[am][an]; an++;
		}
		am++;
	}
	return b;
}
// CAL >> định thức của ma trận vuông cấp n
double det(matrix a, double sum = 0) {
	if (a.m == 2) {
		return a.val[1][1] * a.val[2][2] - a.val[2][1] * a.val[1][2];
	}
	if (a.m == 3) {
		return det3(a);
	}
	else {
		for (int iter = 1; iter <= a.m; iter++) {
			sum = sum + a.val[iter][1] * pow(-1, iter + 1)*det(matrixFilter(a, iter, 1), sum);
		}
	}
	return sum;
}

/* --------------------------------------------------------------------- HANG MA TRAN (RUT GON) --------------------------- */
// FILTER >> đổi chỗ 2 dòng của ma trận
void swapRow(matrix& a, int i, int j, bool print = false) {
	if (i != j) {
		if (i > a.m || j > a.m) { cout << "So dong khong phu hop." << endl; }
		else {
			if (print) { cout << "Doi cho dong " << i << " voi dong " << j << ":" << endl; }
			for (int n = 1; n <= a.n; n++) {
				double tmp = a.val[i][n];
				a.val[i][n] = a.val[j][n];
				a.val[j][n] = tmp;
			}
			if (print)cout << a;
		}
	}
}
// CAL >> rút gọn ma trận theo dòng từng bậc
matrix rutGonTheoDongTungBac(matrix a, bool print = false, int dong = 1, int cot = 1) {
	if (dong > a.m || cot > a.n) {
		return a;
	}
	// tim dong tren cung (a11 = 1 hoac khac 0)
	if (a.val[dong][cot] != 1) {
		int min = dong;
		for (int i = min + 1; i <= a.m; i++) {
			if (a.val[i][cot] == 1 || a.val[i][cot] != 0) {
				min = i;
			}
		}
		swapRow(a, dong, min, print);
	}
	// chuyen dong = 0 xuong duoi cung
	int cache = a.m; bool cacheHasVal = false;
	for (int i = a.m; i > dong; i--) {
		if (a.val[i][cot] == 0 && cacheHasVal) {
			swapRow(a, i, cache, print); i = cache; cacheHasVal = false;
		}
		else if (a.val[i][cot] != 0 && !cacheHasVal) {
			cache = i; cacheHasVal = true;
		}
	}
	// bat dau kiem tra tu dong thu 2
	for (int i = dong + 1; i <= cache; i++) {
		if (a.val[i][cot] != 0) {
			double x = (-1 * a.val[i][cot]) / a.val[dong][cot];
			if (print) {
				cout << "Cong vao dong " << i << " dong " << dong << " nhan voi " << (-1 * a.val[i][cot]) << "/" << a.val[dong][cot] << " = " << x << endl;
			}
			for (int j = cot; j <= a.n; j++) {
				a.val[i][j] += a.val[dong][j] * x;
			}
			if (print) { cout << a; }
		}
	}
	return rutGonTheoDongTungBac(a, print, dong + 1, cot + 1);
}
// CAL >> tính hạng của ma trận
int rg(matrix a) {
	int rank = a.m;
	a = rutGonTheoDongTungBac(a);
	for (int i = a.m; i > 0; i--) {
		for (int j = a.n; j > 0; j--) {
			if (a.val[i][j] != 0) { return rank; }
		}
		rank--;
	}
	return 0;
}

/* -------------------------------------------------------------------------- MA TRAN NGHICH DAO ------------------------- */
// FILTER >> ma trận đơn vị
matrix mtDonVi(matrix a) {
	matrix b; b.m = a.m; b.n = a.n;
	for (int i = 1; i <= b.m; i++) {
		for (int j = 1; j <= b.n; j++) {
			b.val[i][j] = pow(-1, i + j)*det(matrixFilter(a, i, j));
		}
	}
	return b;
}
// FILTER >> biến đổi thành ma trận chuyển vị a^T (dòng thành cột)
matrix mtChuyenVi(matrix a) {
	matrix b; int am = 1, an = 1;
	for (b.n = 1; b.n <= a.m; b.n++) {
		an = 1;
		for (b.m = 1; b.m <= a.n; b.m++) {
			b.val[b.m][b.n] = a.val[am][an]; an++;
		}
		am++;
	}
	b.n--; b.m--;
	return b;
}
// CAL >> ma trận nghịch đảo
void mtDao(matrix a) {
	double d = det(a);
	if (a.m != a.n) {
		cout << "Chi co ma tran VUONG moi co ma tran dao!" << endl;
	}
	else if (d == 0) {
		cout << "Vi det(A) = 0 => Ma tran khong kha dao." << endl;
	}
	else {
		cout << "det(A) = " << d << endl;
		cout << "Ma tran dao se bang 1/" << d << " nhan voi ma tran:" << endl;
		cout << mtChuyenVi(mtDonVi(a));
		cout << "Hoac bang: " << endl << (1 / d)*mtChuyenVi(mtDonVi(a));
	}
}

/* ---------------------------------------------------------------------- HE PHUONG TRINH TUYEN TINH ----------------------- */
// FILTER >> tách hpt ban đầu thành ma trận hệ số
matrix tachMatrix(matrix a, string mode) {
	matrix heso, b;
	heso.m = a.m; heso.n = a.n - 1;
	b.m = a.m; b.n = 1;
	for (int i = 1; i <= a.m; i++) {
		for (int j = 1; j <= a.n; j++) {
			if (j <= a.n - 1) {
				heso.val[i][j] = a.val[i][j];
			}
			else {
				b.val[i][1] = a.val[i][j];
			}
		}
	}
	if (mode == "heso") { return heso; }
	else { return b; }
}
// FILTER >> cột j trong ma trận a = cột b (last col). Trả về ma trận hệ số của a sau khi gán.
matrix swapCramerDi(matrix a, int j) {
	for (int i = 1; i <= a.m; i++) {
		a.val[i][j] = a.val[i][a.n];
	}
	return tachMatrix(a, "heso");
}
// CAL >> giải hệ phương trình tuyến tính theo phương pháp Cramer hoặc Gauss.
void giaiHePTTT(matrix a, bool noCramer = false, bool print = false) {
	// neu la he cramer
	if (a.m == a.n - 1 && !noCramer) {
		matrix heso = tachMatrix(a, "heso");
		cout << "Day la he phuong trinh Cramer. Ma tran he so A la:" << endl << heso;
		double d = det(heso);
		if (d != 0) {
			// co nghiem duy nhat
			cout << "Vi det(A) = " << d << " khac 0 => He phuong trinh co " << a.n - 1 << " nghiem duy nhat la: " << endl;
			for (int i = 1; i < a.n; i++) {
				double di = det(swapCramerDi(a, i));
				cout << "x" << i << " = " << di << "/" << d << " = " << di / d << endl;
			}
		}
		else if (d == 0) {
			int countDetZero = 0;
			for (int i = 1; i < a.n; i++) {
				double di = det(swapCramerDi(a, i));
				if (di == 0) { countDetZero++; }
				else { break; }
			}
			if (countDetZero == a.n - 1) {
				cout << "Vi det(A) = 0 va tat ca cac Di deu = 0 => He phuong trinh VO NGHIEM hoac co VO SO NGHIEM." << endl;
			}
			else {
				cout << "Vi det(A) = 0 va Di thu " << countDetZero + 1 << " khac 0 => He phuong trinh VO NGHIEM." << endl;
			}
		}
	}
	else {
		// dung thuat toan GAUSS: bien doi ma tran bo sung thanh ma tran bac thang
		cout << "Su dung thuat toan Gauss. Ta rut gon ma tran theo dong tung bac:" << endl;
		a = rutGonTheoDongTungBac(a, true);
		cout << "Sau khi rut gon, ta co he phuong trinh sau:" << endl;
		for (int i = 1; i <= a.m; i++) {
			for (int j = 1; j <= a.n; j++) {
				int c = 0;	// dem so x = 0
				if (j < a.n) {
					if (a.val[i][j] != 0) {
						string last = " + ";
						if (j == a.n - 1) { last = ""; }
						cout << a.val[i][j] << char(j + 96) << last;
					}
					else { cout << "     "; c++; }
				}
				else {
					if (c != a.n - 1) cout << " = " << a.val[i][j] << endl;
				}
			}
		}
	}
}

/* ---------------------------------------------------------------------- DOC LAP & PHU THUOC TUYEN TINH ------------------------------- */
void docLapPhuThuoc() {
	int soVector, soPhanTu;
	cout << "Nhap so vector & so luong phan tu trong moi vector: ";
	cin >> soVector >> soPhanTu;

	matrix a; a.m = soVector; a.n = soPhanTu + 1;
	for (int i = 1; i <= a.m; i++) {
		cout << "Nhap vector thu " << i << endl;
		for (int j = 1; j < a.n; j++) {
			cin >> a.val[i][j];
		}
		a.val[i][a.n] = 0;
	}
	cout << "Ma tran thu duoc la:" << endl << a;
	cout << "Rut gon theo dong tung bac:" << endl;
	giaiHePTTT(a, true);
	int rank = rg(a);
	cout << endl << "Ho ";
	for (int i = 1; i <= soPhanTu; i++) {
		string s = ", ";
		if (i == soPhanTu - 1) { s = " "; }
		cout << "x" << i << s;
	}
	if (rank == soPhanTu) {
		cout << "= 0 => DOC LAP TUYEN TINH." << endl;
	}
	else { cout << "PHU THUOC TUYEN TINH." << endl; }
}
void docLapToiDai() {
	int soVector, soPhanTu;
	cout << "Nhap so vector & so luong phan tu trong moi vector: ";
	cin >> soVector >> soPhanTu;

	matrix a; a.m = soPhanTu; a.n = soVector;
	for (int j = 1; j <= a.n; j++) {
		cout << "Nhap vector thu " << j << endl;
		for (int i = 1; i <= a.m; i++) {
			cin >> a.val[i][j];
		}
	}
	cout << "Ma tran thu duoc la:" << endl << a;
	cout << "Rut gon theo dong tung bac:" << endl;
	a = rutGonTheoDongTungBac(a, true);
	int rank = rg(a);
	cout << "rank{ ";
	for (int i = 1; i <= soPhanTu; i++) {
		string s = ", ";
		if (i == soPhanTu) { s = " } = "; }
		cout << "x" << i << s;
	}
	cout << rank << endl;
	cout << "Day 1 mot trong so cac bo phan doc lap tuyen tinh toi dai tim duoc:" << endl;
	for (int i = 1; i <= rank; i++) {
		for (int j = 1; j <= rank; j++) {
			cout << a.val[i][j] << " ";
		}
		cout << endl;
	}
}
/* ------------------------------------------------------------------------ GIAO DIEN DIEU KHIEN --------------------------- */
void welcomeScreen() {
	string cmd[20] = {
		"Chon stt de thuc hien cac lenh sau:",
		"Nhan 2 ma tran.",
		"Nhan 1 so nguyen voi ma tran.",
		"Cong 2 ma tran.",
		"Dinh thuc ma tran vuong cap n.",
		"Ma tran dao.",
		"Hang ma tran (bao gom cac buoc rut gon).",
		"Giai he phuong trinh tuyen tinh.",
		"Doc lap tuyen tinh - Phu thuoc tuyen tinh",
		"Bo phan doc lap tuyen tinh toi dai",
		"Xoa man hinh.",
		"Thoat chuong trinh."
	};
	cout << "----------------- M.A.T.R.I.X [ver-beta-6] [by-BMP] ----------------" << endl << cmd[0] << endl;
	for (int i = 1; i < 12; i++) {
		cout << i << ". " << cmd[i] << endl;
	}
}
void runCommand(int num) {
	matrix a, b; int c;
	switch (num) {
	case 1:
		cout << "------------- Nhan 2 ma tran -----------" << endl;
		cin >> a >> b;
		cout << a*b; break;
	case 2:
		cout << "----- Nhan 1 so nguyen voi ma tran -----" << endl;
		cout << "Nhap so nguyen: "; cin >> c;
		cin >> a;
		cout << c*a; break;
	case 3:
		cout << "------------- Cong 2 ma tran -----------" << endl;
		cin >> a >> b;
		cout << a + b; break;
	case 4:
		cout << "-- Tinh dinh thuc ma tran vuong cap n --" << endl;
		cin >> a;
		while (a.m != a.n) {
			cout << "Ban phai nhap mot ma tran VUONG!" << endl;
			cin >> a;
		}
		cout << "det(A) = " << det(a) << endl; break;
	case 5:
		cout << "-------------- Ma tran dao -------------" << endl;
		cin >> a;
		mtDao(a); break;
	case 6:
		cout << "--------- Tinh hang cua ma tran --------" << endl;
		cin >> a;
		cout << "rank(A) = " << rg(rutGonTheoDongTungBac(a, true)) << endl;; break;
	case 7:
		cout << "---- Giai he phuong trinh tuyen tinh ---" << endl;
		cout << "Hay nhap cac he so cua HPT tuong tu nhu nhap ma tran." << endl;
		cin >> a;
		giaiHePTTT(a, false, true); break;
	case 8:
		cout << "---- Doc lap & Phu thuoc tuyen tinh ---" << endl;
		docLapPhuThuoc(); break;
	case 9:
		cout << "-- Bo phan doc lap tuyen tinh toi dai --" << endl;
		docLapToiDai(); break;
	case 10:
		system("cls"); break;
	}
}
int toInt(string str) {
	int result = 0, i = 0, am = 1;
	if (str[0] == '-') { i = 1; am = -1; }
	for (; i < str.length(); i++) {
		result = result * 10 + str[i] - 48;
	}
	return result*am;
}
void run() {
	bool loop = true;
	while (true) {
		if (!loop) {
			cout << endl << "<<< SAI KIEU DU LIEU - HAY KHOI DONG LAI UNG DUNG >>>" << endl << endl;
			system("pause"); break;
		}
		else {
			welcomeScreen();
			string num; cin >> num;
			int n = toInt(num), l = 0;
			while (n > 11 || n < 1) {
				cout << "Lenh [" + num + "] khong ton tai trong chuong trinh. Moi chon lai: " << endl;
				cin >> num;
				l++;
				if (l > 1) { loop = false; break; }
			}
			if (n == 11) { break; }
			runCommand(toInt(num));
		}
	}
}

int main() {
	run();
	return 0;
}