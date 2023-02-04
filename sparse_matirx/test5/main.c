//
//  main.c
//  test5
//
//  Created by Shivansh Jain on 31/01/23.
//

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "add.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    printf("enter size");
    scanf("%d",&n);
    char* p = (char*) malloc(20 * sizeof(char));
    char** str=malloc(n*sizeof(p));
    for(int i=0;i<n;i++){
        scanf("%s",str[i]);
        }
    char** q=add(str,n);
    //printf(
    
    return 0;
}
