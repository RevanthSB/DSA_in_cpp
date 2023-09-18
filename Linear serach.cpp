#include<iostream>
#include<vector>
using namespace std;

int linearsearch(vector<int> a, int s,int val) {
	int temp = -1;
	for (int i = 0; i < s; i++) {
		if (val == a[i]) {
			temp = i;
		}
	}
	return temp;
}


int main() {
	vector<int> arr;
	int size;
	cout << "enter the size of the array " << endl;
	cin >> size;
	cout << "enter the elements " << endl;
	for (int i = 0; i < size; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	int elesearch;
	cout << "enter the element to be searched " << endl;
	cin >> elesearch;
	int search = linearsearch(arr, size,elesearch);
	if (search != -1) {
		cout << "searched element position : " << search+1 << endl;
	}
	else {
		cout << "searched element is not present in the array" << endl;
	}

}