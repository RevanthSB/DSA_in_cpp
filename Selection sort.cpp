#include<iostream>
#include<vector>
using namespace std;
void selectionsort(int *arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		if (min != i) {
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}
int main() {
	int *arr = new int[5];
	cout << "enter the elements" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	cout << endl;
	selectionsort(arr, 5);
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}
	delete []arr;
}
