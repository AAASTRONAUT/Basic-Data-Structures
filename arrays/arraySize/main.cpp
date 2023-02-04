#include <iostream>
using namespace std;

int main() {
    int *p;
    p = new int[5];
    for (int i =0; i<5 ; i++){
        p[i] = i+1;
    }
    for (int i =0 ; i<5 ; i++){
        cout<<p[i];
    }
    cout<<"\n";
    //to increase the array size
    int *q;
    q = new int[10];
    for (int i =0 ; i<5 ; i++){
        q[i] = p[i];
    }
    
    delete []p;
    p = q;
    q=NULL;
    
    for (int i=0 ; i<10 ; i++){
        cout<<p[i];
    }
    return 0;
}
