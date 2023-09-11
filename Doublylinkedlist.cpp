#include<iostream>
using namespace std;
class Node {
public:
	int key;
	int data;
	Node* next;
	Node* prev;
	Node() {
		key = 0;
		data = 0;
		next = NULL;
		prev = NULL;
	}
	Node(int k, int d) {
		key = k;
		data = d;
		next = NULL;
		prev = NULL;
	}
	void setnode(int k, int d) {
		key = k;
		data = d;
		next = NULL;
		prev = NULL;
	}
};
class Doublylinkedlist {
public:
	Node* head;
	Node* tail;
	int count = 0;
	Doublylinkedlist() {
		head = NULL;
		tail = NULL;
	}
	Doublylinkedlist(Node* n) {
		head = n;
		tail = n;
		count = 1;
	}
	Node* isexist(int key) {
		Node* temp = NULL;
		Node* ptr = head;
		if (ptr->next == NULL && ptr->prev == NULL) {
			if (ptr->key == key) {
				temp = ptr;
			}
		}
		else {
			while (ptr != NULL) {
				if (ptr->key == key) {
					temp = ptr;
					break;
				}
				ptr = ptr->next;
			}
		}
		return temp;
	}
	void appendnode(Node* n) {
		if (head == NULL) {
			head = n;
			tail = n;
		}
		else if (head->next == NULL) {
			if (isexist(n->key) == NULL) {
				head->next = n;
				n->prev = head;
				tail = n;
			}
			else {
				cout << "entered key " << n->key << " already present try with new key value " << endl;
			}
		}
		else {
			if (isexist(n->key) == NULL) {
				Node* ptr = head;
				while (ptr != NULL) {
					if (ptr->next == NULL) {
						ptr->next = n;
						n->prev = ptr;
						tail = n;
						break;
					}
					ptr = ptr->next;
				}
			}
			else {
				cout << "entered key " << n->key << " already present try with new key value " << endl;
			}
		}
	}
	void prependnode(Node* n) {
		if (head == NULL) {
			head = n;
			tail = n;
		}
		else{
			if (isexist(n->key) == NULL) {
				n->next = head;
				head->prev = n;
				head = n;
			}
			else {
				cout << "entered key " << n->key << " already present try with new key value " << endl;
			}
		}
	}
	void insertnodeafter(int key, Node* n) {
		if (head == NULL) {
			head = n;
			tail = n;
		}
		else {
			Node* ptr = isexist(key);
			if (ptr != NULL) {
				if (ptr->next == NULL) {
					if (isexist(n->key) == NULL) {
						ptr->next = n;
						n->prev = ptr;
						tail = n;
					}
					else {
						cout << "entered key " << n->key << " already present try with new key value " << endl;
					}
				}
				else {
					if (isexist(n->key) == NULL) {
						Node* temp = ptr->next;
						n->prev = ptr;
						ptr->next = n;
						n->next = temp;
						temp->prev = n;
					}
					else {
						cout << "entered key " << n->key << " already present try with new key value " << endl;
					}
				}
			}
			else {
				cout << "entered key " << key << " is not have any node in the list" << endl;
			}
		}
	}
	void deletenode(int key) {
		if (head == NULL) {
			cout << "List is empty" << endl;
		}
		else {
			Node* ptr = isexist(key);
			if (ptr != NULL) {
				if (head->key == ptr->key) {
					Node* newhead = head->next;
					head->next = NULL;
					newhead->prev = NULL;
					head = newhead;
				}
				else if (tail->key == ptr->key) {
					Node* newtail = ptr->prev;
					ptr->prev = NULL;
					newtail->next = NULL;
					tail = newtail;
				}
				else {
					Node* delprev = ptr->prev;
					Node* delnext = ptr->next;
					delprev->next = ptr->next;
					delnext->prev = ptr->prev;
				}
			}
			else {
				cout << "entered key " << key << " is not have any node in the list" << endl;
			}
		}
	}
	void updatenode(int key, int data) {
		if (head == NULL) {
			cout << "list is empty" << endl;
		}
		else {
			Node* ptr = isexist(key);
			if (ptr != NULL) {
				ptr->data = data;
			}
			else {
				cout << "entered key " << key << " is not have any node in the list" << endl;
			}
		}
	}
	void displaynode() {
		Node* ptr = head;
		if (head != NULL) {
			while (ptr != NULL) {
				cout << ptr->prev << " " << ptr->key << " " << ptr->data << " " << ptr->next << endl;
				ptr = ptr->next;
			}
		}
		else {
			cout << "List is empty" << endl;
		}
		cout << endl;
	}
};
int main() {
	int data;
	int key;
	int count = 1;
	int choice;
	int k1;
	Doublylinkedlist d;
	do {
		Node* n1 = new Node();
		cout << endl;
		cout << " DOUBLY LINKED LIST OPERATION " << endl;
		cout << " 1. appendnode " << endl;
		cout << " 2. prependnode " << endl;
		cout << " 3. insertnode " << endl;
		cout << " 4. deletenode " << endl;
		cout << " 5. updatedata " << endl;
		cout << " 6. displaylist " << endl;
		cout << " 7. exit " << endl;
		cout << endl;
		cout << "enter the option " << endl;
		cin >> choice;
		cout << endl;
		switch (choice) {
		case 1:
			cout << "enter the key" << endl;
			cin >> key;
			cout << "enter the data" << endl;
			cin >> data;
			n1->setnode(key, data);
			d.appendnode(n1);
			break;
		case 2:
			cout << "enter the key" << endl;
			cin >> key;
			cout << "enter the data" << endl;
			cin >> data;
			n1->setnode(key, data);
			d.prependnode(n1);
			break;
		case 3:
			cout << "enter the key" << endl;
			cin >> key;
			cout << "enter the data" << endl;
			cin >> data;
			n1->setnode(key, data);
			cout << "enter the key in whick element to be inserted after the key " << endl;
			cin >> k1;
			d.insertnodeafter(k1, n1);
			break;
		case 4:
			cout << "enter the key in whick element to be deleted" << endl;
			cin >> k1;
			d.deletenode(k1);
			break;
		case 5:
			cout << "enter the key" << endl;
			cin >> key;
			cout << "enter the data" << endl;
			cin >> data;
			d.updatenode(key, data);
			break;
		case 6:
			d.displaynode();
			break;
		case 7:
			count = 0;
			break;
		default:
			cout << "enter option correctly" << endl;
			break;
		}
	} while (count != 0);
	return 0;
}
