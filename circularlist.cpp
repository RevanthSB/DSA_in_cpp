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
	}
	void set(int k, int d) {
		data = d;
		key = k;
	}
};
class circularlist {
public:
	Node* head;
	circularlist() {
		head = NULL;
	}
	circularlist(Node* n) {
		head = n;
	}
	Node* isexist(int key) {
		Node* temp = NULL;
		Node* ptr = head;
		if (ptr->key == key) {
			temp = ptr;
		}
		else {
			ptr = ptr->next;
			while (ptr != head) {
				if (ptr->key == key) {
					temp = ptr;
					break;
				}
				ptr = ptr->next;
			}
		}
		return temp;
	}
	void append(Node* n) {
		if (head == NULL) {
			head = n;
			n->next = head;
		}
		else {
			Node* ptr = head;
			if (isexist(n->key) == NULL) {
				if (ptr->next == head) {
					ptr->next = n;
					n->next = head;
				}
				else {
					ptr = ptr->next;
					while (ptr != head) {
						if (ptr->next == head) {
							ptr->next = n;
							n->next = head;
							break;
						}
						ptr = ptr->next;
					}
				}
			}
			else {
				cout << "Given key " << n->key << " already present in the list try with new key value" << endl;
			}
		}
	}
	void prepend(Node* n) {
		if (head == NULL) {
			head = n;
			n->next = n;
		}
		else {
			Node* ptr = head;
			if (isexist(n->key) == NULL) {
				if (ptr->next == head) {
					ptr->next == n;
					head = n;
					head->next = ptr;
				}
				else {
					ptr = ptr->next;
					while (ptr != head) {
						if (ptr->next == head) {
							n->next = head;
							head = n;
							ptr->next = head;
							break;
						}
						ptr = ptr->next;
					}
				}
			}
			else {
				cout << "Given key " << n->key << " already present in the list try with new key value" << endl;
			}
		}
	}
	void insert(int key, Node* n) {
		if (head == NULL) {
			head = n;
			n->next = head;
		}
		else {
			Node* ptr = isexist(key);
			if (ptr != NULL) {
				if (isexist(n->key) == NULL) {
					if (ptr->next == head) {
						ptr->next = n;
						n->next = head;
					}
					else {
						Node* temp = ptr->next;
						ptr->next = n;
						n->next = temp;
					}
				}
				else {
					cout << "Given key " << n->key << " already present in the list try with new key value" << endl;
				}
			}
			else {
				cout << "Given key" << key << "is not present in the list" << endl;
			}
		}
	}
	void deletenode(int key) {
		if (head != NULL) {
			Node* ptr = isexist(key);
			if (ptr != NULL) {
				if (ptr == head && ptr->next == head) {
					head = NULL;
				}
				else {
					Node* start = head;
					Node* end = head->next;
						if (start == ptr && ptr->next != start && end->next == start) {
							Node* temp = ptr->next;
							temp->next = ptr->next;
							start->next = NULL;
							head = temp;
						}
						else if (start == ptr && ptr->next != start && end->next != start) {
							do {
								if (start->next == head) {
									start->next = end;
									head->next = NULL;
									head = end;
									break;
								}
								start = start->next;
							} while (start != head);
						}
						else if (start != ptr && ptr->next == start) {
							do {
								if (start->next == ptr) {
									start->next = head;
									break;
								}
								start = start->next;
							}while (start != head);
						}
						else {
							do {
								if (ptr == start->next) {
									start->next = ptr->next;
									ptr->next = NULL;
									break;
								}
								start = start->next;
							} while (start != head);
						}

					}
			}
			else {
				cout << "Given key" << key << "is not present in the list" << endl;
			}
		}
		else {
			cout << "List is empty" << endl;
		}
	}
	void update(int key, int data) {
		if (head == NULL) {
			cout << "List is empty" << endl;
		}
		else {
			Node* ptr = isexist(key);
			if (ptr != NULL) {
				ptr->data = data;
			}
			else {
				cout << "Given key" << key << "is not present in the list" << endl;
			}
		}
	}
	void display() {
		if (head == NULL) {
			cout << "List is empty" << endl;
		}
		else {
			Node* ptr = head;
			do {
				cout << " Key = " << ptr->key <<"  Data = "<< ptr->data << "  address = " << ptr->next << endl;
				ptr = ptr->next;
			} while (ptr != head);
		}
	}
};
int main() {
	int data;
	int key;
	int count = 1;
	int choice;
	int k1;
	circularlist c;
	do {
		Node* n1 = new Node();
		cout << endl;
		cout << " CIRCULAR LINKED LIST OPERATION " << endl;
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
			n1->set(key, data);
			c.append(n1);
			break;
		case 2:
			cout << "enter the key" << endl;
			cin >> key;
			cout << "enter the data" << endl;
			cin >> data;
			n1->set(key, data);
			c.prepend(n1);
			break;
		case 3:
			cout << "enter the key in whick element to be inserted after the key " << endl;
			cin >> k1;
			cout << "enter the key" << endl;
			cin >> key;
			cout << "enter the data" << endl;
			cin >> data;
			n1->set(key, data);
			c.insert(k1, n1);
			break;
		case 4:
			cout << "enter the key in whick element to be deleted" << endl;
			cin >> k1;
			c.deletenode(k1);
			break;
		case 5:
			cout << "enter the key" << endl;
			cin >> key;
			cout << "enter the data" << endl;
			cin >> data;
			c.update(key, data);
			break;
		case 6:
			c.display();
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
