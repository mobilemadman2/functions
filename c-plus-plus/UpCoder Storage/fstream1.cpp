#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(){
	int a, b;
	ifstream in;
	in.open("input.txt");
	in >> a >> b;
	in.close();
	cout << a + b;
	system("pause");
	return 0;
}