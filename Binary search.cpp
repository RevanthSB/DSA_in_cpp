#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int binarysearch(vector<int> a, int s, int val) {
	int ans = -1;
	int left = 0;
	int right = s-1;
	int mid;
	do {
	    mid = (left + right)/ 2;
		if (a[mid] == val) {
			ans = mid;
			break;
		}
		else if (a[mid] > val) {
			right = mid -1 ;
		}
		else {
			left = mid + 1;
		}
	} while (left <= right);
	return ans;
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
	sort(arr.begin(), arr.end());
	int search = binarysearch(arr, size, elesearch);
	if (search != -1) {
		cout << "searched element position : " << search + 1 << endl;
	}
	else {
		cout << "searched element is not present in the array" << endl;
	}
}
