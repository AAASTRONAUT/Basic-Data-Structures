//
//  queue.h
//  Tree
//
//  Created by Shivansh Jain on 22/02/23.
//
#include <iostream>
#ifndef queue_h
#define queue_h
using namespace std;

class node{
public:
    node * right;
    node * left;
    int data;
};

class queue{
private:
    int size;
    int front;
    int rear;
    node ** q;
public:
    queue(){
        q = new node*;
        this->size = 1;
        front = -1;
        rear = -1;
    }
    queue(int size){
        q = new node*[size];
        this->size = size;
        front = -1;
        rear = -1;
    }
    ~queue(){
        delete q;
    }
    void display();
    void enqueue(node * x);
    node * dequeue();
    bool isFull();
    bool isEmpty();
};

void queue::enqueue(node * x){
    if(rear == size-1) cout<<"queue full!!"<<endl;
    else{
        rear++;
        q[rear] = x;
    }
};

node * queue::dequeue(){
    node * x = NULL;
    if(rear == -1) cout<<"queue empty!!"<<endl;
    else{
        x = q[++front];
    }
    return x;
}

bool queue::isFull(){
    if(rear == front || rear == size -1) return true;
    else return false;
}

bool queue::isEmpty(){
    if(rear == size -1) return false;
    else return true;
}

#endif /* queue_h */
