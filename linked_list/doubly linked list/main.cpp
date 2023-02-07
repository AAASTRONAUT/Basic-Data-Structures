//
//  main.cpp
//  doubly linked list
//
//  Created by Shivansh Jain on 07/02/23.
//

#include <iostream>

struct node{
    struct node * prev;
    int data;
    struct node * next;
}* first = 0;

void create(int A[] , int n){
    first = (struct node *)malloc(sizeof(struct node));
    struct node * last;
    first->prev = 0;
    first->data = A[0];
    first->next = 0;
    last = first;
    for(int i = 1 ; i<n ; i++){
        struct node * temp = (struct node *)malloc(sizeof(struct node));
        temp->data = A[i];
        temp->prev = last;
        temp->next = 0;
        last->next = temp;
        last = temp;
    }
}

void display(struct node * iter){
    while(iter!=0){
        printf("%d\t" , iter->data);
        iter = iter->next;
    }
    printf("\n");
}

int length(struct node * iter){
    int len = 0;
    while(iter != 0){
        len++;
        iter = iter->next;
    }
    return len;
}

void insert(struct node * iter , int x , int pos){
    if((pos<0) || (pos > length(first) + 1)) printf("Invalid position!!\n");
    else{
        struct node * n = (struct node *)malloc(sizeof(struct node));
        n->data = x;
        if(pos == 1){
            n->prev = NULL;
            n->next = first;
            first->prev = n;
            first = n;
        }
        else if(pos == length(first) + 1){
            for(int i = 0 ; i<length(first)-1 ; i++){
                iter = iter->next;
            }
            iter->next = n;
            n->prev = iter;
            n->next = NULL;
        }
        
        else{
            for(int i = 1 ; i<pos-1 ; i++){
                iter = iter->next;
            }
            n->prev = iter;
            n->next = iter->next;
            iter->next->prev = n;
            iter->next = n;
        }
    }
}

void Delete(struct node * iter , int x){
    int count = 0;
    while(iter->data != x){
        iter = iter->next;
        count++;
        if(count == length(first)) break;
        else continue;
    }
    if(count == length(first)) printf("element not in list\n");
    else{
        if(iter == first){
            first = first->next;
            first->prev = NULL;
            delete iter;
        }
        
        else if(iter->next != NULL){
            iter->prev->next = iter->next;
            iter->next->prev = iter->prev;
            delete iter;
        }
        
        else{
            iter->prev->next = iter->next;
            delete iter;
        }
    }
}

void reverse(struct node * iter){
    struct node * temp = NULL;
    while(iter != 0){
        temp = iter->next;
        iter->next = iter->prev;
        iter->prev = temp;
        iter = iter->prev;
        if(iter!=NULL && iter->next == NULL) first = iter;
    }
}

int main() {
    int A[5] = {3,5,7,9,11};
    create(A , 5);
    printf("original doubly linked list: ");
    display(first);
    printf("Length of the doubly linked list: ");
    printf("%d\n" , length(first));
    printf("list after insert operation: ");
    insert(first , 12 ,6);
    display(first);
    printf("list after delete operation: ");
    Delete(first , 3);
    display(first);
    printf("list after reversing the list: ");
    reverse(first);
    display(first);
    return 0;
}
