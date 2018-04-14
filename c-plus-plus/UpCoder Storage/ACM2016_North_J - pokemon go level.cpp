#include <iostream>
using namespace std;
int level(int n) {
	int exp[40] = { 0,1,2,3,4,5,6,7,8,9,
		10,10,10,10,15,20,20,20,25,25,
		50,75,100,125,150,190,200,250,300,350,
		500,500,750,1000,1250,1500,2000,2500,3000,5000 };
	int sum = 0;
	for (int i = 0; i < 39; i++) {
		sum = sum + exp[i + 1];
		if (sum * 1000 - n > 0) { return i + 1; }
	}
	return 40;
}
int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int e; cin >> e;
		cout << level(e) << endl;
	}
	system("pause");
	return 0;
}
/*
http://upcoder.xyz/index.php/problems/submit/522/0b9c8876c3e200ee643dceb89f45bac1/Pokemon_Go_level_(ACM_2016_Mi%E1%BB%81n_B%E1%BA%AFc)
*/