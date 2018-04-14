#include <iostream>
#include <string>
#include <fstream>
#define sl 100		//số lượng phần tử tối đa của mảng list trong STACK
using namespace std;

struct STACK{
	int top;
	int list[sl];
};

void initialStack(STACK & stack){
	stack.top = -1;
}

bool isEmptyStack(STACK stack){
	return stack.top == -1;
}

bool isFullStack(STACK stack){
	return stack.top + 1 == sl;
}

void pushStack(STACK & stack, int data){
	stack.top++;
	stack.list[stack.top] = data;
}

void popStack(STACK & stack){
	if (!isEmptyStack(stack)){
		stack.top--;
	}
}

int topStack(STACK stack){
	return stack.list[stack.top];
}

//CONVERT >> chuỗi thành số
int stringToInt(string str){
	int result = 0;
	for (size_t i = 0; i < str.size(); i++){
		result = result * 10 + str[i] - 48;
	}
	return result;
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


int main(){
	ifstream in("hauto.inp");
	string str;
	getline(in, str);
	in.close();
	ofstream out("hauto.out");
	out << tinhHauTo(str);
	out.close();
	return 0;
}
/*
Cho một biểu thức hậu tố với số hạng là các số nguyên dương và ba toán tử +, -, *.
Hãy tính giá trị của biểu thức hậu tố.

Ví dụ: biểu thức hậu tố: 2 3 4 + * 5 - 2 2 * + có giá trị là 13.

Dữ liệu nhập từ tập tin hauto.inp
- Gồm một dòng thể hiện biểu thức hậu tố, mỗi số hạng là một số nguyên dương trong phạm vi từ 1 đến 100.
Giữa hai số hạng, hoặc giữa hai toán tử, hoặc giữa số hạng và toán tử, cách nhau một khoảng trắng.
Chiều dài biểu thức không quá 100 ký tự. Dữ liệu đề bài cho đảm bảo biểu thức hậu tố là hợp lệ.
Trong quá trình tính toán đảm bảo trị tuyệt đối các giá trị trung gian không vượt quá 109.

Dữ liệu xuất ra tập tin hauto.out
- Là giá trị của biểu thức hậu tố.

Lưu ý: dùng hàm gets() hay getline() để đọc chuỗi.
*/