#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

bool isSNT(int num){
	if (num < 2) return false;
	for (int i = 2; i < sqrt(num); i++){
		if (num%i == 0) return false;
	}
	return true;
}

int isSNTLessThanK(int n,int k){
	if (isSNT(n) && n < k) return n;
	else return -1;
}

int main(){
	int k;
	int arr[100];
	ifstream in("input.txt");

	in >> k;
	int i = 0;
	while (!(in.eof()))
	{
		in >> arr[i]; i++;
	}
	int max = -1;
	for (int j = 0; j < i-1; j++){
		if (isSNTLessThanK(arr[j], k) > max)
		max = arr[j];
	}
	ofstream out("output.txt");
	out << max;
	in.close(); out.close();

	system("pause");
	return 0;
}