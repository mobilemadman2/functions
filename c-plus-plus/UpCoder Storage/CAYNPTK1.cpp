#include <iostream>
using namespace std;
struct NODE
{
	int data;
	NODE * left;
	NODE * right;
};
typedef struct NODE * TREE;

void khoiTaoTree(TREE &cay){
	cay = NULL;
}

void insertNodeToTree(TREE &cay, int data){
	if (cay != NULL){
		if (cay->data == data){ return; }
		if (data > cay->data){
			insertNodeToTree(cay->right, data);
		}
		else {
			insertNodeToTree(cay->left, data);
		}
	}
	else{
		cay = new NODE;
		cay->data = data;
		cay->left = NULL;
		cay->right = NULL;
	}
}

void duyetLRN(TREE root){
	if (root != NULL)
	{
		duyetLRN(root->left);

		duyetLRN(root->right);
		cout << root->data << " ";
	}
}

int main(){
	TREE cay;
	khoiTaoTree(cay);
	int data;
	while (cin >> data){
		insertNodeToTree(cay, data);
	}
	duyetLRN(cay);

	return 0;
}
/*
Cho trước N số nguyên, yêu cầu xây dựng cây nhị phân tìm kiếm với N số nguyên đó.
Xuất kết quả duyệt theo thứ tự sau (Postorder)của cây được xây dựng ở trên.

Input:
Gồm N số nguyên, mỗi số cách 1 nhau 1 khoảng trắng.
Ouput:
Thứ tự duyệt theo thứ tự sau

Ví dụ:

input
1 6 3 2
output
2 3 6 1
*/