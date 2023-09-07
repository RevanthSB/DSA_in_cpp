#include<iostream>
using namespace std;
class Queue {
private:
	int front = -1;
	int rear = -1;
	int arr[3];
	int size = 3;
	int itemcount;
public:
	Queue() {
		itemcount = 0;
		for (int i = 0; i < size; i++) {
			arr[i] = 0;
		}
	}
	Queue(int arr[3]) {
		for (int i = 0; i < size; i++) {
			enqueue(arr[i]);
		}
	}
	bool isfull() {
		if ((rear + 1) % size == front) {
			return true;
		}
		else {
			return false;
		}
	}
	bool isempty() {
		if (rear == -1 && front == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	void enqueue(int a) {
		if (!isfull()) {
			itemcount++;
			if (front == -1 && rear == -1) {
				front = rear = 0;
				arr[rear] = a;
			}
			else {
				rear = (rear + 1) % size;
				arr[rear] = a;
			}
		}
		else {
			cout << "queue is full" << endl;
		}
	}
	int dequeue() {
		int x;
		if (!isempty()) {
			itemcount--;
			if (front == rear) {
				x = arr[front];
				front = -1;
				rear = -1;
				return x;
			}
			else {
				x = arr[front];
				front = (front + 1) % size;
				return x;
			}
		}
		else {
			cout << "queue is empty" << endl;
			return 0;
		}
	}
	int count() {
		if (isempty()) {
			cout << 0 << endl;
			return 0;
		}
		else {
			cout << itemcount << endl;
		}
	}
	void display() {
		if (isempty()) {
			cout << "queue is empty" << endl;
		}
		else {
			//cout << "front " << front << "rear " << rear << endl;
			if (front > rear) {
				for (int i = front; i <= front; ) {
					//cout << i << "if  "<<endl;
					cout << arr[i] << " ";
					if (i != rear) {
						i = (i + 1) % size;
						//cout << i << endl;
						//cout << rear << endl;
					}
					else if (i == rear) {
						break;
					}


				}
			}
			else {
				for (int i = front; i <= rear; ) {
					//cout << "else " << endl;
					cout << arr[i] << " ";
					if (i + 1 != size) {
						i = (i + 1) % size;
					}
					else {
						break;
					}

				}
			}
			cout << endl;
		}
	}
};
int main() {
	int i = 1;
	int ch;
	Queue q;
	do {
		cout << endl << endl;
		cout << "Queue operation" << endl;
		cout << "press 1 for enqueue operation" << endl;
		cout << "press 2 for dequeue operation" << endl;
		cout << "press 3 for count operation" << endl;
		cout << "press 4 for display operation" << endl;
		cout << "press 5 for end operation" << endl;
		cout << "enter the option" << endl;
		cin >> ch;
		cout << endl;
		switch (ch) {
		case 1:
			int a;
			cout << "enter the element to insert" << endl;
			cin >> a;
			q.enqueue(a);
			break;
		case 2:
			int b;
			b = q.dequeue();
			cout << b << endl;
			break;
		case 3:
			q.count();
			break;
		case 4:
			q.display();
			break;
		case 5:
			i = 0;
			break;
		}
	} while (i != 0);
	return 0;
}