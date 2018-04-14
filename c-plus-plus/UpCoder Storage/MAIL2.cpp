#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    while(cin>>s){
        if(cin.get()=='\n'){
            cout << s << ",";
        }
    }
    cout << s << ".";
    return 0;
}