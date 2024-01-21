/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;


void merge(int arr[],int l,int m,int r){
    int temp[r];
    int i=l;
    int j=m+1;
    int k = l;
    while(i<=m && j<=r){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            k++;
            i++;
        }
        else{
           temp[k] = arr[j];
            k++;
            j++;
        }
    }
    while(i<=m){
            temp[k] = arr[i];
            k++;
            i++;
    }
    while(j<=r){
            temp[k] = arr[j];
            k++;
            j++;
    }
    for(int i=l;i<=r;i++){
        arr[i] = temp[i];
    }
}

void mergesort(int arr[], int l, int r) {
	if (l < r) {
        int m = (l+r)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
	}
}



int main() {
    int n;
    cout<<"enter the number of elements "<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the elements "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

































