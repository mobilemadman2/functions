#include <iostream>
#define max 100		//số lượng phần tử tối đa của mảng list trong STACK
using namespace std;

struct STACK{
	int top;
	int list[max];
};

//INITIAL >> khởi tạo stack rỗng
void initialStack(STACK & stack){
	stack.top = -1;
}

//CHECK >> stack rỗng?
bool isEmptyStack(STACK stack){
	return stack.top == -1;
}

//CHECK >> stack đầy?
bool isFullStack(STACK stack){
	return stack.top + 1 == max;
}

//INSERT >> thêm phần tử vào stack vj trí top
void pushStack(STACK & stack, int data){
	stack.top++;
	stack.list[stack.top] = data;
}

//DELETE >> giảm đi 1 phần tử trong stack vị trí top
void popStack(STACK & stack){
	if (!isEmptyStack(stack)){
		stack.top--;
	}
}

//RETURN >> giá trị top trong stack
int topStack(STACK stack){
	return stack.list[stack.top];
}

//CONVERT >> đổi cơ số 10 sang 2
void getBinaryToStack(STACK &stack, int num){
	while (num != 0)
	{
		//push phần dư vào stack
		pushStack(stack, num % 2);
		num /= 2;
	}
}

//COUT >> xuất stack từ top trở xuống hoặc từ bot trở lên
void coutStack(STACK stack, string mode){
	if (mode == "fromtop"){
		for (int i = stack.top; i > -1; i--){
			cout << stack.list[i].data;
		}
	}
	else if (mode == "frombot"){
		for (int i = 0; i <= stack.top; i++){
			cout << stack.list[i].data;
		}
	}
	cout << endl;
}

//CALCULATE >> tính biểu thức hậu tố
int tinhHauTo(string str){
	STACK stack;
	initialStack(stack);
	//a và b là 2 toán hạng
	int a, b;
	//lặp chuỗi
	for (int i = 0; i < str.size(); i++)
	{
		switch (str[i])
		{
		case '+':
			a = topStack(stack);
			popStack(stack);
			b = topStack(stack);
			popStack(stack);
			pushStack(stack, a + b);
			break;
		case '-':
			a = topStack(stack);
			popStack(stack);
			b = topStack(stack);
			popStack(stack);
			pushStack(stack, b - a);
			break;
		case '*':
			a = topStack(stack);
			popStack(stack);
			b = topStack(stack);
			popStack(stack);
			pushStack(stack, a * b);
			break;
		case ' ':break;
		default:
			string num;
			//lặp đến khi gặp space
			while (str[i] != ' ')
			{
				num += str[i];
				i++;
			}
			pushStack(stack, stringToInt(num));
			num.clear();
			break;
		}
	}
	return topStack(stack);
}

//CHECK >> dữ liệu đã có trong stack hay chưa?
bool isExistInStack(string data, stack <string> st) {
	while (!st.empty())
	{
		if (st.top() == data) {
			return true;
		}
		st.pop();
	}
	return false;
}