#include<iostream>
#include<vector>
using namespace std;
void insertionsort(int *arr, int size) {
	int flag = 0;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i+1; j < size; j++) {
			if (j == 0) {
				break;
			}
			else if (arr[j] > arr[j - 1]) {
				continue;
			}
			else {
				if (j == i + 1) {
					i++;
					flag++;
				}
				int key = arr[j];
			    arr[j] = arr[j - 1];
			    arr[j - 1] = key;
			    j = j - 2;
			}

		}
		if (flag != 0) {
			i--;
			flag--;
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
	insertionsort(arr, 5);
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}
}