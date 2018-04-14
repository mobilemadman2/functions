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

//INSERT >> thêm NODE vào đầu LIST
void insertNodeAtFirst(LIST &list, NODE * new_node){
	if (list.first == NULL)			//neu list rong thi first va last deu bang new_element
	{
		list.first = new_node;
		list.last = list.first;
	}
	else {
		//nếu khác rỗng, first sẽ truyền link nó đang giữ cho new, data của new sẽ gán cho first
		new_node->link = list.first;
		list.first = new_node;
	}
}

//INSERT >> nhận DATA rồi tạo NODE dùm, xong thêm NODE đó vô vị trí 'đầu' của LIST
void insertDataAtFirst(LIST &list, int num){
	NODE * new_node = setNode(num);
	if (new_node == NULL){ return; }
	else {
		//xem hàm insertNodeAtFirst
		if (list.first == NULL)
		{
			list.first = new_node;
			list.last = list.first;
		}
		else {
			new_node->link = list.first;
			list.first = new_node;
		}
	}
}

//INSERT >> thêm một số NODE xác định vào đầu của LIST
void cinToListAtFirst(LIST &list){
	int num;
	while (cin >> num)
	{
		//tạo 1 node có giá trị là num
		NODE * new_node = setNode(num);
		//xem hàm insertNodeAtFirst
		if (list.first == NULL)
		{
			list.first = new_node;
			list.last = list.first;
		}
		else {
			new_node->link = list.first;
			list.first = new_node;
		}
	}
}

//INSERT >> thêm NODE vào vị trí cuối của LIST
void insertNodeAtLast(LIST &list, NODE * new_node){
	//nếu LIST rỗng thì first và last đều bằng NODE
	if (list.first == NULL){
		list.first = new_node;
		list.last = list.first;
	}
	//nếu LIST đã có last NODE, thì last NODE sẽ lưu vị trí của node mới thêm
	//node mới thêm sẽ thành last NODE mới
	else{
		list.last->link = new_node;
		list.last = new_node;
	}
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

//INSERT >> thêm một số NODE xác định vào cuối LIST
void cinToListAtLast(LIST & list){
	int data;
	while (cin >> data)
	{
		NODE * new_node = setNode(data);
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

//INSERT >> thêm 1 NODE mới ở vị trí sau NODE x nào đó trong LIST
void insertNodeAfterNode(LIST & list, NODE * node_x, NODE * new_node){
	//điều kiện là NODE thêm và vị trí thêm phải tồn tại
	if (node_x != NULL && new_node != NULL){
		//NODE mới sẽ lưu link mà NODE X đang giữ
		new_node->link = node_x->link;
		//NODE X sẽ giữ link của NODE mới
		node_x->link = new_node;
		//nếu NODE X là last thì NODE mới sẽ thành last vì nằm sau NODE X
		if (node_x == list.last){
			list.last = new_node;
		}
	}
}

//INSERT >> thêm DATA tại vị trí x
void insertDataAtX(LIST & list, int position, int data){
	int counter = 0;
	NODE * new_node = setNode(data);
	NODE * anchor_node = list.first;
	while (anchor_node != NULL){
		if (position == 0){
			//xem hàm insertNodeAtFirst
			if (list.first == NULL)
			{
				list.first = new_node;
				list.last = list.first;
			}
			else {
				new_node->link = list.first;
				list.first = new_node;
			}
			anchor_node = NULL;
		}
		else if (counter == position - 1){
			//xem hàm insertNodeAfterNode
			if (anchor_node != NULL && new_node != NULL){
				new_node->link = anchor_node->link;
				anchor_node->link = new_node;
				if (anchor_node == list.last){
					list.last = new_node;
				}
			}
			anchor_node = NULL;
		}
		else{
			counter++;
			anchor_node = anchor_node->link;
		}
	}
}

//INSERT >> thêm NODE tại vị trí x
void insertNodeAtX(LIST & list, int position, NODE * new_node){
	int counter = 0;
	NODE * anchor_node = list.first;
	while (anchor_node != NULL){
		if (position == 0){
			//xem hàm insertNodeAtFirst
			if (list.first == NULL)
			{
				list.first = new_node;
				list.last = list.first;
			}
			else {
				new_node->link = list.first;
				list.first = new_node;
			}
			anchor_node = NULL;
		}
		else if (counter == position - 1){
			//xem hàm insertNodeAfterNode
			if (anchor_node != NULL && new_node != NULL){
				new_node->link = anchor_node->link;
				anchor_node->link = new_node;
				if (anchor_node == list.last){
					list.last = new_node;
				}
			}
			anchor_node = NULL;
		}
		else{
			counter++;
			anchor_node = anchor_node->link;
		}
	}
}

//FIND >> tìm data 'đầu tiên' trong LIST, gán data nếu tìm đc, gán NULL nếu ko 
NODE * findNodeByData(LIST & list, int data){
	NODE * node = list.first;
	while (node != NULL && node->data != data)
	{
		node = node->link;
	}
	return node;
}

//FIND >> tìm xem trong list có phần tử nào = DATA x hay ko

//COUNT >> đếm số NODE trong LIST
int countNode(LIST & list){
	int counter = 0;
	//bắt đầu chạy từ first
	NODE * counter_node = list.first;
	//khi counter_node = last > counter_node = NULL thì dừng
	while (counter_node != NULL)
	{
		counter++;
		//nhảy tới node tiếp theo
		counter_node = counter_node->link;
	}
	delete counter_node;
	return counter;
}

//DELETE >> xóa NODE đầu tiên trong LIST
void deleteFirstNode(LIST & list){
	//điều kiện là LIST phải có NODE
	if (list.first != NULL){
		//tạo 1 node tạm để lưu first
		NODE * node = list.first;
		//first của LIST lúc này sẽ lưu link của node tạm
		list.first = node->link;
		if (list.first == NULL){
			list.last = NULL;
		}
		delete node;
	}
}

//DELETE >> xóa NODE cuoi cung trong LIST
void deleteLastNode(LIST & list){
	//điều kiện là LIST phải có NODE
	if (list.first != NULL){
		//nếu LIST chỉ có 1 phần tử
		if (list.first == list.last){
			list.first = NULL;
			list.last = NULL;
		}
		else{
			//vòng lặp bắt đầu từ first
			NODE * anchor_node = list.first;
			//NODE bị xóa là node tiếp theo
			NODE * bye_node = anchor_node->link;
			//lặp cho đến khi xóa đc NODE
			while (bye_node != NULL)
			{
				//bye_node là NODE sau NODE neo
				bye_node = anchor_node->link;
				//nếu đã đến last thì xóa
				if (bye_node == list.last){
					anchor_node->link = NULL;
					list.last = anchor_node;
					delete bye_node;
				}
				//chưa thì tăng NODE neo
				else{
					anchor_node = anchor_node->link;
				}
			}
		}

	}
}

//DELETE >> xóa NODE sau node anchor (là node neo vào để xóa node sau)
void deleteNodeAfterNode(LIST & list, NODE * anchor_node){
	//điều kiện là NODE neo và NODE cần xóa phải tồn tại
	if (anchor_node != NULL && anchor_node->link != NULL){
		//tạo 1 node tạm để lưu NODE cần xóa (gọi là bye_node)
		NODE * bye_node = anchor_node->link;
		//lúc này anchor_node sẽ bám vào node ở sau bye_node
		anchor_node->link = bye_node->link;
		//và nếu bye_node là last thì sau khi xóa last phải bằng anchor_node
		if (bye_node == list.last){
			list.last = anchor_node;
		}
		//hoàn tất thủ tục chuyển giao, bye node :(
		delete bye_node;
	}
}

//DELETE >> xóa NODE sau DATA anchor (là node neo vào để xóa node sau)
void deleteNodeAfterData(LIST & list, int anchor_data){
	//tìm node neo chứa data
	//xem hàm searchNodeByData
	NODE * anchor_node = list.first;
	while (anchor_node != NULL && anchor_node->data != anchor_data)
	{
		anchor_node = anchor_node->link;
	}
	//điều kiện là NODE neo và NODE cần xóa phải tồn tại
	if (anchor_node != NULL && anchor_node->link != NULL){
		//tạo 1 node tạm để lưu NODE cần xóa (gọi là bye_node)
		NODE * bye_node = anchor_node->link;
		//lúc này anchor_node sẽ bám vào node ở sau bye_node vì bye_node sắp ra đi
		anchor_node->link = bye_node->link;
		//và nếu bye_node là last thì sau khi xóa last phải bằng anchor_node
		if (bye_node == list.last){
			list.last = anchor_node;
		}
		//hoàn tất thủ tục chuyển giao, bye node :(
		delete bye_node;
	}
}

//DELETE >> xóa toàn bộ LIST (xóa từ đầu tới cuối)
void deleteList(LIST & list){
	//tạo node tạm để giữ first
	NODE * tmp_node;
	//khi mà first vẫn còn giá trị thì tiếp tục xóa
	while (list.first != NULL)
	{
		tmp_node = list.first;
		//first sẽ rời node nó đang giữ để nắm node kế đó
		list.first = tmp_node->link;
		//node tạm ko còn liên hệ vs list nữa > xóa
		//delete tmp_node;
		//hoặc dùng hàm 
		free(tmp_node);
	}
	//khi first đã rỗng thì last rỗng > LIST rỗng
	list.last = NULL;
}

//DELETE >> xóa NODE có DATA x
void deleteNodeByData(LIST & list, int data){
	//gọi bye_node là node chứa giá trị cần xóa
	NODE * bye_node = list.first;
	while (bye_node != NULL && bye_node->data != data)
	{
		bye_node = bye_node->link;
	}
	//đặt 1 node neo ở trước bye_node
	NODE * anchor_node = list.first;
	//điều kiện là bye_node phải tồn tại trong LIST
	while (bye_node != NULL)
	{
		//nếu bye_node là first
		if (bye_node->data == list.first->data){
			//xem hàm deleteFirstNode
			if (list.first != NULL){
				NODE * node = list.first;
				list.first = node->link;
				if (list.first == NULL){
					list.last = NULL;
				}
				delete node;
			}
			//cho bye_node = null để dừng vòng lặp
			bye_node = NULL;
		}
		//nếu bye_node là các node sau first
		else{
			//bye_node sẽ là node sau previous_node
			bye_node = anchor_node->link;
			//nếu bye_node = giá trị cần xóa thì xóa node đó
			if (bye_node->data == data){
				//xem hàm deleteNodeAfterNode
				if (anchor_node != NULL && anchor_node->link != NULL){
					NODE * bye_node = anchor_node->link;
					anchor_node->link = bye_node->link;
					if (bye_node == list.last){
						list.last = anchor_node;
					}
					delete bye_node;
				}
				bye_node = NULL;
			}
			//ko thì previous_node sẽ duyệt qua node kế đó
			else{
				anchor_node = bye_node;
			}
		}
	}
	//giải phóng bye_node
	delete bye_node;
}

//DELETE >> xóa NODE (chưa đúng)
/*void deleteNode(LIST & list, NODE * bye_node){
//đặt 1 node neo ở trước bye_node
NODE * previous_node = list.first;
//điều kiện là bye_node phải tồn tại trong LIST
while (bye_node != NULL)
{
//nếu bye_node là first
if (bye_node == list.first){
deleteFirstNode(list);
//cho bye_node = null để dừng vòng lặp
bye_node = NULL;
}
//nếu bye_node là last
else if (bye_node == list.last){
deleteLastNode(list);
bye_node = NULL;
}
//nếu bye_node là các node sau first
else{
if (bye_node->link == list.last){
bye_node->link = NULL;
list.last = bye_node;
}
bye_node->data = bye_node->link->data;
bye_node = bye_node->link;
if (bye_node == list.last){
bye_node = NULL;
}
/*
//bye_node sẽ là node sau previous_node
bye_node = previous_node->link;
//nếu bye_node = giá trị cần xóa thì xóa node đó
if (bye_node->data == data){
deleteNodeAfterNode(list, previous_node);
bye_node = NULL;
}
//ko thì previous_node sẽ duyệt qua node kế đó
else{
previous_node = bye_node;
}
}
}
//giải phóng bye_node
delete bye_node;
}*/

//DELETE >> xóa NODE tại vị trí x
void deleteNodeAtX(LIST & list, int position){
	int counter = 0;
	//lưu NODE sẽ xóa vào NODE neo
	NODE * anchor_node = list.first;
	//lặp đến khi xóa NODE neo bị xóa thì dừng
	while (anchor_node != NULL){
		//nếu xóa vị trí đầu tiên thì gọi hàm này
		if (position == 0){
			//xem hàm deleteFirstNode
			if (list.first != NULL){
				NODE * node = list.first;
				list.first = node->link;
				if (list.first == NULL){
					list.last = NULL;
				}
				delete node;
			}
			//xóa xong thì thoát hàm
			break;
		}
		//vì đã có hàm xóa Node a sau Node b rồi
		//nên sẽ đếm đến trước Node cần xóa rồi gọi hàm đó
		if (counter == position - 1){
			//xem hàm deleteNodeAfterNode
			if (anchor_node != NULL && anchor_node->link != NULL){
				NODE * bye_node = anchor_node->link;
				anchor_node->link = bye_node->link;
				if (bye_node == list.last){
					list.last = anchor_node;
				}
				delete bye_node;
			}
			break;
		}
		//tăng counter đến khi = vị trí đã nhận
		else{
			counter++;
			//NODE neo chạy tới last -> NULL -> dừng vòng lặp
			anchor_node = anchor_node->link;
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

//APPEND >> nối LIST b vào sau LIST a
void appendList(LIST & alist, LIST & blist){
	if (blist.first == NULL){ return; }
	if (alist.first == NULL){
		alist = blist;
	}
	else{
		alist.first->link = blist.first;
		alist.last = blist.last;
	}
	initialList(blist);
}

//SORT >> sắp xếp LIST - BUBLE SORT
//SORT >> sắp xếp LIST - QUICK SORT
LIST quickSortList(LIST & list){
	//nếu list cần sort rỗng hoac chi co 1 phan tu thì thoát hàm
	if (list.first == list.last){ return list; }
	//gọi anchor_node là node neo lại để so sánh
	//sort_node là node tăng dần để so sánh
	NODE *anchor_node, *sort_node;
	//alist chứa các node lớn hơn anchor_node, blist ngược lại
	LIST alist, blist, sortedList;
	initialList(alist);
	initialList(blist);
	initialList(sortedList);

	//neo tại node đầu của list
	anchor_node = list.first;
	sort_node = anchor_node->link;
	//ngắt node đầu ra khỏi list xxx
	//list.first = anchor_node->link;
	//lặp cho đến khi het list
	while (sort_node != NULL){
		//nếu sort <= node neo thì cho vô list a
		if (sort_node->data <= anchor_node->data){
			insertNodeAtLast(alist, sort_node);
		}
		//ngược lại cho vô list b
		else{
			insertNodeAtLast(blist, sort_node);
		}
		//bắt đầu so sánh từ đầu list (đã bị ngắt đầu)
		sort_node = sort_node->link;
	}
	//sắp tiếp trong list a và b
	alist = quickSortList(alist);
	blist = quickSortList(blist);

	//nối list a vào list gốc
	appendList(sortedList, alist);
	cout << anchor_node->data << "-- ";
	insertNodeAtFirst(blist, anchor_node);
	//nối list b vào list gốc
	appendList(sortedList, blist);
	return sortedList;
}
int main(){
	LIST list;
	initialList(list);
	insertElementAtLast(list, 1);
	insertElementAtLast(list, 2);
	insertElementAtLast(list, 3);

	deleteNodeByData(list, 2);
	coutList(list);

	system("pause");
	return 0;
}