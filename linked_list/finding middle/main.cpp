//
//  main.cpp
//  finding middle
//
//  Created by Shivansh Jain on 08/02/23.
//

#include <iostream>

struct node{
    int data;
    struct node *next;
}*first = NULL , *second = NULL;

void create(int A[] , int n){
    struct node * last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(int i = 1 ; i<n ; i++){
        struct node * temp;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void display(struct node * iter){
    while(iter != NULL){
        printf("%d\t" , iter->data);
        iter = iter->next;
    }
    printf("\n");
}

int middle(struct node * iter){
    struct node * p = iter;
    while(p !=0){
        if(p->next != 0) p = p->next->next;
        else break;
        iter = iter->next;
    }
    return iter->data;
}


int main() {
    int A[5] = {3 , 5, 7, 13, 26 };
    create( A , 5);
    display(first);
    printf("%d\n",middle(first));
    return 0;
}
