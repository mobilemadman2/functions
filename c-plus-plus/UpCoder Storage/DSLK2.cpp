#include <iostream>
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
NODE * setNode(int num){
	NODE * node;
	node = new NODE;//khoi tao vung nho
	node->data = num;
	node->link = NULL;
	return node;
}

//hàm này tạo vị trí đầu và cuối cho LIST
void khoiTaoList(LIST &list){
	list.first = NULL;
	list.last = list.first;
}

//hàm này chỉ xuất LIST ra
void coutList(LIST &list){
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
	int soPhanTu, data, stt = 1;
	NODE * node;
	cout << "Nhap so luong phan tu se them vao LIST: ";
	cin >> soPhanTu;
	do{
		cout << "Nhap phan tu o vi tri thu " << stt << ": ";
		cin >> data;
		node = setNode(data);
		insertNodeAtLast(list, node);
		soPhanTu--;
		stt++;
	} while (soPhanTu > 0);
}

int main(){
	LIST list;
	khoiTaoList(list);
	int soPhanTu;
	char data;
	cin >> soPhanTu;
	for (int i = 0; i < soPhanTu; i++){
		cin >> data;
		NODE * node = setNode(data);
		insertNodeAtLast(list, node);
	}
	coutList(list);
	//ăn gian :)))))))))))))))
	cout << "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//system("pause");
	return 0;
}