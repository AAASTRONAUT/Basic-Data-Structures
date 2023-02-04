//
//  main.cpp
//  lower_triangular
//
//  Created by Shivansh Jain on 24/01/23.
//

#include <iostream>

using namespace std;

template <class T>
class lower_triangular{
private:
    T *A;
    int n;
    int m;
public:
    lower_triangular(int n , int m);
    ~lower_triangular();
    void set(int i , int j , int x);
    void display();
};

template <class T>
lower_triangular<T>::lower_triangular(int n , int m){
    this->n = n;
    this->m = m;
    A = new T[n*(n+1)/2];
}

template<class T>
void lower_triangular<T>::set(int i , int j , int x){
    A[i*(i-1)/2 + j-1] = x;
}

template <class T>
void lower_triangular<T>::display(){
    for(int i =1 ; i<=n ; i++){
        for (int j =1 ; j<=n ; j++){
            if(i>=j){
                cout<<A[i*(i-1)/2 + j-1]<<"\t";
            }
            else cout<<0<<"\t";
        }
        cout<<"\n";
    }
}

template <class T>
lower_triangular<T>::~lower_triangular(){
    delete []A;
}

int main() {
    lower_triangular<int> matrix(4,4);
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
