//
//  main.cpp
//  paranthesis_matching
//
//  Created by Shivansh Jain on 10/02/23.
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


//i have written a modifed pop operator for this problem which allows value of top to be less than -1 to shorten the code.
void pop(struct stack * head){
    head->top--;
}

//using traditional pop function
void pop2(struct stack * head){
    if(head->top == -1) printf("stack underflow");
    else{
        head->top--;
    }
}


//this function uses pop2
void isBalanced2(struct stack *head , char A[] , int len){
    int i = 0;
    while(A[i] != '\0'){
        if(A[i] == '(' || A[i] == '{' || A[i] == '['){
            push(head , A[i]);
        }
        else if(A[i] == ')' || A[i] == '}' || A[i] == ']'){
            if(head->top == -1){
                printf("parenthesis are not balanced!!\n");
                break;
            }
            else if(A[i] == head->s[head->top]){
                pop2(head);
            }
        }
        i++;
    }
    if(i == len )printf("parenthesis are balanced!!\n");
}

//this function uses pop
void isBalanced(struct stack *head , char A[] , int len){
    for(int i = 0 ; i<len ; i++){
        if(A[i] == '(' || A[i] == '{' || A[i] == '['){
            push(head , A[i]);
        }
        else continue;
    }
    for(int i = 0 ; i<len ; i++){
        if(A[i] == ')'){
            pop(head);
        }
        else continue;
    }
    
    if(head->top == -1) printf("paranthesis are balanced!!\n");
    else printf("parenthesis are not balanced!!\n");
}

int main() {
    head.s = (char *)malloc(sizeof(char));
    head.top = -1;
    
    //inputting the string
    char s[100];
    cin>>s;
    
    int length =0;
    while(s[length] !='\0'){
        length++;
    }
    head.size = length;
    isBalanced2(&head ,s ,length);
    return 0;
}
