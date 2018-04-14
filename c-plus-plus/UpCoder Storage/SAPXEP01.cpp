#include <iostream>
using namespace std;

//tạo struct NODE
struct NODE {
	int data;
	NODE * link;
};

//tạo struct LIST
struct LIST
{
	NODE * first;
	NODE * last;
};

//INITIAL NODE >> nhận 1 giá trị int và tạo thành NODE
NODE * setNode(int num){
	NODE * node;
	node = new NODE;//khoi tao vung nho
	node->data = num;
	node->link = NULL;
	return node;
}

//INITIAL LIST >> tạo vị trí đầu và cuối cho LIST
void initialList(LIST &list){
	list.first = NULL;
	list.last = list.first;
}

//PRINT >> DUYỆT xuất LIST
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

//INSERT >> nhận DATA rồi tạo NODE dùm xong thêm NODE đó vô vị trí 'cuối' của LIST
void insertElementAtLast(LIST &list, int num){
	NODE * new_node = setNode(num);
	if (new_node == NULL){ return; }
	else {
		//xem hàm insertNodeAtLast
		if (list.first == NULL){
			list.first = new_node;
			list.last = list.first;
		}
		else{
			list.last->link = new_node;
			list.last = new_node;
		}
	}
}

//SORT >> sắp xếp LIST mode: tang/giam - SELECTION SORT
void selectionSortList(LIST & list, string mode){
	for (NODE * pre_node = list.first; pre_node != list.last; pre_node = pre_node->link){
		NODE * min_node = pre_node;
		for (NODE * next_node = pre_node->link; next_node != NULL; next_node = next_node->link){
			if (mode == "tang"){
				if (min_node->data > next_node->data){
					min_node = next_node;
				}
			}
			else if (mode == "giam"){
				if (min_node->data < next_node->data){
					min_node = next_node;
				}
			}
		}
		swap(min_node->data, pre_node->data);
	}
}

int main()
{
	int sl, num, middle = false;
	cin >> sl;

	LIST trai, phai;
	initialList(trai);
	initialList(phai);

	for (int i = 0; i < sl; i++){
		cin >> num;
		//lay ve trai
		if (i < sl / 2){
			insertElementAtLast(trai, num);
		}
		//day chan, lay ve phai
		else if (i >= sl / 2 && sl % 2 == 0){
			insertElementAtLast(phai, num);
		}
		//day le, lay ve phai
		else if (i > sl / 2 && sl % 2 != 0){
			insertElementAtLast(phai, num);
		}
		//day le, lay so le
		else if (i == sl / 2 && sl % 2 != 0){
			middle = num;
		}
	}

	selectionSortList(trai, "tang");
	selectionSortList(phai, "giam");
	coutList(trai);
	if (middle != false){
		cout << middle << endl;
	}
	coutList(phai);
	system("pause");
	return 0;
}
/*
Cho một dãy số nguyên có N phần tử.Hãy sắp xếp dãy số sao cho nữa dãy đầu tăng và nửa dãy sau giảm.
Nếu dãy số có số lượng phần tử lẻ, thì phần tử chính giữa được giữ nguyên vị trí.
Dữ liệu đầu vào:
- Dòng đầu tiên là số nguyên dương cho biết số lượng phần tử trong dãy số
- Dòng tiếp theo là N số trong dãy, mỗi số cách nhau 1 khoảng trắng
Dữ liệu đầu ra:
- Dãy số được sắp xếp theo yêu cầu. Mỗi số được cách nhau 1 khoảng trắng
Vd:
input:
8
4 2 3 1 9 6 8 7
output:
1 2 3 4 9 8 7 6

input:
9
4 2 3 1 5 9 6 8 7
output:
1 2 3 4 5 9 8 7 6
*/