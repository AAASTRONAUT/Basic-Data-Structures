//
//  main.cpp
//  arrayADT
//
//  Created by Shivansh Jain on 15/01/23.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

struct Array{
    int *A;
    int size;
    int length;
};

void display(struct Array a){
    for (int i=0 ; i<a.length ; i++){
        printf("%d " , a.A[i]);
    }
    printf("\n");
}

void append(struct Array *a , int n){
    a->A[a->length] = n;
    a->length ++;
}

void insert(struct Array *a , int n , int index){
    if ((index <= a->length) && (index >= 0)){
        for (int i = a->length ; i>index-1 ; i--){
            a->A[i]= a->A[i-1];
        }
        a->A[index] = n;
        a->length ++;
    }
    else printf("Error: Not a valid index\n");
}

void Delete(struct Array *a , int index){
    if ((index>=0) && (index < a->length)){
        for (int i = index ; i < a->length-1 ; i++){
            a->A[i] = a->A[i+1];
        }
        a->length --;
    }
    else printf("Error: not a valid index.");
}

//binary search alogorithm recursive version
int binarySearch_recursive(struct Array a , int l , int h , int n){
    int mid = (l+h)/2;
    if(l<=h){
        if(n == a.A[mid]){
            return mid;
        }
        else if(n > a.A[mid]){
            l = ++mid;
            return binarySearch_recursive(a , l , h , n);
        }
        else{
            h = --mid;
            return binarySearch_recursive(a , l , h , n);
        }
    }
    else return -1;
}

int binarySearch_iterative(struct Array a , int n){
    int l , h , mid;
    l = 0;
    h = a.length-1;
    while(l<=h){
        mid = (l+h)/2;
        if(a.A[mid] == n){
            return mid;
        }
        else if(a.A[mid]>n){
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return -1;
}

void leftRotate(struct Array *a){
    int temp = a->A[0];
    for (int i=1 ; i< a->length ; i++){
        a->A[i-1] = a->A[i];
    }
    a->A[a->length - 1] = temp;
}

void insertInSorted(struct Array *a , int n){
    int i =a->length - 1;
    while(a->A[i] > n){
        a->A[i+1] = a->A[i];
        i--;
    }
    a->A[i+1] = n;
    a->length++;
}

bool isSorted(struct Array a){
    int i = 0;
    while(i<a.length-1){
        if(a.A[i] < a.A[i+1]){
            ++i;
        }
        else return false;
    }
    return true;
}

void swap(int *a , int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sepNegPos(struct Array *a){
    int i=0 , j=a->length-1;
    while (i<j){
        while(a->A[i] < 0){i++;};
        while(a->A[j] > 0){j--;};
        if(i<j){
            swap(&a->A[i] , &a->A[j]);
        };
    }
}

struct Array * merge(struct Array a , struct Array b){
    int i=0 , j=0 , k=0;
    struct Array *c;
    c = (struct Array *)malloc(sizeof(struct Array));
    c->length = a.length + b.length;
    
    while((i<a.length) && (j<b.length)){
        if(a.A[i] <= b.A[j]){
            c->A[k] = a.A[i];
            ++i;
        }
        else {
            c->A[k] = b.A[j];
            ++j;
        }
        ++k;
    }
    for(;i<a.length;i++){
        c->A[k] = a.A[i];
        ++k;
    }
    for(;j<b.length;j++){
        c->A[k] = a.A[j];
        ++k;
    }
    return c;
}

int main() {
    // construction and initiliasation of array.
    struct Array arr;
    printf("enter the length of array:");
    scanf("%d" , &arr.length);
    arr.A = (int *)malloc(arr.length*sizeof(int));
    arr.size = arr.length*sizeof(int);
    
    //initializing the array
    printf("enter the elements of array:\n");
    for (int i=0 ; i<arr.length ; i++){
        scanf("%d" , &arr.A[i]);
    }
//    displaying elements of array
    display(arr);
//
    //    appending elements in array
//    int n;
//    printf("enter element to append:\n");
//    scanf("%d" , &n);
//    append(&arr , n);
//    display(arr);
//
    //    inserting an element at a desired position
//    int x , i;
//    printf("enter element to be added and at what index:\n");
//    scanf("%d" , &x);
//    scanf("%d" , &i);
//    insert(&arr , x , i);
//    display(arr);
//
    //    deleting element from array
//    int d;
//    printf("enter index of element to be deleted:");
//    scanf("%d" , &d);
//    printf("array after deletion of element at index %d :\n" , d);
//    Delete(&arr , d);
//    display(arr);
//
    //    binary search algorithm
    int s;
    printf("enter the element to be searched:");
    scanf("%d" , &s);
    printf("Result of recursive binary search:%d\n" , binarySearch_recursive(arr , 0 , arr.length-1 , s));
    printf("Result of iterative binary search:%d\n" , binarySearch_iterative(arr , s));

        //left rotating an array
    printf("before rotation: ");
    display(arr);
    printf("after rotation: ");
    leftRotate(&arr);
    display(arr);
    
    // insserting an element in a sorted array
//    int element;
//    printf("element to be inserted:");
//    scanf("%d" , &element);
//    insertInSorted(&arr , element);
//    display(arr);
//
    //checking if the array is sorted or not
//    printf("The array is sorted: %d\n" , isSorted(arr));
    
    //sorting an array to have all the  negative numbers on left hand side and all the positive numbers on the right hand side.
    
//    printf("NegPos sorted array: ");
//    sepNegPos(&arr);
//    display(arr);
    
    // merging two arrays
//    struct Array arr2;
//    printf("enter the length of array-2:");
//    scanf("%d" , &arr2.length);
//    arr2.A = (int *)malloc(arr2.length*sizeof(int));
//    arr2.size = arr2.length*sizeof(int);
//
//    //initializing the array-2
//    printf("enter the elements of array-2:\n");
//    for (int i=0 ; i<arr2.length ; i++){
//        scanf("%d" , &arr2.A[i]);
//    }
//
//    //merging
//    struct Array *c;
//    c = merge(arr , arr2);
//    display(*c);
    
    
    return 0;
}
