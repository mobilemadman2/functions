#include <iostream>
#include <string>
using namespace std;

int main(){
	string str;
	getline(cin, str);
	string arStr[20];
	int i = 0, j = 0;
	for (; i < str.length(); i++){
		arStr[i] = "";
		for (; j < str.length(); j++){
			if (str[j] == ' '){
				j++; break;
			}
			arStr[i] += str[j];
		}
	}
	for (; i>=0; i--){
		cout << arStr[i];
	}
	//system("pause");
	return 0;
}
/*
input:
I am a student

output:
student a am I
*/