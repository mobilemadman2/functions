#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct NODE{
	char data;
};

struct STACK{
	int top;
	int n = 100;
	NODE list[100];
};

void initialStack(STACK & stack){
	stack.top = -1;
}

bool isEmptyStack(STACK stack){
	return stack.top == -1;
}

bool isFullStack(STACK stack){
	return stack.top + 1 == stack.n;
}

void pushStack(STACK & stack, NODE data){
	stack.top++;
	stack.list[stack.top] = data;
	
}

void popStack(STACK & stack){
	if (!isEmptyStack(stack)){
		stack.top--;
	}
}

NODE topStack(STACK stack){
	return stack.list[stack.top];
}

int main(){
	STACK stack;
	initialStack(stack);

	string str;
	ifstream in("stacki.txt");
	in >> str;
	in.close();

	ofstream out("stacko.txt");
	for (int i = 0; i < str.size(); i++){
		if (str[i] == '*'){
			out << topStack(stack).data;
			popStack(stack);
		}
		else{
			NODE tmp;
			tmp.data = str[i];
			pushStack(stack, tmp);
		}
	}
	out.close();

	system("pause");
	return 0;
}
/*
Xuất nội dung của stack sau mỗi thao tác trong dãy.
Một chữ cái tượng trưng cho thao tác thêm chữ cái đó vào trong stack, 
dấu * tượng trưng cho thao tác lấy nội dung một phần tử trong stack in lên màn hình.
Cho biết kết quả xuất ra màn hình sau khi hoàn tất chuỗi input.

input từ file stack.inp
dữ liệu ra file stack.out

Ví dụ:
input:
AB*

ouput:
B
*/