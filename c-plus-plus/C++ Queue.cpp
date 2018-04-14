#include <iostream>
#define max 100
using namespace std;
struct QUEUE
{
	int front, back, count;
	int queue[max];
};
void initialQueue(QUEUE &qu) {
	qu.front = 0;
	qu.back = -1;
}
bool isQueueEmpty(QUEUE qu) {
	return qu.back - 1 == 0;
}
bool isQueueFull(QUEUE qu) {
	return qu.back + 1 == max;
}

void pushQueue(QUEUE &qu, int val) {
	if (!isQueueFull(qu)) {
		qu.queue[++qu.back] = val;
	}
	else { cout << "Error: Queue is full!" << endl; }
}
void popQueue(QUEUE &qu) {
	if (!isQueueEmpty(qu)) {
		for (int i = qu.front; i < qu.back; i++) {
			qu.queue[i] = qu.queue[i + 1];
			qu.back--;
		}
	}
	else { cout << "Error: Queue is empty" << endl; }
}
int frontQueue(QUEUE qu) {
	if (!isQueueEmpty(qu)) {
		return qu.queue[qu.front];
	}
	else { cout << "Error: Queue is empty!" << endl; }
}
void printQueue(QUEUE qu) {
	while (!isQueueEmpty(qu))
	{
		cout << frontQueue(qu) << endl;
		popQueue(qu);
	}
}
int main() {
	QUEUE qu;
	initialQueue(qu);
	pushQueue(qu, 1);
	pushQueue(qu, 2);
	printQueue(qu);
	system("pause");
	return 0;
}