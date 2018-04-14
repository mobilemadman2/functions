#include <iostream>
#define nn 100	//so luong trong list of stack
using namespace std;

struct STACK{
	int top;
	int list[100];	//nn
};

void initialStack(STACK & stack){
	stack.top = -1;
}

bool isEmptyStack(STACK stack){
	return stack.top == -1;
}

bool isFullStack(STACK stack){
	return stack.top + 1 == nn;
}

//them phan tu vao stack
void pushStack(STACK & stack, int data){
	stack.top++;
	stack.list[stack.top] = data;
}

//giam phan tu trong stack
void popStack(STACK & stack){
	if (!isEmptyStack(stack)){
		stack.top--;
	}
}

//lay top
int topStack(STACK stack){
	return stack.list[stack.top];
}

void coso10sang2(STACK s, int n)
{
	int r;
	while (n > 0)
	{
		r = n % 2;
		pushStack(s, r);
		n = n / 2;
	}
	while (!isEmptyStack(s)){
		cout << topStack(s);
		popStack(s);
	}
}

int main(){
	STACK stack;
	initialStack(stack);
	int num; cin >> num;
	coso10sang2(stack, num);

	return 0;
}
/*
Nhập vào 1 số nguyên ở hệ 10, yêu cầu xuất ra 1 số ở hệ 2

vi dụ:
input:
10

output:
1010
*/