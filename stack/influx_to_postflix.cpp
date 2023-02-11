//
//  main.cpp
//  infix to postfix
//
//  Created by Shivansh Jain on 11/02/23.
//

#include <iostream>
using namespace std;

struct stack{
    int top;
    char * s;
    int size;
}head;

void push(struct stack *head , int x){
    if(head->top == head->size-1) printf("stack overflow\n");
    else{
        head->top++;
        head->s[head->top] = x;
    }
}

void pop(struct stack * head){
    if(head->top == -1) printf("stack underflow");
    else{
        head->top--;
    }
}

int length(char s[]){
    int i = 0;
    while(s[i] != '\0'){
        i++;
    }
    return i;
}

int precedance(char x){
    if(x=='+' || x=='-') return 1;
    else if(x=='*' || x=='/')return 2;
    else return 0;
}

bool isOperand(char x){
    if(x == '+' || x=='-' || x=='*' || x=='/') return false;
    else return true;
}

char * toPostfix(char s[] , int len){
    head.size = length(s);
    head.top = -1;
    head.s = (char *)malloc(length(s)*sizeof(char));
    
    char * postfix;
    postfix = (char *)malloc(len*sizeof(char));
    int j = 0;
    int i = 0;
    while(s[i] != '\0'){
        if(isOperand(s[i])){
            postfix[j] = s[i];
            j++;
        }
        else{
            if(precedance(s[i]) > precedance(head.s[head.top])){
                push(&head , s[i]);
            }
            else{
                postfix[j] = head.s[head.top];
                pop(&head);
                push(&head , s[i]);
                j++;
            }
        }
        i++;
    }
    while(head.top != -1){
        postfix[j] = head.s[head.top];
        pop(&head);
        j++;
        i++;
    }
    return postfix;
}


int main() {
    char s[100];
    cin>>s;
    char * p;
    p = toPostfix(s , length(s));
    int i = 0;
    while(p[i] != '\0'){
        cout<<p[i];
        i++;
    }
    cout<<endl;
    return 0;
}
