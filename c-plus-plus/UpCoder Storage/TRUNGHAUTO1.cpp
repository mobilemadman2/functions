#include <iostream>
#include <string>
using namespace std;
#define sl 100
struct STACK{
	int top;
	char list[sl];
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
	return stack.top + 1 == sl;
}

//INSERT >> thêm phần tử vào stack vj trí top
void pushStack(STACK & stack, char data){
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
char topStack(STACK stack){
	return stack.list[stack.top];
}

//GET >> độ ưu tiên của các toán tử * / + -
int getPriority(char toan_tu){
	switch (toan_tu)
	{
	case '*':return 4;
	case '/':return 3;
	case '+':return 2;
	case '-':return 1;
	default: return 0;
	}
}

//CONVERT >> chuyển trung tố sang hậu tố
string trungToSangHauTo(string trungto){
	string hau_to;
	STACK toan_tu;
	initialStack(toan_tu);
	for (size_t i = 0; i < trungto.size(); i++){
		if (int(trungto[i]) >= 48 && int(trungto[i]) <= 57){
			hau_to += trungto[i];
		}
		else{
			if (trungto[i] == '*' || trungto[i] == '/' || trungto[i] == '+' || trungto[i] == '-'){
				if (isEmptyStack(toan_tu))
				{
					pushStack(toan_tu, trungto[i]);
				}
				else{
					if (getPriority(topStack(toan_tu)) <= getPriority(trungto[i])){
						pushStack(toan_tu, trungto[i]);
					}
					if (getPriority(topStack(toan_tu)) > getPriority(trungto[i])){
						hau_to += topStack(toan_tu);
						popStack(toan_tu);
						pushStack(toan_tu, trungto[i]);
					}
				}
			}
			else{
				if (trungto[i] == '('){
					pushStack(toan_tu, trungto[i]);

				}
				if (trungto[i] == ')'){
					while (topStack(toan_tu) != '('){
						hau_to += topStack(toan_tu);
						popStack(toan_tu);
					}
					popStack(toan_tu);
				}
			}
		}
	}
	while (!isEmptyStack(toan_tu)){
		hau_to += topStack(toan_tu);
		popStack(toan_tu);
	}
	return hau_to;
}
int main()
{
	string s = "3+4*2/(1-5)";
	cout << trungToSangHauTo(s);

	system("pause");
	return 0;
}
/*
Nhập vào 1 biêu thức trung tố, yêu cầu xuất biểu thức theo dạng hậu tố.

(Các số hạng là số có 1 chữ số)

Ví dụ:
input
3+4*2/(1-5)
output
3 4 2 * 1 5 – / +
*/