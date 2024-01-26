#include<iostream>
#include <vector>
using namespace std;

int* countingsort(int* arr, int n) {
    int* output = new int[n];
    int temp = 0;
    int count[10] = { 0 };

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    for (int i = 1; i < 10; i++) {
        count[i] = count[i] + count[i - 1];
    }
   

    for (int i = 0; i < 10; i++) {
        if (count[i] <= n) {
            if (count[i] > temp) {
                for (int j = temp; j < count[i]; j++) {
                    output[j] = i;
                }
                temp = count[i];
            }
        }
        else {
            break;
        }

    }

    return output;
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
    int* output = countingsort(arr, n);
    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << output[i] << " ";
    }
    cout << endl;

    delete[] output;
    delete[] arr;

    return 0;
}
