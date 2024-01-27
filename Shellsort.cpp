#include<iostream>
#include<algorithm>
using namespace std;



void shellsort(int* arr, int n) {
    int gap = n;
    while (gap != 0) {
        gap = gap / 2;
        int i = 0, j = gap;
        while (j < n) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
            if (i - gap >= 0) {
                if (arr[i - gap] > arr[i]) {
                    swap(arr[i - gap], arr[i]);
                }
            }
            i++;
            j++;
        }
    }

}






int main() {
    int n;
    cout << "enter the size of the array" << endl;
    cin >> n;
    int* arr = new int[n];
    cout << "enter the elements" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Corrected: Use arr[i] instead of arr[n]
    }
    shellsort(arr, n);
    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}
