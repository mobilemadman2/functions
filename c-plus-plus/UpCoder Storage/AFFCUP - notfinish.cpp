#include <iostream>
#include <string>
using namespace std;
//tạo struct NODE
int sero = 0;
struct NODE {
	string team;
	int score;
	int win;
	int lose;
	NODE * link;
};

//tạo struct LIST
struct LIST
{
	NODE * first;
	NODE * last;
};
//INITIAL LIST >> tạo vị trí đầu và cuối cho LIST
void initialList(LIST &list) {
	list.first = NULL;
	list.last = list.first;
}
//INITIAL NODE >> nhận 1 giá trị int và tạo thành NODE
NODE * setNode(string team, int score) {
	NODE * node;
	node = new NODE;//khoi tao vung nho
	node->team = team;
	node->score = score;
	node->link = NULL;
	return node;
}

void insertElementAtLast(LIST &list, string team, int score) {
	NODE * new_node = setNode(team, score);
	if (score == 3) { new_node->win = 1; new_node->lose = 0; }
	if (score == 0) { new_node->lose = 1; new_node->win = 0; }
	if (score == 1) { new_node->lose = 0; new_node->win = 0; }
	if (new_node == NULL) { return; }
	else {
		//xem hàm insertNodeAtLast
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

//cộng điểm cho đội
void congDiem(LIST &teamlist, string team, int score) {
	//tao mot node de luu gia tri dau tien
	NODE * node = teamlist.first;
	//nếu đội đã có trong ds thì cộng điểm
	while (node != NULL) {
		if (node->team == team) {
			node->score += score;
			if (score == 3) { node->win += 1; }
			if (score == 0) { node->lose += 1; }
			return;
		}
		node = node->link;
	}
	//nếu chưa thì thêm vào
	insertElementAtLast(teamlist, team, score);
}

//tách dữ liệu, tính điểm cho từng đội
void tinhDiem(LIST & teamlist, string input) {
	int count_space = 0, scor1, scor2;
	string tmp, team1, team2;
	//tách dữ liệu
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == ' ') {
			switch (count_space)
			{
			case 0: team1 = tmp; tmp = ""; count_space++; break;
			case 1: scor1 = int(tmp[0]) - 48; tmp = ""; count_space++; break;
			case 2: tmp = ""; count_space++; break;
			case 3: scor2 = int(tmp[0]) - 48; tmp = ""; count_space++; break;
			default: break;
			}
		}
		else {
			tmp += input[i];
		}
	}
	team2 = tmp;

	//thêm đội vào bảng
	if (scor1 > scor2) {
		congDiem(teamlist, team1, 3);
		congDiem(teamlist, team2, 0);
	}
	if (scor1 < scor2) {
		congDiem(teamlist, team2, 3);
		congDiem(teamlist, team1, 0);
	}
	if (scor1 == scor2) {
		congDiem(teamlist, team1, 1);
		congDiem(teamlist, team2, 1);
	}
}

//PRINT >> DUYỆT xuất LIST
void coutList(LIST &list) {
	//tao mot node de luu gia tri dau tien
	NODE * node = list.first;
	//neu gia tri do khac null thi cout
	while (node != NULL) {
		cout << node->team << " " << node->score << " " << node->win << "-" << node->lose << endl;
		node = node->link;
	}
}

//SORT >> sắp xếp LIST mode: tang/giam - SELECTION SORT
void selectionSortList(LIST & list, string mode) {
	//cong hieu ban thang vao score
	/*NODE * node = list.first;
	while (node!= NULL) {
	node->score = node->score + node->win - node->lose;
	node = node->link;
	}*/
	//sắp xếp score theo thứ tự
	for (NODE * pre_node = list.first; pre_node != list.last; pre_node = pre_node->link) {
		NODE * min_node = pre_node;
		for (NODE * next_node = pre_node->link; next_node != NULL; next_node = next_node->link) {
			if (mode == "tang") {
				if (min_node->score > next_node->score) {
					min_node = next_node;
				}
			}
			else if (mode == "giam") {
				if (min_node->score < next_node->score) {
					min_node = next_node;
				}
			}
		}
		swap(min_node->score, pre_node->score);
		swap(min_node->team, pre_node->team);
	}
	//nếu score nhất nhì bằng nhau thì xếp theo hiệu bàn thắng
	/*NODE * node = list.first;
	while (node->link != NULL) {
	if (node->score == node->link->score) {
	if (node->win - node->lose < node->link->win - node->link->lose) {
	swap(node->score, node->link->score);
	swap(node->team, node->link->team);
	swap(node->win, node->link->win);
	swap(node->lose, node->link->lose);
	}
	}
	node = node->link;
	}*/
}

int main() {
	LIST table_a, table_b;
	initialList(table_a);
	initialList(table_b);
	string match;
	for (int i = 1; i <= 12; i++) {
		getline(cin, match);
		if (i <= 6) {
			tinhDiem(table_a, match);
		}
		else {
			tinhDiem(table_b, match);
		}
	}
	selectionSortList(table_a, "giam");
	selectionSortList(table_b, "giam");
	coutList(table_a); cout << "--" << endl; coutList(table_b);
	cout << table_a.first->team << " - " << table_b.first->team << endl;
	cout << table_b.first->link->team << " - " << table_a.first->link->team << endl;

	system("pause");
	return 0;
}
/*
Cách tính điểm theo luật FIFA, thắng được 3 điểm, hòa được 1 điểm và thua không được điểm.
Trong trường hợp có hai đội bằng điểm thì thứ hạng sẽ được phân định bằng hiệu số bàn thắng bại.

Vòng bán kết gồm hai cặp đấu: nhất bảng A - nhì bảng B; nhất bảng B - nhì bảng A.

Cho kết quả 12 trận đấu tại vòng bảng, hãy xác định các cặp đấu ở vòng bán kết.

Dữ liệu đầu vào:
- 6 dòng đầu là kết quả 6 trận đấu bảng A
- 6 dòng tiếp theo là kết quả 6 trận đấu bảng B

Dữ liệu đầu ra: gồm 2 dòng là hai cặp đấu ở bán kết theo thứ tự:
- Nhất bảng A - Nhì bảng B
- Nhất bảng B - Nhì bảng A

(Định dạng dữ liệu vào, dữ liệu ra xem ở ví dụ)

Ví dụ:
Input:
Vietnam 2 - 1 Indonesia
Cambodia 0 - 0 Myanmar
Vietnam 1 - 0 Camdobia
Indonesia 3 - 0 Myanmar
Vietnam 1 - 0 Myanmar
Cambodia 0 - 2 Indonesia
Thailand 2 - 1 Malaysia
Singapore 4 - 0 Laos
Thailand 1 - 1 Singapore
Malaysia 0 - 0 Laos
Laos 0 - 1 Thailand
Malaysia 0 - 3 Singapore

Output:
Vietnam - Thailand
Singapore - Indonesia
*/