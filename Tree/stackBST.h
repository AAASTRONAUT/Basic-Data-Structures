//
//  stack.h
//  Tree
//
//  Created by Shivansh Jain on 22/02/23.
//

#ifndef stack_h
#define stack_h

#include <iostream>
#include <stdio.h>
#include "queue.h"

using namespace std;

class stack{
private:
    int size;
    int top;
    node ** s;
public:
    stack(int size){
        this->size = size;
        top = -1;
        s = new node*[size];
    }
    void push(node* x);
    node * pop();
    bool isEmpty();
    node * topele();
};


void stack::push(node * x){
    if(top == size-1) printf("Stack Overflow!!\n");
    else{
        top++;
        s[top] = x;
    }
}

node * stack::pop(){
    node * x = NULL;
    if(top == -1) {
        printf("Stack underflow!!\n");
    }
    else{
        x = s[top];
        top--;
    }
    return x;
}

bool stack::isEmpty(){
    if(top == -1) return true;
    else return false;
}

node * stack::topele(){
    return s[top];
}

#endif /* stack_h */
