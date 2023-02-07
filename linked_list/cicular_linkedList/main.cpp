//
//  main.cpp
//  cicular_linkedList
//
//  Created by Shivansh Jain on 04/02/23.
//

#include <iostream>
#include <stdio.h>


class node{
public:
    int data;
    node * next;
};

class circularList{
private:
    node * first;
public:
    circularList(){
        first = new node;
    }
    circularList(int A[] , int length);
    ~circularList();
    void display();
    void rDisplay();
    void insert(int x  , int pos);
    int length();
    void Delete(int x);
};
                                
circularList::circularList(int A[] , int length){
    node * last = 0;
    first = new node;
    first->data = A[0];
    first->next = first;
    last = first;
    for(int i = 1 ; i<length ; i++){
        node * temp = (node *)malloc(sizeof(node));
        temp->data = A[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

circularList::~circularList(){
    free(first);
}

void circularList::display(){
    node * iter = first;
    do{
        printf("%d\t" , iter->data);
        iter = iter->next;
    }while(iter != first);
    printf("\n");
}

void circularList::rDisplay(){
    static int flag = 0;
    static node * p = first;
    if((flag != 1) || (p!=first)){
        printf("%d\t" , p->data);
        p = p->next;
        flag = 1;
        rDisplay();
    }
    flag = 0;
}

int circularList::length(){
    node * iter = first;
    int len = 1;
    do{
        len++;
        iter = iter->next;
    }while(iter->next != first);
    
    return len;
}

void circularList::insert(int x , int pos){
    node * iter = first;
    node * n = new node;
    n->data = x;
    if((pos<0) || (pos>length())) printf("invalid position");
    else{
        if (pos ==1){
            if(first != 0){
                do{
                    iter = iter->next;
                }while(iter->next != first);
                n->next = iter->next;
                iter->next = n;
                first = n;
            }
            else {
                first = n;
                first->next = first;
            }
        }
        else{
            for(int i = 1 ; i<pos-1 ; i++){
                iter = iter->next;
            }
            n->next = iter->next;
            iter->next = n;
        }
    }
}

void circularList::Delete(int x){
    node * iter = first;
    node * trail = first;
    int count = 0;
    if(first->data == x){
        while(trail->next != first){
            trail = iter;
            iter = iter->next;
        }
        trail->next = iter->next;
        first = iter->next;
        delete iter;
    }
    else{
        while(iter->data != x){
            trail = iter;
            iter = iter->next;
            if(count == length()) break;
            else count++;
        }
        if(count== length()) printf("element not in list!\n");
        else{
            trail->next = iter->next;
            delete iter;
        }
    }
    
}

int main() {
    int A[5] = {3 , 5, 7, 13, 22};
    circularList first(A,5);
    first.display();
//    first.rDisplay();
//    first.insert(4,5);
//    printf("\n");
//    first.display();
//    first.Delete(5);
//    first.display();
    return 0;
}
