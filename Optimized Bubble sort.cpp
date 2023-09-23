#include<iostream>
#include<vector>
using namespace std;
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void bubblesort(int* arr, int size) {
	bool flag;
	int round = 0;
	for (int i = 0; i < size; i++) {
		flag = false;
		round++;
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				flag = true;
				swap(&arr[j], &arr[j + 1]);
			}
		}
		if (flag == false) {
			cout << "No of rounds : " << round << endl << endl;
			break;
		}
	}

}
int main() {
	int* arr = new int[5];
	cout << "enter the elements" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	cout << endl;
	bubblesort(arr, 5);
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}
}