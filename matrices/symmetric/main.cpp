//
//  main.cpp
//  symmetric
//
//  Created by Shivansh Jain on 24/01/23.
//

#include <iostream>

using namespace std;

class symmetric{
private:
    int *A;
    int n;
public:
    symmetric(int n){
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    ~symmetric(){
        delete []A;
    }
    void set(int i , int j , int x){
        A[i*(i-1)/2 + j-1] = x;
    }
    void display(){
        for(int i =1 ; i<=n ; i++){
            for (int j =1 ; j<=n ; j++){
                if(i>=j){
                    cout<<A[i*(i-1)/2 + j-1]<<"\t";
                }
                else cout<<A[j*(j-1)/2 + i-1]<<"\t";
            }
            cout<<endl<<endl;
        }
    }
};

int main() {
    symmetric matrix(4);
    
    matrix.set(1, 1, 1);
    matrix.set(2, 1, 2);
    matrix.set(2, 2, 3);
    matrix.set(3, 1, 4);
    matrix.set(3, 2, 5);
    matrix.set(3, 3, 6);
    matrix.set(4, 1, 7);
    matrix.set(4, 2, 8);
    matrix.set(4, 3, 9);
    matrix.set(4, 4, 10);
    
    matrix.display();
    return 0;
}
