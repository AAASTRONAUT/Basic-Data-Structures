//
//  add.c
//  test5
//
//  Created by Shivansh Jain on 31/01/23.
//

#include "add.h"
#include <stdlib.h>
char** add(char** arr,int n){
    char* p = (char*) malloc(20 * sizeof(char));
    char** arr1=malloc((n+1)*sizeof(p));
    for(int i=0;i<n;i++){
        arr1[i]=arr[i];
    }
    char s[10];
    printf("enter the string you want to add");
    scanf("%s",s);
    arr1[n]=&s[0];
    return arr1;
}
