//
//  main.cpp
//  infix to postfix including associativity
//
//  Created by Shivansh Jain on 13/02/23.
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
    if(x == '+' || x=='-' || x=='*' || x=='/' || x=='(' || x==')' || x=='^') return false;
    else return true;
}


int instackPref(struct stack * head , char x){
    if(x == '+' || x == '-') return 2;
    else if(x == '*') return 4;
    else if(x=='/') return 6;
    else if(x == '^') return 7;
    else if(x=='(') return 0;
    else return 0;
}

int outstackPref(struct stack * head , char x){
    if(x == '+' || x == '-') return 1;
    else if(x == '*') return 3;
    else if(x=='/') return 5;
    else if(x == '^') return 8;
    else if(x == '(') return 9;
    else if(x==')') return 0;
    else return 0;
}

char * toPost(char s[]){
    struct stack head;
    head.size = length(s);
    head.top = -1;
    head.s = (char *)malloc(length(s)*sizeof(char));
    
    char * post = (char *)malloc(length(s)*sizeof(char));
    int i = 0;
    int j = 0;
    while(s[i] != 0){
        if(isOperand(s[i])){
            post[j] = s[i];
            j++;
        }
        else{
            if(head.top == -1){
                push(&head , s[i]);
            }
            else{
                if(instackPref(&head,head.s[head.top]) < outstackPref(&head , s[i])){
                    push(&head , s[i]);
                }
                
                else{
                    if(s[i] == ')'){
                        while(instackPref(&head,head.s[head.top]) != outstackPref(&head , s[i])){
                            post[j] = pop(&head); // fix the bug
                            j++;
                        }
                        pop(&head);
                    }
                    else{
                        post[j] = pop(&head);
                        push(&head , s[i]);
                        j++;
                    }
                }
            }
        }
        i++;
    }
    while(head.top != -1){
        post[j] = pop(&head);
        j++;
    }
    return post;
}

int main() {
    char s[100];
    cin>>s;
    char * p;
    p = toPost(s);
    int i = 0;
    while(p[i] != '\0'){
        cout<<p[i];
        i++;
    }
    cout<<endl;
    return 0;
}
