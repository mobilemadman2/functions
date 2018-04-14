#include <iostream>
using namespace std;

bool isDevisorOf(int devidend, int devisor){
	//chia cho float sẽ lấy phần thập phân, chia cho int thì ngc lại
	//nếu a chia hết cho b nghĩa là a/b sẽ ko bị dư phần thập phân nào
	if (devidend / (float)devisor == devidend / devisor){
		return true;
	}
	return false;
}

int sumOfDevisor(int num){
	int sum = 0;
	for (int i = 1; i < num; i++){
		if (isDevisorOf(num, i)){
			sum += i;
		}
	}
	return sum;
}
int main(){
	int anum, bnum;
	cin >> anum >> bnum;
	if (sumOfDevisor(anum) == bnum && sumOfDevisor(bnum) == anum){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	system("pause");
	return 0;
}
/*
Một cặp số nguyên dương được gọi là số bạn bè nếu tổng các ước số của số này bằng chính số kia.
Ví dụ 220 và 284 là cặp số bạn bè vì tổng các ước số của 220 là:
1+2+4+5+10+11+20+22+44+55+110=284 và tổng các ước số của 284 là 1+2+4+71+142=220.
1184 và 1210 cũng là hai số bạn bè. Hãy viết chương trình kiểm tra xem 2 số nhập vào có phải là số bạn bè hay không.

Dữ liệu nhập:
- Là hai số nguyên a, b cách nhau một khoảng trắng (1 ≤ a, b ≤ 105)

Dữ liệu xuất:
- In ra YES nếu a, b là hai số bạn bè. In ra NO nếu không phải.

Ví dụ
Input1		Output 1	Input 2		Output 2
220 284		YES			12 20		NO
*/