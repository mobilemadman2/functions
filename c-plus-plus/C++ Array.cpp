#include <iostream>
using namespace std;

void xuatMangSo(int mang[], int mLen){
	for (int i = 0; i < mLen; i++){
		cout << mang[i];
	}
}

//SEARCH >> tìm kiếm tuần tự, trả về vị trí của giá trị nếu có trong mảng (loại cùi bắp)
int linearSearch(int a[], int len, int val) {
	for (int i = 0; i < len; i++) {
		if (a[i] == val) {
			return i;
		}
	}
	return -1;
}
//SEARCH >> tìm kiếm nhị phân (nhanh hơn linear search)
int binarySearch(int a[], int len, int val) {
	int left = 0, right = len - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] == val) { return mid; }
		if (a[mid] > val) {
			right = mid - 1;
		}
		else { left = mid + 1; }
	}
	return -1;
}
//SORT >> sắp xếp nổi bọt
void bubbleSort(int a[], int len, string mode) {
	int left = 0, shaker = left;
	for (int i = left; i < len; i++) {
		for (int j = len - 1; j > left; j--) {
			if (mode == "tang") {
				if (a[j] < a[j - 1]) {
					swap(a[j], a[j - 1]); shaker = j;
				}
			}
			else if (mode == "giam") {
				if (a[j] > a[j - 1]) {
					swap(a[j], a[j - 1]); shaker = j;
				}
			}

		}
		left = shaker;
	}
}
//SORT >> sắp xếp chọn
void selectionSort(int a[], int len, string mode) {
	for (int i = 0; i < len - 1; i++) {
		int min = i;
		for (int j = i + 1; j < len; j++) {
			if (mode == "giam") {
				if (a[j] > a[min]) {
					min = j;
				}
			}
			if (mode == "tang") {
				if (a[j] < a[min]) {
					min = j;
				}
			}
		}
		if (min != i) {
			swap(a[min], a[i]);
		}
	}
}