#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <cstringt.h>
#include <vector>
using namespace std;


class stack {
private:
	int top;
	int size = 10;
	int arr[20];

public:
	stack() {
		top = -1;
		for (int i = 0; i < 10; i++) {
			arr[i] = 0;
		}
	}
	stack(int arr[]) {
		for (int i = 0; i < 10; i++) {
			if (arr[i] != 0) {
				push(arr[i]);
			}
			else {
				break;
			}
		}
	}

	void push(int value) {
		if (!isfull()) {
			top++;
			arr[top] = value;
		}
		else {
			cout << "stack overflow" << endl;
		}
	}

	void pop() {
		if (!isempty()) {
			arr[top] = 0;
			top--;
		}
		else {
			cout << "stack underflow" << endl;
		}
	}

	bool isempty() {
		if (top == -1) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isfull() {
		if (top == size - 1) {
			return true;
		}
		else {
			return false;
		}
	}

	int peek(int value) {
		return arr[value - 1];
	}

	int count() {
		return top + 1;
	}

	void change(int index, int value) {
		arr[index - 1] = value;
	}

	void display() {
		for (int i = 0; i < 10; i++) {
			if (arr[i] != 0) {
				cout << arr[i] << " ";
			}
			else {
				break;
			}
		}
		cout << endl;
	}
};





int main() {
	//stack size limit upto to 10
	stack s;

	s.push(11);
	s.push(12);
	s.push(13);
	s.push(14);
	s.push(15);
	s.push(16);
	s.push(17);
	s.push(18);
	s.push(20);
	s.display();
	s.pop();
	s.pop();
	s.display();
	cout << s.peek(4) << endl;
	s.count();
	s.change(5, 23);
	s.display();
	cout << s.isempty() << endl;
	cout << s.isfull() << endl;
	return 0;
}

