#include<iostream>
using namespace std;
class Node {
public:
	int data;
	int key;
	Node* next;

	Node() {
		data = 0;
		key = 0;
		next = NULL;
	}
	Node(int d, int k) {
		data = d;
		key = k;
		next = NULL;
	}
	void setnode(int k, int d) {
		data = d;
		key = k;
		next = NULL;
	}
};

class Linkedlist {
public:
	Node* head;

	Linkedlist() {
		head = NULL;
	}
	Linkedlist(Node* h) {
		head = h;
	}
	Node* isexist(int key) {
		Node* temp = NULL;
		Node* ptr = head;
		while (ptr != NULL) {
			if (ptr->key == key) {

				temp = ptr;
			}
			ptr = ptr->next;
		}

		return temp;
	}
	void appendnode(Node* n) {
		int key = n->key;
			if (isexist(key) != NULL) {
				cout << "key " << key << " is already existed try with a new key value" << endl;
			}
			else {
				Node* ptr = head;
				if (head == NULL) {
					head = n;
				}
				else {
					while (ptr != NULL) {
						if (ptr->next == NULL) {
							ptr->next = n;
							break;
						}
						ptr = ptr->next;
					}
				}
				displaylist();
			}

	}
	void prependnode(Node* n) {
		int key = n->key;
			if (isexist(key) != NULL) {
				cout << "key " << key << " is already existed try with a new key value" << endl;
			}
			else {
				if (head == NULL) {
					head = n;
				}
				else {
					n->next = head;
					head = n;
				}
			}
	}
	void insertnode(int key, Node* n) {
		Node* ptr = isexist(key);
		if (ptr != NULL) {
			if (isexist(n->key) == NULL) {
				n->next = ptr->next;
				ptr->next = n;
			}
			else {
				cout << "key " << n->key << " is already existed try with a new key value" << endl;
			}
		}
		else {
			cout << "key is not existed" << endl;
		}
	}
	void deletenode(int key) {
		if (head != NULL) {
			Node* ptr = isexist(key);
			if (ptr != NULL) {
				if (ptr == head) {
					head = head->next;
				}
				else {
					Node* prevtemp = head;
					Node* currtemp = head->next;
					while (currtemp != NULL) {
						if (currtemp->key == ptr->key) {
							prevtemp->next = currtemp->next;
							currtemp->next = NULL;
							break;
						}
						prevtemp = currtemp;
						currtemp = currtemp->next;
					}
				}
			}
			else {
				cout << "key is not existed" << endl;
			}
		}
		else {
			cout << "Linked list is empty" << endl;
		}
	}
	void updatedata(int key, int d) {
		Node* ptr = isexist(key);
			if (ptr != NULL) {
				ptr->data = d;
			}
			else {
				cout << "Node is not present in the linked list" << endl;
			}
	}
	void displaylist() {
		if (head == NULL) {
			cout << "linked list is empty" << endl;
		}
		else {
			cout << "Linked list elements" << endl;
			Node* ptr = head;
			while (ptr != NULL) {
				cout << ptr->key << " " << ptr->data << " " << ptr->next << endl;
				ptr = ptr->next;
			}
			cout << endl;
		}
	}
};

int main() {
	int data;
	int key;
	int k1;
	int count = 1;
	int choice;
	Linkedlist l;
	do {
		Node* n1 = new Node();
		cout << endl;
		cout << " LINKED LIST OPERATION " << endl;
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
			//Node * n1 = new Node();
			cout << "enter the key" << endl;
			cin >> key;
			cout << "enter the data" << endl;
			cin >> data;
			n1->setnode(key, data);
			l.appendnode(n1);
			break;
		case 2:
			//Node * n1 = new Node();
			cout << "enter the key" << endl;
			cin >> key;
			cout << "enter the data" << endl;
			cin >> data;
			n1->setnode(key, data);
			l.prependnode(n1);
			break;
		case 3:
			cout << "enter the key" << endl;
			cin >> key;
			cout << "enter the data" << endl;
			cin >> data;
			n1->setnode(key, data);
			cout << "enter the key in whick element to be inserted after the key " << endl;
			cin >> k1;
			l.insertnode(k1, n1);
			break;
		case 4:
			cout << "enter the key in whick element to be deleted" << endl;
			cin >> k1;
			l.deletenode(k1);
			break;
		case 5:
			cout << "enter the key" << endl;
			cin >> key;
			cout << "enter the data" << endl;
			cin >> data;
			l.updatedata(key, data);
			break;
		case 6:
			l.displaylist();
			break;
		case 7:
			count = 0;
			break;
		default:
			cout << "enter option correctly" << endl;
		}
	} while (count != 0);

return 0;
}