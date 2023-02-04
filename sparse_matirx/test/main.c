#include <stdio.h>

int trap(int* A, int length){
    int rain=0;
    int sum = 0;
    for (int i = 0 ; i<length ; i++){
        sum += A[i];
    }
    
    while(sum>1){
        int max = 0 , min = 0;
        int test[length];
        for(int i = 0 ; i<length ; i++){
            test[i]= -1;
            if(A[i] > max) max = A[i];
            if(A[i]< min) min = A[i];
        }
        
        int k =0;
        for(int i = 0 ; i<length ; i++){
            if(A[i] == max){
                test[k++] = i;
                A[i] -= 1;
            }
            else continue;
        }
        sum  -= k;
        rain += test[k-1] - test[0] + 1 - k;
    }
    return rain;
}

int efftrap(int *A , int length){
    int rain = 0 , diff = 0;
    int max = 0;
    for(int i = 0 ; i<length ; i++){
        if(A[i] > max) max = A[i];
    }
    int lastmax = 0;
    for (int j=length -1 ; j>0 ; j-- ){
        if (A[j] == max){
            lastmax = j;
            break;
        }
        else continue;
    }
    for (int i = 0 ; i<length-2 ;){
        if (i != lastmax){
            if(A[i+1] < A[i]){
                diff = A[i] - A[i+1];
                rain += diff;
                A[i+1] = A[i];
                i++;
            }
            else i++;
        }
        else {
            A[i]--;
            max = 0;
            for (int i=lastmax ; i<length ; i++){
                if(A[i] >= max) max = A[i];
                else continue;
            }
            for (int j = length-1 ; j>lastmax ; j--){
                if(A[j] == max) {
                    lastmax = j;
                    break;
                }
                else continue;
            }
            if(i!= lastmax){
                if(A[i+1] < A[i]){
                    diff = A[i] - A[i+1];
                    rain += diff;
                    A[i+1] = A[i];
                    i++;
                }
                else i++;
            }
            else continue;
        }
    }
    return rain;
}

int main(){
    int A[] = {};
    printf("%d",efftrap(A , 0));
    return 0;
}
