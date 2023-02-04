//
//  main.cpp
//  toeplitz
//
//  Created by Shivansh Jain on 24/01/23.
//

#include <iostream>
using namespace std;

class toeplitz{
private:
    int *A;
    int n;
public:
    toeplitz(int n){
        this->n = n;
        A = new int[2*n-1];
    }
    ~toeplitz(){
        delete []A;
    }
    void set(int i , int j , int x){
        if(j>=i){
            A[j-i] = x;
        }
        else A[n+i-j-1] = x;
    }
    void display(){
        for(int i =1 ; i<=n ; i++){
            for (int j =1 ; j<=n ; j++){
                if(j>=i){
                    cout<<A[j-i]<<"\t";
                }
                else cout<<A[n+i-j-1]<<"\t";
            }
            cout<<endl<<endl;
        }
    }
};

int main() {
    toeplitz matrix(4);
    
    matrix.set(1, 1, 1);
    matrix.set(1, 2, 2);
    matrix.set(1, 3, 3);
    matrix.set(1, 4, 4);
    matrix.set(2, 1, 5);
    matrix.set(3, 1, 6);
    matrix.set(4, 1, 7);
    
    matrix.display();
    return 0;
}
