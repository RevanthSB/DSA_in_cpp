#include<iostream>
#include <vector>
using namespace std;





void countingsort(int* arr, int n, int div) {
    int* output = new int[n];
    int count[10] = { 0 };
    for (int i = 0; i < n; i++) {
        ++count[((arr[i] / div) % 10)];
    }
    for (int i = 1; i < 10; i++) {
        count[i] = count[i] + count[i - 1];
    }
    for (int i = n-1; i >= 0; i--) {
        output[--count[((arr[i] / div) % 10)]] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    delete[] output;
}




int getmax(int* arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;

}


void radixsort(int* arr, int n) {
    int m = getmax(arr, n);
    for (int div = 1; m / div > 0; div = div * 10) {
        countingsort(arr, n, div);
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
    radixsort(arr, n);
    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}
