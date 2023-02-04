//
//  main.cpp
//  2darray
//
//  Created by Shivansh Jain on 14/01/23.
//

#include <iostream>
using namespace std;

int main() {
    //1 array in stack
    int c[3][3] = {{1,2,3} , {4,5,6} , {7,8,9}};
    //2 pointer in stack and array in heap
    int *A[3];
    
    A[0] = new int[3];
    A[1] = new int[3];
    A[2] = new int[3];
    
    A[1][2] = 12;
    cout<<A[1][2]<<endl;
    
    //3  both pointer and array in heap
    int **B;
    B = (int **)malloc(3*sizeof(int *));
    B[0] = (int *)malloc(3*sizeof(int));
    B[1] = (int *)malloc(3*sizeof(int));
    B[2] = (int *)malloc(3*sizeof(int));
    for (int i = 0 ; i<3 ; i++){
        for (int j=0 ; j<3 ; j++){
            B[i][j] = (i+1)*(j+1);
            cout<<B[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}
