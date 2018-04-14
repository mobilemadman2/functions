#include <iostream>
#include <string>
using namespace std;
struct NODE {
	int diem; string ten;
	NODE * link;
};
struct LIST
{
	NODE * first;
	NODE * last;
};
void initialList(LIST &list) {
	list.first = NULL;
	list.last = list.first;
}
void coutList(LIST &list, int n) {
	NODE * node = list.first;
	int i = 0;
	while (i<n && node != NULL) {
		cout << node->ten << endl;
		node = node->link;
		i++;
	}
	cout << endl;
}
NODE * setNode(string ten, int diem) {
	NODE * node;
	node = new NODE;//khoi tao vung nho
	node->ten = ten; node->diem = diem;
	node->link = NULL;
	return node;
}
void insertElementAtLast(LIST &list, string ten, int diem) {
	NODE * new_node = setNode(ten, diem);
	if (new_node == NULL) { return; }
	else {
		if (list.first == NULL) {
			list.first = new_node;
			list.last = list.first;
		}
		else {
			list.last->link = new_node;
			list.last = new_node;
		}
	}
}
//SORT >> sắp xếp LIST mode: tang/giam - SELECTION SORT
void selectionSortList(LIST & list, string mode) {
	for (NODE * pre_node = list.first; pre_node != list.last; pre_node = pre_node->link) {
		NODE * min_node = pre_node;
		for (NODE * next_node = pre_node->link; next_node != NULL; next_node = next_node->link) {
			if (mode == "tang") {
				if (min_node->diem > next_node->diem) {
					min_node = next_node;
				}
			}
			else if (mode == "giam") {
				if (min_node->diem < next_node->diem) {
					min_node = next_node;
				}
			}
		}
		swap(min_node->diem, pre_node->diem);
		swap(min_node->ten, pre_node->ten);
	}
}
//CONVERT >> chuỗi thành số
int tonum(string str) {
	int result = 0;
	for (size_t i = 0; i < str.size(); i++) {
		result = result * 10 + str[i] - 48;
	}
	return result;
}
int main() {
	//database
	LIST doi; initialList(doi); string ten; int diem;

	//input process
	string input;
	int phase = 1;
	bool end = false;
	while (cin >> input)
	{
		switch (phase)
		{
		case 1:
			if (input == "000") { end = true; break; }
			ten = input; diem = 0;
			phase = 2; break;
		case 2:
			diem += tonum(input);
			phase = 3; break;
		case 3:
			diem += tonum(input) * 2;
			phase = 4; break;
		case 4:
			diem += tonum(input) * 3;
			insertElementAtLast(doi, ten, diem);
			phase = 1; break;
		}
		if (end) { break; }
	}
	selectionSortList(doi, "giam");
	coutList(doi, 3);
	system("pause");
	return 0;
}
/*
Cách tính điểm như sau: mỗi lượt like được 1 điểm, comment được 2 điểm và share được 3 điểm.
Ban tổ chức đã nhờ người thống kê số lượt tương tác của từng đội,
việc còn lại của bạn là tính điểm và xác định 3 đội được trao quà.
Dữ liệu đầu vào: gồm nhiều đội tuyển, dữ liệu mỗi đội tuyển bao gồm 4 dòng:
- Tên đội (không có khoảng trắng)
- Số lượt like
- Số lượt comment
- Số lượt share
Dữ liệu đầu vào kết thúc khi tên đội là "000"
Dữ liệu đầu ra: gồm 3 dòng ghi tên lần lượt 3 đội được trao quà
theo thứ tự điểm cao đến thấp (dữ liệu vào đảm bảo không có 2 đội nào bằng điểm)


Ví dụ:
Input:
UP_Balloons
456
215
34
UP_Unlimited
654
45
21
UP_Explorer
452
142
15
UP_Ashe
356
654
78
000

Output:
UP_Ashe
UP_Balloons
UP_Unlimited
*/