//
//  main.cpp
//  stack
//
//  Created by Shivansh Jain on 08/02/23.
//

#include <iostream>
using namespace std;

class stack{
private:
    int size;
    int top;
    int * s;
public:
    stack(int size){
        this->size = size;
        top = -1;
        s = new int[size];
    }
    void display();
    void push(int x);
    int pop();
    int peek(int pos);
};

void stack::display(){
    for(int i = top ; i>-1 ; i--){
        printf("%d\n" , s[i]);
    }
}

void stack::push(int x){
    if(top == size-1) printf("Stack Overflow!!\n");
    else{
        top++;
        s[top] = x;
    }
}

int stack::pop(){
    int x = -1;
    if(top == -1) {
        printf("Stack underflow!!\n");
    }
    else{
        x = s[top];
        top--;
    }
    return x;
}

int stack::peek(int pos){
    if(pos<0 || pos>top+1) {
        printf("Invalid Position!!\n");
        return -1;
    }
    else{
        return s[top-pos+1];
    }
}

int main() {
    stack s(5);
    s.push(3);
    s.push(7);
    s.push(9);
    s.push(5);
    s.push(10);
    cout<<"original stack: "<<endl;
    s.display();
    cout<<"popped element after pop method: "<<s.pop()<<endl;
    cout<<"element at position 1 using peek method: "<<s.peek(1)<<endl;
    cout<<"display of stack after operations:"<<endl;
    s.display();
    return 0;
}
