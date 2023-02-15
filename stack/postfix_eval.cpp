//
//  main.cpp
//  postfix_eval
//
//  Created by Shivansh Jain on 15/02/23.
//

#include <iostream>
using namespace std;

struct stack{
    int top;
    char * s;
    int size;
};

void push(struct stack *head , char x){
    if(head->top == head->size-1) printf("stack overflow\n");
    else{
        head->top++;
        head->s[head->top] = x;
    }
}

char pop(struct stack * head){
    char x;
    if(head->top == -1) {
        x = NULL;
        printf("stack underflow");
    }
    else{
        x = head->s[head->top];
        head->top--;
    }
    return x;
}

int length(char s[]){
    int i = 0;
    while(s[i] != '\0'){
        i++;
    }
    return i;
}

bool isOperand(char x){
    if(x == '+' || x=='-' || x=='*' || x=='/' || x=='^') return false;
    else return true;
}

int eval(char s[]){
    struct stack head;
    head.top = -1;
    head.size = length(s);
    head.s = (char *)malloc(length(s)*sizeof(char));
    
    int i = 0;
    while(s[i] != '\0'){
        if(isOperand(s[i])){
            push(&head , s[i]);
        }
        else{
            int x = pop(&head) - '0';
            int y = pop(&head) - '0';
            switch(s[i]){
                case '+':
                    push(&head , x+y+'0');
                    break;
                case '-':
                    push(&head , y-x+'0');
                    break;
                case '*':
                    push(&head , x*y+'0');
                    break;
                case '/':
                    push(&head , y/x+'0');
                    break;
                case '^':
                    push(&head , y^x+'0');
                    break;
            }
        }
        i++;
    }
    return pop(&head) - '0';
}

int main() {
    char s[100];
    cin>>s;
    printf("%d" , eval(s));
    return 0;
}
