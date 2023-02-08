//
//  main.cpp
//  Sparse matrix
//
//  Created by Shivansh Jain on 08/02/23.
//

#include <iostream>

struct node{
    int c;
    int data;
    struct node * next;
};

void create(struct node **A , int row , int col){
    for(int i = 0 ; i<row ; i++){
        A[i] = (struct node *)malloc(sizeof(struct node));
        struct node * first = A[i];
        struct node * last = (struct node *)malloc(sizeof(struct node));
        last = first;
        
        for(int j = 1 ; j<col ; j++){
            if((i>1) && (j>2)){
                struct node *temp = (struct node *)malloc(sizeof(struct node));
                temp->c = j;
                temp->data = j>3?5:6;
                temp->next = 0;
                last->next = temp;
                last = temp;
            }
            else continue;
        }
    }
}

void display(struct node **A , int row , int col){
    for(int i = 0 ; i<row ; i++){
        struct node * iter = A[i]->next;
        for(int j = 0 ; j<col ; j++){
            if(iter != 0){
                if(j == iter->c){
                    printf("%d\t" , iter->data);
                    iter = iter->next;
                }
                else printf("0\t");
            }
            else printf("0\t");
        }
        printf("\n");
    }
}

int main() {
    int row = 6;
    int col = 6;
    struct node * A[row];
    create(A , row , col);
    display(A , row , col);
    return 0;
}
