//
//  main.cpp
//  heap
//
//  Created by Shivansh Jain on 28/02/23.
//
// creating maxheap

#include <iostream>
using namespace std;

void insert(int A[] , int size){
    int i = size;
    int temp = A[i];
    
    while(i>1 && A[i] > A[i/2]){
        A[i] = A[i/2];
        A[i/2] = temp;
        i = i/2;
    }
}

void Delete(int A[] , int size){
    int i = 1;
    int init = A[1];
    A[1] = A[size];
    while(2*i < size){
        int j = 2*i;
        if(A[2*i] < A[2*i + 1]){
            j = 2*i +1;
        }
        int temp = A[j];
        A[j] = A[i];
        A[i] = temp;
        i = j;
    }
    A[size] = init;
}

void HeapSort(int A[] , int size){
    for(int i= size ; i>1 ; i--){
        Delete(A , i);
    }
}

void Heapify(int A[] , int size){
    int i = size/2;
    while(i > 0){
        int j = 2*i;
        if(A[2*i] < A[2*i + 1]){
            j = A[2*i + 1];
        }
        int k = i;
        while(A[i] < A[j] & j <=size){
            int temp = A[j];
            A[j] = A[k];
            A[k] = temp;
            i = k;
            j = 2*i;
            if(A[2*i] < A[2*i + 1]){
                j = A[2*i + 1];
            }
        }
        i--;
    }
}

int main() {
    int size;
    cout<<"Enter size of heap: ";
    cin>>size;
    int A[size+1];
    cout<<"Enter elements of heap but give and add zero as the first element: ";
    for(int i = 0 ; i<=size ; i++){
        cin>>A[i];
    }
    for(int i = 1 ; i<size+1 ; i++){
        insert(A , i);
    }
    cout<<"Heap: ";
    for(int i = 0 ; i<size+1 ; i++){
        cout<<A[i]<<"\t";
    }
    cout<<endl;
    cout<<"Heap using Heapify: ";
    Heapify(A, size);
    for(int i = 0 ; i<size+1 ; i++){
        cout<<A[i]<<"\t";
    }
    cout<<endl;
    cout<<"sorting heap using delete: ";
    HeapSort(A , size);
    for(int i = 0 ; i<size+1 ; i++){
        cout<<A[i]<<"\t";
    }
    return 0;
}
