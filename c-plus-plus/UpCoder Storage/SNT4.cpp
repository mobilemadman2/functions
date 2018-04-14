#include <iostream>
#include <cmath>

using namespace std;

bool isSNT(int num){
	if (num < 2) return false;
	else
	for (int i = 2; i <= sqrt(num); i++){
		if (num%i == 0) return false;
	}
	return true;
}

int main(){
	int n;
	cin >> n;
	isSNT(n) ? cout << n : cout << 0;
	system("pause");
	return 0;
}