#include <iostream>
using namespace std;
//hieu chinh
void shift(int array_num[], int left, int right)
{
	int  anchor, curr, joint;
	curr = left; joint = 2 * curr + 1;
	anchor = array_num[curr];
	while (joint <= right)
	{
		if (joint < right) //neu co du 2 thanh phan lien doi
		{
			if (array_num[joint] < array_num[joint + 1]) {
				joint = joint + 1;
			}
		}
		if (array_num[joint] < anchor) //thoa quan he lien doi
		{
			break;
		}
		array_num[curr] = array_num[joint];
		curr = joint;
		joint = 2 * curr + 1;
	}
	array_num[curr] = anchor;
}
//tao heap
void createHeap(int array_num[], int right)
{
	int left;
	for (left = (right - 1) / 2; left >= 0; left--)
		shift(array_num, left, right - 1);
}
//sap xep giam dan
void heapSort(int array_num[], int len)
{
	int right;
	createHeap(array_num, len);
	right = len - 1;
	while (right > 0)
	{
		int tmp = array_num[0];
		array_num[0] = array_num[right];
		array_num[right] = tmp;
		right--;
		shift(array_num, 0, right);
	}
}

void xuatMangSo(int mang[], int mLen) {
	for (int i = 0; i < mLen; i++) {
		cout << mang[i] << " ";
	}
}

bool isSNT(int num) {
	if (num < 2) return false;
	for (int i = 2; i < num; i++) {
		if (num%i == 0) return false;
	}
	return true;
}

int main() {
	int soLuong, num, arr_snt[300], arr_num[1000], so_snt = 0;
	cin >> soLuong;
	//nhập mảng
	for (int i = 0; i < soLuong; i++) {
		cin >> num;
		//nếu là SNT thì lưu vào mảng riêng
		//mảng chính gán bằng false để đánh dấu
		if (isSNT(num)) {
			arr_snt[so_snt] = num;
			arr_num[i] = false;
			so_snt++;
		}
		else {
			arr_num[i] = num;
		}
	}
	//sắp tăng dần
	shift(arr_snt, 1, so_snt);
	heapSort(arr_snt, so_snt);
	//xếp ngược vào vị trí đã đánh dấu
	int j = 0;
	for (int i = 0; i < soLuong; i++) {
		if (arr_num[i] == false) {
			arr_num[i] = arr_snt[so_snt - 1];
			so_snt--;
		}
	}
	xuatMangSo(arr_num, soLuong);
	system("pause");
	return 0;
}