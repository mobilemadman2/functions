.﻿#include <iostream>
#include <cstdlib>
using namespace std;

//tao struct
struct NODE{
	char data;
	NODE * link;
};

//tao LIST
struct LIST
{
	NODE * first;
	NODE * last;
};

//hàm này nhận 1 giá trị int và tạo thành NODE
NODE * setNode(char data){
	NODE * node;
	node = new NODE;//khoi tao vung nho
	node->data = data;
	node->link = NULL;
	return node;
}

//hàm này tạo vị trí đầu và cuối cho LIST
void khoiTaoList(LIST &list){
	list.first = NULL;
	list.last = list.first;
}

//xuất LIST
void coutList(LIST & list){
	//tao mot node de luu gia tri dau tien
	NODE * node = list.first;
	//neu gia tri do khac null thi cout
	while (node != NULL){
		cout << node->data << " ";
		node = node->link;
	}
	cout << endl;
}

//thêm NODE vào vị trí cuối của LIST
void insertNodeAtLast(LIST &list, NODE * node){
	//nếu LIST rỗng thì first và last đều bằng NODE
	if (list.first == NULL){
		list.first = node;
		list.last = list.first;
	}
	//nếu LIST đã có last NODE, thì last NODE sẽ lưu vị trí của node mới thêm
	//node mới thêm sẽ thành last NODE mới
	else{
		list.last->link = node;
		list.last = node;
	}
}

//thêm một số NODE xác định vào cuối LIST
void cinToListAtLast(LIST & list){
	char data, before;
	while (cin >> data)
	{
		NODE * node;
		//nếu LIST rỗng thì lưu NODE đầu tiên, node before để so sánh = data
		if (list.first == NULL){
			node = setNode(data);
			insertNodeAtLast(list, node);
			before = data;
		}
		//khi LIST đã có node
		else {
			//nếu mã acsii của data > before thì lưu vào LIST
			if (int(data) > int(before)){
				node = setNode(data);
				insertNodeAtLast(list, node);
				//before biến thành node vừa lưu
				before = data;
			}
		}
	}
}

int main(){
	LIST list;
	khoiTaoList(list);
	cinToListAtLast(list);
	coutList(list);
	system("pause");
	return 0;
}
/*
Cho một DSLK đơn. Mỗi phần tử info là một ký tự ('A'..'Z') và liên kết chỉ đến phần tử kế.
- Tạo một danh sách liên kết đơn, chứa các ký tự đầu vào
- Viết chương trình loại khỏi danh sách đã cho các phần tử vi phạm điều kiện tăng dần của danh sách.
Biết rằng phần tử đầu tiên được giữ lại trong danh sách. (không có phần tử trùng nhau).

DDDữ liệu đầu vào: chứa 1 dãy ký tự, mỗi ký tự cách nhau 1 khoảng trắng

Dữ liệu đầu ra: chứa 1 dòng gồm các phần tử của danh sách thỏa điều kiện (mỗi ký tự cách nhau 1 khoảng trắng)

Ví dụ:

Input:

D F H G K M A B Q

Output:

D F H K M Q


(BÀI NÀY YÊU CẦU PHẢI DÙNG CON TRỎ - KHÔNG DÙNG MẢNG ĐỘNG)
*/