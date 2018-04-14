#include <iostream>
#include <string>
#include <stack>
using namespace std;
//CONVERT >> chuyển sang chữ thường
string toLowerCase(string str) {
	for (size_t i = 0; i < str.size(); i++) {
		if ((int)str[i] >= 65 && (int)str[i] <= 90) {
			str[i] = char((int)str[i] + 32);
		}
	}
	return str;
}
//CHECK >> dữ liệu đã có trong stack hay chưa?
bool isExistInStack(string data, stack <string> st) {
	while (!st.empty())
	{
		if (st.top() == data) {
			return true;
		}
		st.pop();
	}
	return false;
}
int countWords(string str) {
	str = toLowerCase(str);

	//chuỗi tạm để lưu từng từ, lưu kí tự đầu tiên trước
	string tmp;
	tmp += str[0];
	//chỉ số của chữ trong tmp
	int top_tmp = 0;

	//stack lưu các từ ko trùng nhau tìm đc
	stack <string> words;
	//đếm số từ trong stack
	int count = 0;

	//kí hiệu để push từ vào stack
	bool readyToPush = false;

	//lặp từ vị trí 1 đến hết
	for (int i = 1; i < str.size(); i++) {
		//nếu từ khác từ trc đó thì check
		if (str[i] != tmp[top_tmp]) {
			//nếu có dấu hiệu push
			if (readyToPush) {
				//nếu từ chưa có trong stack thì push vào và tăng count
				if (!isExistInStack(tmp, words)) {
					words.push(tmp); count++;
				}
				//tmp lấy bằng từ hiện tại để tiếp tục so sánh
				tmp = str[i]; top_tmp = 0;
				readyToPush = false;
			}
			//nếu từ khác mà ko đc push thì cộng thêm vào tmp
			else {
				tmp += str[i]; top_tmp++;
			}
		}
		//nếu từ giống từ trước thì bật push
		else {
			readyToPush = true;
		}
	}
	//khi hết chuỗi trong tmp vẫn còn lưu từ cuối cùng chưa kịp push
	return count + 1;
}

int main() {
	string str;// = "xinnchaootoiilaabuiiminhhphucccc";
	cin >> str;
	cout << countWords(str);
	return 0;
}