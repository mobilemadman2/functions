#include <iostream>
#include <string>
using namespace std;

int main()
{
	struct dsLTV
	{
		string nv1, nv2;
		string state1, state2;
		int duan1, duan2;
		int cv1, cv2;
	};
	dsLTV asana;
	cin >> asana.nv1 >> asana.nv2;
	cin >> asana.state1 >> asana.state2;
	cin >> asana.duan1 >> asana.duan2;
	cin >> asana.cv1 >> asana.cv2;
	if (asana.state1 == "true" && asana.state2 == "false")
		cout << asana.nv2;
	if (asana.state1 == "false"&& asana.state2 == "true")
		cout << asana.nv1;
	if (asana.state1 == "false" && asana.state2 == "false")
	{
		if (asana.cv1 <= asana.cv2 && asana.duan1 < asana.duan2)
		{
			cout << asana.nv1;
		}
		else
		if (asana.cv1 >= asana.cv2 && asana.duan1 > asana.duan2)
		{
			cout << asana.nv2;
		}
	}
	system("pause");
	return 0;
}


/*
Asana là một hệ thống phân việc thông minh được thiết kế đề chia sẻ công việc giữa các lập trình viên. Một công việc mới sẽ được phân công một cách tự động cho một lập trình viên có thời gian phù hợp trong nhóm. Một lập trình viên sẽ có các thông tin sau:
- Tên
- Trạng thái: là true nếu lập trình viên này đang nghỉ phép, là false nếu ngược lại
- Số lượng dự án
- Số lượng công việc phải thực hiện.

Nếu một lập trình viên có "trạng thái" là true, có nghĩa là họ đang nghỉ phép và không thể nhận việc.
Ngược lại, họ có thể nhận công việc.
Asana sẽ sắp xếp các lập trình viên theo khả năng nhận việc của họ.
Một lập trình viên A sẽ có khả năng nhận việc cao hơn lâp trình viên B nếu họ có ít công việc hơn B,
hoặc có cùng số lượng cộng việc nhưng A được phân công dự án ít hơn B.
Mặt khác, chúng ta cho rằng lập trình viên A có khả năng nhận việc cao hơn B nếu A vừa ít công việc
và dự án hơn B (xét theo cặp (số công việc (task), số dự án (project))
Hãy chỉ ra người có khả năng nhận việc cao nhất

Input:
- Dòng đầu tiên là danh sách tên các lập trình viên
- Dòng thứ hai là trạng thái nghỉ phép của các lâp trình viên
- Dòng thứ ba là số lượng dự án của từng lập trình viên
- Dòng thứ tư là số lượng công việc của từng lập trình viên

Output:
Tên lập trình viên được phân công

Vd
Input:
John Martin
false false
2 1
16 5

Output:
Martin
*/