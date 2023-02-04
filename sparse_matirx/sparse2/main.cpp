//
//  main.cpp
//  sparse2
//
//  Created by Shivansh Jain on 25/01/23.
//

#include <iostream>
using namespace std;

struct element{
    int i;
    int j;
    int x;
};

struct sparse{
    int n;
    int m;
    int nz;
    struct element *e;
};

void create(struct sparse *s){
    printf("Enter size of matrix(Row X Column): ");
    scanf("%d %d" , &s->n , &s->m);
    printf("Enter the number the non-zero elements: ");
    scanf("%d" , &s->nz);
    printf("Enter elements of the matrix:\n");
    s->e = (struct element*)malloc((s->nz)*sizeof(struct element));
    for (int t=0 ; t<s->nz ; t++){
        printf("row, col, element:");
        scanf("%d %d %d" , &s->e[t].i , &s->e[t].j , &s->e[t].x);
    }
}

void display(struct sparse s){
    int k=0;
    for (int i=1 ; i<=s.n ; i++){
        for (int j=1 ; j<=s.m ; j++){
            if((i==s.e[k].i)&&(j == s.e[k].j)){
                printf("%d\t" , s.e[k++].x);
            }
            else printf("%d\t" , 0);
        }
        cout<<endl<<endl;
    }
}

void add(struct sparse a , struct sparse b){
    int k =0;
    struct sparse sum;
    sum.n = a.n;
    sum.m = a.m;
    sum.nz = a.nz + b.nz;
    sum.e = (struct element *)malloc((sum.nz)*sizeof(struct sparse));
    int t =0 ; int z =0;
    while(z<b.nz && t<a.nz){
        
        if(a.e[t].i < b.e[z].i){
            sum.e[k] = a.e[t];
            t++;k++;
        }
        else if(a.e[t].i > b.e[z].i){
            sum.e[k] = b.e[z];
            z++;k++;
        }
        else{
            if(a.e[t].j > b.e[z].j){
                sum.e[k] = b.e[z];
                z++;k++;
            }
            else if(a.e[t].j <b.e[z].j){
                sum.e[k] = a.e[t];
                t++;k++;
            }
            else{
                sum.e[k].i = a.e[t].i; sum.e[k].j = a.e[t].j ; sum.e[k].x = a.e[k].x+b.e[k].x;
                t++;k++;z++;
            }
        }
    }
    
    while(z<b.nz){
        sum.e[k]=b.e[z];
        z++;k++;
    }
    while(t<a.nz){
        sum.e[k] = a.e[t];
        t++;k++;
    }
    
    display(sum);
}

int main() {
    struct sparse a,b;
    create(&a);
    create(&b);
    add(a , b);
    return 0;
}
